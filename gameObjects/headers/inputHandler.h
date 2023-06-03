#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <QWidget>
#include <QKeyEvent>

class InputHandler : public QWidget
{
    Q_OBJECT
public:
    InputHandler(QWidget *parent = 0);
    ~InputHandler();

    // Clears input buffers
    void clearInputBuffers();

    // Checks whether a key has been pressed or not
    bool keyboardCheckPressed(int key);

    // Checks whether a key has been released or not
    bool keyboardCheckReleased(int key);

    void update();

private:
    /*  INPUT   */
    // buffers to store key presses
    QSet<int> keyPressBuffer;
    QSet<int> keyReleaseBuffer;

    // key press values updated each frame
    QSet<int> keyPressed;
    QSet<int> keyReleased;

    // Gets key presses and updates keyPressBuffer
    void keyPressEvent(QKeyEvent *event) override;

    // Gets key releases and updates keyReleaseBuffer
    void keyReleaseEvent(QKeyEvent *event) override;

    // updates keyPressed to match keyPressBuffer
    void updateKeyPress();

    // Updates keyReleased to match keyReleaseBuffer
    void updateKeyRelease();
};

#endif // INPUTHANDLER_H
