#include "mafenetre.h"

MaFenetre::MaFenetre() : QWidget()
{
        setFixedSize(300, 300);

        // Construction du bouton
        m_quit = new QPushButton("Yeah I quit!", this);

        m_quit->setFont(QFont("Comic Sans MS", 14));
        m_quit->setCursor(Qt::PointingHandCursor);
        m_quit->setIcon(QIcon(QCoreApplication::applicationDirPath() + "\\Smiley.png"));
        //m_quit->setIcon(QIcon("Smiley.png"));
        m_quit->move(100, 80);


        // Connexion du clic du bouton à la fermeture de l'application
        QObject::connect(m_quit, SIGNAL(clicked()), qApp, SLOT(quit()));

        m_progressBarH= new QProgressBar(this);
        m_progressBarH->setGeometry(10,30,200,20);
        m_progressBarH->setFormat("%p%");

        m_progressBarV= new QProgressBar(this);
        m_progressBarV->setOrientation(Qt::Vertical);
        m_progressBarV->setGeometry(250,20,20,200);
        m_progressBarV->setFormat("%p%");
        m_progressBarV->setTextVisible(true);


        m_sliderH = new QSlider(Qt::Horizontal, this);
        m_sliderH->setGeometry(10, 60, 200, 20);
        m_sliderH->setRange(0,100);

        m_sliderV = new QSlider(this);
        m_sliderV->setGeometry(280, 20, 20, 200);
        m_sliderV->setRange(0,100);

        QObject::connect(m_sliderH, SIGNAL(valueChanged(int)), m_progressBarH, SLOT(setValue(int))) ;
        QObject::connect(m_sliderV, SIGNAL(valueChanged(int)), m_progressBarV, SLOT(setValue(int))) ;//Les sliders sont connectés aux barres de progressions.


        m_reset = new QPushButton("Reset", this);
        m_reset->setFont(QFont("Comic Sans MS", 14));
        m_reset->setCursor(Qt::PointingHandCursor);
        m_reset->move(10, 80);

        QObject::connect(m_reset, SIGNAL(clicked()), this, SLOT(resetSlider()));//Le bouton reset remet à 0 tout.

        QObject::connect(m_sliderH, SIGNAL(valueChanged(int)), this, SLOT(changerLargeur(int)));//SliderH contrôle la largeur de la fenêtre
        QObject::connect(m_sliderV, SIGNAL(valueChanged(int)), this, SLOT(changerHauteur(int)));//SliderV contrôle la hauteur de la fenêtre

        //QObject::connect(this, SIGNAL(agrandissementMax()), qApp, SLOT(quit()));//La fenêtre se ferme si une des dimensions atteint sa valeur maximale.

        m_boutonDialogue = new QPushButton("Ouvrir la boîte de dialogue", this);
        m_boutonDialogue->setFont(QFont("Comic Sans MS", 14));
        m_boutonDialogue->setCursor(Qt::PointingHandCursor);
        m_boutonDialogue->move(10, 130);

        QObject::connect(m_boutonDialogue, SIGNAL(clicked()), this, SLOT(ouvrirDialogue()));

        m_boutonSaisie = new QPushButton("What is your f* name!", this);
        m_boutonSaisie->setFont(QFont("Comic Sans MS", 14));
        m_boutonSaisie->setCursor(Qt::PointingHandCursor);
        m_boutonSaisie->move(10, 180);

        QObject::connect(m_boutonSaisie, SIGNAL(clicked()), this, SLOT(ouvrirSaisie()));

        m_boutonFile = new QPushButton("Choose a file", this);
        m_boutonFile ->setFont(QFont("Comic Sans MS", 14));
        m_boutonFile ->setCursor(Qt::PointingHandCursor);
        m_boutonFile ->move(10, 230);

         QObject::connect(m_boutonFile, SIGNAL(clicked()), this, SLOT(ouvrirFile()));



}

void MaFenetre::resetSlider()
{
    m_sliderH->setValue(0);
    m_sliderV->setValue(0);

}

void MaFenetre::changerLargeur(int largeur)
{
    setFixedSize(300+largeur*3, this->height());

    if (largeur == 100)
        {
            emit agrandissementMax();
        }
}

void MaFenetre::changerHauteur(int hauteur)
{
    setFixedSize (this->width(),300+3*hauteur);
    if (hauteur == 100)
        {
            emit agrandissementMax();
        }
}

void MaFenetre::ouvrirDialogue()
{

    bool ok = false;

    QFont police = QFontDialog::getFont(&ok, m_boutonDialogue->font(), this, "Choisissez une police");//La tailler de la boîte de dialogue n'est pas modifiée!

    if (ok)
    {
        m_boutonDialogue->setFont(police);
    }

    QColor couleur = QColorDialog::getColor(Qt::white, this);

    QPalette palette;
    palette.setColor(QPalette::ButtonText, couleur);
    m_boutonDialogue->setPalette(palette);

    int reponse = QMessageBox::information(this, "Titre de la fenêtre", "Et bien il faut bien écrire quelque chose! <strong>Hein?</strong>",QMessageBox::Yes|QMessageBox::No);
    //Remplacer information par warning/critical/question change le symbole apparaissant à gauche du message de manière adéquate.

    if (reponse == QMessageBox::Yes)
        {
            QMessageBox::information(this, "Suite", "Bein oui, what else?");
        }
        else if (reponse == QMessageBox::No)
        {
            QMessageBox::critical(this, "Suite", "Tricheur ! Menteur ! Voleur ! Ingrat ! Lâche ! Traître !\nSors d'ici ou j'appelle la police !");
        }
}

void MaFenetre::ouvrirSaisie()
{
    bool ok = false;
    QString pseudo = QInputDialog::getText(this, "Pseudo", "Quel est votre pseudo ?", QLineEdit::Normal, QString(), &ok);

    if (ok && !pseudo.isEmpty())
    {
        QMessageBox::information(this, "Pseudo", "Bonjour " + pseudo + ", ça va ?");
        m_boutonSaisie->setText("Bonjour " + pseudo + ", ça va ?");

    }
    else
    {
        QMessageBox::critical(this, "Pseudo", "Vous n'avez pas voulu donner votre nom… snif.");
    }
}

 void MaFenetre::ouvrirFile()
 {
     QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
     QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + fichier);
 }
