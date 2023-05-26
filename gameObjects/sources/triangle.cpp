#include "../headers/triangle.h"
#include "../../headers/globalVars.h"

Triangle::Triangle(QWidget *parent) : GameObject(50, 50, 0.25, parent)
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
