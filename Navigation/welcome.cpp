#include "welcome.h"
#include "ui_welcome.h"

welcome::welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);
    setWindowTitle (" 您好");
    setWindowFlags(Qt::FramelessWindowHint);
    setGeometry(900,600,500,300);

}

welcome::~welcome()
{
    delete ui;
}
