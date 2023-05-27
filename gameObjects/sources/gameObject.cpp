#include "../headers/gameObject.h"
#include "../../headers/globalVars.h"
#include <QDebug>

GameObject::GameObject(QWidget *parent) : QWidget(parent)
{
    x = 0;
    y = 0;
    depth = 0;

    grabKeyboard();
}

GameObject::GameObject(int xPos, int yPos, QWidget *parent) : QWidget(parent)
{
    x = xPos;
    y = yPos;
    depth = 0;

    grabKeyboard();
}

GameObject::GameObject(int xPos, int yPos, float depthAmnt, QWidget *parent) : QWidget(parent)
{
    x = xPos;
    y = yPos;
    depth = depthAmnt;

    grabKeyboard();
}

// Destructor
GameObject::~GameObject()
{
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
    drawSelf();
}

// Clears input buffers
void GameObject::clearInputBuffers()
{
    keyPressed.clear();
    keyReleased.clear();
    keyPressBuffer.clear();
    keyReleaseBuffer.clear();
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
    glBegin(GL_QUADS);                // Begin drawing the colored square
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    //glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(x+width, y+height, drawDepth);
    //glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(x, y+height, drawDepth);
    //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(x, y, drawDepth);
    //glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
    glVertex3f(x+width, y, drawDepth);
    glEnd();  // End of drawing color-cube

    // load sprite image if not loaded
    if(spriteImage.isNull())
    {
        try
        {
            loadSpriteImage();
        }
        catch(std::exception&)
        {
            qFatal("Could not load sprite image for path: ");
        }
    }
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

// loads sprite image
void GameObject::loadSpriteImage()
{
    bool sprLoadIsSuccessful = spriteImage.load(spritePath);
    if(!sprLoadIsSuccessful)
        throw std::exception();
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


