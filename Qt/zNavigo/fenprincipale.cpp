#include "fenprincipale.h"


FenPrincipale::FenPrincipale()
{
    // Génération des widgets de la fenêtre principale
    creerMenus();
//    creerActions();

//    creerBarresOutils();
//    creerBarreEtat();

    // Génération des onglets et chargement de la page d'accueil
    onglets = new QTabWidget;
    onglets->addTab(creerOngletPageWeb(tr("http://www.siteduzero.com")), tr("(Nouvelle page)"));
    connect(onglets, SIGNAL(currentChanged(int)), this, SLOT(changementOnglet(int)));
    setCentralWidget(onglets);

    // Définition de quelques propriétés de la fenêtre
    setMinimumSize(500, 350);
    setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "\\images/znavigo.png"));
    setWindowTitle(tr("zNavigo"));
}

void FenPrincipale::creerMenus()
{

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



    QMenu *menuNavigation = menuBar()->addMenu(tr("&Navigation"));
        QAction *actionGras = new QAction(tr("&Gras"), this);
        menuNavigation ->addAction(actionGras);
        actionGras->setCheckable(true);


    QMenu *menuAide= menuBar()->addMenu(tr("&?"));
/* mainWindow->menuBar() return a QMenuBar object representing the set of menus,
then one can addMenu to the menuBar, this latter method create a pointer to the
Menu. */
}



QWidget *FenPrincipale::creerOngletPageWeb(QString url)
{
    QWidget *pageOnglet = new QWidget;
    QWebView *pageWeb = new QWebView;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(pageWeb);
    pageOnglet->setLayout(layout);

    if (url.isEmpty())
    {
        pageWeb->load(QUrl(tr("html/page_blanche.html")));
    }
    else
    {
        if (url.left(7) != "http://")
        {
            url = "http://" + url;
        }
        pageWeb->load(QUrl(url));
    }

    // Gestion des signaux envoyés par la page web
//    connect(pageWeb, SIGNAL(titleChanged(QString)), this, SLOT(changementTitre(QString)));
//    connect(pageWeb, SIGNAL(urlChanged(QUrl)), this, SLOT(changementUrl(QUrl)));
//    connect(pageWeb, SIGNAL(loadStarted()), this, SLOT(chargementDebut()));
//    connect(pageWeb, SIGNAL(loadProgress(int)), this, SLOT(chargementEnCours(int)));
//    connect(pageWeb, SIGNAL(loadFinished(bool)), this, SLOT(chargementTermine(bool)));

    return pageOnglet;
}

QWebView *FenPrincipale::pageActuelle()
{
    return onglets->currentWidget()->findChild<QWebView *>();
}

void FenPrincipale::changementOnglet(int)
{//get the tab by index "int" retrieve its adress and title and apply them to QLineEdit *champAdresse; and the title of the tabwidget

}
