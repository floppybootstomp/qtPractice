#include "../headers/game.h"
#include "../headers/globalVars.h"

Game::Game(QWidget *parent) : QWidget (parent)
{
    oglWidget = new OpenGLWidget(this);
    iptHandler = new InputHandler(this);
    trgl = new Triangle(oglWidget, iptHandler);
    bkg = new Background(oglWidget, iptHandler);

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
    delete trgl;
    delete bkg;
    delete oglWidget;
    delete iptHandler;
    delete refreshTimer;
}

void Game::update()
{
    bkg->update();
    trgl->update();
    oglWidget->update();
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
