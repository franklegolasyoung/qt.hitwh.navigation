/********************************************************************************
** Form generated from reading UI file 'loginbox.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINBOX_H
#define UI_LOGINBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginBox
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;
    QLabel *label_4;

    void setupUi(QWidget *LoginBox)
    {
        if (LoginBox->objectName().isEmpty())
            LoginBox->setObjectName(QStringLiteral("LoginBox"));
        LoginBox->resize(277, 432);
        verticalLayout = new QVBoxLayout(LoginBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(LoginBox);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(11, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(200, 200));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../image/index.jpg")));
        label_3->setScaledContents(true);

        horizontalLayout->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(12, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(LoginBox);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: 75 11pt \"Aharoni\";"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("font: 75 11pt \"Aharoni\";"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(LoginBox);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 3);

        verticalLayout_3->addLayout(horizontalLayout_4);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\226\260\345\256\213\344\275\223\";"));

        verticalLayout_3->addWidget(label_4);

        verticalLayout_3->setStretch(0, 2);
        verticalLayout_3->setStretch(1, 1);

        verticalLayout->addWidget(widget_3);


        retranslateUi(LoginBox);

        QMetaObject::connectSlotsByName(LoginBox);
    } // setupUi

    void retranslateUi(QWidget *LoginBox)
    {
        LoginBox->setWindowTitle(QApplication::translate("LoginBox", "Form", Q_NULLPTR));
        label_3->setText(QString());
        label->setText(QApplication::translate("LoginBox", "       \347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginBox", "       \345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("LoginBox", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("LoginBox", "\351\200\200\345\207\272", Q_NULLPTR));
        label_4->setText(QApplication::translate("LoginBox", "\351\273\230\350\256\244\347\224\250\346\210\267\345\220\215:123123 \351\273\230\350\256\244\345\257\206\347\240\201:123123", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginBox: public Ui_LoginBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINBOX_H
