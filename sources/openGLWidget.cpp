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

    glTranslatef(0.0, 0.0, -7.0);
    glRotatef(0.0, 1.0, 0.0, 0.0);
    glRotatef(0.0, 0.0, 1.0, 0.0);
    glRotatef(0.0, 0.0, 0.0, 1.0);

    glTranslatef(0,0,0);

    trgl.draw_self();

    glFlush();
}

void OpenGLWidget::resizeGL(int w, int h){
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glFrustum(-1-(w-400), +1+(w-400), -1-(h-400), +1+(h-400), 4.0, 10.0);
    glFrustum(-1, +1, -1, +1, 4.0, 10.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenGLWidget::resizeEvent(QResizeEvent *event)
{
    QSize newSize;

    if(width() < height())
    {
        newSize.setWidth(width());
        newSize.setHeight(width());
    }
    else
    {
        newSize.setWidth(height());
        newSize.setHeight(height());
    }

    resize(newSize);

    QOpenGLWidget::resizeEvent(event);
}
