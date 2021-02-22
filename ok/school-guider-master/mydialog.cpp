#include "mydialog.h"
#include "ui_mydialog.h"

myDialog::myDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("景点介绍");

}

void myDialog::ins(QString content)
{
    ui->label->setText(content);
}

myDialog::~myDialog()
{
    delete ui;
}

void myDialog::on_pushButton_clicked()
{
    this->close();
}
