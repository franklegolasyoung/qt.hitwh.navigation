#include "mainwindow.h"

#include <QApplication>
#include <QFont>
#include <QDebug>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show ();

    return a.exec();
}
