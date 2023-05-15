#include "../headers/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    mwLayout.addWidget(&oglWidget);

    window.setLayout(&mwLayout);
    setCentralWidget(&window);

    defaultSize.setWidth(400);
    defaultSize.setHeight(400);

    window.resize(defaultSize);
    resize(defaultSize);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    //qInfo() << mwLayout.setAlignment(&oglWidget, Qt::AlignCenter);
}


MainWindow::~MainWindow()
{
}
