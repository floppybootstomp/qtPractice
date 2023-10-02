#include "../headers/gameObject.h"
#include "../../headers/globalVars.h"
#include <QDebug>

GameObject::GameObject(OpenGLWidget *oglWidg, InputHandler *iptHandl, QWidget *parent) : QWidget(parent)
{
    x = 0;
    y = 0;
    width = 16;
    height = 16;
    depth = 0;

    oglWidget = oglWidg;
    iptHandler = iptHandl;
}

GameObject::GameObject(int xPos, int yPos, float depthAmnt, OpenGLWidget *oglWidg, InputHandler *iptHandl, QWidget *parent) : QWidget(parent)
{
    x = xPos;
    y = yPos;
    width = 16;
    height = 16;
    depth = depthAmnt;

    oglWidget = oglWidg;
    iptHandler = iptHandl;
}

// Destructor
GameObject::~GameObject()
{
}

// Initializes a gameObject
void GameObject::init()
{
}

// Updates object on frame update
void GameObject::updateGameObject()
{
    // call derived object's update function
    update();

    // update draw depth to current depth value
    updateDrawDepth();

    // draw self
    if(animationSequences.size() > 0)
    {
        animationSequences[currentAnimation].cycleAnimation();
        drawSelf();
    }
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
    return iptHandler->keyboardCheckPressed(key);
}

// Check keyReleased value against key
bool GameObject::keyboardCheckReleased(int key)
{
    return iptHandler->keyboardCheckReleased(key);
}

// Checks whether a mouse button has been pressed or not
bool GameObject::mouseCheckPressed(int button)
{
    return iptHandler->mouseCheckPressed(button);
}

// Checks whether a mouse button has been released or not
bool GameObject::mouseCheckReleased(int button)
{
    return iptHandler->mouseCheckReleased(button);
}

// Returns mouse X position
int GameObject::mouseX()
{
    return iptHandler->mouseX();
}

// Returns mouse Y position
int GameObject::mouseY()
{
    return iptHandler->mouseY();
}

// Shows or Hides Cursor
void GameObject::showCursor(bool isShown)
{
    iptHandler->showCursor(isShown);
}

// Draws sprite to screen
void GameObject::drawSelf()
{
    if(oglWidget->viewportX < x + width &&
        oglWidget->viewportX+SCREEN_WIDTH > x - width &&
        oglWidget->viewportY < y + width &&
        oglWidget->viewportY+SCREEN_HEIGHT > y-height)
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
