#include "../headers/mainwindow.h"
#include "../headers/globalVars.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setCentralWidget(&oglWidget);

    defaultSize.setWidth(SCREEN_WIDTH);
    defaultSize.setHeight(SCREEN_HEIGHT);

    resize(defaultSize);

    setFocusPolicy(Qt::StrongFocus);
}

MainWindow::~MainWindow()
{
}

// Handles what happens when widget gains focus
void MainWindow::focusInEvent(QFocusEvent *event)
{
}

// Handles what happens when widget loses focus
void MainWindow::focusOutEvent(QFocusEvent *event)
{
    winUnfocusedAction();
}

// Action to perform when widget loses focus
void MainWindow::winUnfocusedAction()
{
    oglWidget.winUnfocusedAction();
}
