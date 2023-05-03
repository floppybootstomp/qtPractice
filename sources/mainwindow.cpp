#include "../headers/mainwindow.h"

MainWindow::MainWindow(QWindow *parent) : QWindow(parent)
{
    setWidth(defaultWidth);
    setHeight(defaultHeight);
}

MainWindow::MainWindow(int w, int h, QString title, QWindow *parent) : QWindow(parent)
{
    setWidth(w);
    setHeight(h);
    setTitle(title);
}

MainWindow::~MainWindow()
{
}
