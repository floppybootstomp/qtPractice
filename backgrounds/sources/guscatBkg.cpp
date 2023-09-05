#include "../headers/guscatBkg.h"

GuscatBkg::GuscatBkg(OpenGLWidget *oglWidg, QWidget * parent) : Background(oglWidg, parent)
{
    width = 768;
    height = 720;
    depth = 1;
    drawDepth = depth;
    bkgImagePath = ":/images/backgrounds/bkgImages/guscat.jpg";

    init();
}

GuscatBkg::~GuscatBkg()
{
}
