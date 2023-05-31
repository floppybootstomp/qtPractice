#include "../headers/background.h"
#include "../../headers/globalVars.h"

Background::Background(OpenGLWidget *oglWidg, QWidget *parent) : QWidget(parent)
{
    depth = 1;
    drawDepth = depth;
    oglWidget = oglWidg;
    bkgImagePath = ":/images/backgrounds/bkgImages/guscat.jpg";

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
    oglWidget->drawImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 1, 0, 1, drawDepth, backgroundTexture);
}

// Initializes texture for opengl to draw
void Background::initializeTexture()
{
    // load background image if not loaded
    loadBackgroundImage();

    backgroundTexture = QGLWidget::convertToGLFormat(backgroundImage);
}

// loads background image
void Background::loadBackgroundImage()
{
    bool bkgLoadIsSuccessful = backgroundImage.load(bkgImagePath);

    // replace with pink square if bad file name
    if(!bkgLoadIsSuccessful)
    {
        qDebug() << "Could not load background image for path: " << bkgImagePath;
        backgroundImage = *(new QImage(QSize(SCREEN_WIDTH, SCREEN_HEIGHT), QImage::Format_RGB32));
        backgroundImage.fill(QColor::fromRgb(255, 0, 178));
    }
}
