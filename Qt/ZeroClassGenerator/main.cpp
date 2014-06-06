#include "fencodegenere.h"
#include "fenprincipale.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString *nom(0);
    nom = new QString;
    *nom="name";
    QString *mother(0);
    mother = new QString;
    *mother="mother";
    QString *auteur(0);
    auteur = new QString;
    *auteur="su";
    QDate *date(0);
    date = new QDate;
    *date=QDate::currentDate();
    QString *role(0);
    role = new QString;
    *role="qsihdfpiq sjdofnqsjklfnkln";
    FenCodeGenere fenetre(nom,mother,true,auteur,date,role);
//    FenPrincipale fenetre;
    fenetre.show();

    return app.exec();

}
