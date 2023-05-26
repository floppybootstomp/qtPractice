#include "../headers/background.h"
#include "../../headers/globalVars.h"

Background::Background(QWidget *parent) : QWidget(parent)
{
    depth = 1;
    drawDepth = depth;
}

Background::~Background()
{
}

void Background::update()
{
    updateDrawDepth();
    drawSelf();
}

void Background::updateDrawDepth()
{
    if(depth <= 1)
    {
        drawDepth = MIN_DRAWDEPTH;
        return;
    }

    drawDepth = -1*MAX_DEPTH/depth;
}

void Background::drawSelf()
{
    glBegin(GL_QUADS);                // Draw Background
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(0.25f, 0.25f, 0.25f); // Dark Gray
    glVertex3f(SCREEN_WIDTH, SCREEN_HEIGHT, drawDepth);
    glColor3f(0.25f, 0.25f, 0.25f); // Dark Gray
    glVertex3f(0, SCREEN_HEIGHT, drawDepth);
    glColor3f(0.75f, 0.75f, 0.75f); // Light Gray
    glVertex3f(0, 0, drawDepth);
    glColor3f(0.75f, 0.75f, 0.75f); // Light Gray
    glVertex3f(SCREEN_WIDTH, 0, drawDepth);
    glEnd();
}
