#include "../headers/game.h"
#include "../headers/globalVars.h"

Game::Game(QWidget *parent) : QWidget (parent)
{
    oglWidget = new OpenGLWidget(this);
    iptHandler = new InputHandler(oglWidget, this);

    // init scene
    scnHandl = new SceneHandler(this);
    mainscene = new Scene(QString("gusroom"), oglWidget, this);

    // init scene items
    trgl = new Triangle(oglWidget, iptHandler);
    cde = new Cade(oglWidget, iptHandler);
    //proohbkg = new Prooh(oglWidget, iptHandler);
    gusbkg = new GuscatBkg(oglWidget);

    // add items to scene
    mainscene->changeBackground(gusbkg);
    mainscene->addGameObject(cde);
    mainscene->addGameObject(trgl);

    // set to follow trgl
    mainscene->setViewportFollowing(trgl, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

    // add mainscene to scene handler
    scnHandl->addScene(mainscene);
    scnHandl->setCurrentScene(QString("gusroom"));

    // resize to screen size
    resize(SCREEN_WIDTH, SCREEN_HEIGHT);

    //set layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(oglWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    // set focus policy
    setFocusPolicy(Qt::StrongFocus);

    // refresh timer
    refreshTimer = new QTimer();
    refreshTimer->setSingleShot(false);
    connect(refreshTimer, SIGNAL(timeout()), this, SLOT(refreshLoop()));
    refreshTimer->start(1000/FRAMERATE);
}

Game::~Game()
{
    delete scnHandl;
    delete mainscene;
    delete oglWidget;
    delete iptHandler;
    delete refreshTimer;
}

void Game::update()
{
    scnHandl->update();
    oglWidget->update();
    iptHandler->update();
}

// Handles what happens when widget loses focus
void Game::focusOutEvent(QFocusEvent *event)
{
    winUnfocusedAction();
}

// actions to perform when window is unfocused
void Game::winUnfocusedAction()
{
    iptHandler->clearInputBuffers();
}

// actions to be updated each frame
void Game::refreshLoop()
{
    update();
}
