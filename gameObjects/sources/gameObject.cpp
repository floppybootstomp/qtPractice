#include "../headers/gameObject.h"
#include "../../headers/globalVars.h"
#include <QDebug>

GameObject::GameObject(OpenGLWidget *oglWidg, QWidget *parent) : QWidget(parent)
{
    x = 0;
    y = 0;
    width = 16;
    height = 16;
    depth = 0;

    oglWidget = oglWidg;
}

GameObject::GameObject(int xPos, int yPos, float depthAmnt, OpenGLWidget *oglWidg, QWidget *parent) : QWidget(parent)
{
    x = xPos;
    y = yPos;
    width = 16;
    height = 16;
    depth = depthAmnt;

    oglWidget = oglWidg;
}

// Destructor
GameObject::~GameObject()
{
}

// Initializes a gameObject
void GameObject::init()
{
    grabKeyboard();
}

// Updates object on frame update
void GameObject::update()
{
    // update draw depth to current depth value
    updateDrawDepth();

    // update key press and release to new info from key buffers
    updateKeyPress();
    updateKeyRelease();

    // draw self
    if(animationSequences.size() > 0)
    {
        animationSequences[currentAnimation].cycleAnimation();
        drawSelf();
    }
}

// Clears input buffers
void GameObject::clearInputBuffers()
{
    keyPressed.clear();
    keyReleased.clear();
    keyPressBuffer.clear();
    keyReleaseBuffer.clear();
}

// Adds an animation
void GameObject::addAnimation(QString name, QString spritePath, QList<int> aniSeq, int aniSpeed, int xNumImg, int yNumImg, int xOffset, int yOffset)
{
    Animation ani(name, spritePath, aniSeq, aniSpeed, xNumImg, yNumImg, xOffset, yOffset);
    animationSequences.insert(ani.name, ani);
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

// Draws sprite to screen
void GameObject::drawSelf()
{
    oglWidget->drawImage(
        x,
        y,
        width,
        height,
        animationSequences[currentAnimation].sprDims.left,
        animationSequences[currentAnimation].sprDims.right,
        animationSequences[currentAnimation].sprDims.top,
        animationSequences[currentAnimation].sprDims.bottom,
        drawDepth,
        animationSequences[currentAnimation].spriteTexture
    );
}

// Calculates and updates OpenGL draw depth from GameObject depth value
void GameObject::updateDrawDepth()
{
    if(depth <= 0)
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
