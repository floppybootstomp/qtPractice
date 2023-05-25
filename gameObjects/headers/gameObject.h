#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QWidget>
#include <QKeyEvent>


class GameObject : public QWidget
{
    Q_OBJECT
public:
    GameObject(QWidget *parent = 0);

    GameObject(int xPos, int yPos, QWidget *parent = 0);

    GameObject(int xPos, int yPos, float depthAmnt, QWidget *parent = 0);

    ~GameObject();
    int x, y, width, height;

protected:
    float depth;

    void updateDrawDepth();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    int drawDepth;
};

#endif // GAMEOBJECT_H
