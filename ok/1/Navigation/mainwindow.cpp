#include "mainwindow.h"
#include <qdebug.h>
#include <QToolBar>
#include <QtAlgorithms>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle ("哈工大校园导航系统");
    createAction ();
    createToolBar ();           //实现一个工具栏
    setGeometry(300,50,800,800);
    this->setFixedSize(800,800);

    this->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
                     QBrush(QPixmap(":/Map").scaled(this->size(),
                                                    Qt::IgnoreAspectRatio,
                                                    Qt::SmoothTransformation)));             // 使用平滑的缩放方式
    this->setPalette(palette);

    //初始化地图
    InitMap();
}



MainWindow::~MainWindow()
{

}

void MainWindow::createAction ()
{
    findPathAction = new QAction(tr("搜索路径"), this);
    findPathAction->setText(tr("导航"));
    findPathAction->setStatusTip (tr("搜索路径"));
    connect (findPathAction, SIGNAL(triggered(bool)), this, SLOT(FindPath()));

    clearAction = new QAction( tr("清理路径"), this);
    clearAction->setText(tr("重置"));
    clearAction->setStatusTip (tr("清理路径"));
    connect (clearAction, SIGNAL(triggered(bool)), this, SLOT(Clear()));

}

void MainWindow::CreateGraph ()
{
    //初始化路径权重
    //8公寓 0
    //12公寓 1
    //m楼 2
    //n楼 3
    //大学生服务中心 4
    //大学生活动中心 5
    //图书馆 6
    //学子餐厅 7
    //学苑餐厅 8
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            mgraph.arcs[i][j]=i==j?0:INF;
    }
    mgraph.arcs[0][7]=mgraph.arcs[7][0]=130;
    mgraph.arcs[0][2]=mgraph.arcs[2][0]=350;
    mgraph.arcs[0][4]=mgraph.arcs[4][0]=120;
    mgraph.arcs[0][8]=mgraph.arcs[8][0]=140;

    mgraph.arcs[1][7]=mgraph.arcs[7][1]=300;
    mgraph.arcs[1][5]=mgraph.arcs[5][1]=400;
    mgraph.arcs[1][6]=mgraph.arcs[6][1]=450;
    mgraph.arcs[1][8]=mgraph.arcs[8][1]=180;

    mgraph.arcs[2][4]=mgraph.arcs[4][2]=50;
    mgraph.arcs[2][8]=mgraph.arcs[8][2]=200;

    mgraph.arcs[3][6]=mgraph.arcs[6][3]=160;
    mgraph.arcs[3][5]=mgraph.arcs[5][3]=150;
    mgraph.arcs[3][0]=mgraph.arcs[0][3]=300;
    mgraph.arcs[3][7]=mgraph.arcs[7][3]=200;

    mgraph.arcs[8][7]=mgraph.arcs[7][8]=140;
    mgraph.arcs[5][7]=mgraph.arcs[7][5]=100;
    mgraph.arcs[5][6]=mgraph.arcs[6][5]=100;
    mgraph.arcs[4][8]=mgraph.arcs[8][4]=90;

    for(int i=0;i<9;i++)
    {
        mgraph.vertex[i] = i;
    }
    mgraph.verNum = 9;
    mgraph.arcNum = 18;

}

void MainWindow::InitMap()
{
    CreateGraph();
    Road = false;
}

//计算最短路径
bool MainWindow::Calculate()
{

    return ShortestPath_Floyd(this->mgraph,startComboBox->currentIndex(),endComboBox->currentIndex(),road);
}

void MainWindow::DrawRoad(QPainter &painter)
{
    painter.setPen("black");
    for(int i=1;i<road.size();i++)
    {
        painter.drawLine(getPosition(road[i-1]),getPosition(road[i]));
    }
}

