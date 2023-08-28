#include "../headers/animation.h"

Animation::Animation()
{
}

Animation::Animation(QString aniName, QString spritePath, QList<int> aniSeq, int aniSpeed, int xNumImg, int yNumImg, int xOffset, int yOffset)
{
    name = aniName;
    seq = aniSeq;
    speed = aniSpeed;
    xNumImages = xNumImg;
    yNumImages = yNumImg;
    xImageOffset = xOffset;
    yImageOffset = yOffset;
    count = 0;

    defaultWidth = 16;
    defaultHeight = 16;

    // load sprite image if not loaded
    spriteImage = loadSpriteImage(spritePath);

    // create one openGL texture
    spriteTexture = QGLWidget::convertToGLFormat(spriteImage);

    // get dimensions of sprite
    setSpriteDimensions(xNumImg, yNumImg, xOffset, yOffset);
}

Animation::~Animation()
{
}

// Cycles image animation
void Animation::cycleAnimation()
{
    if(speed > 0)
    {
        count++;
     
        if(count == speed)
        {
            count = 0;

            index = (index + 1) % seq.length();

            // make sure index is within bounds
            if(index < 0 || index > seq.length()-1)
                index = 0;

            xImageOffset = seq[index];
        }

        setSpriteDimensions(xNumImages, yNumImages, xImageOffset, yImageOffset);
    }
}

// loads sprite image
QImage Animation::loadSpriteImage(QString path)
{
    QImage sprImage;
    bool sprLoadIsSuccessful = sprImage.load(path);

    // replace with pink square if bad file name
    if(!sprLoadIsSuccessful)
    {
        qDebug() << "Could not load sprite image for path: " << path;
        sprImage = *(new QImage(QSize(defaultWidth, defaultHeight), QImage::Format_RGB32));
        sprImage.fill(QColor::fromRgb(255, 0, 178));
    }

    return sprImage;
}

// sets sprite dimensions
void Animation::setSpriteDimensions(int xNumImg, int yNumImg, int xOffset, int yOffset)
{
    float imageXLength = 1.0f/xNumImg;
    float imageYLength = 1.0f/yNumImg;

    float lCoord = xOffset*(imageXLength);
    float rCoord = lCoord + (imageXLength);
    // add negative imageYLength, because opengl coords start 0,0 in bottom left corner
    float tCoord = (-1*imageYLength) + yOffset*(imageYLength);
    float bCoord = tCoord + (imageYLength);

    sprDims = {lCoord, rCoord, tCoord, bCoord};
}
