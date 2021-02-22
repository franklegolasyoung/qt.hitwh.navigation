#include "loginbox.h"
#include "ui_loginbox.h"
#include <QPainter>

QString LoginBox::user = "123123";
QString LoginBox::password = "123123";

LoginBox::LoginBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginBox)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");
}

void LoginBox::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);

    painter.drawPixmap(0,0,width(),height(),QPixmap("../image/timg.jpg"));

    painter.end();
}

LoginBox::~LoginBox()
{
    delete ui;
}

void LoginBox::on_pushButton_clicked()
{
    QString u = ui->lineEdit->text();
    QString p = ui->lineEdit_2->text();

    if(u==user && p==password)
    {
        w.setFixedSize(1000,600);
        w.setWindowFlags(Qt::WindowCloseButtonHint);
        w.show();
        this->hide();
    }
    else
    {
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    }
}

void LoginBox::on_pushButton_2_clicked()
{
    this->close();
}
