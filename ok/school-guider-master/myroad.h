#ifndef MYROAD_H
#define MYROAD_H

#include<iostream>
#include<QString>
using namespace std;

class myRoad
{
public:
    myRoad();
    void init(int s,int e,int w);
    int getBeginSite();
    int getEndSite();
    int getDistance();
private:
    int beginSite;
    int endSite;
    int distance;
};

#endif // MYROAD_H
