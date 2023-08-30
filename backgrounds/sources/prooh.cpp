#include "../headers/prooh.h"

Prooh::Prooh(OpenGLWidget *oglWidg, QWidget * parent) : Background(oglWidg, parent)
{
    width = 768;
    height = 720;
    depth = 1;
    drawDepth = depth;
    bkgImagePath = ":/images/backgrounds/bkgImages/biggabakooba.png";

    init();
}

Prooh::~Prooh()
{
}
