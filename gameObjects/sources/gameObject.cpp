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
    // load sprite image if not loaded
    if(spriteImage.isNull())
    {
        try
        {
            loadSpriteImage();
        }
        catch(std::exception&)
        {
            qDebug() << "Could not load sprite image for path: " << spritePath;
            return;
        }
    }

    // create one openGL texture
    QImage spriteTexture = QGLWidget::convertToGLFormat(spriteImage);

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, spriteTexture.width(), spriteTexture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, spriteTexture.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // draw surface to render texture on
    glBegin(GL_QUADS);                // Begin drawing the colored square
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    //glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x+width, y+height, drawDepth);
    //glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x, y+height, drawDepth);
    //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x, y, drawDepth);
    //glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x+width, y, drawDepth);
    glEnd();  // End of drawing color-cube
}

// loads sprite image
void GameObject::loadSpriteImage()
{
    bool sprLoadIsSuccessful = spriteImage.load(spritePath);
    if(!sprLoadIsSuccessful)
        throw std::exception();
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
