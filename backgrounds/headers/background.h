#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QWidget>
#include <QtOpenGL>
#include "../../headers/openGLWidget.h"

class Background : public QWidget
{
    Q_OBJECT
public:
    Background(OpenGLWidget *oglWidg, QWidget *parent = 0);

    ~Background();

    // Initializes a Background
    void init();

    void move(int xDist, int yDist);

    void update();

protected:
    int xOffset, yOffset, width, height;
    // accepts values > 1; values <= 1 default to MIN_DRAWDEPTH
    int depth;

    QString bkgImagePath;

    // depth that OpenGL uses to draw to screen
    float drawDepth;

    // Calculates and updates OpenGL draw depth from Background depth value
    void updateDrawDepth();

private:
    QImage backgroundImage, backgroundTexture;
    OpenGLWidget *oglWidget;

    // draws background to screen
    void drawSelf();

    // Initializes texture for opengl to draw
    void initializeTexture();

    // loads sprite image
    void loadBackgroundImage();
};

#endif // BACKGROUND_H
