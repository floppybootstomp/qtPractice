#include "../headers/triangle.h"
#include "../../headers/globalVars.h"

Triangle::Triangle(QWidget *parent) : GameObject(50, 50, 5, parent)
{
    width = 100;
    height = 100;
    speed = 5;
    spritePath = ":/images/gameObjects/sprites/testSpr.bmp";
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
