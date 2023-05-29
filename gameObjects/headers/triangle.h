#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QtOpenGL>
#include "gameObject.h"
#include "../../headers/openGLWidget.h"

class Triangle : public GameObject
{
    Q_OBJECT
public:
    Triangle(OpenGLWidget *oglWidg, QWidget *parent = 0);

    ~Triangle();

    void update();

protected:

private:
    int speed;

    void draw_self();
    void moveObject();
};

#endif // TRIANGLE_H
