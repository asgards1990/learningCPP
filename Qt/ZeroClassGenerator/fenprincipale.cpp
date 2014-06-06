#include "fenprincipale.h"

FenPrincipale::FenPrincipale() :
    QWidget()
{
    QVBoxLayout *m_layoutPrincipal = new QVBoxLayout(this);

    QGroupBox *groupClass = new QGroupBox;
        QGridLayout *layoutClass = new QGridLayout;
        QLabel *labelName= new QLabel;
        QLabel *labelMotherClass = new QLabel;
        QLineEdit *name = new QLineEdit;
        QLineEdit *motherClass = new QLineEdit;

        groupClass->setTitle("Définition de la classe");
        name->setToolTip("Entrez le nom de votre classe");
        labelName->setText("nom : ");
        motherClass->setToolTip("Entrez le nom de la classe mère si votre classe hérite d'une autre classe");
        labelMotherClass->setText("Class mère : ");

        layoutClass->addWidget(labelName,0,0);
        layoutClass->addWidget(name,0,1);
        layoutClass->addWidget(labelMotherClass,1,0);
        layoutClass->addWidget(motherClass,1,1);

        groupClass->setLayout(layoutClass);

        m_layoutPrincipal->addWidget(groupClass);

    QGroupBox *groupOptions= new QGroupBox;
        QVBoxLayout *layoutOptions = new QVBoxLayout;
        QCheckBox *header = new QCheckBox;
        QCheckBox *constructeur = new QCheckBox;
        QCheckBox *destructeur = new QCheckBox;

        header->setText("Protéger le header contre les intrusions multiples");
        header->setChecked(true);
        constructeur->setText("Générer un constructeur par défaut");
        constructeur->setChecked(true);
        destructeur->setText("Générer un destructeur");

        layoutOptions->addWidget(header);
        layoutOptions->addWidget(constructeur);
        layoutOptions->addWidget(destructeur);

        groupOptions->setTitle("Options");
        groupOptions->setLayout(layoutOptions);
        m_layoutPrincipal->addWidget(groupOptions);

    QGroupBox *groupCommentaires= new QGroupBox;
        QGridLayout *layoutCommentaires = new QGridLayout;
        QLabel *labelAuteur= new QLabel;
        QLabel *labelDate = new QLabel;
        QLabel *labelRole = new QLabel;
        QLineEdit *auteur = new QLineEdit;
        QDateEdit *date = new QDateEdit;
        QTextEdit *role= new QTextEdit;

        labelAuteur->setText("Auteur : ");
        labelDate->setText("Date de création : ");
        labelRole->setText("Rôle de la classe : ");
        auteur->setToolTip("Entrez votre nom que vous voulez voir apparaître comme celui de l'auteur");
        date->setToolTip("Spécifiez la date de création de la classe");
        date->setDate(QDate::currentDate());
        role->setToolTip("Précisez les rôles principales de la classe");

        layoutCommentaires->addWidget(labelAuteur,0,0);
        layoutCommentaires->addWidget(labelDate,1,0);
        layoutCommentaires->addWidget(labelRole,2,0);
        layoutCommentaires->addWidget(auteur,0,1);
        layoutCommentaires->addWidget(date,1,1);
        layoutCommentaires->addWidget(role,2,1);

        groupCommentaires->setTitle("Ajouter des commentaires");
        groupCommentaires->setCheckable(true);
        groupCommentaires->setChecked(false);
        groupCommentaires->setLayout(layoutCommentaires);
        m_layoutPrincipal->addWidget(groupCommentaires);

       // setLayout(m_layoutPrincipal);
}
