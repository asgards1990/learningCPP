#include "fencodegenere.h"
#include "fenprincipale.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    QString *code(0);
//    code = new QString;
//    *code="nasdsddddddddddddddddddddddddddddddme\ndfsdfsdfsdf\nqsdfzrgzrg\noisdfsdf";

//    FenCodeGenere fenetre(code);
    FenPrincipale fenetre;
    fenetre.show();

    return app.exec();

}
