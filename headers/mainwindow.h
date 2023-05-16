#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../headers/openGLWidget.h"

class MainWindow : public QMainWindow
{
Q_OBJECT

    OpenGLWidget oglWidget;
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

protected:

private:
    QSize defaultSize;
};

#endif // MAINWINDOW_H
