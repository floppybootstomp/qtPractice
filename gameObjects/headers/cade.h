#ifndef CADE_H
#define CADE_H

#include "gameObject.h"
#include "../../headers/openGLWidget.h"

class Cade : public GameObject
{
    Q_OBJECT
public:
    Cade(OpenGLWidget *oglWidg, InputHandler *iptHandl, QWidget *parent = 0);

    ~Cade();

    void update();

private:
    bool carrying;

    void checkInput();

    void carryTheCat();
};

#endif // CADE_H
