#ifndef DATA_H
#define DATA_H

#include "viewspot.h"
#include <QVector>
#include <QMap>
#include <QString>
#include <QFile>
#include <QTextStream>
class Data
{
private:
    int ViewSpotNum = 16;//地点数量
    static const int ViewSpotNumMAX = 16;
    static const int INF = 1e9;//距离最大值
    struct _map{
        int vertexs[ViewSpotNumMAX];//顶点集合
        int arcs[ViewSpotNumMAX][ViewSpotNumMAX];
        int vern;//顶点数
        int arcn;//边数
    };
    typedef _map Map;

public:
    Data();
    int getId(QString name)const;//通过地点名获取地点id
    QString getName(int id)const;//通过地点id获取地点名
    ViewSpot getById(int id)const;//通过地点id获取地点信息
    ViewSpot getByName(QString name)const;//通过地点名称获取地点信息

    int getViewSpotNum()const;//获取景点数量
    int isExist(QString name)const;//根据名称判断景点是否存在，如果存在返回景点id（非负数），如果不存在，返回-1
    QVector<QString> getNames()const;//获取所有景点名

    QVector<int> getRoad(int startId,int endId);//根据起点和终点id获取最短路径
    QPoint getPosition(int id)const;//根据id获取位置
    QString getInfo(int id)const;//根据id获取信息
private:
    QVector<ViewSpot> viewSpots;//景点数据
    QMap<QString,int> record;//景点名称与id的映射

    Map map;//景点连接关系记录

    int Road[ViewSpotNumMAX][ViewSpotNumMAX];//Road[i][j]表示i和j点间最短路径上的前驱节点

    void Init();
    void calculate();//计算任意两点间的最短路径
    void ReadData(QString file);//从文件中读取数据
};



#endif // DATA_H
