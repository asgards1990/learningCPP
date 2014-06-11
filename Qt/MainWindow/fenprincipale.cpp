#include "fenprincipale.h"

FenPrincipale::FenPrincipale(QWidget *parent) :
    QMainWindow(parent)
{
    QMdiArea *zoneCentrale = new QMdiArea;

    QTextEdit *zoneTexte1 = new QTextEdit;
    QTextEdit *zoneTexte2 = new QTextEdit;

    QMdiSubWindow *sousFenetre1 = zoneCentrale->addSubWindow(zoneTexte1);
    QMdiSubWindow *sousFenetre2 = zoneCentrale->addSubWindow(zoneTexte2);

    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
        QMenu *fichiersRecents = menuFichier->addMenu("Fichiers récents");
        fichiersRecents->addAction("Fichier bidon 1.txt");
        fichiersRecents->addAction("Fichier bidon 2.txt");
        fichiersRecents->addAction("Fichier bidon 3.txt");

        QAction *actionQuitter = new QAction("&Quitter", this);
        menuFichier->addAction(actionQuitter);
        actionQuitter->setIcon(QIcon(QCoreApplication::applicationDirPath() + "\\quitter.gif"));
        //actionQuitter->setIcon(QIcon("quitter.gif"));
        QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
        actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));



    QMenu *menuEdition = menuBar()->addMenu("&Edition");
        QAction *actionGras = new QAction("&Gras", this);
        menuEdition ->addAction(actionGras);
        actionGras->setCheckable(true);


    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");
/* mainWindow->menuBar() return a QMenuBar object representing the set of menus,
then one can addMenu to the menuBar, this latter method create a pointer to the
Menu. */

    QToolBar *toolBarFichier = addToolBar("Fichier");
        toolBarFichier->addAction(actionQuitter);

        QFontComboBox *choixPolice = new QFontComboBox;
        toolBarFichier->addWidget(choixPolice); //La méthode addWidget retourne un élément de type QAction*, nous ne l'avons pas récupéré ici.

        toolBarFichier->addSeparator();


    setGeometry(500,300,600,500);
    setCentralWidget(zoneCentrale);
}
