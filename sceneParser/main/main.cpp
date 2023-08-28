#include <QApplication>
#include "../headers/globalVars.h"
#include "../headers/mainwindow.h"

int main(int argc, char **argv){
    QApplication app (argc, argv);

    MainWindow sp;
    sp.show();

    return app.exec();
}
