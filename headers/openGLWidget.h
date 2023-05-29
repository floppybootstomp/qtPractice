#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H


#include <QtWidgets>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <GL/glu.h>

class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLWidget(QWidget *parent = 0);
    ~OpenGLWidget();

    // inserts image into draw buffer to be drawn during frame update
    void drawImage(int posX, int posY, int width, int height, float depth, QImage texture);

protected:
    // initializes opengl
    void initializeGL();

    // repaints opengl widget
    void paintGL();

    // resizes opengl widget
    void resizeGL(int w, int h);

private:
    // struct to buffer info of images to draw
    struct DrawImageBufferInfo 
    {
        int x, y, w, h;
        float drawDepth;
        QImage drawTexture;
    };

    // buffer of images to draw when paintGL is called
    QList<DrawImageBufferInfo> drawImageBuffer;

    // Draws image to screen
    void drawImageFromBuffer(DrawImageBufferInfo textureInfo);
};

#endif //OPENGLWIDGET_H
