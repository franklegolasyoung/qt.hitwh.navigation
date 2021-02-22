#include "viewspot.h"

ViewSpot::ViewSpot()
{

}

ViewSpot::ViewSpot(int id, const QPoint &point, const QString &info)
{
    this->id = id;
    this->location = point;
    this->info = info;
}

QPoint ViewSpot::getLocation() const
{
    return location;
}

QString ViewSpot::getInfo() const
{
    return info;
}

int ViewSpot::getId() const
{
    return this->id;
}

void ViewSpot::setLocation(const QPoint &point)
{
    this->location = point;
}

void ViewSpot::setInfo(const QString &info)
{
    this->info = info;
}
