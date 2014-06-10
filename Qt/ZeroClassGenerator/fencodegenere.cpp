#include "fencodegenere.h"

FenCodeGenere::FenCodeGenere(QString *code,QString *bodyCode,QString *nameClass, QWidget *parent) :
    QDialog(parent)
{



    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    QTabWidget *tabs = new QTabWidget;

    header = new QTextEdit;
    header->setText(*code);

    body = new QTextEdit;
    body->setText(*bodyCode);

    tabs->addTab(header,*nameClass+".h");
    tabs->addTab(body,*nameClass+".cpp");

    fermer = new QPushButton;
    fermer->setText("Fermer");

    layoutPrincipal->addWidget(tabs);
    layoutPrincipal->addWidget(fermer);
    QObject::connect(fermer,SIGNAL(clicked()),this,SLOT(accept()));

    setLayout(layoutPrincipal);



}
