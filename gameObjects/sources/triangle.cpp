#include "../headers/triangle.h"
#include "../../headers/globalVars.h"

Triangle::Triangle(QWidget *parent) : GameObject(parent)
{
}

Triangle::~Triangle()
{
}

void Triangle::draw_self()
{
    glBegin(GL_QUADS);                // Draw Background
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(0.25f, 0.25f, 0.25f); // Dark Gray
    glVertex3f(SCREEN_WIDTH, SCREEN_HEIGHT, -0.01);
    glColor3f(0.25f, 0.25f, 0.25f); // Dark Gray
    glVertex3f(0, SCREEN_HEIGHT, -0.01);
    glColor3f(0.75f, 0.75f, 0.75f); // Light Gray
    glVertex3f(0, 0, -0.01);
    glColor3f(0.75f, 0.75f, 0.75f); // Light Gray
    glVertex3f(SCREEN_WIDTH, 0, -0.01);
    glEnd();

    glBegin(GL_QUADS);                // Begin drawing the colored square
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(100, 100, 0);
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0, 100, 0);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(0, 0, 0);
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
    glVertex3f(100, 0, 0);
    glEnd();  // End of drawing color-cube
}

void Triangle::keyCheckPressed(int key)
{
    qInfo() << key;
}
