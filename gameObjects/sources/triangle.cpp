#include "../headers/triangle.h"
#include "../../headers/globalVars.h"

Triangle::Triangle(QWidget *parent) : GameObject(50, 50, 5, parent)
{
    width = 100;
    height = 100;
    speed = 5;
}

Triangle::~Triangle()
{
}

void Triangle::draw_self()
{
    glBegin(GL_QUADS);                // Begin drawing the colored square
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(x+width, y+height, drawDepth);
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(x, y+height, drawDepth);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(x, y, drawDepth);
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
    glVertex3f(x+width, y, drawDepth);
    glEnd();  // End of drawing color-cube
}

void Triangle::update()
{
    moveObject();
    draw_self();
    GameObject::update();
}

void Triangle::moveObject()
{
    //qInfo() << "(" << x << ", " << y << ")";
    if(keyboardCheckPressed(Qt::Key_Up))
        y -= speed;
    if(keyboardCheckPressed(Qt::Key_Down))
        y += speed;
    if(keyboardCheckPressed(Qt::Key_Left))
        x -= speed;
    if(keyboardCheckPressed(Qt::Key_Right))
        x += speed;
}
