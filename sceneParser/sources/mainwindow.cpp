#include "../headers/mainwindow.h"
#include "../headers/globalVars.h"
#include <QDebug>
#include <QMenu>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow (parent)
{
    // resize to screen size
    resize(SCREEN_WIDTH, SCREEN_HEIGHT);

    // set focus policy
    setFocusPolicy(Qt::StrongFocus);

    setBackgroundRole(QPalette::Shadow);
    setAutoFillBackground(true);

    cWidget = new QWidget(this);
    cWidget->resize(SCREEN_WIDTH, SCREEN_HEIGHT);

    leftWidget = new QWidget(0);
    leftWidget->setBackgroundRole(QPalette::Dark);
    leftWidget->setAutoFillBackground(true);
    leftWidget->resize(SCREEN_WIDTH/3 - xPadding, SCREEN_HEIGHT);
    rightWidget = new QWidget(0);
    rightWidget->setBackgroundRole(QPalette::Dark);
    rightWidget->setAutoFillBackground(true);
    rightWidget->resize((2*SCREEN_WIDTH)/3 - xPadding, SCREEN_HEIGHT);

    QLayout *layout = new QHBoxLayout();
    layout->addWidget(leftWidget);
    layout->addWidget(rightWidget);
    cWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete leftWidget;
    delete rightWidget;
}
