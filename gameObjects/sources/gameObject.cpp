#include "../headers/gameObject.h"
#include "../../headers/globalVars.h"
#include <QDebug>

GameObject::GameObject(QWidget *parent) : QWidget(parent)
{
    qInfo() << "go construt";
    grabKeyboard();
}

GameObject::GameObject(int xPos, int yPos, QWidget *parent) : QWidget(parent)
{
    x = xPos;
    y = yPos;
    grabKeyboard();
}

GameObject::GameObject(int xPos, int yPos, float depthAmnt, QWidget *parent) : QWidget(parent)
{
    x = xPos;
    y = yPos;
    depth = depthAmnt;
    updateDrawDepth();
    grabKeyboard();
}

GameObject::~GameObject()
{
}

void GameObject::updateDrawDepth()
{
    drawDepth = MAX_DEPTH/depth;
}

void GameObject::keyPressEvent(QKeyEvent *event)
{
    qInfo() << "pressu";
}

void GameObject::keyReleaseEvent(QKeyEvent *event)
{
    qInfo() << "done";
}
