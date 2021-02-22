#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <windows.h>
#include <time.h>
#include <qdebug.h>
#include <QToolBar>
#include <QtAlgorithms>
#include "tool.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    setWindowTitle (" 哈尔滨工业大学（威海）校园导航系统");
    createAction ();
    createToolBar ();           //实现一个工具栏
    setGeometry(650,350,1000,800);
    this->setFixedSize(1000,800);
    //显示背景图
    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/Map").scaled(this->size(),
                            Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));//使用平滑的缩放方式
    this->setPalette(palette);
    ui->intro->setWordWrap(true);
    //初始化地图
    InitMap();
}


MainWindow::~MainWindow()
{

}

void MainWindow::createToolBar ()
{
    //十一公寓 0
    //八公寓 1
    //M楼 2
    //N楼 3
    //H楼 4
    //大学生服务中心 5
    //大学生活动中心 6
    //图书馆 7
    //学子餐厅 8
    //学苑餐厅 9
    //天雅苑 10
    QToolBar *toolBar = addToolBar ("Tool");
    startLabel = new QLabel(tr("起点: "));
    startComboBox = new QComboBox;
    startComboBox->setMaxVisibleItems(15);
    startComboBox->addItem (tr("十一公寓"));  //0
    startComboBox->addItem (tr("八公寓"));  //1
    startComboBox->addItem (tr("M楼"));  //2
    startComboBox->addItem (tr("N楼"));  //3
    startComboBox->addItem (tr("H楼"));  //4
    startComboBox->addItem (tr("大学生服务中心"));  //5
    startComboBox->addItem (tr("大学生活动中心"));  //6
    startComboBox->addItem (tr("图书馆")); //7
    startComboBox->addItem (tr("学子餐厅"));  //8
    startComboBox->addItem (tr("学苑餐厅"));  //9
    startComboBox->addItem (tr("天雅苑"));  //10

    endLabel = new QLabel(tr(" 终点: "));
    endComboBox = new QComboBox;
    endComboBox->setMaxVisibleItems(15);
    endComboBox->addItem (tr("十一公寓"));  //0
    endComboBox->addItem (tr("八公寓"));  //1
    endComboBox->addItem (tr("M楼"));  //2
    endComboBox->addItem (tr("N楼"));  //3
    endComboBox->addItem (tr("H楼"));  //4
    endComboBox->addItem (tr("大学生服务中心"));  //5
    endComboBox->addItem (tr("大学生活动中心"));  //6
    endComboBox->addItem (tr("图书馆")); //7
    endComboBox->addItem (tr("学子餐厅"));  //8
    endComboBox->addItem (tr("学苑餐厅"));  //9
    endComboBox->addItem (tr("天雅苑"));  //10
    endComboBox->setCurrentIndex(7);

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

void MainWindow::createAction()
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
    //十一公寓 0
    //八公寓 1
    //M楼 2
    //N楼 3
    //H楼 4
    //大学生服务中心 5
    //大学生活动中心 6
    //图书馆 7
    //学子餐厅 8
    //学苑餐厅 9
    //天雅苑 10

    for(int i=0;i<=10;i++)
    {
        for(int j=0;j<=10;j++)
            mgraph.arcs[i][j]=i==j?0:INF;
    }
    //公寓圈
    mgraph.arcs[0][1]=mgraph.arcs[1][0]=102;//1
    mgraph.arcs[0][3]=mgraph.arcs[3][0]=107;//2
    mgraph.arcs[1][3]=mgraph.arcs[3][1]=55;//4
    mgraph.arcs[0][8]=mgraph.arcs[8][0]=113;//3
    mgraph.arcs[1][8]=mgraph.arcs[8][1]=37;//5
    mgraph.arcs[3][8]=mgraph.arcs[8][3]=49;//6
    mgraph.arcs[3][6]=mgraph.arcs[6][3]=34;//7
    mgraph.arcs[6][8]=mgraph.arcs[8][6]=53;//10
    mgraph.arcs[3][7]=mgraph.arcs[7][3]=112;//8
    mgraph.arcs[6][7]=mgraph.arcs[7][6]=99;//9

    //教学圈
    mgraph.arcs[1][5]=mgraph.arcs[5][1]=199;//12
    mgraph.arcs[5][8]=mgraph.arcs[8][5]=193;//19
    mgraph.arcs[8][9]=mgraph.arcs[9][8]=176;//20
    mgraph.arcs[10][8]=mgraph.arcs[8][10]=230;//21
    mgraph.arcs[10][9]=mgraph.arcs[9][10]=228;//22
    mgraph.arcs[10][6]=mgraph.arcs[6][10]=245;//11
    mgraph.arcs[5][9]=mgraph.arcs[9][5]=136;//18
    mgraph.arcs[2][5]=mgraph.arcs[5][2]=47;//13
    mgraph.arcs[2][4]=mgraph.arcs[4][2]=134;//14
    mgraph.arcs[5][4]=mgraph.arcs[4][5]=142;//16
    mgraph.arcs[9][4]=mgraph.arcs[4][9]=129;//15
    mgraph.arcs[4][10]=mgraph.arcs[10][4]=310;//23
    mgraph.arcs[2][9]=mgraph.arcs[9][2]=156;//17

    //路线点集
    r01.vertex[0][0]=175;r01.vertex[0][1]=236;//1
    r01.vertex[1][0]=156;r01.vertex[1][1]=265;
    r01.vertex[2][0]=210;r01.vertex[2][1]=298;
    r01.verNum=3;
    r[0][1]=r01;
    r03.vertex[0][0]=175;r03.vertex[0][1]=236;//2
    r03.vertex[1][0]=191;r03.vertex[1][1]=208;
    r03.vertex[2][0]=301;r03.vertex[2][1]=261;
    r03.vertex[3][0]=354;r03.vertex[3][1]=156;
    r03.verNum=4;
    r[0][3]=r03;
    r08.vertex[0][0]=175;r08.vertex[0][1]=236;//3
    r08.vertex[1][0]=191;r08.vertex[1][1]=208;
    r08.vertex[2][0]=301;r08.vertex[2][1]=261;
    r08.verNum=3;
    r[0][8]=r08;
    r13.vertex[0][0]=259;r13.vertex[0][1]=353;//4
    r13.vertex[1][0]=354;r13.vertex[1][1]=156;
    r13.verNum=2;
    r[1][3]=r13;
    r18.vertex[0][0]=259;r18.vertex[0][1]=353;//5
    r18.vertex[1][0]=294;r18.vertex[1][1]=280;
    r18.verNum=2;
    r[1][8]=r18;
    r38.vertex[0][0]=354;r38.vertex[0][1]=156;//6
    r38.vertex[1][0]=294;r38.vertex[1][1]=280;
    r38.verNum=2;
    r[3][8]=r38;
    r36.vertex[0][0]=356;r36.vertex[0][1]=151;//7
    r36.verNum=1;
    r[3][6]=r36;
    r37.vertex[0][0]=354;r37.vertex[0][1]=156;//8
    r37.vertex[1][0]=416;r37.vertex[1][1]=43;
    r37.verNum=2;
    r[3][7]=r37;
    r67.vertex[0][0]=358;r67.vertex[0][1]=148;//9
    r67.vertex[1][0]=416;r67.vertex[1][1]=43;
    r67.verNum=2;
    r[6][7]=r67;
    r68.vertex[0][0]=358;r68.vertex[0][1]=148;//10
    r68.vertex[1][0]=294;r68.vertex[1][1]=280;
    r68.verNum=2;
    r[6][8]=r68;
    r610.vertex[0][0]=371;r610.vertex[0][1]=210;//11
    r610.vertex[1][0]=428;r610.vertex[1][1]=230;
    r610.vertex[2][0]=529;r610.vertex[2][1]=248;
    r610.vertex[3][0]=601;r610.vertex[3][1]=248;
    r610.vertex[4][0]=605;r610.vertex[4][1]=293;
    r610.verNum=5;
    r[6][10]=r610;
    r15.vertex[0][0]=259;r15.vertex[0][1]=353;//12
    r15.vertex[1][0]=177;r15.vertex[1][1]=511;
    r15.verNum=2;
    r[1][5]=r15;
    r25.vertex[0][0]=128;r25.vertex[0][1]=612;//13
    r25.vertex[1][0]=177;r25.vertex[1][1]=511;
    r25.verNum=2;
    r[2][5]=r25;
    r24.vertex[0][0]=272;r24.vertex[0][1]=687;//14
    r24.vertex[1][0]=295;r24.vertex[1][1]=648;
    r24.verNum=2;
    r[2][4]=r24;
    r49.vertex[0][0]=295;r49.vertex[0][1]=648;//15
    r49.vertex[1][0]=326;r49.vertex[1][1]=584;
    r49.verNum=2;
    r[4][9]=r49;
    r45.vertex[0][0]=295;r45.vertex[0][1]=648;//16
    r45.vertex[1][0]=325;r45.vertex[1][1]=583;
    r45.verNum=2;
    r[4][5]=r45;
    r29.vertex[0][0]=207;r29.vertex[0][1]=656;//17
    r29.vertex[1][0]=270;r29.vertex[1][1]=526;
    r29.vertex[2][0]=327;r29.vertex[2][1]=522;
    r29.verNum=3;
    r[2][9]=r29;
    r59.vertex[0][0]=257;r59.vertex[0][1]=548;//18
    r59.vertex[1][0]=270;r59.vertex[1][1]=526;
    r59.vertex[2][0]=327;r59.vertex[2][1]=522;
    r59.verNum=3;
    r[5][9]=r59;
    r58.vertex[0][0]=177;r58.vertex[0][1]=511;//19
    r58.vertex[1][0]=294;r58.vertex[1][1]=280;
    r58.verNum=2;
    r[5][8]=r58;
    r89.vertex[0][0]=294;r89.vertex[0][1]=326;//20
    r89.vertex[1][0]=325;r89.vertex[1][1]=345;
    r89.vertex[2][0]=406;r89.vertex[2][1]=425;
    r89.vertex[3][0]=409;r89.vertex[3][1]=482;
    r89.verNum=4;
    r[8][9]=r89;
    r810.vertex[0][0]=319;r810.vertex[0][1]=271;//21
    r810.vertex[1][0]=567;r810.vertex[1][1]=384;
    r810.verNum=2;
    r[8][10]=r810;
    r910.vertex[0][0]=409;r910.vertex[0][1]=482;//22
    r910.vertex[1][0]=449;r910.vertex[1][1]=572;
    r910.vertex[2][0]=467;r910.vertex[2][1]=583;
    r910.vertex[3][0]=473;r910.vertex[3][1]=535;
    r910.vertex[4][0]=500;r910.vertex[4][1]=474;
    r910.vertex[5][0]=572;r910.vertex[5][1]=380;
    r910.verNum=6;
    r[9][10]=r910;
    r410.vertex[0][0]=407;r410.vertex[0][1]=658;//23
    r410.vertex[1][0]=449;r410.vertex[1][1]=572;
    r410.vertex[2][0]=467;r410.vertex[2][1]=583;
    r410.vertex[3][0]=473;r410.vertex[3][1]=535;
    r410.vertex[4][0]=494;r410.vertex[4][1]=473;
    r410.vertex[5][0]=566;r410.vertex[5][1]=388;
    r410.verNum=6;
    r[4][10]=r410;

    for(int i=0;i<=10;i++){
        mgraph.vertex[i] = i;
    }
    mgraph.verNum = 11;
    mgraph.arcNum = 23;
}

