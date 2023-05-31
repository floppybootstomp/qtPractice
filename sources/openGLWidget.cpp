#include "../headers/openGLWidget.h"
#include "../headers/globalVars.h"

OpenGLWidget::OpenGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
}

// Destructor
OpenGLWidget::~OpenGLWidget()
{
}

// initializes opengl
void OpenGLWidget::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

// repaints opengl widget each frame
void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // loop through image buffer, draw them, and remove them from the buffer 
    while(drawImageBuffer.length() > 0)
    {
        drawImageFromBuffer(drawImageBuffer.front());
        drawImageBuffer.pop_front();
    }

    glFlush();
}

// resizes opengl widget
void OpenGLWidget::resizeGL(int w, int h){
    // prevent divide by zero
    if(h == 0)
        h = 1;
    // calculate aspect ratio
    float aspectRatio = ((float)w) / ((float)h);
    // set viewport to cover window
    glViewport(0,0,w,h);

    /* SET ASPECT RATIO */
    // switch to projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(w >= h)
    {
        glOrtho(0.0f*aspectRatio, SCREEN_HEIGHT*aspectRatio, SCREEN_HEIGHT, 0.0f, MIN_DEPTH, MAX_DEPTH);
        // center screen
        glTranslatef(((SCREEN_HEIGHT*aspectRatio)-(SCREEN_WIDTH))*0.5f, 0.0f, 0.0f);
    }
    else
    {
        glOrtho(0.0f, SCREEN_HEIGHT, SCREEN_HEIGHT/aspectRatio, 0.0f/aspectRatio, MIN_DEPTH, MAX_DEPTH);
        // center screen
        glTranslatef(0.0f, ((SCREEN_WIDTH/aspectRatio)-(SCREEN_HEIGHT))*0.3, 0.0f);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// inserts image into draw buffer to be drawn during frame update
void OpenGLWidget::drawImage(int posX, int posY, int width, int height, float leftTextCoord, float rightTextCoord, float topTextCoord, float bottomTextCoord, float depth, QImage texture)
{
    DrawImageBufferInfo theInfo{posX, posY, width, height, leftTextCoord, rightTextCoord, topTextCoord, bottomTextCoord, depth, texture};
    drawImageBuffer.push_back(theInfo);
}

// Draws image to screen
void OpenGLWidget::drawImageFromBuffer(DrawImageBufferInfo textureInfo)
{
    // create one openGL texture
    GLuint drawGLTexture;

    glGenTextures(1, &drawGLTexture);
    glBindTexture(GL_TEXTURE_2D, drawGLTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureInfo.drawTexture.width(), textureInfo.drawTexture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, textureInfo.drawTexture.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // draw surface to render texture on
    glBegin(GL_QUADS);                // Begin drawing the colored square
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glTexCoord2f(textureInfo.leftTextCoord, textureInfo.bottomTextCoord);
    glVertex3f(textureInfo.x, textureInfo.y, textureInfo.drawDepth);
    glTexCoord2f(textureInfo.rightTextCoord, textureInfo.bottomTextCoord);
    glVertex3f(textureInfo.x + textureInfo.w, textureInfo.y, textureInfo.drawDepth);
    glTexCoord2f(textureInfo.rightTextCoord, textureInfo.topTextCoord);
    glVertex3f(textureInfo.x + textureInfo.w, textureInfo.y + textureInfo.h, textureInfo.drawDepth);
    glTexCoord2f(textureInfo.leftTextCoord, textureInfo.topTextCoord);
    glVertex3f(textureInfo.x, textureInfo.y + textureInfo.h, textureInfo.drawDepth);
    glEnd();  // End of drawing color-cube

    // unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);
}
