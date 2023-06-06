#include "../headers/triangle.h"
#include "../../headers/globalVars.h"

Triangle::Triangle(OpenGLWidget *oglWidg, InputHandler *iptHandl, QWidget *parent) : GameObject(oglWidg, iptHandl, parent)
{
    x = 50;
    y = 50;
    depth = 5;
    width = 16;
    height = 16;

    // animation setup
    QList<int> redWoimSequence = {0, 1, 2, 3, 2, 1};
    addAnimation(
        "redWoim",
        ":/images/gameObjects/sprites/inchworm.png",
        redWoimSequence,
        0,
        4,
        1,
        2,
        0
    );

    addAnimation(
        "frontWoim",
        ":/images/gameObjects/sprites/frontofinchworm.png",
        redWoimSequence,
        0,
        4,
        1,
        2,
        0
    );

    currentAnimation = "frontWoim";
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
        ySpeed = -2;
        animationSequences[currentAnimation].speed = 5;
        currentAnimation = "frontWoim";
    }
    else if(keyboardCheckPressed(Qt::Key_Down))
    {
        ySpeed = 2;
        animationSequences[currentAnimation].speed = 5;
        currentAnimation = "frontWoim";
    }
    else
    {
        ySpeed = 0;
        if(xSpeed == 0)
            animationSequences[currentAnimation].speed = 0;
    }

    if(keyboardCheckPressed(Qt::Key_Left))
    {
        xSpeed = -2;
        animationSequences[currentAnimation].speed = 5;
        currentAnimation = "redWoim";
    }
    else if(keyboardCheckPressed(Qt::Key_Right))
    {
        xSpeed = 2;
        animationSequences[currentAnimation].speed = 5;
        currentAnimation = "redWoim";
    }
    else
    {
        xSpeed = 0;
        if(ySpeed == 0)
            animationSequences[currentAnimation].speed = 0;
    }
}

void Triangle::moveObject()
{
    y += ySpeed;
    x += xSpeed;
}
