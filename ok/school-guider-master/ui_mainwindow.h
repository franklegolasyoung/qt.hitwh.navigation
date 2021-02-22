/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_12;
    QTabWidget *tabWidget;
    QWidget *findData;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *tableWidgetFind;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QWidget *searchAll;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *tableWidgetAll;
    QListWidget *listWidgetAll;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_21;
    QComboBox *comboBox_21;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_22;
    QComboBox *comboBox_22;
    QPushButton *pushButton_21;
    QWidget *tab;
    QVBoxLayout *verticalLayout_11;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_5;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QWidget *searchBest;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidgetBest;
    QListWidget *listWidgetBest;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_32;
    QLabel *label_31;
    QComboBox *comboBox_32;
    QComboBox *comboBox_31;
    QPushButton *pushButton_31;
    QComboBox *comboBox_33;
    QWidget *searchLimit;
    QVBoxLayout *verticalLayout_9;
    QTableWidget *tableWidgetLimit;
    QListWidget *listWidgetLimit;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_41;
    QComboBox *comboBox_41;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_42;
    QComboBox *comboBox_42;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_43;
    QPushButton *pushButton_41;
    QLabel *label_4;
    QSpinBox *spinBox_41;
    QPushButton *pushButton_42;
    QWidget *dealSite;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidgetSite;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_51;
    QLineEdit *lineEdit_51;
    QHBoxLayout *horizontalLayout;
    QLabel *label_56;
    QLineEdit *lineEdit_52;
    QGridLayout *gridLayout_4;
    QLabel *label_52;
    QLabel *label_55;
    QLabel *label_54;
    QLabel *label_53;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_51;
    QPushButton *pushButton_52;
    QPushButton *pushButton_53;
    QWidget *dealRoad;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidgetRoad;
    QHBoxLayout *horizontalLayout_98;
    QLabel *label_61;
    QComboBox *comboBox_61;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_66;
    QComboBox *comboBox_62;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_61;
    QVBoxLayout *verticalLayout_34;
    QHBoxLayout *horizontalLayout_99;
    QPushButton *pushButton_63;
    QPushButton *pushButton_61;
    QPushButton *pushButton_62;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1007, 653);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(10000, 10000));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setScaledContents(true);

        horizontalLayout_6->addWidget(label);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_12 = new QHBoxLayout(widget_2);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        tabWidget = new QTabWidget(widget_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        findData = new QWidget();
        findData->setObjectName(QStringLiteral("findData"));
        verticalLayout_7 = new QVBoxLayout(findData);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        tableWidgetFind = new QTableWidget(findData);
        tableWidgetFind->setObjectName(QStringLiteral("tableWidgetFind"));
        tableWidgetFind->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableWidgetFind->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_7->addWidget(tableWidgetFind);

        pushButton_11 = new QPushButton(findData);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        verticalLayout_7->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(findData);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        verticalLayout_7->addWidget(pushButton_12);

        tabWidget->addTab(findData, QString());
        searchAll = new QWidget();
        searchAll->setObjectName(QStringLiteral("searchAll"));
        searchAll->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_10 = new QVBoxLayout(searchAll);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        tableWidgetAll = new QTableWidget(searchAll);
        tableWidgetAll->setObjectName(QStringLiteral("tableWidgetAll"));

        verticalLayout_8->addWidget(tableWidgetAll);

        verticalLayout_8->setStretch(0, 1);

        verticalLayout_10->addLayout(verticalLayout_8);

        listWidgetAll = new QListWidget(searchAll);
        listWidgetAll->setObjectName(QStringLiteral("listWidgetAll"));

        verticalLayout_10->addWidget(listWidgetAll);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_21 = new QLabel(searchAll);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_4->addWidget(label_21);

        comboBox_21 = new QComboBox(searchAll);
        comboBox_21->setObjectName(QStringLiteral("comboBox_21"));

        horizontalLayout_4->addWidget(comboBox_21);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_22 = new QLabel(searchAll);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_5->addWidget(label_22);

        comboBox_22 = new QComboBox(searchAll);
        comboBox_22->setObjectName(QStringLiteral("comboBox_22"));

        horizontalLayout_5->addWidget(comboBox_22);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        pushButton_21 = new QPushButton(searchAll);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));

        gridLayout->addWidget(pushButton_21, 0, 1, 1, 1);


        verticalLayout_10->addLayout(gridLayout);

        tabWidget->addTab(searchAll, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_11 = new QVBoxLayout(tab);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        listWidget = new QListWidget(tab);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_11->addWidget(listWidget);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("font: 75 11pt \"Aharoni\";"));

        horizontalLayout_13->addWidget(label_5);

        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_13->addWidget(comboBox);

        horizontalLayout_13->setStretch(0, 1);
        horizontalLayout_13->setStretch(1, 2);

        verticalLayout_11->addLayout(horizontalLayout_13);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_11->addWidget(pushButton);

        tabWidget->addTab(tab, QString());
        searchBest = new QWidget();
        searchBest->setObjectName(QStringLiteral("searchBest"));
        verticalLayout_2 = new QVBoxLayout(searchBest);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableWidgetBest = new QTableWidget(searchBest);
        tableWidgetBest->setObjectName(QStringLiteral("tableWidgetBest"));

        verticalLayout_2->addWidget(tableWidgetBest);

        listWidgetBest = new QListWidget(searchBest);
        listWidgetBest->setObjectName(QStringLiteral("listWidgetBest"));

        verticalLayout_2->addWidget(listWidgetBest);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_32 = new QLabel(searchBest);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_2->addWidget(label_32, 1, 0, 1, 1);

        label_31 = new QLabel(searchBest);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_2->addWidget(label_31, 0, 0, 1, 1);

        comboBox_32 = new QComboBox(searchBest);
        comboBox_32->setObjectName(QStringLiteral("comboBox_32"));

        gridLayout_2->addWidget(comboBox_32, 1, 1, 1, 1);

        comboBox_31 = new QComboBox(searchBest);
        comboBox_31->setObjectName(QStringLiteral("comboBox_31"));

        gridLayout_2->addWidget(comboBox_31, 0, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 2);

        horizontalLayout_2->addLayout(gridLayout_2);

        pushButton_31 = new QPushButton(searchBest);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));

        horizontalLayout_2->addWidget(pushButton_31);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        comboBox_33 = new QComboBox(searchBest);
        comboBox_33->setObjectName(QStringLiteral("comboBox_33"));

        verticalLayout_2->addWidget(comboBox_33);

        tabWidget->addTab(searchBest, QString());
        searchLimit = new QWidget();
        searchLimit->setObjectName(QStringLiteral("searchLimit"));
        verticalLayout_9 = new QVBoxLayout(searchLimit);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        tableWidgetLimit = new QTableWidget(searchLimit);
        tableWidgetLimit->setObjectName(QStringLiteral("tableWidgetLimit"));

        verticalLayout_9->addWidget(tableWidgetLimit);

        listWidgetLimit = new QListWidget(searchLimit);
        listWidgetLimit->setObjectName(QStringLiteral("listWidgetLimit"));

        verticalLayout_9->addWidget(listWidgetLimit);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_41 = new QLabel(searchLimit);
        label_41->setObjectName(QStringLiteral("label_41"));

        horizontalLayout_8->addWidget(label_41);

        comboBox_41 = new QComboBox(searchLimit);
        comboBox_41->setObjectName(QStringLiteral("comboBox_41"));

        horizontalLayout_8->addWidget(comboBox_41);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_42 = new QLabel(searchLimit);
        label_42->setObjectName(QStringLiteral("label_42"));

        horizontalLayout_9->addWidget(label_42);

        comboBox_42 = new QComboBox(searchLimit);
        comboBox_42->setObjectName(QStringLiteral("comboBox_42"));

        horizontalLayout_9->addWidget(comboBox_42);


        verticalLayout_3->addLayout(horizontalLayout_9);


        verticalLayout_9->addLayout(verticalLayout_3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_3 = new QLabel(searchLimit);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        comboBox_43 = new QComboBox(searchLimit);
        comboBox_43->setObjectName(QStringLiteral("comboBox_43"));

        gridLayout_3->addWidget(comboBox_43, 0, 1, 1, 1);

        pushButton_41 = new QPushButton(searchLimit);
        pushButton_41->setObjectName(QStringLiteral("pushButton_41"));

        gridLayout_3->addWidget(pushButton_41, 0, 2, 1, 1);

        label_4 = new QLabel(searchLimit);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        spinBox_41 = new QSpinBox(searchLimit);
        spinBox_41->setObjectName(QStringLiteral("spinBox_41"));

        gridLayout_3->addWidget(spinBox_41, 1, 1, 1, 1);

        pushButton_42 = new QPushButton(searchLimit);
        pushButton_42->setObjectName(QStringLiteral("pushButton_42"));

        gridLayout_3->addWidget(pushButton_42, 1, 2, 1, 1);


        verticalLayout_9->addLayout(gridLayout_3);

        tabWidget->addTab(searchLimit, QString());
        dealSite = new QWidget();
        dealSite->setObjectName(QStringLiteral("dealSite"));
        verticalLayout_5 = new QVBoxLayout(dealSite);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tableWidgetSite = new QTableWidget(dealSite);
        tableWidgetSite->setObjectName(QStringLiteral("tableWidgetSite"));

        verticalLayout_5->addWidget(tableWidgetSite);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_51 = new QLabel(dealSite);
        label_51->setObjectName(QStringLiteral("label_51"));

        horizontalLayout_10->addWidget(label_51);

        lineEdit_51 = new QLineEdit(dealSite);
        lineEdit_51->setObjectName(QStringLiteral("lineEdit_51"));

        horizontalLayout_10->addWidget(lineEdit_51);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 1);

        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_56 = new QLabel(dealSite);
        label_56->setObjectName(QStringLiteral("label_56"));

        horizontalLayout->addWidget(label_56);

        lineEdit_52 = new QLineEdit(dealSite);
        lineEdit_52->setObjectName(QStringLiteral("lineEdit_52"));

        horizontalLayout->addWidget(lineEdit_52);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_5->addLayout(horizontalLayout);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_52 = new QLabel(dealSite);
        label_52->setObjectName(QStringLiteral("label_52"));

        gridLayout_4->addWidget(label_52, 0, 0, 1, 1);

        label_55 = new QLabel(dealSite);
        label_55->setObjectName(QStringLiteral("label_55"));

        gridLayout_4->addWidget(label_55, 1, 0, 1, 1);

        label_54 = new QLabel(dealSite);
        label_54->setObjectName(QStringLiteral("label_54"));

        gridLayout_4->addWidget(label_54, 1, 1, 1, 1);

        label_53 = new QLabel(dealSite);
        label_53->setObjectName(QStringLiteral("label_53"));

        gridLayout_4->addWidget(label_53, 0, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_4);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        pushButton_51 = new QPushButton(dealSite);
        pushButton_51->setObjectName(QStringLiteral("pushButton_51"));

        horizontalLayout_11->addWidget(pushButton_51);

        pushButton_52 = new QPushButton(dealSite);
        pushButton_52->setObjectName(QStringLiteral("pushButton_52"));

        horizontalLayout_11->addWidget(pushButton_52);

        pushButton_53 = new QPushButton(dealSite);
        pushButton_53->setObjectName(QStringLiteral("pushButton_53"));

        horizontalLayout_11->addWidget(pushButton_53);


        verticalLayout_5->addLayout(horizontalLayout_11);

        tabWidget->addTab(dealSite, QString());
        dealRoad = new QWidget();
        dealRoad->setObjectName(QStringLiteral("dealRoad"));
        verticalLayout_6 = new QVBoxLayout(dealRoad);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        tableWidgetRoad = new QTableWidget(dealRoad);
        tableWidgetRoad->setObjectName(QStringLiteral("tableWidgetRoad"));

        verticalLayout_6->addWidget(tableWidgetRoad);

        horizontalLayout_98 = new QHBoxLayout();
        horizontalLayout_98->setSpacing(6);
        horizontalLayout_98->setObjectName(QStringLiteral("horizontalLayout_98"));
        label_61 = new QLabel(dealRoad);
        label_61->setObjectName(QStringLiteral("label_61"));

        horizontalLayout_98->addWidget(label_61);

        comboBox_61 = new QComboBox(dealRoad);
        comboBox_61->setObjectName(QStringLiteral("comboBox_61"));

        horizontalLayout_98->addWidget(comboBox_61);


        verticalLayout_6->addLayout(horizontalLayout_98);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_66 = new QLabel(dealRoad);
        label_66->setObjectName(QStringLiteral("label_66"));

        horizontalLayout_7->addWidget(label_66);

        comboBox_62 = new QComboBox(dealRoad);
        comboBox_62->setObjectName(QStringLiteral("comboBox_62"));

        horizontalLayout_7->addWidget(comboBox_62);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(dealRoad);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_61 = new QLineEdit(dealRoad);
        lineEdit_61->setObjectName(QStringLiteral("lineEdit_61"));

        horizontalLayout_3->addWidget(lineEdit_61);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout_3);

        verticalLayout_34 = new QVBoxLayout();
        verticalLayout_34->setSpacing(6);
        verticalLayout_34->setObjectName(QStringLiteral("verticalLayout_34"));
        horizontalLayout_99 = new QHBoxLayout();
        horizontalLayout_99->setSpacing(6);
        horizontalLayout_99->setObjectName(QStringLiteral("horizontalLayout_99"));
        pushButton_63 = new QPushButton(dealRoad);
        pushButton_63->setObjectName(QStringLiteral("pushButton_63"));

        horizontalLayout_99->addWidget(pushButton_63);

        pushButton_61 = new QPushButton(dealRoad);
        pushButton_61->setObjectName(QStringLiteral("pushButton_61"));

        horizontalLayout_99->addWidget(pushButton_61);

        pushButton_62 = new QPushButton(dealRoad);
        pushButton_62->setObjectName(QStringLiteral("pushButton_62"));

        horizontalLayout_99->addWidget(pushButton_62);


        verticalLayout_34->addLayout(horizontalLayout_99);


        verticalLayout_6->addLayout(verticalLayout_34);

        tabWidget->addTab(dealRoad, QString());

        horizontalLayout_12->addWidget(tabWidget);


        horizontalLayout_6->addWidget(widget_2);

        horizontalLayout_6->setStretch(0, 2);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_4->addWidget(widget);

        verticalLayout_4->setStretch(0, 2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1007, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QString());
        pushButton_11->setText(QApplication::translate("MainWindow", "\346\214\211\347\205\247\345\255\227\345\205\270\345\272\217\346\237\245\346\211\276", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", "\346\214\211\347\205\247\347\274\226\345\217\267\346\237\245\346\211\276", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(findData), QApplication::translate("MainWindow", "\346\237\245\350\257\242\346\211\200\346\234\211\344\277\241\346\201\257", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "\350\265\267\345\247\213\347\202\271", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "\347\233\256\347\232\204\345\234\260", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("MainWindow", "\346\217\220\344\272\244", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(searchAll), QApplication::translate("MainWindow", "\346\211\200\346\234\211\350\267\257\345\276\204", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "    \350\265\267\345\247\213\347\202\271\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\346\217\220\344\272\244", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\345\215\225\346\272\220\346\234\200\347\237\255\350\267\257\345\276\204", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindow", "\347\233\256\347\232\204\345\234\260", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "\350\265\267\345\247\213\347\202\271", Q_NULLPTR));
        pushButton_31->setText(QApplication::translate("MainWindow", "\346\217\220\344\272\244", Q_NULLPTR));
        comboBox_33->clear();
        comboBox_33->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\234\200\344\274\230\350\267\235\347\246\273\350\267\257\345\276\204", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\234\200\344\274\230\346\227\266\351\227\264\350\267\257\345\276\204", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(searchBest), QApplication::translate("MainWindow", "\346\234\200\344\274\230\350\267\257\345\276\204", Q_NULLPTR));
        label_41->setText(QApplication::translate("MainWindow", "\350\265\267\345\247\213\347\202\271", Q_NULLPTR));
        label_42->setText(QApplication::translate("MainWindow", "\347\233\256\347\232\204\345\234\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\351\231\220\345\256\232\345\207\272\350\241\214\346\226\271\345\274\217", Q_NULLPTR));
        comboBox_43->clear();
        comboBox_43->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\255\245\350\241\214", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\240\241\345\206\205\345\205\254\344\272\244", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\205\261\344\272\253\345\215\225\350\275\246", Q_NULLPTR)
        );
        pushButton_41->setText(QApplication::translate("MainWindow", "\346\217\220\344\272\244", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\351\231\220\345\256\232\345\207\272\350\241\214\346\227\266\351\227\264", Q_NULLPTR));
        pushButton_42->setText(QApplication::translate("MainWindow", "\346\217\220\344\272\244", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(searchLimit), QApplication::translate("MainWindow", "\351\231\220\345\256\232\350\267\257\345\276\204", Q_NULLPTR));
        label_51->setText(QApplication::translate("MainWindow", "    \346\231\257\347\202\271\345\220\215\347\247\260\357\274\232 ", Q_NULLPTR));
        label_56->setText(QApplication::translate("MainWindow", "    \346\231\257\347\202\271\345\220\215\347\247\260\346\213\274\351\237\263\357\274\232", Q_NULLPTR));
        label_52->setText(QApplication::translate("MainWindow", "    X\350\275\264\345\235\220\346\240\207\357\274\232", Q_NULLPTR));
        label_55->setText(QApplication::translate("MainWindow", "    Y\350\275\264\345\235\220\346\240\207\357\274\232", Q_NULLPTR));
        label_54->setText(QApplication::translate("MainWindow", "\347\202\271\345\207\273\345\233\276\350\216\267\345\217\226", Q_NULLPTR));
        label_53->setText(QApplication::translate("MainWindow", "\347\202\271\345\207\273\345\233\276\350\216\267\345\217\226", Q_NULLPTR));
        pushButton_51->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        pushButton_52->setText(QApplication::translate("MainWindow", "Del", Q_NULLPTR));
        pushButton_53->setText(QApplication::translate("MainWindow", "Uppdate", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(dealSite), QApplication::translate("MainWindow", "\346\223\215\344\275\234\346\231\257\347\202\271", Q_NULLPTR));
        label_61->setText(QApplication::translate("MainWindow", "    \351\201\223\350\267\257\350\265\267\345\247\213\347\202\271\357\274\232", Q_NULLPTR));
        label_66->setText(QApplication::translate("MainWindow", "    \351\201\223\350\267\257\347\273\210\346\255\242\347\202\271\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "      \350\267\257\345\276\204\351\225\277\345\272\246\357\274\232", Q_NULLPTR));
        pushButton_63->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        pushButton_61->setText(QApplication::translate("MainWindow", "Del", Q_NULLPTR));
        pushButton_62->setText(QApplication::translate("MainWindow", "Uppdate", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(dealRoad), QApplication::translate("MainWindow", "\346\223\215\344\275\234\351\201\223\350\267\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
