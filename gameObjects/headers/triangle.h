#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QtOpenGL>
#include "gameObject.h"
#include "../../headers/openGLWidget.h"

class Triangle : public GameObject
{
    Q_OBJECT
public:
    Triangle(OpenGLWidget *oglWidg, InputHandler *iptHandl, QWidget *parent = 0);

    ~Triangle();

    void update();

protected:

private:
    int xSpeed, ySpeed;

    void draw_self();
    void checkKeyboardInput();
    void moveObject();
};

#endif // TRIANGLE_H
