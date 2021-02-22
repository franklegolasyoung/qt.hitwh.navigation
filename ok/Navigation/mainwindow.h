#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mapwidget.h"
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

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createToolBar();
    void createAction();

public slots:

    void FindPath();
    void Clear();
private:
    MapWidget *mapWidget;
    QLabel *startLabel;
    QLabel *endLabel;
    QComboBox *startComboBox;
    QComboBox *endComboBox;
    QComboBox *reviseComboBox;

    QAction *findPathAction;
    QAction *clearAction;

    static QPoint getPosition(int id);
    static int getId(int x,int y);
    static QString getName(int id);



    MGraph mgraph;

protected:
    void mouseDoubleClickEvent (QMouseEvent *e);
    void paintEvent(QPaintEvent *event);
private:
    QPixmap pic;      //图书馆
    QString strPath;      //文件路径
    QLabel *label;

    bool Road;
    QVector<int> road;

    void CreateGraph();
    void InitMap();
    bool Calculate();
    void DrawRoad(QPainter& painter);
};

#endif // MAINWINDOW_H
















