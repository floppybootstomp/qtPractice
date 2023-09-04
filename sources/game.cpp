#include "../headers/game.h"
#include "../headers/globalVars.h"

Game::Game(QWidget *parent) : QWidget (parent)
{
    oglWidget = new OpenGLWidget(this);
    iptHandler = new InputHandler(oglWidget, this);

    // init scene
    mainscene = new Scene(this);

    // init scene items
    trgl = new Triangle(oglWidget, iptHandler);
    cde = new Cade(oglWidget, iptHandler);
    bkg = new Prooh(oglWidget, iptHandler);

    // add items to scene
    mainscene->changeBackground(bkg);
    mainscene->addGameObject(cde);
    mainscene->addGameObject(trgl);

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
    delete mainscene;
    delete oglWidget;
    delete iptHandler;
    delete refreshTimer;
}

void Game::update()
{
    mainscene->update();
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
