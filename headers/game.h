#ifndef GAME_H
#define GAME_H

#include <QWidget>

#include "../headers/openGLWidget.h"
#include "../gameObjects/headers/inputHandler.h"
#include "../gameObjects/headers/triangle.h"
#include "../gameObjects/headers/cade.h"
#include "../backgrounds/headers/background.h"

class Game : public QWidget
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    ~Game();

    void update();

public slots:
    // actions to be updated each frame
    void refreshLoop();

private:
    // calls refreshLoop each frame
    QTimer *refreshTimer;

    // openGLWidget to draw game
    OpenGLWidget *oglWidget;

    // inputHandler to handle input
    InputHandler *iptHandler;

    // game assets
    Triangle *trgl;
    Cade *cde;
    Background *bkg;

    // Handles what happens when widget loses focus
    void focusOutEvent(QFocusEvent *event) override;

    // Action to perform when widget loses focus
    void winUnfocusedAction();
};

#endif // GAME_H
