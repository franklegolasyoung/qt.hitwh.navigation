/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *text1;
    QLabel *text2;
    QLabel *hitlogo;
    QLabel *start;
    QLabel *texts;
    QLabel *texte;
    QLabel *end;
    QLabel *textd;
    QLabel *dis;
    QLabel *intro;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 817);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(780, 10, 211, 781));
        frame->setAutoFillBackground(true);
        frame->setStyleSheet(QStringLiteral("backgroundcolor:rgb(0, 170, 255)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        text1 = new QLabel(frame);
        text1->setObjectName(QStringLiteral("text1"));
        text1->setGeometry(QRect(0, 210, 201, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(9);
        text1->setFont(font);
        text2 = new QLabel(frame);
        text2->setObjectName(QStringLiteral("text2"));
        text2->setGeometry(QRect(0, 240, 201, 41));
        text2->setFont(font);
        hitlogo = new QLabel(frame);
        hitlogo->setObjectName(QStringLiteral("hitlogo"));
        hitlogo->setGeometry(QRect(10, 10, 191, 191));
        hitlogo->setStyleSheet(QStringLiteral("image: url(:/hit);"));
        start = new QLabel(frame);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(70, 310, 141, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        start->setFont(font1);
        texts = new QLabel(frame);
        texts->setObjectName(QStringLiteral("texts"));
        texts->setGeometry(QRect(20, 310, 41, 31));
        texts->setFont(font1);
        texte = new QLabel(frame);
        texte->setObjectName(QStringLiteral("texte"));
        texte->setGeometry(QRect(20, 350, 41, 31));
        texte->setFont(font1);
        end = new QLabel(frame);
        end->setObjectName(QStringLiteral("end"));
        end->setGeometry(QRect(70, 350, 141, 31));
        end->setFont(font1);
        textd = new QLabel(frame);
        textd->setObjectName(QStringLiteral("textd"));
        textd->setGeometry(QRect(20, 390, 41, 31));
        textd->setFont(font1);
        dis = new QLabel(frame);
        dis->setObjectName(QStringLiteral("dis"));
        dis->setGeometry(QRect(70, 390, 141, 31));
        dis->setFont(font1);
        intro = new QLabel(frame);
        intro->setObjectName(QStringLiteral("intro"));
        intro->setGeometry(QRect(10, 440, 201, 321));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(8);
        intro->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 17));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        text1->setText(QApplication::translate("MainWindow", " \345\223\210\345\260\224\346\273\250\345\267\245\344\270\232\345\244\247\345\255\246\357\274\210\345\250\201\346\265\267\357\274\211", Q_NULLPTR));
        text2->setText(QApplication::translate("MainWindow", "     \346\240\241\345\233\255\345\257\274\350\210\252\347\263\273\347\273\237", Q_NULLPTR));
        hitlogo->setText(QString());
        start->setText(QString());
        texts->setText(QApplication::translate("MainWindow", "\350\265\267\347\202\271\357\274\232", Q_NULLPTR));
        texte->setText(QApplication::translate("MainWindow", "\347\273\210\347\202\271\357\274\232", Q_NULLPTR));
        end->setText(QString());
        textd->setText(QApplication::translate("MainWindow", "\350\267\235\347\246\273\357\274\232", Q_NULLPTR));
        dis->setText(QString());
        intro->setText(QApplication::translate("MainWindow", "\345\223\210\345\260\224\346\273\250\345\267\245\344\270\232\345\244\247\345\255\246\346\230\257\344\270\200\346\211\200\346\234\211\347\235\200\350\277\221\347\231\276\345\271\264\345\216\206\345\217\262\343\200\201\344\270\226\347\225\214\347\237\245\345\220\215\347\232\204\345\267\245\347\247\221\345\274\272\346\240\241\357\274\214\345\267\245\347\250\213\345\255\246\345\234\250\345\205\250\347\220\203\346\216\222\345\220\215\347\254\254\345\205\255\343\200\202\345\223\210\345\267\245\345\244\247\346\230\257\346\210\221\345\233\275\351\246\226\346\211\271\345\205\245\351\200\211\345\233\275\345\256\266985\345\267\245\347\250\213\351\207\215\347\202\271\345\273\272\350\256\276\347\232\204\345\244\247\345\255\246\357\274\214\344\270\255\345\233\275C9\350\201\224\347\233\237\351\253\230\346\240\241\346\210\220\345\221\230\343\200\2022017\345\271\264\345\205\245\351\200\211\345\233\275\345\256\266\345\217\214\344\270\200\346\265\201\345\273\272\350\256\276 A\347\261\273\351\253\230\346\240\241\343\200\202 1985\345"
                        "\271\264\347\273\217\345\216\237\350\210\252\345\244\251\345\267\245\344\270\232\351\203\250\346\211\271\345\207\206\357\274\214\345\223\210\345\260\224\346\273\250\345\267\245\344\270\232\345\244\247\345\255\246\345\250\201\346\265\267\345\210\206\346\240\241\346\210\220\347\253\213\343\200\202\345\255\246\346\240\241\345\235\220\350\220\275\345\234\250\347\276\216\344\270\275\345\256\234\345\261\205\347\232\204\346\265\267\346\273\250\345\237\216\345\270\202\345\250\201\346\265\267\357\274\214\346\240\241\345\233\255\345\215\240\345\234\260\351\235\242\347\247\2571860\344\275\231\344\272\251\357\274\214\344\276\235\345\261\261\345\202\215\346\265\267\347\232\204\346\240\241\345\233\255\345\210\260\345\244\204\345\221\210\347\216\260\347\235\200\346\201\254\351\235\231\345\215\232\351\233\205\347\232\204\346\260\224\346\201\257\357\274\214\346\254\247\351\243\216\344\277\204\351\237\265\347\232\204\346\240\241\345\233\255\345\273\272\347\255\221\344\270\216\345\220\204\345\274\217\345\233\255\346\236\227\344\272"
                        "\244\347\233\270\350\276\211\346\230\240\357\274\214\345\257\223\346\204\217\347\235\200\345\223\210\345\267\245\345\244\247\346\226\207\345\214\226\345\234\250\345\250\201\346\265\267\347\232\204\344\274\240\346\211\277\344\270\216\345\210\233\346\226\260\343\200\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
