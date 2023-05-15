#ifndef MyGL_H
#define MyGL_H


#include <QtWidgets>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <GL/glu.h>

class MyGL : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit MyGL(QWidget *parent = 0);

    void setRotation(float x, float y, float z);
    void setPosition(float x, float y, float z);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void drawTetrahedron(float base, float height, float xs, float ys, float zs);

signals:

public slots:

private:
    float xrot,yrot,zrot;
    float xpos, ypos, zpos;

};

#endif // QGLBEGIN_H
