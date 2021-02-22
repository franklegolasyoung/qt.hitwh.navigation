#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QWebEngineView>
namespace Ui {
class MapWidget;
}

class MapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MapWidget(QWidget *parent = nullptr);
    ~MapWidget();
    void setWeb(int num);
protected:
    void resizeEvent(QResizeEvent *);
private:
    Ui::MapWidget *ui;
    QWebEngineView* view;
};

#endif // MAPWIDGET_H
