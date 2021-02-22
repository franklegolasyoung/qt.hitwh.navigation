#ifndef VIEWSPOT_H
#define VIEWSPOT_H

#include<QPoint>
#include<QString>

//景点类
class ViewSpot
{
public:
    ViewSpot();
    ViewSpot(int id,const QPoint& point,const QString& info);

    QPoint getLocation()const;
    QString getInfo()const;
    int getId()const;
    void setLocation(const QPoint& point);
    void setInfo(const QString& info);
private:
    QPoint location;//景点位置
    QString info;//景点信息
    int id;//景点id，唯一值
};

#endif // VIEWSPOT_H
