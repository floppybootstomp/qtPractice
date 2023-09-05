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
    int x, y, width, height;

    /*
        isPersistent: preserve state of scene after leaving
        isFollowingObj: move the viewport to follow an object around the scene
    */
    bool isPersistent, isFollowingObj;

    Background *bkg;

    QList<GameObject *> objs;

    // the object that the viewport follows
    GameObject *followObj;
    int followToleranceX, followToleranceY;

    Scene(OpenGLWidget *oglWidg, QWidget *parent = 0);

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

    void setViewportFollowing(GameObject *obj, int tolx, int toly);

    void moveViewportToFollowObject();

private:
    OpenGLWidget *oglWidget;

    // Remove all gameObjects from scene
    void clearGameObjects();
};

#endif // SCENE_H
