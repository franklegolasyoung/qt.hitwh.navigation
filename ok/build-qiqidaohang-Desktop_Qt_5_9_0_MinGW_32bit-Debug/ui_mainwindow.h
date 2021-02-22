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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *lujing_button;
    QComboBox *comboBox_4;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(924, 487);
        MainWindow->setMinimumSize(QSize(924, 487));
        MainWindow->setMaximumSize(QSize(924, 487));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 601, 341));
        label->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(760, 0, 171, 581));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(232, 232, 232);"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 20, 75, 23));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 70, 75, 23));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(40, 150, 101, 22));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 110, 51, 41));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 180, 51, 31));
        lujing_button = new QPushButton(widget);
        lujing_button->setObjectName(QStringLiteral("lujing_button"));
        lujing_button->setGeometry(QRect(50, 270, 81, 23));
        comboBox_4 = new QComboBox(widget);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(40, 210, 101, 22));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(50, 320, 75, 23));
        pushButton->raise();
        pushButton_2->raise();
        label_2->raise();
        label_3->raise();
        lujing_button->raise();
        comboBox->raise();
        comboBox_4->raise();
        pushButton_3->raise();
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 924, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\344\270\255\345\233\275\347\237\263\346\262\271\345\244\247\345\255\246\346\240\241\345\233\255\345\257\274\350\210\252\347\263\273\347\273\237", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247\345\234\260\345\233\276", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217\345\234\260\345\233\276", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\214\227\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\234\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\245\277\345\214\227\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\267\245\347\247\221A\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\267\245\347\247\221B\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\267\245\347\247\221C\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\267\245\347\247\221D\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\267\245\347\247\221E\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\240\241\345\214\273\351\231\242", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\275\223\350\202\262\351\246\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\275\223\350\202\262\345\234\272", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\234\347\216\257 \350\256\262\345\240\202\347\276\244", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\245\277\347\216\257 \350\256\262\345\240\202\347\276\244", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\345\240\202", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\233\276\344\271\246\351\246\206\350\241\214\346\224\277\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\237\272\347\241\200\345\256\236\351\252\214\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\244\232\345\252\222\344\275\223\344\270\255\345\277\203", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\211\271\347\247\215\345\256\236\351\252\214\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\346\225\231\345\214\227\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\346\225\231\345\215\227\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\346\225\231\350\245\277\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\346\225\231\344\270\234\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\226\207\347\220\206\346\245\274\350\245\277\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\226\207\347\220\206\346\245\274\344\270\234\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\225\231\345\237\271\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\215\237\350\220\203\350\213\221\351\244\220\345\216\205", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\224\220\345\262\233\346\271\276\351\244\220\345\216\205", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\216\211\345\205\260\350\213\221\351\244\220\345\216\205", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "5\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "10\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "11\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "12\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "13\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "14\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "15\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "16\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "17\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "18\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "19\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\240\224\344\270\200\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\240\224\344\272\214\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\240\224\344\270\211\345\205\254\345\257\223", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\350\265\267\347\202\271", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\347\273\210\347\202\271", Q_NULLPTR));
        lujing_button->setText(QApplication::translate("MainWindow", "\350\267\257\345\276\204\350\247\204\345\210\222", Q_NULLPTR));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\215\227\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\214\227\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\234\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\245\277\345\214\227\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\267\245\347\247\221A\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\267\245\347\247\221B\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\267\245\347\247\221C\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\267\245\347\247\221D\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\267\245\347\247\221E\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\240\241\345\214\273\351\231\242", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\275\223\350\202\262\351\246\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\275\223\350\202\262\345\234\272", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\234\347\216\257 \350\256\262\345\240\202\347\276\244", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\245\277\347\216\257 \350\256\262\345\240\202\347\276\244", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\345\240\202", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\233\276\344\271\246\351\246\206\350\241\214\346\224\277\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\237\272\347\241\200\345\256\236\351\252\214\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\244\232\345\252\222\344\275\223\344\270\255\345\277\203", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\211\271\347\247\215\345\256\236\351\252\214\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\346\225\231\345\214\227\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\346\225\231\345\215\227\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\346\225\231\350\245\277\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\346\225\231\344\270\234\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\226\207\347\220\206\346\245\274\350\245\277\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\226\207\347\220\206\346\245\274\344\270\234\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\225\231\345\237\271\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\215\237\350\220\203\350\213\221\351\244\220\345\216\205", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\224\220\345\262\233\346\271\276\351\244\220\345\216\205", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\216\211\345\205\260\350\213\221\351\244\220\345\216\205", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "5\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "10\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "11\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "12\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "13\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "14\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "15\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "16\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "17\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "18\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "19\345\217\267\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\240\224\344\270\200\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\240\224\344\272\214\345\205\254\345\257\223", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\240\224\344\270\211\345\205\254\345\257\223", Q_NULLPTR)
        );
        pushButton_3->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\350\267\257\345\276\204", Q_NULLPTR));
        menu->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
