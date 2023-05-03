#include <QApplication>
#include "../headers/hello.h"
#include "../headers/mainwindow.h"

int main(int argc, char **argv){
    QApplication app (argc, argv);

    /*
    Hello theHello;
    theHello.showHello();
    */

    MainWindow window(600, 400, "YOOOO");
    window.show();

    return app.exec();
}
