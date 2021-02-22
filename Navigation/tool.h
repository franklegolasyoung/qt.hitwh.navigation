#ifndef TOOL_H
#define TOOL_H
#include<iostream>
#include<QVector>
#include"cstring"
#include"mainwindow.h"
using namespace std;

#define MAX_VERTEX_NUM 20  // 顶点数量上限
#define MAX_ROAD_NUM 7  // 路边权点上限
static const int INF = 99999999;

class MGraph{
public:
    int vertex[MAX_VERTEX_NUM];                           //顶点集合
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];             //临接矩阵
    int verNum;                                           //顶点数
    int arcNum;                                           //边数
};

class MRoad{
public:
    int vertex[MAX_ROAD_NUM][2];                          //路线点集合
    int verNum;                                           //点数
};

template<class T>class Vectory:public QVector<T>{
public:
    virtual void push_back(T &&t){
        append(std::move(t));
        cout << t << endl;
    }
    virtual void push_front(const T &t){
        prepend(t);
        cout << t << endl;
    }
};

#endif // TOOL_H
