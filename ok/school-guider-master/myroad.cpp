#include "myroad.h"

myRoad::myRoad()
{
    this->beginSite = 0;
    this->endSite = 0;
    this->distance = 0;
}

void myRoad::init(int s,int e,int w)
{
    this->beginSite = s;
    this->endSite = e;
    this->distance = w;
}

int myRoad::getBeginSite()
{
   return this->beginSite;
}

int myRoad::getEndSite()
{
    return this->endSite;
}

int myRoad::getDistance()
{
    return this->distance;
}
