#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QWidget>
#include <QKeyEvent>
#include <QtOpenGL>
#include <QImage>
#include <QString>

class GameObject : public QWidget
{
    Q_OBJECT
public:
    int x, y, width, height;

    QString spritePath;

    GameObject(QWidget *parent = 0);

    GameObject(int xPos, int yPos, QWidget *parent = 0);

    GameObject(int xPos, int yPos, float depthAmnt, QWidget *parent = 0);

    ~GameObject();

    // Initializes a gameObject
    void init();

    // Updates object on frame update
    void update();

    // Clears input buffers
    void clearInputBuffers();

protected:
    // accepts values > 0; values <= 0 default to 0
    int depth;

    // depth that OpenGL uses to draw to screen
    float drawDepth;

    // Checks whether a key has been pressed or not
    bool keyboardCheckPressed(int key);

    // Checks whether a key has been released or not
    bool keyboardCheckReleased(int key);

private:
    /*  DRAWING */
    QImage spriteImage, spriteTexture;
    GLuint spriteGLTexture;

    // Draws sprite to screen
    void drawSelf();

    // Initializes texture for opengl to draw
    void initializeTexture();

    // loads sprite image
    void loadSpriteImage();

    // Calculates and updates OpenGL draw depth from GameObject depth value
    void updateDrawDepth();

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

#endif // GAMEOBJECT_H
