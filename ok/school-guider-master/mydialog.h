#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QWidget>
#include <QString>

namespace Ui {
class myDialog;
}

class myDialog : public QWidget
{
    Q_OBJECT

public:
    explicit myDialog(QWidget *parent = 0);
    ~myDialog();

    void ins(QString);

signals:
    void mysignal();

private slots:
    void on_pushButton_clicked();

private:
    Ui::myDialog *ui;
};

#endif // MYDIALOG_H
