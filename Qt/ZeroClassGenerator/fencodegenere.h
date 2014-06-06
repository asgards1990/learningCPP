#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

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
#include <QString>

class FenCodeGenere : public QWidget
{
    Q_OBJECT

public:
    FenCodeGenere(QString *nom, QString *mother, bool commentaires=false, QString *auteur=0, QDate *date=0,QString *role=0,
                  bool option1=true, bool option2=true , bool option3=false);

signals:

public slots:

private:
    QVBoxLayout *m_layoutGenere;

};

#endif // FENCODEGENERE_H
