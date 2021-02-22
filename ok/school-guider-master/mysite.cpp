#include "mysite.h"

int mySite::cnt = 0;

mySite::mySite()
{
    this->id = "";
    this->x = "";
    this->y = "";
    this->name = "";
    this->pinYin = "";
}

void mySite::init(QString x,QString y,QString name,QString ins,QString pyin)
{
    cnt++;
    int i = cnt;
    this->id = QString::number(i);
    this->x = x;
    this->y = y;
    this->name = name;
    this->introduction = ins;
    this->pinYin = pyin;
}

QString mySite::getX()
{
    return this->x;
}

QString mySite::getY()
{
    return this->y;
}

QString mySite::getId()
{
    return this->id;
}

QString mySite::getName()
{
    return this->name;
}


QString mySite::getPinyin()
{
    return this->pinYin;
}

QString mySite::setId(QString Id)
{
    return this->id = Id;
}