QPoint MainWindow::getPosition(int id)
{
    //8公寓 0
    //12公寓 1
    //m楼 2
    //n楼 3
    //大学生服务中心 4
    //大学生活动中心 5
    //图书馆 6
    //学子餐厅 7
    //学苑餐厅 8
    //TODO：各个屏幕坐标
    static int positions[MAX_VERTEX_NUM][2] = {
        {223,379},{746,529},{141,772},{335,105},{200,674},
        {503,165},{591,71},{377,365},{384,574},{0,0}
    };
    return QPoint(positions[id][0],positions[id][1]);
}

int MainWindow::getId(int x, int y)
{
    int len = 40;
    for(int i=0;i<9;i++)
    {
        QPoint p = getPosition(i);
        if(qAbs(p.x()-x)<=len && qAbs(p.y()-y)<=len)
            return i;
    }
    return -1;
}

QString MainWindow::getName(int id)
{
    static QString name[9]={tr("学生公寓8号楼"),tr("十二公寓"),tr("m楼"),tr("n楼"),tr("大学生服务中心"),
                            tr("大学生活动中心"),tr("图书馆"),tr("学子餐厅"),tr("学苑餐厅")};
    return name[id];
}

void MainWindow::createToolBar ()
{
    QToolBar *toolBar = addToolBar ("Tool");
    startLabel = new QLabel(tr("起点: "));
    startComboBox = new QComboBox;
    startComboBox->addItem (tr("8公寓"));  //0
    startComboBox->addItem (tr("12公寓"));  //1
    startComboBox->addItem (tr("m楼"));  //2
    startComboBox->addItem (tr("n楼"));  //3
    startComboBox->addItem (tr("大学生服务中心"));  //4
    startComboBox->addItem (tr("大学生活动中心"));  //5

    startComboBox->addItem (tr("图书馆")); //6
    startComboBox->addItem (tr("学子餐厅"));  //7
    startComboBox->addItem (tr("学苑餐厅"));  //8

    endLabel = new QLabel(tr("终点: "));
    endComboBox = new QComboBox;

    endComboBox->addItem (tr("8公寓"));  //0
    endComboBox->addItem (tr("12公寓"));  //1
    endComboBox->addItem (tr("m楼"));  //2
    endComboBox->addItem (tr("n楼"));  //3
    endComboBox->addItem (tr("大学生服务中心"));  //4
    endComboBox->addItem (tr("大学生活动中心"));  //5

    endComboBox->addItem (tr("图书馆")); //6
    endComboBox->addItem (tr("学子餐厅"));  //7
    endComboBox->addItem (tr("学苑餐厅"));  //8

    toolBar->addWidget (startLabel);
    toolBar->addWidget (startComboBox);
    toolBar->addSeparator ();

    toolBar->addWidget (endLabel);
    toolBar->addWidget (endComboBox);
    toolBar->addSeparator ();

    toolBar->addAction(findPathAction);
    toolBar->addSeparator ();

    toolBar->addAction(clearAction);
    toolBar->addSeparator ();

}


void MainWindow::FindPath ()
{
    //TODO:计算最短路径，并绘制路线
    cout<<"find path"<<endl;
    if(Calculate())
    {
        Road = true;
        update();
    }

}

void MainWindow::Clear ()
{
    //TODO:清除绘制
    Road = false;
    road.clear();
    update();
}

//鼠标事件
void MainWindow::mouseDoubleClickEvent (QMouseEvent *e)
{
    QDialog *dialog = new QDialog;
    QGridLayout *layout = new QGridLayout(dialog);
    label = new QLabel;

    int id = -1;
    if((id = getId(e->x(),e->y()))>=0)
    {
        strPath = ":/p"+QString::number(id);
        pic.load (strPath);
        pic.scaled(200,200);
        label->setPixmap (pic);
        layout->addWidget (label);
        dialog->setGeometry(e->x(),e->y(),200,200);
        dialog->setWindowTitle (getName(id));
        dialog->show();
    }


}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush("red"));
    painter.setRenderHint(QPainter::Antialiasing, true);
    for(int i=0;i<9;i++)
    {
        QPoint p = getPosition(i);
        painter.drawEllipse(p.x(),p.y(),10,10);
    }

    if(Road && road.size()>=2)
    {
        DrawRoad(painter);
    }

}










