#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QObject>
#include <QtOpenGL>

class Triangle : public QObject
{
    Q_OBJECT
public:
    Triangle();

    void draw_self();
};

#endif // TRIANGLE_H
