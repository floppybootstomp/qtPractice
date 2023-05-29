#ifndef GAME_H
#define GAME_H

#include <QWidget>

#include "../headers/openGLWidget.h"
#include "../gameObjects/headers/triangle.h"
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

    // game assets
    Triangle *trgl;
    Background *bkg;

    // Handles what happens when widget loses focus
    void focusOutEvent(QFocusEvent *event) override;

    // Action to perform when widget loses focus
    void winUnfocusedAction();
};

#endif // GAME_H
