#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QWidget>
#include <QKeyEvent>


class GameObject : public QWidget
{
    Q_OBJECT
public:
    GameObject(QWidget *parent = 0);

    GameObject(int xPos, int yPos, QWidget *parent = 0);

    GameObject(int xPos, int yPos, float depthAmnt, QWidget *parent = 0);

    ~GameObject();

    int x, y, width, height;

    // Updates object on frame update
    void update();

protected:
    float depth;

    // Calculates and updates OpenGL draw depth from GameObject depth value
    void updateDrawDepth();

    // Gets key presses and updates keyPressBuffer
    void keyPressEvent(QKeyEvent *event) override;

    // Gets key releases and updates keyReleaseBuffer
    void keyReleaseEvent(QKeyEvent *event) override;

    // Checks whether a key has been pressed or not
    bool keyboardCheckPressed(int key);

    // Checks whether a key has been released or not
    bool keyboardCheckReleased(int key);

private:
    // depth that OpenGL uses to draw to screen
    int drawDepth;

    // buffers to store key presses
    QSet<int> keyPressBuffer;
    QSet<int> keyReleaseBuffer;

    // key press values updated each frame
    QSet<int> keyPressed;
    QSet<int> keyReleased;

    // updates keyPressed to match keyPressBuffer
    void updateKeyPress();

    // Updates keyReleased to match keyReleaseBuffer
    void updateKeyRelease();
};

#endif // GAMEOBJECT_H