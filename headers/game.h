#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "../headers/openGLWidget.h"
#include "../gameObjects/headers/inputHandler.h"
#include "../gameObjects/headers/triangle.h"
#include "../gameObjects/headers/cade.h"
#include "../backgrounds/headers/prooh.h"
#include "../backgrounds/headers/guscatBkg.h"
#include "../scenes/headers/scene.h"

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
    Scene *mainscene;
    Triangle *trgl;
    Cade *cde;
    Prooh *proohbkg;
    GuscatBkg *gusbkg;

    // Handles what happens when widget loses focus
    void focusOutEvent(QFocusEvent *event) override;

    // Action to perform when widget loses focus
    void winUnfocusedAction();
};

#endif // GAME_H
