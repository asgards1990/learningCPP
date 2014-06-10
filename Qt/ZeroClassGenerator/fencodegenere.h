#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QApplication>
#include <QLineEdit>
#include <QString>
#include <QTextEdit>
#include <QPushButton>
#include <QTabWidget>

class FenCodeGenere : public QDialog
{
    Q_OBJECT

public:
    FenCodeGenere(QString *codeGenere, QString *bodyCode, QString *nameClass, QWidget *parent=0);

signals:

public slots:

private:
    QTextEdit *header;
    QTextEdit *body;
    QPushButton *fermer;

};

#endif // FENCODEGENERE_H
