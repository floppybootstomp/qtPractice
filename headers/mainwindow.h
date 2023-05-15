#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../headers/openGLWidget.h"
#include "../headers/my_gl.h"

class MainWindow : public QMainWindow
{
Q_OBJECT

    QWidget window;
    QGridLayout mwLayout;
    OpenGLWidget oglWidget;
    MyGL ogl;
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event);

private:
    QSize defaultSize;
};

#endif // MAINWINDOW_H
