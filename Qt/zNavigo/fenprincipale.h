#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QWidget>
#include <QtWebKitWidgets>
#include <QApplication>
#include <QMainWindow>
#include <QTableWidget>
#include <QAction>
#include <QLineEdit>
#include <QProgressBar>
#include <QWebView>
//#include <QGridLayout>
//#include <QHBoxLayout>
#include <QVBoxLayout>
//#include <QGroupBox>
//#include <QLabel>
//#include <QCheckBox>
//#include <QDateEdit>
//#include <QTextEdit>
//#include <QDate>
//#include <QPushButton>
//#include <QMessageBox>

class FenPrincipale : public QMainWindow
{
    Q_OBJECT

    public:
        FenPrincipale();

    private:
        void creerMenus();
//        void creerActions();

//        void creerBarresOutils();
//        void creerBarreEtat();
        QWebView *pageActuelle();
        QWidget *creerOngletPageWeb(QString url);

    private slots:
        void changementOnglet(int);
//        void changementTitre(QString);
//        void changementUrl(QUrl);
//        void chargementDebut();
//        void chargementEnCours(int);
//        void chargementTermine(bool);

    private:
        QTabWidget *onglets;

        QAction *actionNouvelOnglet;
        QAction *actionFermerOnglet;
        QAction *actionQuitter;
        QAction *actionAPropos;
        QAction *actionAProposQt;
        QAction *actionPrecedente;
        QAction *actionSuivante;
        QAction *actionStop;
        QAction *actionActualiser;
        QAction *actionAccueil;
        QAction *actionGo;

        QLineEdit *champAdresse;
        QProgressBar *progression;
};

#endif // FENPRINCIPALE_H
