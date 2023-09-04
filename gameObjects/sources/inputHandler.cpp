#include "../headers/inputHandler.h"
#include "../../headers/globalVars.h"
#include <QDebug>
#include <QGuiApplication>

InputHandler::InputHandler(OpenGLWidget *oglWidg, QWidget *parent) : QWidget(parent)
{
    grabKeyboard();
    grabMouse();
    setMouseTracking(true);
    oglWidget = oglWidg;
}

InputHandler::~InputHandler()
{
}

// Clears input buffers
void InputHandler::clearInputBuffers()
{
    keyPressed.clear();
    keyReleased.clear();
    keyPressBuffer.clear();
    keyReleaseBuffer.clear();
}

// Check keyPressed value against key
bool InputHandler::keyboardCheckPressed(int key)
{
    if(keyPressed.contains(key))
        return true;
    return false;
}

// Check keyReleased value against key
bool InputHandler::keyboardCheckReleased(int key)
{
    if(keyReleased.contains(key))
        return true;
    return false;
}

// Checks whether a mouse button has been pressed or not
bool InputHandler::mouseCheckPressed(int button)
{
    if(mousePressed.contains(button))
        return true;
    return false;
}

// Checks whether a mouse button has been released or not
bool InputHandler::mouseCheckReleased(int button)
{
    if(mouseReleased.contains(button))
        return true;
    return false;
}

// Returns mouse X position
int InputHandler::mouseX()
{
    return mousePosition.first + oglWidget->viewportX;
}

// Returns mouse Y position
int  InputHandler::mouseY()
{
    return mousePosition.second + oglWidget->viewportY;
}

// Shows or Hides Cursor
void InputHandler::showCursor(bool isShown)
{
    isShown ? QGuiApplication::setOverrideCursor(Qt::ArrowCursor) : QGuiApplication::setOverrideCursor(Qt::BlankCursor);
}

void InputHandler::update()
{
    // update key press and release to new info from key buffers
    updateKeyPress();
    updateKeyRelease();

    // update mouse press and release to new info from mouse buffers
    updateMousePress();
    updateMouseRelease();
    updateMousePosition();
}

// Gets key presses and updates keyPressBuffer
void InputHandler::keyPressEvent(QKeyEvent *event)
{
    keyPressBuffer.insert(event->key());
}

// Gets key releases and updates keyReleaseBuffer
void InputHandler::keyReleaseEvent(QKeyEvent *event)
{
    // do not call when key is held down
    if(!event->isAutoRepeat())
        keyReleaseBuffer.insert(event->key());
}

// updates keyPressed to match keyPressBuffer
void InputHandler::updateKeyPress()
{
    if(!(keyPressBuffer.isEmpty()))
    {
        keyPressed += keyPressBuffer;
        keyPressBuffer.clear();
    }
}

// Updates keyReleased to match keyReleaseBuffer
void InputHandler::updateKeyRelease()
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

// Gets mouse presses and updates mousePressBuffer
void InputHandler::mousePressEvent(QMouseEvent *event)
{
    mousePressBuffer.insert(event->button());
}

// Gets mouse releases and updates keyReleaseBuffer
void InputHandler::mouseReleaseEvent(QMouseEvent *event)
{
    mouseReleaseBuffer.insert(event->button());
}

// Gets mouse position and updates mousePositionBuffer
void InputHandler::mouseMoveEvent(QMouseEvent *event){
    int wWidth = parentWidget()->width();
    int wHeight = parentWidget()->height();
    int gwWidth = wHeight*SCREEN_ASPECTRATIO;
    int screenShift = ((wWidth) - (gwWidth))/2;
    int gwScreenShift = (screenShift*SCREEN_WIDTH)/gwWidth;
    int mouseX = (event->x()*SCREEN_WIDTH)/gwWidth - (gwScreenShift);
    int mouseY = (event->y()*SCREEN_HEIGHT)/wHeight;

    mousePositionBuffer = qMakePair(mouseX, mouseY);
}

// Updates mousePressed to match mousePressBuffer
void InputHandler::updateMousePress()
{
    if(!(mousePressBuffer.isEmpty()))
    {
        mousePressed += mousePressBuffer;
        mousePressBuffer.clear();
    }
}

// Updates mouseReleased to match mouseReleaseBuffer
void InputHandler::updateMouseRelease()
{
    // clear keyReleased each frame
    mouseReleased.clear();

    if(!(mouseReleaseBuffer.isEmpty()))
    {
        // remove released keys from keyPressed
        mousePressed -= mouseReleaseBuffer;

        mouseReleased = mouseReleaseBuffer;
        mouseReleaseBuffer.clear();
    }
}

// Updates mousePosition to match mousePositionBuffer
void InputHandler::updateMousePosition()
{
    mousePosition = mousePositionBuffer;
}


