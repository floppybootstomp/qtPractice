#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>

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

    // Checks whether a mouse button has been pressed or not
    bool mouseCheckPressed(int button);

    // Checks whether a mouse button has been released or not
    bool mouseCheckReleased(int button);

    // Returns mouse X position
    int mouseX();

    // Returns mouse Y position
    int mouseY();

    // Shows or Hides Cursor
    void showCursor(bool isShown);

    void update();

private:
    /*  KEYBOARD INPUT   */
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

    /*  MOUSE INPUT     */
    // buffers to store mouse presses
    QSet<int> mousePressBuffer;
    QSet<int> mouseReleaseBuffer;
    QPair<int, int> mousePositionBuffer;

    // mouse press values updated each frame
    QSet<int> mousePressed;
    QSet<int> mouseReleased;
    QPair<int, int> mousePosition;

    // Gets mouse presses and updates mousePressBuffer
    void mousePressEvent(QMouseEvent *event) override;

    // Gets mouse releases and updates keyReleaseBuffer
    void mouseReleaseEvent(QMouseEvent *event) override;

    // Gets mouse position and updates mousePositionBuffer
    void mouseMoveEvent(QMouseEvent *event) override;

    // Updates mousePressed to match mousePressBuffer
    void updateMousePress();

    // Updates mouseReleased to match mouseReleaseBuffer
    void updateMouseRelease();

    // Updates mousePosition to match mousePositionBuffer
    void updateMousePosition();
};

#endif // INPUTHANDLER_H
