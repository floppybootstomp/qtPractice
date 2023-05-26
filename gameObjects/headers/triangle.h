#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QtOpenGL>
#include "gameObject.h"

class Triangle : public GameObject
{
    Q_OBJECT
public:
    Triangle(QWidget *parent = 0);

    ~Triangle();

    void update();

protected:

private:
    void draw_self();
    void moveObject();
    int speed;
};

#endif // TRIANGLE_H
