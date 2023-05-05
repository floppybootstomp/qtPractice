#include "../headers/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setCentralWidget(&oglWidget);
    defaultSize.setWidth(600);
    defaultSize.setHeight(400);

    resize(defaultSize);
}

MainWindow::~MainWindow()
{
}
