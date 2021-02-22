#include "mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    InitState();//初始化状态

    setWindows();//设置窗体
    setToolBar();//设置工具栏
    setBackgroud();//设置背景地图


}



MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if(startNavigtor){
        QPainter pen(this);
        pen.setRenderHint(QPainter::Antialiasing, true);
        QPen *p=new QPen("black");
        p->setWidth(6);
        pen.setPen(*p);

        for(int i=1;i<road.size();i++){
            pen.drawLine(data->getPosition(road[i-1]),data->getPosition(road[i]));
        }
    }

}



void MainWindow::SearchViewSpot()
{
    QString str = searchLE->text();
    int id = data->isExist(str);//获取地点id
    if(id == -1)//地点不存在
    {
        SearchFaild();
    }else{
        SearchSuccess(id);
    }
}

void MainWindow::setToolBar()
{
    //创建工具栏
    QToolBar *toolBar = addToolBar ("Tool");

    //组件初始化
    //地点输入框
    searchLE = new QLineEdit;
    //地点查询按钮
    Search = new QAction(this);
    Search->setText(tr("查询地点"));
    connect(Search,SIGNAL(triggered(bool)),this,SLOT(SearchViewSpot()));
    //起点下拉框
    startCB = new QComboBox;
    //指示箭头
    arrow = new QLabel(tr("—>"));
    //终点下拉框
    endCB = new QComboBox;
    //起点下拉框和终点下拉框选项
    QVector<QString> names = data->getNames();
    for(auto it:names){
        startCB->addItem(it);
        endCB->addItem(it);
    }
    //导航按钮
    Navigator = new QAction(this);
    Navigator->setText(tr("开始导航"));
    connect (Navigator, SIGNAL(triggered(bool)), this, SLOT(StartNavigation()));
    //重置按钮
    Back = new QAction(this);
    Back->setText(tr("撤销导航"));
    connect (Back, SIGNAL(triggered(bool)), this, SLOT(Reset()));
    //位置初始化
    toolBar->addWidget(searchLE);
    toolBar->addSeparator();
    toolBar->addAction(Search);
    toolBar->addSeparator();

    toolBar->addWidget(startCB);
    toolBar->addSeparator();
    toolBar->addWidget(arrow);
    toolBar->addSeparator();
    toolBar->addWidget (endCB);
    toolBar->addSeparator ();

    toolBar->addAction(Navigator);
    toolBar->addSeparator ();

    toolBar->addAction(Back);
    toolBar->addSeparator ();

}

void MainWindow::setBackgroud()
{
    this->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
                     QBrush(QPixmap(":/Map").scaled(this->size(),
                                                    Qt::IgnoreAspectRatio,
                                                    Qt::SmoothTransformation)));             // 使用平滑的缩放方式
    this->setPalette(palette);
}

void MainWindow::setWindows()
{
    setGeometry(300,300,800,800);
    this->setFixedSize(800,800);
}

void MainWindow::InitState()
{
    data = new Data;
    startNavigtor = false;
}

void MainWindow::SearchFaild()
{
    //TODO:地点不存在的处理
    qDebug()<<"地点不存在";
}

void MainWindow::SearchSuccess(int id)
{
    //展示地点信息
    ShowViewSpot(id);
}

void MainWindow::ShowViewSpot(int id)
{

    QPoint point = data->getPosition(id);

    QDialog *dialog = new QDialog;
    //QGridLayout *layout = new QGridLayout(dialog);
    QLabel *label = new QLabel(data->getInfo(id),dialog);
    dialog->setGeometry(point.x(),point.y(),188,188);
    dialog->setWindowTitle(data->getName(id));
    dialog->show();
}

void MainWindow::DrawRoad()
{
    startNavigtor = true;

    update();
}


void MainWindow::StartNavigation()
{
    QString startName = startCB->currentText();
    QString endName = endCB->currentText();

    road = data->getRoad(data->getId(startName),data->getId(endName));
    if(road.size()>=2)
    {

        DrawRoad();
    }

}

void MainWindow::Reset()
{
    startNavigtor = false;

    update();
}