void MainWindow::InitMap()
{
    CreateGraph();
    QPainter painter(this);
    painter.setBrush(QBrush("blue"));
    painter.setRenderHint(QPainter::Antialiasing, true);
    for(int i=0;i<=10;i++)
    {
        QPoint p = getPosition(i);
        painter.drawEllipse(p.x()-5,p.y()-5,10,10);
    }
    Road = false;
}

QPoint MainWindow::getPosition(int id)
{
    //十一公寓 0
    //八公寓 1
    //M楼 2
    //N楼 3
    //H楼 4
    //大学生服务中心 5
    //大学生活动中心 6
    //图书馆 7
    //学子餐厅 8
    //学苑餐厅 9
    //天雅苑 10

    //TODO：各个屏幕坐标
    static int positions[MAX_VERTEX_NUM][2] = {
        {160,230},{240,340},{147,623},{325,140},{370,690},{192,520},
        {390,165},{430,51},{310,290},{326,495},{600,320},{0,0}
    };
    return QPoint(positions[id][0],positions[id][1]);
}

int MainWindow::getRoad(int a[], int value, int low, int high)
{
    int mid = low+(value-a[low])/(a[high]-a[low])*(high-low);
    if(a[mid]==value)
        return mid;
    if(a[mid]>value)
        return getRoad(a, value, low, mid-1);
    if(a[mid]<value)
        return getRoad(a, value, mid+1, high);
}

