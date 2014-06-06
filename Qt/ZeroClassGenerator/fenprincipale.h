#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QDate>

class FenPrincipale : public QWidget
{
    Q_OBJECT

public:
     FenPrincipale();

signals:

public slots:

private:
     QVBoxLayout *m_layoutPrincipal;

};

#endif // FENPRINCIPALE_H
