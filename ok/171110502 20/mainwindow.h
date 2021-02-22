#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QAction>
#include <QToolBar>
#include <QPaintEvent>
#include <QPainter>
#include <QDialog>

#include "data.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);

public slots:

    void SearchViewSpot();
    void StartNavigation();
    void Reset();
private:

    QComboBox *startCB;//起点下拉框
    QLabel *arrow;//指示箭头
    QComboBox *endCB;//终点下拉框
    QLineEdit *searchLE;//查询地点输入框

    QAction *Navigator;//导航按钮
    QAction *Back;//撤销导航按钮
    QAction *Search;//查询地点按钮

    Data *data;//系统数据
    QVector<int> road;//导航路线

    bool startNavigtor;
protected:
    void setToolBar();
    void setBackgroud();
    void setWindows();
    void InitState();

    void SearchFaild();
    void SearchSuccess(int id);

    void ShowViewSpot(int id);

    void DrawRoad();

};

#endif // MAINWINDOW_H
