int MainWindow::getId(int x, int y)
{
    int len = 40;
    for(int i=0;i<=10;i++)
    {
        QPoint p = getPosition(i);
        if(qAbs(p.x()-x)<=len && qAbs(p.y()-y)<=len)
            return i;
    }
    return -1;
}

QString MainWindow::getName(int id)
{
    static QString name[11]={tr("十一公寓"),tr("八公寓"),tr("M楼"),tr("N楼"),tr("H楼"),
                             tr("大学生服务中心"),tr("大学生活动中心"),tr("图书馆"),
                             tr("学子餐厅"),tr("学苑餐厅"),tr("天雅苑")};
    return name[id];
}

//计算最短路径
bool MainWindow::Calculate()
{
    return ShortestPath(this->mgraph,startComboBox->currentIndex(),endComboBox->currentIndex(),road);
}

void MainWindow::FindPath ()
{
    ui->start->setText(getName(startComboBox->currentIndex()));
    ui->end->setText(getName(endComboBox->currentIndex()));
    QPainter painter(this);
    //TODO:计算最短路径，并绘制路线
    cout<<"find path"<<endl;
    d = 0;int x;
    if(Calculate())
    {
        Road = true;
    }
    ui->dis->setText(QString::number(d*2+116)+"米");
    if(d==0) ui->dis->setText("请重新选择");
    update();
}

