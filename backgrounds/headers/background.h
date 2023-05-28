#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QWidget>
#include <QtOpenGL>

class Background : public QWidget
{
    Q_OBJECT
public:
    Background(QWidget *parent = 0);

    ~Background();

    // Initializes a Background
    void init();

    void update();

protected:
    // accepts values > 1; values <= 1 default to MIN_DRAWDEPTH
    int depth;

    // depth that OpenGL uses to draw to screen
    float drawDepth;

    // Calculates and updates OpenGL draw depth from Background depth value
    void updateDrawDepth();

private:
    QString bkgImagePath;
    QImage backgroundImage, backgroundTexture;
    GLuint backgroundGLTexture;

    // draws background to screen
    void drawSelf();

    // Initializes texture for opengl to draw
    void initializeTexture();

    // loads sprite image
    void loadBackgroundImage();
};

#endif // BACKGROUND_H
