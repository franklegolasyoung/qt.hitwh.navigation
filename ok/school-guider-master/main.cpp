#include "mainwindow.h"
#include "loginbox.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginBox lBox;
    lBox.setFixedSize(400,400);
    lBox.show();
    return a.exec();
}
