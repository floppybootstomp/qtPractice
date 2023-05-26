#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H


#include <QtWidgets>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <GL/glu.h>

#include "../gameObjects/headers/triangle.h"

class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLWidget(QWidget *parent = 0);
    ~OpenGLWidget();
    Triangle trgl;

protected:
    // initializes opengl
    void initializeGL();

    // repaints opengl widget
    void paintGL();

    // resizes opengl widget
    void resizeGL(int w, int h);

signals:

public slots:
    // actions to be updated each frame
    void refreshLoop();

private:
    // calls refreshLoop each frame
    QTimer *refreshTimer;
};

#endif //OPENGLWIDGET_H
