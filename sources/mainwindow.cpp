#include "../headers/mainwindow.h"
#include "../headers/globalVars.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setCentralWidget(&oglWidget);

    defaultSize.setWidth(SCREEN_WIDTH);
    defaultSize.setHeight(SCREEN_HEIGHT);

    resize(defaultSize);
}

MainWindow::~MainWindow()
{
}
