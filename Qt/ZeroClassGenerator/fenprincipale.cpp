#include "fenprincipale.h"

FenPrincipale::FenPrincipale() :
    QWidget()
{
    QVBoxLayout *m_layoutPrincipal = new QVBoxLayout(this);

    QGroupBox *groupClass = new QGroupBox;
        QGridLayout *layoutClass = new QGridLayout;
        QLabel *labelName= new QLabel;
        QLabel *labelMotherClass = new QLabel;
        name = new QLineEdit;
        motherClass = new QLineEdit;

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
        header = new QCheckBox;
        constructeur = new QCheckBox;
        destructeur = new QCheckBox;

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

    groupCommentaires= new QGroupBox;
        QGridLayout *layoutCommentaires = new QGridLayout;
        QLabel *labelAuteur= new QLabel;
        QLabel *labelDate = new QLabel;
        QLabel *labelRole = new QLabel;
        auteur = new QLineEdit;
        date = new QDateEdit;
        role= new QTextEdit;

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

    QGroupBox *groupSubmit= new QGroupBox;
        QHBoxLayout *layoutSubmit = new QHBoxLayout;
        generate = new QPushButton;
        quitter = new QPushButton;

        generate->setText("Générer!");
        quitter->setText("Quitter");

        QObject::connect(generate, SIGNAL(clicked()), this, SLOT(generateCode()));
        QObject::connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));

        layoutSubmit->addWidget(generate);
        layoutSubmit->addWidget(quitter);

        groupSubmit->setLayout(layoutSubmit);
        m_layoutPrincipal->addWidget(groupSubmit);
        m_layoutPrincipal->setAlignment(groupSubmit,Qt::AlignRight);

       // setLayout(m_layoutPrincipal);
}

void FenPrincipale::generateCode()
{


    if ((name->text()).isEmpty())
        {
            QMessageBox::critical(this, "Erreur", "Veuillez entrer au moins un nom de classe");
            return; // Arrêt de la méthode
        }

    QString *code = new QString;
    QString *bodyCode = new QString;

    bodyCode->append("#include \"" + name->text() + ".h\"\n\n");
    if (groupCommentaires->isChecked())
    {

        code->append("/* \nAuteur : " + auteur->text() + "\nDate de création :  " + (date->date()).toString() + "\n");
        if(!role->toPlainText().isEmpty())
        {
        code->append("\nRôle :\n" + role->toPlainText() + "\n");
        }
        code->append( "*/\n\n\n");

    }

    code->append("#ifndef HEADER_" + name->text().toUpper() + "\n#define HEADER_" + name->text().toUpper() + "\n\n\nclass " + name->text());

    bool motherClassEmpty = motherClass->text().isEmpty();
    if (!motherClassEmpty)
    {
        code->append(" : public " + motherClass->text());
    }

    code->append("\n{\n\n    public:\n");

    if(constructeur->isChecked())
    {
        code->append("        "+name->text() +"();\n");
        bodyCode->append(name->text()+"::"+name->text());
        if(!motherClassEmpty)
        {
            bodyCode->append(" :\n    " + motherClass->text() + "()");
        }
        bodyCode->append("\n{\n\n}");
    }

    if(destructeur->isChecked())
    {
        code->append("       ~" + name->text() +"();\n");
    }

    code->append("\n\n    protected:\n\n\n    private:\n\n\n}");




    FenCodeGenere *fenetreCode=new FenCodeGenere(code, bodyCode, &(name->text()), this);
    fenetreCode->exec();
}
