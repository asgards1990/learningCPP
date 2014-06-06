#include "fencodegenere.h"

FenCodeGenere::FenCodeGenere(QString *nom, QString *mother, bool commentaires, QString *auteur, QDate *date, QString *role,
                             bool option1, bool option2 , bool option3) :
    QWidget()
{

    QTextEdit *code = new QTextEdit;
    QVBoxLayout *m_layoutGenere = new QVBoxLayout(this);

    if (commentaires)
    {
        code->setText("/* \nAuteur : " + *auteur + "\nDate de création :  " + date->toString() + "\nRôle :" + *role + "\n*/" );

        m_layoutGenere->addWidget(code);
        setLayout(m_layoutGenere);

    }


}
