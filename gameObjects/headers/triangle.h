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

    void draw_self();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    void moveObject(int hdir, int vdir, int spd);
    int horizontal, vertical, speed;
};

#endif // TRIANGLE_H
