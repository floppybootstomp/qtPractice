#include "../headers/triangle.h"
#include "../../headers/globalVars.h"

Triangle::Triangle(OpenGLWidget *oglWidg, QWidget *parent) : GameObject(oglWidg, parent)
{
    x = 50;
    y = 50;
    depth = 5;
    width = 16;
    height = 16;

    // sprite info
    spritePath = ":/images/gameObjects/sprites/inchworm.png";
    xNumImages = 4;
    yNumImages = 1;
    xImageOffset = 2;
    yImageOffset = 0;
    imageSpeed = 0;
    spriteAnimationStyle = BILINEAR;

    init();
}

Triangle::~Triangle()
{
}

void Triangle::update()
{
    checkKeyboardInput();
    moveObject();
    GameObject::update();
}

void Triangle::checkKeyboardInput()
{
    if(keyboardCheckPressed(Qt::Key_Up))
    {
        ySpeed = -5;
        imageSpeed = 5;
    }
    else if(keyboardCheckPressed(Qt::Key_Down))
    {
        ySpeed = 5;
        imageSpeed = 5;
    }
    else
    {
        ySpeed = 0;
        if(xSpeed == 0)
            imageSpeed = 0;
    }

    if(keyboardCheckPressed(Qt::Key_Left))
    {
        xSpeed = -5;
        imageSpeed = 5;
    }
    else if(keyboardCheckPressed(Qt::Key_Right))
    {
        xSpeed = 5;
        imageSpeed = 5;
    }
    else
    {
        xSpeed = 0;
        if(ySpeed == 0)
        {
            imageSpeed = 0;
            //xImageOffset = 0;
        }
    }

}

void Triangle::moveObject()
{
    y += ySpeed;
    x += xSpeed;
}
