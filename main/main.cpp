#include <QApplication>
#include "../headers/hello.h"
#include "../headers/mainwindow.h"

int main(int argc, char **argv){
    QApplication app (argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}
