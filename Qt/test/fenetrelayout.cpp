#include "fenetrelayout.h"

FenetreLayout::FenetreLayout() :
    QWidget()
{    

    m_boxLayout = new QPushButton("BoxLayout !", this);
    m_boxLayout->setFont(QFont("Comic Sans MS", 14));
    m_boxLayout->setCursor(Qt::PointingHandCursor);
    QObject::connect(m_boxLayout, SIGNAL(clicked()), this, SLOT(openBoxLayout()));

    m_gridLayout = new QPushButton("GridLayout !", this);
    m_gridLayout->setFont(QFont("Comic Sans MS", 14));
    m_gridLayout->setCursor(Qt::PointingHandCursor);
    QObject::connect(m_gridLayout, SIGNAL(clicked()), this, SLOT(openGridLayout()));

    m_formCombineLayout = new QPushButton("FormCombineLayout !", this);
    m_formCombineLayout->setFont(QFont("Comic Sans MS", 14));
    m_formCombineLayout->setCursor(Qt::PointingHandCursor);
    QObject::connect( m_formCombineLayout, SIGNAL(clicked()), this, SLOT(openFormCombineLayout()));


    //Le bloc qui définit le BoxLayout
    QPushButton *boxBouton1 = new QPushButton("Bonjour");
    QPushButton *boxBouton2 = new QPushButton("les");
    QPushButton *boxBouton3 = new QPushButton("Zéros");
    QHBoxLayout *boxLayout = new QHBoxLayout;
    boxLayout->addWidget(boxBouton1);
    boxLayout->addWidget(boxBouton2);
    boxLayout->addWidget(boxBouton3);
    m_fenetreBoxLayout.setLayout(boxLayout);


    //Le bloc qui définit le GridLayout
    QPushButton *gridBouton1 = new QPushButton("Bonjour");
    QPushButton *gridBouton2 = new QPushButton("les");
    QPushButton *gridBouton3= new QPushButton("Zéros");
    QPushButton *gridBouton4 = new QPushButton("!!!!!");
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(gridBouton1,0,0);
    gridLayout->addWidget(gridBouton2,0,1);
    gridLayout->addWidget(gridBouton3,1,0,1,2);
    gridLayout->addWidget(gridBouton4,2,2);
    m_fenetreGridLayout.setLayout(gridLayout);

    //Le bloc qui définit le FormCombineLayout
    QLineEdit *nom = new QLineEdit;
    QLineEdit *prenom = new QLineEdit;
    QLineEdit *age = new QLineEdit;
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Votre nom", nom);
    formLayout->addRow("Votre prénom", prenom);
    formLayout->addRow("Votre âge", age);

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(formLayout); // Ajout du layout de formulaire
    QPushButton *boutonQuitter = new QPushButton("Quitter");

    QWidget::connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    layoutPrincipal->addWidget(boutonQuitter); // Ajout du bouton
    m_fenetreFormCombineLayout.setLayout(layoutPrincipal);

    //Le bloc qui définit le layout de l'objet

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_boxLayout);
    layout->addWidget(m_gridLayout);
    layout->addWidget(m_formCombineLayout);
    this->setLayout(layout);
}

void FenetreLayout::openBoxLayout()
{

    m_fenetreBoxLayout.show();

}

void FenetreLayout::openGridLayout()
{
    m_fenetreGridLayout.show();
}

void FenetreLayout::openFormCombineLayout()
{
    m_fenetreFormCombineLayout.show();
}
