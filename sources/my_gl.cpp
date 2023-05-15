#include "../headers/my_gl.h"

MyGL::MyGL(QWidget *parent) : QOpenGLWidget(parent)
{
    xrot = yrot = zrot = 0.0;
    xpos = ypos = zpos = 0.0;
}

void MyGL::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
}

void MyGL::drawTetrahedron(float base, float height, float xs, float ys, float zs){
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.7f, 0.4f); //tan
        glVertex3f(-base/2+xs, -height/2+ys, -height/2+zs);
        glVertex3f(0+xs, height/2+ys, -height/2+zs);
        glVertex3f(base/2+xs, -height/2+ys, -height/2+zs);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.5f, 0.05f); //green
        glVertex3f(-base/2+xs, -height/2+ys, -height/2+zs);
        glVertex3f(0+xs, height/2+ys, -height/2+zs);
        glVertex3f(0+xs, 0+ys, height/2+zs);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(0.5f, 0.2f, 0.05f); //brown
        glVertex3f(0+xs, height/2+ys, -height/2+zs);
        glVertex3f(base/2+xs, -height/2+ys, -height/2+zs);
        glVertex3f(0+xs, 0+ys, height/2+zs);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 0.3f); //yellow
        glVertex3f(-base/2+xs, -height/2+ys, -height/2+zs);
        glVertex3f(base/2+xs, -height/2+ys, -height/2+zs);
        glVertex3f(0+xs, 0+ys, height/2+zs);
    glEnd();

}

void MyGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    glTranslatef(0.0, 0.0, -7.0);
    glRotatef(xrot, 1.0, 0.0, 0.0);
    glRotatef(yrot, 0.0, 1.0, 0.0);
    glRotatef(zrot, 0.0, 0.0, 1.0);

    glTranslatef(0,0,0);

    //float height = 1.0f;
    //float base = 1.0f;

    //drawTetrahedron(base, height, xpos, ypos, zpos);

    

    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads

    // Top face (y = 1.0f)
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    // Bottom face (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Front face  (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Back face (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Left face (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Right face (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();  // End of drawing color-cube



    glFlush();
}

void MyGL::resizeGL(int w, int h)
{
    //set viewport
    glViewport(0,0,w,h);

    //initialize projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /* multiply the current matrix by a perspective matrix
     * void glFrustum(GLdouble left, GLdouble right,GLdouble bottom,GLdouble top,GLdouble nearVal,GLdouble farVal);
     * left, right: Specify the coordinates for the left and right vertical clipping planes.
     * bottom, top: Specify the coordinates for the bottom and top horizontal clipping planes.
     * nearVal, farVal: Specify the distances to the near and far depth clipping planes. Both distances must be positive.
     */
    glFrustum(-2, +2, -2, +2, 4.0, 10.0);

    //initialize modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void MyGL::setRotation(float x, float y, float z)
{
    xrot = x;
    yrot = y;
    zrot = z;
    update();
}

void MyGL::setPosition(float x, float y, float z){
    xpos = x;
    ypos = y;
    zpos = z;
    update();
}