void MainWindow::Clear ()
{
    //TODO:清除绘制
    Road = false;
    road.clear();
    update();
}

//画笔事件
void MainWindow::DrawRoad(QPainter &painter)
{
    painter.setPen(QPen(Qt::red,5,Qt::DotLine,Qt::RoundCap,Qt::MiterJoin));
    //painter.setPen("black");
    for(int i=1;i<road.size();i++)
    {
        if(road[i-1]>road[i])
        {
            painter.drawLine(getPosition(road[i-1]),QPoint(r[road[i]][road[i-1]].vertex[r[road[i]][road[i-1]].verNum-1][0],r[road[i]][road[i-1]].vertex[r[road[i]][road[i-1]].verNum-1][1]));
            for(int j=r[road[i]][road[i-1]].verNum-1;j>0;j--)
            {
                painter.drawLine(QPoint(r[road[i]][road[i-1]].vertex[j][0],r[road[i]][road[i-1]].vertex[j][1]),QPoint(r[road[i]][road[i-1]].vertex[j-1][0],r[road[i]][road[i-1]].vertex[j-1][1]));
            }
            painter.drawLine(QPoint(r[road[i]][road[i-1]].vertex[0][0],r[road[i]][road[i-1]].vertex[0][1]),getPosition(road[i]));
        }
        else
        {
            painter.drawLine(getPosition(road[i-1]),QPoint(r[road[i-1]][road[i]].vertex[0][0],r[road[i-1]][road[i]].vertex[0][1]));
            for(int j=0;j<r[road[i-1]][road[i]].verNum-1;j++)
            {
                painter.drawLine(QPoint(r[road[i-1]][road[i]].vertex[j][0],r[road[i-1]][road[i]].vertex[j][1]),QPoint(r[road[i-1]][road[i]].vertex[j+1][0],r[road[i-1]][road[i]].vertex[j+1][1]));
            }
            painter.drawLine(QPoint(r[road[i-1]][road[i]].vertex[r[road[i-1]][road[i]].verNum-1][0],r[road[i-1]][road[i]].vertex[r[road[i-1]][road[i]].verNum-1][1]),getPosition(road[i]));
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush("blue"));
    painter.setRenderHint(QPainter::Antialiasing, true);
    for(int i=0;i<=10;i++)
    {
        QPoint p = getPosition(i);
        painter.drawEllipse(p.x()-5,p.y()-5,10,10);
    }

    if(Road && road.size()>=2)
    {
        DrawRoad(painter);
    }

}

//计算最短路径
bool MainWindow::ShortestPath(MGraph &G,int start,int end,QVector<int>& R)
{
    if(start == end)return false;
    const int N = G.verNum, n = N;
    int Path[N][N];      //表示vi和vj之间的最短路上的前驱顶点
    long long D[N][N];   //表示vi和vj之间的最短路径长度
    int Place[N];
    if(start + end >-3)
    {
    //Floyd
        for(int i = 0; i < N ; ++ i)
        {
            for(int j = 0; j < N; ++ j)
            {
                D[i][j] = G.arcs[i][j];
                Path[i][j] = D[i][j] != INF ? i : -1;
            }
        }

        for(int k = 0; k < N; ++ k)
        {
            for(int i = 0; i < N; ++ i)
            {
                for(int j = 0; j < N; ++ j)
                {
                    if(D[i][k] + D[k][j] < D[i][j])
                    {
                        D[i][j] = D[i][k] + D[k][j];
                        Path[i][j] = Path[k][j];
                    }
                }
            }
        }
    }
    else
    {
    //Dijastra
        for (int k = 0; k < n; k++)
        {//控制总共循环的次数
            int Min = INF;
            int pos = 1;//min记录最小路径，pos记录下一个访问结点的标
            //找到最短距离，以及对应下标，作为下一次的起始节点
            for (int i = 0,j = 0; i < n; i++)
            {
                if ((Place[i] == 0) && (Place[j] < Min))
                {
                    Min = Place[i];
                }
            }
            if (pos == 1) break;
            //根据下一个结点在矩阵中对应的值，调整结点到原点距离的最小值
            for (int j = 0; j < n; j++)
            {
                if ((Place[j] == 0) && (D[pos][j] != INF))//判断D中对应的值是否存在
                {
                    if (Place[j]>Place[pos] + D[pos][j])
                    {
                        Place[j] = Place[pos];
                    }
                    /*else if (city[j].dist==(city[pos].dist + map[pos][j]))//这种情况是为了处理最短路径有多条时的情况
                    {
                        city[j].number += city[pos].number;
                        if (city[j].call < city[pos].call + callnum[j])
                        city[j].call = city[pos].call + callnum[j];
                    }*/
                }
            }
        }
    }

    /* 输出每对最短路径 */
    for(int i = 0; i < N; ++ i)
    {
        for(int j = 0; j < N; ++ j)
        {
            if(G.vertex[i] == start && G.vertex[j] == end)
            {
                R.clear();
                R.push_front(end);
                //显示
                cout << G.vertex[i] << " to " << G.vertex[j] << ": " << G.vertex[j];
                for(int vi = Path[i][j]; vi != i; vi = Path[i][vi])
                {
                    cout << " to " << G.vertex[vi];
                    R.push_front(G.vertex[vi]);
                }
                cout << " to " << G.vertex[i] << " (Dis: " << D[i][j]*2+116 << ")" << endl;
                d = D[i][j];
                R.push_front(start);
                return R.size()>=2;
            }
        }
    }
    return R.size()>=2;
}

//鼠标键盘事件
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    QPoint p1 = e->globalPos();
    qDebug()<<"x ="<<p1.rx()-650<<"y ="<<p1.ry()-350<<";";
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if ( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        FindPath();
    }
}

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
        pic.scaled(this->size(),
                   Qt::IgnoreAspectRatio,
                   Qt::SmoothTransformation);
        label->setPixmap (pic);
        layout->addWidget (label);
        dialog->setGeometry(500,500,200,200);
        dialog->setWindowTitle (getName(id));
        dialog->show();
    }
}
