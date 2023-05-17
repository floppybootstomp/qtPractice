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

    GameObject(int xPos, int yPos, int depthAmnt, QWidget *parent = 0);

    ~GameObject();

protected:
    int x, y, depth;

    void updateDrawDepth();
    void keyCheckPressed(int key);
    void keyCheckReleased(int key);

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    int drawDepth;
};

#endif // GAMEOBJECT_H
