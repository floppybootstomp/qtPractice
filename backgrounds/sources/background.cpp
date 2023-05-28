#include "../headers/background.h"
#include "../../headers/globalVars.h"

Background::Background(QWidget *parent) : QWidget(parent)
{
    depth = 1;
    drawDepth = depth;
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
    glGenTextures(1, &backgroundGLTexture);
    glBindTexture(GL_TEXTURE_2D, backgroundGLTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, backgroundTexture.width(), backgroundTexture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, backgroundTexture.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // draw surface to render texture on
    glBegin(GL_QUADS);                // Begin drawing the colored square
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(SCREEN_WIDTH, SCREEN_HEIGHT, drawDepth);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0, SCREEN_HEIGHT, drawDepth);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0, 0, drawDepth);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(SCREEN_WIDTH, 0, drawDepth);
    glEnd();  // End of drawing color-cube

    glBindTexture(GL_TEXTURE_2D, 0);
}

// Initializes texture for opengl to draw
void Background::initializeTexture()
{
    // load sprite image if not loaded
    try
    {
        loadBackgroundImage();
    }
    catch(std::exception&)
    {
        qDebug() << "Could not load background image for path: " << bkgImagePath;
        return;
    }

    // create one openGL texture
    backgroundTexture = QGLWidget::convertToGLFormat(backgroundImage);
}

// loads sprite image
void Background::loadBackgroundImage()
{
    bool bkgLoadIsSuccessful = backgroundImage.load(bkgImagePath);
    if(!bkgLoadIsSuccessful)
        throw std::exception();

    backgroundImage = backgroundImage.mirrored(false, true);
}
