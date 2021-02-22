#include "mainwindow.h"
#include "welcome.h"
#include <windows.h>
#include <QApplication>
#include <QFont>
#include <QDebug>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcome r;
    MainWindow w;
    r.show();
    Sleep(3000);
    w.show();
    r.close();
    return a.exec();
}
