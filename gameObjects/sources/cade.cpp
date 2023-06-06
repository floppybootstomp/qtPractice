#include "../headers/cade.h"
#include <QGuiApplication>

Cade::Cade(OpenGLWidget *oglWidg, InputHandler *iptHandl, QWidget *parent) : GameObject(oglWidg, iptHandl, parent)
{
    x = 150;
    y = 150;
    depth =4;
    width = 16;
    height = 16;

    // animation setup
    QList<int> cadeSitSeq = {0, 1};
    addAnimation(
        "cadeSit",
        ":/images/gameObjects/sprites/cadeson.png",
        cadeSitSeq,
        9,
        4,
        2,
        0,
        0
    );

    QList<int> cadeCarrySeq = {2, 3};
    addAnimation(
        "cadeCarry",
        ":/images/gameObjects/sprites/cadeson.png",
        cadeCarrySeq,
        3,
        4,
        1,
        2,
        0
    );

    currentAnimation = "cadeSit";
    init();
}

Cade::~Cade()
{
}

void Cade::update()
{
    checkInput();
    carryTheCat();
    GameObject::update();
}

void Cade::checkInput()
{
    if(mouseX() >= x && mouseY() >= y && mouseX() <= x+width && mouseY() <= y+height)
    {
        if(mouseCheckPressed(Qt::LeftButton))
        {
            QGuiApplication::setOverrideCursor(Qt::ClosedHandCursor);
            carrying = true;
        }
        else if(mouseCheckReleased(Qt::LeftButton))
        {
            carrying = false;
        }
        else if(carrying == false)
        {
            QGuiApplication::setOverrideCursor(Qt::OpenHandCursor);
        }
    }
    else if(!keyboardCheckPressed(Qt::LeftButton))
    {
        showCursor(true);
        carrying = false;
    }
}

void Cade::carryTheCat()
{
    if(carrying)
    {
        height = 32;
        currentAnimation = "cadeCarry";
        x = mouseX()-width/2;
        y = mouseY()-3;
    }
    else
    {
        height = 16;
        currentAnimation = "cadeSit";
    }
}
