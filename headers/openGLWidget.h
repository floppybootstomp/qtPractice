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
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

signals:

public slots:
    void refreshLoop();

private:
    QTimer *refreshTimer;
};

#endif //OPENGLWIDGET_H
