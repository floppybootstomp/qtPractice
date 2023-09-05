#ifndef SCENEHANDLER_H
#define SCENEHANDLER_H

#include <QWidget>
#include <QString>
#include <QMap>

#include "scene.h"

class SceneHandler : public QWidget
{
    Q_OBJECT
public:
    QMap<QString, Scene *> Scenes;

    SceneHandler(QWidget *parent = 0);

    ~SceneHandler();

    void addScene(Scene *s);

    void setCurrentScene(QString sName);

    void update();

private:
    Scene *currentScene;
};

#endif // SCENEHANDLER_H
