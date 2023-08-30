#ifndef PROOH_H
#define PROOH_H

#include <QWidget>
#include <QtOpenGL>
#include "../../headers/openGLWidget.h"
#include "background.h"

class Prooh : public Background
{
    Q_OBJECT
public:
    Prooh(OpenGLWidget *oglWidg, QWidget *parent = 0);

    ~Prooh();
};

#endif // PROOH_H
