/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_welcome
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *hitlogo;

    void setupUi(QWidget *welcome)
    {
        if (welcome->objectName().isEmpty())
            welcome->setObjectName(QStringLiteral("welcome"));
        welcome->resize(400, 300);
        welcome->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255)"));
        label = new QLabel(welcome);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 70, 351, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(welcome);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 160, 351, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(welcome);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 200, 351, 31));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(welcome);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 260, 351, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setWeight(50);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);
        hitlogo = new QLabel(welcome);
        hitlogo->setObjectName(QStringLiteral("hitlogo"));
        hitlogo->setGeometry(QRect(10, 10, 111, 101));
        hitlogo->setStyleSheet(QStringLiteral("image: url(:/hit);"));

        retranslateUi(welcome);

        QMetaObject::connectSlotsByName(welcome);
    } // setupUi

    void retranslateUi(QWidget *welcome)
    {
        welcome->setWindowTitle(QApplication::translate("welcome", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("welcome", "\346\254\242\350\277\216\344\275\277\347\224\250", Q_NULLPTR));
        label_2->setText(QApplication::translate("welcome", "\345\223\210\345\260\224\346\273\250\345\267\245\344\270\232\345\244\247\345\255\246\357\274\210\345\250\201\346\265\267\357\274\211", Q_NULLPTR));
        label_3->setText(QApplication::translate("welcome", "\346\240\241\345\233\255\345\257\274\350\210\252\347\263\273\347\273\237", Q_NULLPTR));
        label_4->setText(QApplication::translate("welcome", "Designed by Frank Young", Q_NULLPTR));
        hitlogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class welcome: public Ui_welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
