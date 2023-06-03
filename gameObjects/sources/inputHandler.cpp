#include "../headers/inputHandler.h"

InputHandler::InputHandler(QWidget *parent) : QWidget(parent)
{
    grabKeyboard();
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

void InputHandler::update()
{
    // update key press and release to new info from key buffers
    updateKeyPress();
    updateKeyRelease();
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
