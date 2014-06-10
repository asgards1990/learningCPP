#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QDate>
#include <QPushButton>
#include <QMessageBox>
#include "fencodegenere.h"

class FenPrincipale : public QWidget
{
    Q_OBJECT

public:
     FenPrincipale();

signals:

public slots:
     void generateCode();

private:
     QLineEdit *name;
     QLineEdit *motherClass;
     QCheckBox *header;
     QCheckBox *constructeur;
     QCheckBox *destructeur;
     QGroupBox *groupCommentaires;
     QLineEdit *auteur;
     QDateEdit *date;
     QTextEdit *role;
     QPushButton *generate;
     QPushButton *quitter;

};

#endif // FENPRINCIPALE_H
