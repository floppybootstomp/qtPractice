#ifndef SCENE_H
#define SCENE_H

#include <QWidget>

#include "../../headers/openGLWidget.h"
#include "../../gameObjects/headers/inputHandler.h"
#include "../../backgrounds/headers/background.h"
#include "../../gameObjects/headers/gameObject.h"

class Scene : public QWidget
{
    Q_OBJECT
public:
    int x, y, width, height, viewportX, viewportY, viewportW, viewportH;

    // preserve state of scene after leaving
    bool isPersistent;

    Background *bkg;

    QList<GameObject *> objs;

    // the object that the viewport follows
    GameObject *followObj;
    int followToleranceX1, followToleranceX2, followToleranceY1, followToleranceY2;

    Scene(QWidget *parent = 0);

    ~Scene();

    // Add gameObject to scene
    void addGameObject(GameObject *go);

    // Change background for scene
    void changeBackground(Background *b);

    // Remove gameObject from scene
    void removeGameObject(GameObject *go);

    // Remove background from scene
    void removeBackground();

    // update scene background, and all objects in scene
    void update();

private:
    // Remove all gameObjects from scene
    void clearGameObjects();
};

#endif // SCENE_H
