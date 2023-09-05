#include "../headers/scene.h"
#include "../../headers/globalVars.h"
#include <QDebug>

Scene::Scene(OpenGLWidget *oglWidg, QWidget *parent) : QWidget(parent)
{
    isFollowingObj = false;
    followToleranceX = 0;
    followToleranceY = 0;

    oglWidget = oglWidg;
}

Scene::~Scene()
{
    clearGameObjects();
    removeBackground();
}

// Add gameObject to scene
void Scene::addGameObject(GameObject *go)
{
    objs.push_front(go);
}

// Change background for scene
void Scene::changeBackground(Background *b)
{
    bkg = b;
}

// Remove gameObject from scene
void Scene::removeGameObject(GameObject *go)
{
    for(int i = 0; i < objs.size(); i ++)
    {
        if(objs[i] == go)
        {
            objs.removeAt(i);
            delete go;
        }
    }
}

// Remove background from scene
void Scene::removeBackground()
{
    Background *temp = bkg;
    bkg = 0;
    delete temp;
}

// update scene background, and all objects in scene
void Scene::update()
{
    bkg->update();
    for(int i = 0; i < objs.size(); i ++)
    {
        objs[i]->updateGameObject();
    }

    if(isFollowingObj)
    {
        moveViewportToFollowObject();
    }
}

// Remove all gameObjects from scene
void Scene::clearGameObjects()
{
    while(!objs.isEmpty())
    {
        GameObject *temp = objs.front();
        objs.pop_front();
        delete temp;
    }
}

void Scene::setViewportFollowing(GameObject *obj, int tolx, int toly)
{
    isFollowingObj = true;

    followObj = obj;

    followToleranceX = tolx;
    followToleranceY = toly;
}

void Scene::moveViewportToFollowObject()
{
    if(
        (oglWidget->viewportX + followToleranceX > followObj->x && bkg->xOffset < oglWidget->viewportX) ||
        (oglWidget->viewportX + followToleranceX < followObj->x && bkg->xOffset + bkg->width > oglWidget->viewportX + SCREEN_WIDTH)
    )
    {
        oglWidget->viewportX = followObj->x - followToleranceX;
    }

    if(
        (oglWidget->viewportY + followToleranceY > followObj->y && bkg->yOffset < oglWidget->viewportY) ||
        (oglWidget->viewportY + followToleranceY < followObj->y && bkg->yOffset + bkg->height > oglWidget->viewportY + SCREEN_HEIGHT)
    )
    {
        oglWidget->viewportY = followObj->y - followToleranceY;
    }
}
