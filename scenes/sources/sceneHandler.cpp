#include "../headers/sceneHandler.h"

SceneHandler::SceneHandler(QWidget *parent) : QWidget(parent)
{
}

SceneHandler::~SceneHandler()
{
}

void SceneHandler::addScene(Scene *s)
{
    Scenes.insert(s->name, s);
}

void SceneHandler::setCurrentScene(QString sName)
{
    currentScene = Scenes[sName];
}

void SceneHandler::update()
{
    currentScene->update();
}
