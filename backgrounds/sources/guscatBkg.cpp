#include "../headers/guscatBkg.h"

GuscatBkg::GuscatBkg(OpenGLWidget *oglWidg, QWidget * parent) : Background(oglWidg, parent)
{
    width = 256;
    height = 240;
    depth = 1;
    drawDepth = depth;
    bkgImagePath = ":/images/backgrounds/bkgImages/guscat.jpg";

    init();
}

GuscatBkg::~GuscatBkg()
{
}
