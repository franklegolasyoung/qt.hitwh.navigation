#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <fstream>
#include <QMainWindow>
#include <QWidget>
#include <QList>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QListWidgetItem>
#include <QLabel>
#include "mysite.h"
#include "myroad.h"
#include "mydialog.h"

const int MAX = 999999;
const float BusSpeed = 10.0;
const float BikeSpeed = 5.0;
const float WalkSpeed = 1.0;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initMap();      //初始化地图
    void initPath();     //初始化path
    void initDownBox();  //初始化下拉框
    void initUiweidget(); //初始化ui容器
    void initSite();     //设置初始化景点
    void initWeight();   //设置初始化权重(距离，时间)

    void FindData_1();   //查询各景点相关信息
    void FindData_2();     //查询各景点的相关信息
    void SearchAll();    //所有路径
    void SearchBest();   //最优路径
    void SearchLimit();  //限定路径

    void SearchDis();    //距离最短
    void SearchTime();   //时间最少

    void SearchLimitTime();//限定时间
    void SearchLimitTool();//限定交通工具

    void AddSite();          //新增景点
    void DeleSite();         //删除景点
    void UpdateSite();       //更新景点

    void AddRoad();		//新增道路
    void DeleRoad();	//删除道路
    void UpdateRoad();	//更新道路

    int Search(QString);          //顺序查找
    QString BinSearch(int key);        //二分查找
    QString HashSearch(int key);   //哈希查找
    void HashCreate(int id);       //创建哈希表

    void QSort(int,int);		       //快排
    void MSort(int l,int mid,int r);   //归并排序
    void MergeSort(int l,int r);       //归并排序

    void DFS(int s,int e);  //DFS(图的遍历 )
    void Floyd();
    void Dijkstra(int source);
    void Dijk();


    void SaveData();     //保存到文件
    void LoadData();     //从文件中提取
    void SaveObject();   //将对象数组保存到文件
    void LoadObject();   //从文件中读取对象数组
protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *mouse);

private slots:
    void on_pushButton_21_clicked();

private:
    Ui::MainWindow *ui;
    myDialog mylog;
    QLabel label;

    int start,end;       //起始点，终止点
    float speed;

    int dis[100][100];   //最短距离
    int map[100][100];   //地图
    int path[100][100];  //记录路径

    mySite site[100];   //景点类
    myRoad road[100];   //道路类

    mySite tep[100];
    mySite s[100];

    mySite hash[100];

    static int cnt;
    static int cntRoad;
};

#endif // MAINWINDOW_H
