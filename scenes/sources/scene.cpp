#include "../headers/scene.h"
#include "../../headers/globalVars.h"
#include <QDebug>

Scene::Scene(QWidget *parent) : QWidget(parent)
{
    viewportW = SCREEN_WIDTH;
    viewportH = SCREEN_HEIGHT;

    followToleranceX1 = 0;
    followToleranceX2 = 0;
    followToleranceY1 = 0;
    followToleranceY2 = 0;
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
