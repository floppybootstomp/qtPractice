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
    // Handles what happens when widget gains focus
    void focusInEvent(QFocusEvent *event) override;

    // Handles what happens when widget loses focus
    void focusOutEvent(QFocusEvent *event) override;

    // Action to perform when widget loses focus
    void winUnfocusedAction();

    QSize defaultSize;
};

#endif // MAINWINDOW_H
