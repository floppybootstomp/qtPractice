#include "../headers/gameObject.h"
#include "../../headers/globalVars.h"
#include <QDebug>

GameObject::GameObject(QWidget *parent) : QWidget(parent)
{
    x = 0;
    y = 0;
    depth = 0;
    updateDrawDepth();
    grabKeyboard();
}

GameObject::GameObject(int xPos, int yPos, QWidget *parent) : QWidget(parent)
{
    x = xPos;
    y = yPos;
    depth = 0;
    updateDrawDepth();
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

// Destructor
GameObject::~GameObject()
{
}

// Updates object on frame update
void GameObject::update()
{
    // update key press and release to new info from key buffers
    updateKeyPress();
    updateKeyRelease();
}

// Calculates and updates OpenGL draw depth from GameObject depth value
void GameObject::updateDrawDepth()
{
    if(depth == 0)
    {
        drawDepth = 0;
        return;
    }

    drawDepth = MAX_DEPTH/depth;
}

// Gets key presses and updates keyPressBuffer
void GameObject::keyPressEvent(QKeyEvent *event)
{
    keyPressBuffer.insert(event->key());
}

// Gets key releases and updates keyReleaseBuffer
void GameObject::keyReleaseEvent(QKeyEvent *event)
{
    // do not call when key is held down
    if(!event->isAutoRepeat())
        keyReleaseBuffer.insert(event->key());
}

// Check keyPressed value against key
bool GameObject::keyboardCheckPressed(int key)
{
    if(keyPressed.contains(key))
        return true;
    return false;
}

// Check keyReleased value against key
bool GameObject::keyboardCheckReleased(int key)
{
    if(keyReleased.contains(key))
        return true;
    return false;
}

// updates keyPressed to match keyPressBuffer
void GameObject::updateKeyPress()
{
    if(!(keyPressBuffer.isEmpty()))
    {
        keyPressed += keyPressBuffer;
        keyPressBuffer.clear();
    }
}

// Updates keyReleased to match keyReleaseBuffer
void GameObject::updateKeyRelease()
{
    // clear keyReleased each frame
    keyReleased.clear();

    if(!(keyReleaseBuffer.isEmpty()))
    {
        // remove released keys from keyPressed
        keyPressed -= keyReleaseBuffer;

        keyReleased = keyReleaseBuffer;
        keyReleaseBuffer.clear();
    }
}
