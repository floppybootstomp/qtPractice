#include "../headers/triangle.h"

Triangle::Triangle()
{
}

void Triangle::draw_self()
{
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(20, 380, 100);
        glVertex3f(380, 380, 50);
        glVertex3f(190, 20, 320);
    glEnd();
}
