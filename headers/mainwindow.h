#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../headers/openGLWidget.h"
#include "../headers/my_gl.h"

class MainWindow : public QMainWindow 
{
Q_OBJECT

    OpenGLWidget oglWidget;
    MyGL ogl;
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:
    QSize defaultSize;
};

#endif // MAINWINDOW_H
