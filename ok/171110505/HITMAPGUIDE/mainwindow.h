#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mapwidget.h"
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
QT_BEGIN_NAMESPACE
class QWheelEvent;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createToolBar();
    void createAction();
    void setStart(int X, int Y);
    void setEnd(int X, int Y);
    void setNextPos (int index);
    void initScene();
    void mouseMoveEvent (QMouseEvent *event);

    // 放大/缩小
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
    void magnify();
    void shrink();
    void scaling(qreal scaleFactor);


    // 平移
    //void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    //void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    //void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

   // void translate(QPointF delta);  // 平移


public slots:
    void news1show();
    void news2show();
    void setStartFrome();
    void setEndFrome();
    void setStartStation();
    void setEndStation();
    void FindPath();
    void Clear();
    void Revise();
    void callOtherMap();
    void callMorenews();
    void ShowDialog();
private:
     int num=-1;
     int num2=-1;
     MapWidget *mapWidget;

    //Qt::MouseButton m_translateButton;  // 平移按钮
    //qreal m_translateSpeed;  // 平移速度
    //bool m_bMouseTranslate;  // 平移标识
     //QPoint m_lastMousePos;  // 鼠标最后按下的位置

    //滚动字幕
    void showTicker();

    int m_curIndex;
    QLabel *m_label;
    QString m_showText;

    int m_curIndex1;
    QLabel *m_label1;
    QString m_showText1;

    QLabel *sceneCoord;

    QLabel *startLabel;
    QLabel *endLabel;
    QComboBox *startComboBox;
    QComboBox *endComboBox;
    QComboBox *reviseComboBox;

    QAction *findPathAction;
    QAction *clearAction;
    QAction *reviseAction;
    QAction *callMap;

    QGraphicsScene *scene;
    QGraphicsView *view;

    int startX, startY, endX, endY;
    QVector<int> nextPath;


     // 图的实现，和最短路径算法声明

    struct ArcCell{    //弧信息
        int adj;       //对无权图有1，0表示是否相邻，对带权图，则为权值类型
    };


    //内部类
    static const int MAX_VERTEX_NUM = 92;
    static const int INF = 999999;
    static const int M=1000; //定义哈希表最大长度
    static const int P=1000; //保留余数法的除数

    struct MGraph{
        QVector<int> vexs;                                    //顶点集合
        //临接矩阵
        ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
        int vexnum;                                           //顶点数
        int arcnum;//边数
        int bignum;//建筑数量
    };
    class DijkstraFindPath
    {
    public:
        DijkstraFindPath();
        MGraph mgraph;
        void CreateGraph();

        int prev[MAX_VERTEX_NUM];  //最短路上的前驱顶点
        int d[MAX_VERTEX_NUM];     //表示边e = (u,v)的权值(不存在时为INF,不过d[i][i]=0)
        bool used[MAX_VERTEX_NUM]; //已经使用过的图
        void dijkstra(int startPos);      //求从起点startPos出发到各个顶点的最短距离
        QVector<int> get_Path(int endPos);//到顶点endPos的最短路
    };

    //hash
    typedef struct node
    {
        int key; //关键字
        int count; //探查次数
        QString pixAdress;//图片路径
        QString txtAdress;//介绍文档路径
    }HashTable[M];

    class hashType
    {
    public:
        hashType();
        HashTable ha;
        void Creat_HT(HashTable ha,int A[],int n);
        int Delete_HT(HashTable ha,int k);
        void Insert_HT(HashTable ha,int k);
        int Search_HT(HashTable ha,int k);
        int len=30,m=0; //哈希表的长度和元素个数
        int A[M]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30},n=30;
    };
    hashType *hash;
    DijkstraFindPath *dj;

//鼠标事件
protected:
    void mouseDoubleClickEvent (QMouseEvent *e);
private:
    QPixmap pix;      //图片
    QString strPath;      //图片文件路径
    QString txtPath;
    QLabel *label;
    qreal m_scale; // 缩放值
    qreal m_scalingOffset;


};

#endif // MAINWINDOW_H
















