#ifndef GUSCATBKG_H
#define GUSCATBKG_H

#include <QWidget>
#include <QtOpenGL>
#include "../../headers/openGLWidget.h"
#include "background.h"

class GuscatBkg : public Background
{
    Q_OBJECT
public:
    GuscatBkg(OpenGLWidget *oglWidg, QWidget *parent = 0);

    ~GuscatBkg();
};

#endif // GUSCATBKG_H
