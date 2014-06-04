#ifndef FENETRELAYOUT_H
#define FENETRELAYOUT_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>

class FenetreLayout : public QWidget
{
    Q_OBJECT
public:
FenetreLayout();

public slots:
void openBoxLayout();
void openGridLayout();
void openFormCombineLayout();

signals:


private:
QPushButton *m_boxLayout;
QWidget m_fenetreBoxLayout;
QPushButton *m_gridLayout;
QWidget m_fenetreGridLayout;
QPushButton *m_formCombineLayout;
QWidget m_fenetreFormCombineLayout;



};

#endif // FENETRELAYOUT_H
