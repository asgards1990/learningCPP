#include <QApplication>
#include "mafenetre.h"
#include "fenetrelayout.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenetreLayout fenetre;
    fenetre.show();

    return app.exec();

}


