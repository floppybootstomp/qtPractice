#include "../headers/background.h"
#include "../../headers/globalVars.h"

Background::Background(OpenGLWidget *oglWidg, QWidget *parent) : QWidget(parent)
{
    depth = 1;
    drawDepth = depth;
    bkgImagePath = ":/images/backgrounds/bkgImages/guscat.jpg";
    oglWidget = oglWidg;

    init();
}

Background::~Background()
{
}

// Initializes a Background
void Background::init(){
    initializeTexture();
    updateDrawDepth();
}

void Background::update()
{
    updateDrawDepth();
    drawSelf();
}

// Calculates and updates OpenGL draw depth from Background depth value
void Background::updateDrawDepth()
{
    if(depth <= 1)
    {
        drawDepth = MIN_DRAWDEPTH;
        return;
    }

    drawDepth = -1*MAX_DEPTH/depth;
}

// Draws sprite to screen
void Background::drawSelf()
{
    oglWidget->drawImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, drawDepth, backgroundTexture);
}

// Initializes texture for opengl to draw
void Background::initializeTexture()
{
    // load background image if not loaded
    try
    {
        loadBackgroundImage();
    }
    catch(std::exception&)
    {
        qDebug() << "Could not load background image for path: " << bkgImagePath;
        return;
    }

    backgroundTexture = QGLWidget::convertToGLFormat(backgroundImage);
}

// loads background image
void Background::loadBackgroundImage()
{
    bool bkgLoadIsSuccessful = backgroundImage.load(bkgImagePath);
    if(!bkgLoadIsSuccessful)
        throw std::exception();

    backgroundImage = backgroundImage.mirrored(false, true);
}
