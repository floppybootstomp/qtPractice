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

    spritePath = "";
    xNumImages = 1;
    yNumImages = 1;
    xImageOffset = 0;
    yImageOffset = 0;
    imageSpeed = 0;
    spriteAnimationStyle = LINEAR;

    oglWidget = oglWidg;
}

GameObject::GameObject(int xPos, int yPos, float depthAmnt, OpenGLWidget *oglWidg, QWidget *parent) : QWidget(parent)
{
    x = xPos;
    y = yPos;
    width = 16;
    height = 16;
    depth = depthAmnt;

    spritePath = "";
    xNumImages = 1;
    yNumImages = 1;
    xImageOffset = 0;
    yImageOffset = 0;
    imageSpeed = 0;
    spriteAnimationStyle = LINEAR;

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
    initializeTexture();
    imageUpdateCounter = 0;
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
    cycleImageAnimation();
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

// Cycles image animation
void GameObject::cycleImageAnimation()
{
    if(imageSpeed > 0)
    {
        imageUpdateCounter ++;
     
        if(imageUpdateCounter == imageSpeed)
        {
            imageUpdateCounter = 0;

            if(spriteAnimationStyle == LINEAR)
            {
                if(xImageOffset < xNumImages)
                    xImageOffset ++;
                else
                    xImageOffset = 1;
            }
            else if(spriteAnimationStyle == BILINEAR)
            {
                if(xImageOffset == xNumImages-1 || xImageOffset == 0)
                    bilinearAnimationForward = !bilinearAnimationForward;
                if(bilinearAnimationForward == true)
                    xImageOffset ++;
                else
                    xImageOffset --;
            }
        }
    }
}

// Draws sprite to screen
void GameObject::drawSelf()
{
    oglWidget->drawImage(x, y, width, height, xNumImages, yNumImages, xImageOffset, yImageOffset, drawDepth, spriteTexture);
}

// Initializes texture for opengl to draw
void GameObject::initializeTexture()
{
    // load sprite image if not loaded
    loadSpriteImage();

    // create one openGL texture
    spriteTexture = QGLWidget::convertToGLFormat(spriteImage);
}

// loads sprite image
void GameObject::loadSpriteImage()
{
    bool sprLoadIsSuccessful = spriteImage.load(spritePath);

    // replace with pink square if bad file name
    if(!sprLoadIsSuccessful)
    {
        qDebug() << "Could not load sprite image for path: " << spritePath;
        spriteImage = *(new QImage(QSize(width, height), QImage::Format_RGB32));
        spriteImage.fill(QColor::fromRgb(255, 0, 178));
    }

    spriteImage = spriteImage.mirrored(false, true);
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
