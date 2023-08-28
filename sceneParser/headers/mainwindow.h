#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../headers/globalVars.h"
#include <QMainWindow>

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    float xPadding = SCREEN_WIDTH*0.05;
    QWidget *cWidget;
    QWidget *leftWidget;
    QWidget *rightWidget;
};

#endif // MAINWINDOW_H
