#include "../headers/gameObject.h"
#include "../../headers/globalVars.h"

GameObject::GameObject(QWidget *parent) : QWidget(parent)
{
}

GameObject::GameObject(int xPos, int yPos, QWidget *parent) : QWidget(parent)
{
    x = xPos;
    y = yPos;
}

GameObject::GameObject(int xPos, int yPos, int depthAmnt, QWidget *parent) : QWidget(parent)
{
    x = xPos;
    y = yPos;
    depth = depthAmnt;
    updateDrawDepth();
}

GameObject::~GameObject()
{
}

void GameObject::updateDrawDepth()
{
    drawDepth = MAX_DEPTH/depth;
}

void GameObject::keyCheckPressed(int key)
{
}

void GameObject::keyCheckReleased(int key)
{
}

void GameObject::keyPressEvent(QKeyEvent *event)
{
    keyCheckPressed(event->key());
}

void GameObject::keyReleaseEvent(QKeyEvent *event)
{
    keyCheckReleased(event->key());
}
