#include "mapwidget.h"
#include "ui_mapwidget.h"

MapWidget::MapWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapWidget)
{
    ui->setupUi(this);

}
MapWidget::~MapWidget()
{
    delete ui;
}
void MapWidget::setWeb(int num){
    if(num==1){
        view = new QWebEngineView(this);
        view->load(QUrl("https://www.amap.com/"));
        view->show();
    }
    if(num==2){
        view = new QWebEngineView(this);
        view->load(QUrl("http://www.hitwh.edu.cn/"));
        view->show();
    }
}

void MapWidget::resizeEvent(QResizeEvent *)
{
    view->resize(this->size());
}
