#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>
#include <QMessageBox>
#include <QInputDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QFileDialog>

class MaFenetre : public QWidget
{
    Q_OBJECT

    public:
    MaFenetre();

    public slots:
    void resetSlider();
    void changerLargeur(int largeur);
    void changerHauteur(int hauteur);
    void ouvrirDialogue();
    void ouvrirSaisie();
    void ouvrirFile();

    signals:
    void agrandissementMax();

    private:
    QPushButton *m_quit;
    QPushButton *m_reset;
    QLCDNumber *m_lcd;
    QProgressBar *m_progressBarH;
    QProgressBar *m_progressBarV;
    QSlider *m_sliderH;
    QSlider *m_sliderV;
    QPushButton *m_boutonDialogue;
    QPushButton *m_boutonSaisie;
    QPushButton *m_boutonFile;

};

#endif // MAFENETRE_H
