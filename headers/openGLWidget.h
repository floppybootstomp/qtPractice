#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H


#include <QtWidgets>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <GL/glu.h>

#include "../backgrounds/headers/background.h"
#include "../gameObjects/headers/triangle.h"

class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLWidget(QWidget *parent = 0);
    ~OpenGLWidget();

    Background bkg;
    Triangle trgl;

    // actions to perform when window is unfocused
    void winUnfocusedAction();

protected:
    // initializes opengl
    void initializeGL();

    // repaints opengl widget
    void paintGL();

    // resizes opengl widget
    void resizeGL(int w, int h);

public slots:
    // actions to be updated each frame
    void refreshLoop();

private:
    // calls refreshLoop each frame
    QTimer *refreshTimer;
};

#endif //OPENGLWIDGET_H
