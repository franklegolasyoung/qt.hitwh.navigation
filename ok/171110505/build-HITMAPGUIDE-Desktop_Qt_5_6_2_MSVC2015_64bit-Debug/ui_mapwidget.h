/********************************************************************************
** Form generated from reading UI file 'mapwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWIDGET_H
#define UI_MAPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWidget
{
public:

    void setupUi(QWidget *MapWidget)
    {
        if (MapWidget->objectName().isEmpty())
            MapWidget->setObjectName(QStringLiteral("MapWidget"));
        MapWidget->resize(687, 475);

        retranslateUi(MapWidget);

        QMetaObject::connectSlotsByName(MapWidget);
    } // setupUi

    void retranslateUi(QWidget *MapWidget)
    {
        MapWidget->setWindowTitle(QApplication::translate("MapWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class MapWidget: public Ui_MapWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWIDGET_H
