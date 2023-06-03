#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QWidget>
#include <QKeyEvent>
#include <QtOpenGL>
#include <QImage>
#include <QString>
#include "../../headers/openGLWidget.h"
#include "../headers/inputHandler.h"
#include "animation.h"

class GameObject : public QWidget
{
    Q_OBJECT
public:
    int x, y, width, height;

    QString spritePath;

    GameObject(OpenGLWidget *oglWidg, InputHandler *iptHandl, QWidget *parent = 0);

    GameObject(int xPos, int yPos, float depthAmnt, OpenGLWidget *oglWidg, InputHandler *iptHandl, QWidget *parent = 0);

    ~GameObject();

    // Initializes a gameObject
    void init();

    // Updates object on frame update
    void update();

protected:
    QHash<QString, Animation> animationSequences;
    QString currentAnimation;

    // accepts values > 0; values <= 0 default to 0
    int depth;

    // depth that OpenGL uses to draw to screen
    float drawDepth;

    // Adds an animation
    void addAnimation(QString name, QString spritePath, QList<int> aniSeq, int aniSpeed, int xNumImg, int yNumImg, int xOffset, int yOffset);

    // Checks whether a key has been pressed or not
    bool keyboardCheckPressed(int key);

    // Checks whether a key has been released or not
    bool keyboardCheckReleased(int key);

private:
    /*  DRAWING */
    OpenGLWidget *oglWidget;

    // Draws sprite to screen
    void drawSelf();

    // Calculates and updates OpenGL draw depth from GameObject depth value
    void updateDrawDepth();

    /*  INPUT   */
    InputHandler *iptHandler;
};

#endif // GAMEOBJECT_H
