#include "../headers/openGLWidget.h"
#include "../headers/globalVars.h"

OpenGLWidget::OpenGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    refreshTimer = new QTimer();
    refreshTimer->setSingleShot(false);
    connect(refreshTimer, SIGNAL(timeout()), this, SLOT(refreshLoop()));
    refreshTimer->start(1000/FRAMERATE);
}

OpenGLWidget::~OpenGLWidget()
{
    delete refreshTimer;
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

    trgl.x += 1;
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
    {
        glOrtho(0.0f*aspectRatio, SCREEN_HEIGHT*aspectRatio, SCREEN_HEIGHT, 0.0f, MIN_DEPTH, MAX_DEPTH);
        // center screen
        glTranslatef(((SCREEN_HEIGHT*aspectRatio)-(SCREEN_WIDTH))*0.5f, 0.0f, 0.0f);
    }
    else
    {
        glOrtho(0.0f, SCREEN_HEIGHT, SCREEN_HEIGHT/aspectRatio, 0.0f/aspectRatio, MIN_DEPTH, MAX_DEPTH);
        // center screen
        glTranslatef(0.0f, ((SCREEN_WIDTH/aspectRatio)-(SCREEN_HEIGHT))*0.3, 0.0f);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenGLWidget::refreshLoop()
{
    paintGL();
}
