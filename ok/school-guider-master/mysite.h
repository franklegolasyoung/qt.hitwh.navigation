#ifndef MYSITE_H
#define MYSITE_H

#include <iostream>
#include <QString>
#include <QDebug>
using namespace std;

class mySite
{
public:
    mySite();
    void init(QString x,QString y,QString name,QString ins,QString pyin);
    QString getId();		//获取编号
    QString getX();			//获取横坐标
    QString getY();			//获取纵坐标
    QString getName();      //获取名字
    QString getPinyin();    //获取名字的拼音
    QString setId(QString );//设置编号
private:
    QString x;     //横坐标
    QString y;     //纵坐标
    QString id;    //编号
    QString pinYin; //拼音
    QString name;          //名称
    QString introduction;  //简介

    int static cnt;       //景点数目
};

#endif // MYSITE_H
