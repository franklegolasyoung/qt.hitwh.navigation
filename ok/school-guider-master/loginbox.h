#ifndef LOGINBOX_H
#define LOGINBOX_H

#include <QWidget>
#include <QPaintEvent>
#include "mainwindow.h"

namespace Ui {
class LoginBox;
}

class LoginBox : public QWidget
{
    Q_OBJECT

public:
    explicit LoginBox(QWidget *parent = 0);
    ~LoginBox();

protected:
    void paintEvent(QPaintEvent*);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LoginBox *ui;

    static QString user;
    static QString password;

    MainWindow w;
};

#endif // LOGINBOX_H
