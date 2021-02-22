#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QVector>
#include <QMouseEvent>
#include <QDialog>
#include <QPixmap>
#include <QGridLayout>
#include <QLineEdit>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QPoint>
#include <QPaintEvent>
#include "tool.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createToolBar();
    void createAction();
    int d;

public slots:
    void FindPath();
    void Clear();

private:
    Ui::MainWindow *ui;
    QLabel *startLabel;
    QLabel *endLabel;
    QComboBox *startComboBox;
    QComboBox *endComboBox;
    QAction *findPathAction;
    QAction *clearAction;

    static QPoint getPosition(int id);
    static int getId(int x,int y);
    static QString getName(int id);

    MGraph mgraph;
    MRoad r01,r08,r03,r13,r18,r37,r67,r38,r36,r68,r15,r58,r25,r29,r24,r45,r59,r49,r89,r410,r910,r810,r610;
    MRoad r[11][11];

protected:
    void mouseDoubleClickEvent (QMouseEvent *e);    //双击显示图片
    void paintEvent(QPaintEvent *event);   //画坐标点和路线
    void mousePressEvent(QMouseEvent *e);   //控制台显示坐标
    void keyPressEvent(QKeyEvent *event);   //enter键监测

private:
    QPixmap pic;      //介绍图
    QString strPath;      //文件路径
    QLabel *label;

    bool Road;
    QVector<int> road;

    void CreateGraph();
    int getRoad(int a[], int value, int low, int high);
    void InitMap();
    bool Calculate();
    void DrawRoad(QPainter& painter);
    bool ShortestPath(MGraph &G,int start,int end,QVector<int>& R);
};

#endif // MAINWINDOW_H

