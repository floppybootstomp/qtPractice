#include "../headers/openGLWidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
}

void OpenGLWidget::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
}


void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    trgl.draw_self();

    glFlush();
}

void OpenGLWidget::resizeGL(int w, int h){
    // prevent divide by zero
    if(h == 0)
        h = 1;
    // calculate aspect ratio
    float aspectRatio = ((float)w) / ((float)h);
    // set viewport to cover window
    glViewport(0,0,w,h);

    /* SET ASPECT RATIO */
    // switch to projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(w >= h)
        glOrtho(-5.0f*aspectRatio, 5.0f*aspectRatio, -5.0f, 5.0f, -0.5f, 0.1f);
    else
        glOrtho(-5.0f, 5.0f, -5.0f/aspectRatio, 5.0f/aspectRatio, -0.5f, 0.1f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
