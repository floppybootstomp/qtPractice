#include "../headers/triangle.h"
#include "../../headers/globalVars.h"

Triangle::Triangle(QWidget *parent) : GameObject(50, 50, 0.25, parent)
{
    width = 100;
    height = 100;
}

Triangle::~Triangle()
{
}

void Triangle::draw_self()
{
    /*
    glBegin(GL_QUADS);                // Draw Background
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(0.25f, 0.25f, 0.25f); // Dark Gray
    glVertex3f(SCREEN_WIDTH, SCREEN_HEIGHT, -0.01);
    glColor3f(0.25f, 0.25f, 0.25f); // Dark Gray
    glVertex3f(0, SCREEN_HEIGHT, -0.01);
    glColor3f(0.75f, 0.75f, 0.75f); // Light Gray
    glVertex3f(0, 0, -0.01);
    glColor3f(0.75f, 0.75f, 0.75f); // Light Gray
    glVertex3f(SCREEN_WIDTH, 0, -0.01);
    glEnd();
    */

    glBegin(GL_QUADS);                // Begin drawing the colored square
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(x+width, y+height, 0);
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(x, y+height, 0);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(x, y, 0);
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
    glVertex3f(x+width, y, 0);
    glEnd();  // End of drawing color-cube

    qInfo() << "(" << x << ", " << y << ")";
}

void Triangle::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        vertical = -1;
        speed = 1;
        moveObject(horizontal, vertical, speed);
    }

    if(event->key() == Qt::Key_Down)
    {
        vertical = 1;
        speed = 1;
        moveObject(horizontal, vertical, speed);
    }

    if(event->key() == Qt::Key_Left)
    {
        horizontal = -1;
        speed = 1;
        moveObject(horizontal, vertical, speed);
    }

    if(event->key() == Qt::Key_Right)
    {
        horizontal = 1;
        speed = 1;
        moveObject(horizontal, vertical, speed);
    }
}

void Triangle::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        vertical = 0;
        speed = 0;
    }

    if(event->key() == Qt::Key_Down)
    {
        vertical = 0;
        speed = 0;
    }

    if(event->key() == Qt::Key_Left)
    {
        horizontal = 0;
        speed = 0;
    }

    if(event->key() == Qt::Key_Right)
    {
        horizontal = 0;
        speed = 0;
    }
}

void Triangle::moveObject(int hdir, int vdir, int spd)
{
    x += hdir * spd;
    y += vdir * spd;
}
