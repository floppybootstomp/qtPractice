#ifndef ANIMATION_H
#define ANIMATION_H

#include <QtOpenGL>
#include <QImage>
#include <QString>

class Animation
{
public:
    QString name;
    QImage spriteTexture;
    int index, speed;

    struct SpriteDimensions
    {
        float left, right, top, bottom;
    } sprDims;

    Animation();
    Animation(QString name, QString spritePath, QList<int> aniSeq, int aniSpeed, int xNumImg, int yNumImg, int xOffset, int yOffset);
    ~Animation();

    // Cycles image animation
    void cycleAnimation();

private:
    QImage spriteImage;
    QList<int> seq;
    int xNumImages, yNumImages, xImageOffset, yImageOffset, count;
    int defaultWidth, defaultHeight;

    // loads sprite image
    QImage loadSpriteImage(QString path);

    // sets sprite dimensions
    void setSpriteDimensions(int xNumImg, int yNumImg, int xOffset, int yOffset);
};

#endif // ANIMATION_H
