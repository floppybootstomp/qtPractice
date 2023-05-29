#include <QApplication>
#include "../headers/globalVars.h"
#include "../headers/game.h"

int main(int argc, char **argv){
    QApplication app (argc, argv);

    Game theGame;
    theGame.show();

    return app.exec();
}
