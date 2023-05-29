#include "../headers/triangle.h"
#include "../../headers/globalVars.h"

Triangle::Triangle(OpenGLWidget *oglWidg, QWidget *parent) : GameObject(oglWidg, parent)
{
    x = 50;
    y = 50;
    depth = 5;
    width = 16;
    height = 16;
    speed = 5;
    spritePath = ":/images/gameObjects/sprites/testSpr.bmp";

    init();
}

Triangle::~Triangle()
{
}

void Triangle::update()
{
    moveObject();
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
