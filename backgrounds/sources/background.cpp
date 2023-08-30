#include "../headers/background.h"
#include "../../headers/globalVars.h"

Background::Background(OpenGLWidget *oglWidg, QWidget *parent) : QWidget(parent)
{
    width = 0;
    height = 0;
    xOffset = 0;
    yOffset = 0;
    depth = 1;
    drawDepth = depth;
    oglWidget = oglWidg;
    bkgImagePath = "";
}

Background::~Background()
{
}

// Initializes a Background
void Background::init(){
    initializeTexture();
    updateDrawDepth();
    qInfo() << SCREEN_WIDTH/width << ", " << SCREEN_HEIGHT/height;
}

void Background::move(int xDist, int yDist)
{
    xOffset += xDist;
    yOffset += yDist;
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
    float textX1 = xOffset/(SCREEN_WIDTH);
    float textX2 = (width > 0) ? (xOffset/(SCREEN_WIDTH) + SCREEN_WIDTH/(width)) : 0;
    float textY1 = (height > 0) ? (1-yOffset/SCREEN_HEIGHT-SCREEN_HEIGHT/height) : 1;
    float textY2 = 1-(yOffset/SCREEN_HEIGHT);

    oglWidget->drawImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, textX1, textX2, textY1, textY2, drawDepth, backgroundTexture);
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
