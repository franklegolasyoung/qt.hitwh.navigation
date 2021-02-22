#include "mainwindow.h"
#include "mapwidget.h"
#include <qdebug.h>
#include <QToolBar>
#include <QtAlgorithms>
#include <iostream>
#include <windows.h>
#include<QTextBrowser>
#include <QWheelEvent>
#include <QPushButton>
#include <QButtonGroup>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),m_scalingOffset(0.1)
{

    setWindowTitle (QStringLiteral("哈工大威海校园导航"));
    dj = new MainWindow::DijkstraFindPath();
    hash =new MainWindow::hashType();
    hash->Creat_HT(hash->ha,hash->A,hash->n);
    dj->CreateGraph ();

    scene = new QGraphicsScene;
    initScene();
    scene->setSceneRect (-350, -350, 1800, 1900);


    view = new QGraphicsView;
    view->setScene (scene);
    view->setMinimumSize (800, 400);
    view->show ();
    setCentralWidget (view);

    QLabel *label2 = new QLabel(QStringLiteral(" "));
    sceneCoord = new QLabel;
    QGridLayout *gridLayout = new QGridLayout(view);
    gridLayout->addWidget (label2, 1, 0);
    gridLayout->addWidget (sceneCoord, 1, 1);/**/

    createAction ();
    createToolBar ();           //实现一个工具栏
    setMinimumSize (800, 400);  //设置最小尺寸
    Sleep(2000);

}



void MainWindow::mouseMoveEvent (QMouseEvent *event)
{
 //QGraphicesView 坐标
    QPoint viewPoint = event->pos ();   //鼠标事件位置

    //QGraphiccsScene 坐标 -- 将视图坐标转换成场景坐标
    QPointF scenePoint = view->mapToScene (viewPoint);
   // sceneCoord->setText (QString::number (scenePoint.x ()) + "," + QString::number (scenePoint.y ()));  /* */
}

//图
MainWindow::DijkstraFindPath::DijkstraFindPath()
{
    mgraph.vexnum = 92;                        //初始化点数目
    mgraph.bignum=49;
       for (int i = 0; i < mgraph.vexnum; i++) //初始化点编号
           mgraph.vexs.push_back (i);
       mgraph.arcnum = 120;                     //暂定
       for (int i = 0; i < mgraph.vexnum; i++) {
           for (int j = 0; j < mgraph.vexnum; j++) {
               if (i == j)
                   mgraph.arcs[i][j].adj = 0;
               else
                   mgraph.arcs[i][j].adj = INF;
   //            mgraph.arcs[i][j].info = "";
           }
       }
}

void MainWindow::DijkstraFindPath::CreateGraph ()
{
            int u=mgraph.bignum;
            mgraph.arcs[30][u+33].adj  =mgraph.arcs[u+33][30].adj=120;    //图书馆30         1
              mgraph.arcs[40][u+33].adj  =mgraph.arcs[u+33][40].adj=0;        //N楼东
              mgraph.arcs[u+33][29].adj  =mgraph.arcs[29][u+33].adj=0;        //大活
              mgraph.arcs[u+33][u].adj   =mgraph.arcs[u][u+33].adj=70;       //o
              mgraph.arcs[20][41].adj    =mgraph.arcs[41][20].adj=80;        //北门-N楼南
              mgraph.arcs[41][u].adj     =mgraph.arcs[u][41].adj=100;        //N楼南
              mgraph.arcs[u][28].adj     =mgraph.arcs[28][u].adj=170;       //综合球类馆
              mgraph.arcs[28][u+1].adj   =mgraph.arcs[u+1][28].adj=55;       //综合球类馆
              mgraph.arcs[u+1][u+2].adj  =mgraph.arcs[u+2][u+1].adj=135;     //o
              mgraph.arcs[u][u+3].adj    =mgraph.arcs[u+3][u].adj=100;      //o                 10
              mgraph.arcs[u+1][u+6].adj  =mgraph.arcs[u+6][u+1].adj=135;     //o
              mgraph.arcs[u+2][27].adj   =mgraph.arcs[27][u+2].adj=65;      //留学生公寓
              mgraph.arcs[27][26].adj    =mgraph.arcs[26][27].adj=60;       //留学生公寓-天雅轩
              mgraph.arcs[12][26].adj    =mgraph.arcs[26][12].adj=60;       //十二公寓-天雅轩
              mgraph.arcs[11][10].adj    =mgraph.arcs[10][11].adj=30;       //十一公寓-十公寓
              mgraph.arcs[10][u+3].adj   =mgraph.arcs[u+3][10].adj=145;      //十公寓
              mgraph.arcs[u+3][u+4].adj  =mgraph.arcs[u+4][u+3].adj=120;     //o
              mgraph.arcs[u+4][u+5].adj  =mgraph.arcs[u+5][u+4].adj=70;      //o
              mgraph.arcs[u+5][u+6].adj  =mgraph.arcs[u+6][u+5].adj=40;      //o
              mgraph.arcs[u+6][12].adj   =mgraph.arcs[12][u+6].adj=125;     //十二公寓          20
              mgraph.arcs[u+3][u+8].adj  =mgraph.arcs[u+8][u+3].adj=45;      //o
              mgraph.arcs[9][u+8].adj    =mgraph.arcs[u+8][9].adj =0;       //九公寓
              mgraph.arcs[43][u+8].adj   =mgraph.arcs[u+8][43].adj=0;       //学子西
              mgraph.arcs[u+8][u+9].adj  =mgraph.arcs[u+9][u+8].adj=20;      //o
              mgraph.arcs[8][u+10].adj   =mgraph.arcs[u+10][8].adj =65;   //八公寓
              mgraph.arcs[31][6].adj     =mgraph.arcs[6][31].adj =50;       //六公寓-菜鸟驿站

            mgraph.arcs[6][u+11].adj   =mgraph.arcs[u+11][6].adj =50;   //六公寓
            mgraph.arcs[u+10][32].adj  =mgraph.arcs[32][u+10].adj=70;      //洗衣o
            mgraph.arcs[u+4][42].adj   =mgraph.arcs[42][u+4].adj=30;       //学子东
            mgraph.arcs[42][31].adj    =mgraph.arcs[31][42].adj=55;       //学子东-菜鸟驿站
            mgraph.arcs[u+9][31].adj   =mgraph.arcs[31][u+9].adj=130;     //菜鸟驿站
            mgraph.arcs[u+9][8].adj    =mgraph.arcs[8][u+9].adj =60;      //八公寓房
            mgraph.arcs[32][u+11].adj  =mgraph.arcs[u+11][32].adj=45;       //洗衣房
            mgraph.arcs[u+10][7].adj   =mgraph.arcs[7][u+10].adj =55;       //七公寓男
            mgraph.arcs[u+11][4].adj   =mgraph.arcs[4][u+11].adj =80;       //四公寓
            mgraph.arcs[7][4].adj      =mgraph.arcs[4][7].adj  =95;       //四公寓-七公寓男
            mgraph.arcs[7][u+12].adj   =mgraph.arcs[u+12][7].adj =35;      //七公寓男
            mgraph.arcs[7][0].adj      =mgraph.arcs[0][7].adj  =110;      //七公寓女-七公寓男
            mgraph.arcs[4][u+13].adj   =mgraph.arcs[u+13][4].adj =40;       //四公寓
            mgraph.arcs[31][34].adj    =mgraph.arcs[34][31].adj=145;      //菜鸟驿站-陶瓷       40
            mgraph.arcs[u+5][u+7].adj  =mgraph.arcs[u+7][u+5].adj=90;       //o
            mgraph.arcs[u+7][34].adj   =mgraph.arcs[34][u+7].adj=105;     //陶瓷
            mgraph.arcs[u+7][12].adj   =mgraph.arcs[12][u+7].adj=125;     //十二公寓
            mgraph.arcs[12][u+23].adj  =mgraph.arcs[u+23][12].adj=230;     //十二公寓
            mgraph.arcs[u+12][3].adj   =mgraph.arcs[3][u+12].adj =85;      //三公寓
            mgraph.arcs[3][u+13].adj   =mgraph.arcs[u+13][3].adj =40;      //三公寓
            mgraph.arcs[u+13][33].adj  =mgraph.arcs[33][u+13].adj=65;      //学苑
            mgraph.arcs[33][34].adj    =mgraph.arcs[34][33].adj=95;       //学苑-陶瓷
            mgraph.arcs[34][u+23].adj  =mgraph.arcs[u+23][34].adj=130;     //陶瓷
            mgraph.arcs[u+23][24].adj  =mgraph.arcs[24][u+23].adj=135;     //梅苑小区          50
            mgraph.arcs[0][19].adj     =mgraph.arcs[19][0].adj =280;      //七公寓女-西门
            mgraph.arcs[0][45].adj     =mgraph.arcs[45][0].adj =105;      //七公寓女-大服西
            mgraph.arcs[u+12][45].adj  =mgraph.arcs[45][u+12].adj=55;      //大服西
            mgraph.arcs[3][u+14].adj   =mgraph.arcs[u+14][3].adj =45;   //三公寓
            mgraph.arcs[2][u+14].adj   =mgraph.arcs[u+14][2].adj =35;   //二公寓
            mgraph.arcs[2][45].adj     =mgraph.arcs[45][2].adj =75;       //二公寓-大服西
            mgraph.arcs[u+14][u+15].adj=mgraph.arcs[u+15][u+14].adj=20;   //o
            mgraph.arcs[u+15][44].adj  =mgraph.arcs[44][u+15].adj=40;   //大服东
            mgraph.arcs[1][u+15].adj   =mgraph.arcs[u+15][1].adj =35;   //一公寓
            mgraph.arcs[1][u+16].adj   =mgraph.arcs[u+16][1].adj =45;   //一公寓           60
            mgraph.arcs[33][u+16].adj  =mgraph.arcs[u+16][33].adj=40;   //学苑
            mgraph.arcs[u+16][5].adj   =mgraph.arcs[5][u+16].adj =70;   //五公寓
            mgraph.arcs[34][5].adj     =mgraph.arcs[5][34].adj =150;      //五公寓-陶瓷
            mgraph.arcs[u+23][25].adj  =mgraph.arcs[25][u+23].adj=30;   //博物馆
            mgraph.arcs[24][u+24].adj  =mgraph.arcs[u+24][24].adj=135;  //梅苑小区
            mgraph.arcs[u+24][23].adj  =mgraph.arcs[23][u+24].adj=0;    //留学生餐厅
            mgraph.arcs[u+24][u+34].adj=mgraph.arcs[u+34][u+24].adj=25;   //o
            mgraph.arcs[u+34][u+35].adj=mgraph.arcs[u+35][u+34].adj=25;   //o
            mgraph.arcs[u+35][u+36].adj=mgraph.arcs[u+36][u+35].adj=60;   //o
            mgraph.arcs[u+36][u+37].adj=mgraph.arcs[u+37][u+36].adj=40;   //o             70
            mgraph.arcs[u+37][u+38].adj=mgraph.arcs[u+38][u+37].adj=90;   //o
            mgraph.arcs[u+38][5].adj   =mgraph.arcs[5][u+38].adj =90;      //五公寓
            mgraph.arcs[5][44].adj     =mgraph.arcs[44][5].adj =95;        //大服东-五公寓
            mgraph.arcs[44][45].adj    =mgraph.arcs[45][44].adj=110;       //大服西-大服东
            mgraph.arcs[45][u+19].adj  =mgraph.arcs[u+19][45].adj=145;     //大服西
            mgraph.arcs[44][u+17].adj  =mgraph.arcs[u+17][44].adj=80;     //大服东
            mgraph.arcs[u+17][u+20].adj=mgraph.arcs[u+20][u+17].adj=60;   //o
            mgraph.arcs[u+17][16].adj  =mgraph.arcs[16][u+17].adj=30;      //B楼
            mgraph.arcs[16][u+18].adj  =mgraph.arcs[u+18][16].adj=75;     //B楼
            mgraph.arcs[5][u+18].adj   =mgraph.arcs[u+18][5].adj =85;     //五公寓           80

            mgraph.arcs[u+18][u+22].adj=mgraph.arcs[u+22][u+18].adj=65;   //o
            mgraph.arcs[25][13].adj    =mgraph.arcs[13][25].adj=160;      //博物馆-H楼
            mgraph.arcs[u+24][u+25].adj=mgraph.arcs[u+25][u+24].adj=35;   //o
            mgraph.arcs[u+19][15].adj  =mgraph.arcs[15][u+19].adj=50;      //M楼
            mgraph.arcs[15][u+20].adj  =mgraph.arcs[u+20][15].adj=65;      //M楼
            mgraph.arcs[u+20][u+21].adj=mgraph.arcs[u+21][u+20].adj=25;   //o
            mgraph.arcs[u+21][14].adj  =mgraph.arcs[14][u+21].adj=20;      //G楼
            mgraph.arcs[14][u+22].adj  =mgraph.arcs[u+22][14].adj=50;     //G楼
            mgraph.arcs[u+22][13].adj  =mgraph.arcs[13][u+22].adj=125;    //H楼
            mgraph.arcs[13][u+25].adj  =mgraph.arcs[u+25][13].adj=130;    //H楼            90
            mgraph.arcs[u+25][22].adj  =mgraph.arcs[22][u+25].adj=20;      //o
            mgraph.arcs[22][21].adj    =mgraph.arcs[21][22].adj=80;       //留学生公寓-校医院
            mgraph.arcs[21][18].adj    =mgraph.arcs[18][21].adj=20;       //校医院-东门
            mgraph.arcs[u+19][u+39].adj=mgraph.arcs[u+39][u+19].adj=105;  //o
            mgraph.arcs[36][u+39].adj  =mgraph.arcs[u+39][36].adj=0;       //球场
            mgraph.arcs[47][u+39].adj  =mgraph.arcs[u+39][47].adj=0;       //体育场西门
            mgraph.arcs[u+26][u+39].adj=mgraph.arcs[u+39][u+26].adj=105;  //o
            mgraph.arcs[u+20][46].adj  =mgraph.arcs[46][u+20].adj=0;       //体育场1号门
            mgraph.arcs[u+21][35].adj  =mgraph.arcs[35][u+21].adj=80;      //球场
            mgraph.arcs[35][37].adj    =mgraph.arcs[37][35].adj=65;       //球场-健身中心   100
            mgraph.arcs[37][u+27].adj  =mgraph.arcs[u+27][37].adj=65;      //健身中心
            mgraph.arcs[u+26][u+27].adj=mgraph.arcs[u+27][u+26].adj=150;  //o
            mgraph.arcs[u+27][u+28].adj=mgraph.arcs[u+28][u+27].adj=70;   //o
            mgraph.arcs[u+22][u+28].adj=mgraph.arcs[u+28][u+22].adj=200;  //o
            mgraph.arcs[u+28][u+29].adj=mgraph.arcs[u+29][u+28].adj=135;  //o
            mgraph.arcs[13][u+29].adj  =mgraph.arcs[u+29][13].adj=225;     //H楼
            mgraph.arcs[u+25][u+30].adj=mgraph.arcs[u+30][u+25].adj=190;  //o
            mgraph.arcs[u+29][u+30].adj=mgraph.arcs[u+30][u+29].adj=135;  //o
            mgraph.arcs[u+29][u+31].adj=mgraph.arcs[u+31][u+29].adj=25;   //o
            mgraph.arcs[u+31][u+32].adj=mgraph.arcs[u+32][u+31].adj=50;   //o             110
            mgraph.arcs[17][u+32].adj  =mgraph.arcs[u+32][17].adj=40;      //南门
            mgraph.arcs[u+32][u+41].adj=mgraph.arcs[u+41][u+32].adj=80;   //o
            mgraph.arcs[u+31][u+40].adj=mgraph.arcs[u+40][u+31].adj=80;   //o
            mgraph.arcs[u+40][u+41].adj=mgraph.arcs[u+41][u+40].adj=50;   //o
            mgraph.arcs[u+40][48].adj  =mgraph.arcs[48][u+40].adj=65;       //研究院北
            mgraph.arcs[u+41][38].adj  =mgraph.arcs[38][u+41].adj=60;       //研究院
            mgraph.arcs[u+40][38].adj  =mgraph.arcs[38][u+40].adj=60;       //研究院
            mgraph.arcs[u+30][48].adj  =mgraph.arcs[48][u+30].adj=25;      //研究院北门
            mgraph.arcs[u+42][39].adj  =mgraph.arcs[39][u+42].adj=50;     //研究院1-2
            mgraph.arcs[u+42][48].adj  =mgraph.arcs[48][u+42].adj=165;    //研究院北

}

void MainWindow::DijkstraFindPath::dijkstra (int startPos)
{
    for (int i = 0; i < mgraph.vexnum; i++) d[i] = INF;
    for (int i = 0; i < mgraph.vexnum; i++) used[i] = false;
    for (int i = 0; i < mgraph.vexnum; i++) prev[i] = -1;
    d[startPos] = 0;

    while (true) {
        int v = -1;
        for (int u = 0; u < mgraph.vexnum; u++) {
            if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }

        if (v == -1) break;
        used[v] = true;

        for (int u = 0; u < mgraph.vexnum; u++) {
            if (d[u] > d[v] + mgraph.arcs[v][u].adj) {
                d[u] = d[v] + mgraph.arcs[v][u].adj;
                prev[u] = v;
            }
        }
    }
}

QVector<int> MainWindow::DijkstraFindPath::get_Path (int endPos)
{
    QVector<int> path;

    for ( ; endPos != -1; endPos = prev[endPos]) {
        path.push_back (endPos);
    }

    std::reverse(path.begin (), path.end ());

    return path;
}



//哈希表
MainWindow::hashType::hashType(){

}
int MainWindow::hashType::Search_HT(HashTable ha,int k)
{//查找元素
    int post=k%P;
    for(int i=0;ha[post].key!=-1&&ha[post].key!=k;i++)
        post=(post+1)%P;
    if(ha[post].key==k) return post; //查找成功
    else return -1; //查找失败
}
int MainWindow::hashType::Delete_HT(HashTable ha,int k)
{//删除元素
    int post=Search_HT(ha,k);
    if(post!=-1)
    {
        ha[post].key=-2;
        m--;
        return 1; //删除成功
    }
    else return 0; //删除失败(未找到关键字)
}
void MainWindow::hashType::Insert_HT(HashTable ha,int k)
{//插入关键字
    int post=k%P;
    if(ha[post].key==-1||ha[post].key==-2)
    {
        ha[post].key=k;
        ha[post].count=1;
        ha[post].pixAdress="images//"+QString::number(post);
        ha[post].txtAdress=QString::number(post)+".txt";
    }
    else //发生哈希冲突时采用线性探查法解决冲突
    {
        int cnt=1; //插入k时发生冲突的次数
        do
        {
            post=(post+1)%P;
            cnt++;
        }while(ha[post].key!=-1&&ha[post].key!=-2);
        ha[post].key=k;
        ha[post].count=cnt;
    }
    m++;
}
void MainWindow::hashType::Creat_HT(HashTable ha,int A[],int n)
{//创建哈希表
    for(int i=0;i<M;i++)
    {
        ha[i].key=-1;
        ha[i].count=0;
    }
    for(int i=0;i<n;i++)
        Insert_HT(ha,A[i]);
}


//界面
void MainWindow::initScene (){
    QGraphicsPixmapItem *item =scene->addPixmap (QPixmap("haiwei.png"));
    //item->setFlag (QGraphicsItem::ItemIsMovable);
    item->setPos (-400, -600);
}/**/
MainWindow::~MainWindow()
{

}

void MainWindow::createAction ()
{
    findPathAction = new QAction(QIcon("Search.png"),QStringLiteral("搜索路径"), this);
    findPathAction->setShortcut (QStringLiteral("Ctrl+F"));
    findPathAction->setStatusTip (QStringLiteral("搜索路径"));
    connect (findPathAction, SIGNAL(triggered(bool)), this, SLOT(FindPath()));

    clearAction = new QAction(QIcon("Clear.png"), QStringLiteral("清理路径"), this);
    clearAction->setShortcut (QStringLiteral("Ctrl+W"));
    clearAction->setStatusTip (QStringLiteral("清理路径"));
    connect (clearAction, SIGNAL(triggered(bool)), this, SLOT(Clear()));

    reviseAction = new QAction(QIcon("revise.png"), QStringLiteral("修改景点"), this);
    reviseAction->setShortcut (QStringLiteral("Ctrl+R"));
    clearAction->setStatusTip (QStringLiteral("修改景点"));
    connect (reviseAction, SIGNAL(triggered(bool)), this, SLOT(Revise()));

    callMap = new QAction(QIcon("map.png"), QStringLiteral("调用高德地图"), this);
    callMap->setShortcut (QStringLiteral("Ctrl+M"));
    callMap->setStatusTip (QStringLiteral("调用测试地图"));
    connect (callMap, SIGNAL(triggered(bool)), this, SLOT(callOtherMap()));

}

void MainWindow::createToolBar ()
{
    QToolBar *toolBar = addToolBar ("Tool");
    startLabel = new QLabel(QStringLiteral("起点: "));
    startComboBox = new QComboBox;
    startComboBox->addItem (QStringLiteral("七公寓女"));	//0
    startComboBox->addItem (QStringLiteral("一公寓"));
    startComboBox->addItem (QStringLiteral("二公寓"));
    startComboBox->addItem (QStringLiteral("三公寓"));
    startComboBox->addItem (QStringLiteral("四公寓"));
    startComboBox->addItem (QStringLiteral("五公寓"));
    startComboBox->addItem (QStringLiteral("六公寓"));
        startComboBox->addItem (QStringLiteral("七公寓男"));
        startComboBox->addItem (QStringLiteral("八公寓"));
        startComboBox->addItem (QStringLiteral("九公寓"));
        startComboBox->addItem (QStringLiteral("十公寓"));		//10
        startComboBox->addItem (QStringLiteral("十一公寓"));
    startComboBox->addItem (QStringLiteral("十二公寓"));
        startComboBox->addItem (QStringLiteral("H楼"));
        startComboBox->addItem (QStringLiteral("G楼"));
        startComboBox->addItem (QStringLiteral("M楼"));
        startComboBox->addItem (QStringLiteral("B楼"));
        startComboBox->addItem (QStringLiteral("南门"));
    startComboBox->addItem (QStringLiteral("东门"));
        startComboBox->addItem (QStringLiteral("西门"));
        startComboBox->addItem (QStringLiteral("北门"));		//20
        startComboBox->addItem (QStringLiteral("校医院"));
        startComboBox->addItem (QStringLiteral("老留学生公寓"));
        startComboBox->addItem (QStringLiteral("留学生餐厅"));
    startComboBox->addItem (QStringLiteral("梅苑小区"));
        startComboBox->addItem (QStringLiteral("校博物馆"));
        startComboBox->addItem (QStringLiteral("天雅轩"));
        startComboBox->addItem (QStringLiteral("新留学生公寓"));
        startComboBox->addItem (QStringLiteral("综合球类馆"));
        startComboBox->addItem (QStringLiteral("大学生活动中心"));
    startComboBox->addItem (QStringLiteral("图书馆"));		//30
        startComboBox->addItem (QStringLiteral("菜鸟驿站"));
        startComboBox->addItem (QStringLiteral("洗衣房"));
        startComboBox->addItem (QStringLiteral("学苑餐厅"));
        startComboBox->addItem (QStringLiteral("特种陶瓷实验室"));
        startComboBox->addItem (QStringLiteral("东球场"));
    startComboBox->addItem (QStringLiteral("西球场"));
        startComboBox->addItem (QStringLiteral("健身中心"));
        startComboBox->addItem (QStringLiteral("研究院西门"));
        startComboBox->addItem (QStringLiteral("研究院二号楼"));
        startComboBox->addItem (QStringLiteral("N楼东门"));	//40
    startComboBox->addItem (QStringLiteral("N楼南门"));
    startComboBox->addItem (QStringLiteral("学子餐厅东门"));
        startComboBox->addItem (QStringLiteral("学子餐厅西门"));
        startComboBox->addItem (QStringLiteral("大学生服务区东入口"));
        startComboBox->addItem (QStringLiteral("大学生服务区西入口"));
        startComboBox->addItem (QStringLiteral("体育场一号门"));
        startComboBox->addItem (QStringLiteral("体育场西门"));
    startComboBox->addItem (QStringLiteral("研究院北门"));


    endLabel = new QLabel(QStringLiteral("终点: "));

    endComboBox = new QComboBox;
    endComboBox->addItem (QStringLiteral("七公寓女"));	//0
        endComboBox->addItem (QStringLiteral("一公寓"));
        endComboBox->addItem (QStringLiteral("二公寓"));
        endComboBox->addItem (QStringLiteral("三公寓"));
        endComboBox->addItem (QStringLiteral("四公寓"));
        endComboBox->addItem (QStringLiteral("五公寓"));
    endComboBox->addItem (QStringLiteral("六公寓"));
        endComboBox->addItem (QStringLiteral("七公寓男"));
        endComboBox->addItem (QStringLiteral("八公寓"));
        endComboBox->addItem (QStringLiteral("九公寓"));
        endComboBox->addItem (QStringLiteral("十公寓"));		//10
        endComboBox->addItem (QStringLiteral("十一公寓"));
    endComboBox->addItem (QStringLiteral("十二公寓"));
        endComboBox->addItem (QStringLiteral("H楼"));
        endComboBox->addItem (QStringLiteral("G楼"));
        endComboBox->addItem (QStringLiteral("M楼"));
        endComboBox->addItem (QStringLiteral("B楼"));
        endComboBox->addItem (QStringLiteral("南门"));
    endComboBox->addItem (QStringLiteral("东门"));
        endComboBox->addItem (QStringLiteral("西门"));
        endComboBox->addItem (QStringLiteral("北门"));		//20
        endComboBox->addItem (QStringLiteral("校医院"));
        endComboBox->addItem (QStringLiteral("老留学生公寓"));
        endComboBox->addItem (QStringLiteral("留学生餐厅"));
    endComboBox->addItem (QStringLiteral("梅苑小区"));
        endComboBox->addItem (QStringLiteral("校博物馆"));
        endComboBox->addItem (QStringLiteral("天雅轩"));
        endComboBox->addItem (QStringLiteral("新留学生公寓"));
        endComboBox->addItem (QStringLiteral("综合球类馆"));
        endComboBox->addItem (QStringLiteral("大学生活动中心"));
    endComboBox->addItem (QStringLiteral("图书馆"));		//30
        endComboBox->addItem (QStringLiteral("菜鸟驿站"));
        endComboBox->addItem (QStringLiteral("洗衣房"));
        endComboBox->addItem (QStringLiteral("学苑餐厅"));
        endComboBox->addItem (QStringLiteral("特种陶瓷实验室"));
        endComboBox->addItem (QStringLiteral("东球场"));
    endComboBox->addItem (QStringLiteral("西球场"));
        endComboBox->addItem (QStringLiteral("健身中心"));
        endComboBox->addItem (QStringLiteral("研究院西门"));
        endComboBox->addItem (QStringLiteral("研究院二号楼"));
        endComboBox->addItem (QStringLiteral("N楼东门"));	//40
    endComboBox->addItem (QStringLiteral("N楼南门"));
    endComboBox->addItem (QStringLiteral("学子餐厅东门"));
        endComboBox->addItem (QStringLiteral("学子餐厅西门"));
        endComboBox->addItem (QStringLiteral("大学生服务区东入口"));
        endComboBox->addItem (QStringLiteral("大学生服务区西入口"));
        endComboBox->addItem (QStringLiteral("体育场一号门"));
        endComboBox->addItem (QStringLiteral("体育场西门"));
    endComboBox->addItem (QStringLiteral("研究院北门"));


    connect (startComboBox, SIGNAL(activated(int)), this, SLOT(setStartStation()));
    connect (endComboBox, SIGNAL(activated(int)), this, SLOT(setEndStation()));

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
    toolBar->addAction(reviseAction);
    toolBar->addSeparator ();
    toolBar->addAction(callMap);

}


//最短路径
void MainWindow::setStart(int X, int Y) {
    startX = X; startY = Y;
//    qDebug() << X << ", " << Y;
}

void MainWindow::setEnd (int X, int Y)
{
    endX = X; endY = Y;
}

void MainWindow::setStartStation ()
{
    const int u=49;
    switch (startComboBox->currentIndex ()) {
        case 0:
            setStart(297,372); break;
        case 1:
            setStart (589,467); break;	//o
        case 2:
            setStart (507,436); break;
        case 3:
            setStart (544,380); break;
    case 4:
            setStart (596,325); break;
        case 5:
            setStart (642,557); break;
        case 6:
            setStart (644,209); break;
    case 7:
            setStart (455,332); break;
    case 8:
            setStart (525,195); break;
    case 9:
            setStart (575,100); break;
    case 10:
            setStart (433,-43); break;
    case 11:
            setStart (393,-66); break;
    case 12:
            setStart (1005,288); break;
    case 13:
            setStart (704,829); break;
    case 14:
            setStart (499,703); break;
    case 15:
            setStart (375,637); break;
    case 16:
            setStart (510,618); break;
    case 17:
            setStart (500,1209); break;
    case 18:
            setStart (1003,967); break;
    case 19:
            setStart (-28,546); break;
    case 20:
            setStart (474,-210); break;
    case 21:
            setStart (966,948); break;
    case 22:
            setStart (875,897); break;
    case 23:
            setStart (857,847); break;
    case 24:
            setStart (951,690); break;
    case 25:
            setStart (828,582); break;
    case 26:
            setStart (1050,224); break;
    case 27:
            setStart (1094,151); break;
    case 28:
            setStart (860,8); break;
    case 29:
            setStart (702,-136); break;
    case 30:
            setStart (778,-280); break;
    case 31:
            setStart (695,219); break;
    case 32:
            setStart (576,273); break;
    case 33:
            setStart (647,419); break;
    case 34:
            setStart (770,402); break;
    case 35:
            setStart (449,742); break;
    case 36:
            setStart (244,727); break;
    case 37:
            setStart (392,857); break;
    case 38:
            setStart (674,1216); break;
    case 39:
            setStart (875,1318); break;
    case 40:
            setStart (702,-136); break;
    case 41:
            setStart (557,-144); break;
    case 42:
            setStart (724,160); break;
    case 43:
            setStart (575,100); break;
    case 44:
            setStart (522,510); break;
    case 45:
            setStart (399,441); break;
    case 46:
            setStart (447,674); break;
    case 47:
            setStart (244,727); break;
    case 48:
            setStart (725,1144); break;
    case u+0:
            setStart (658,-64); break;  //48
    case u+1:
            setStart (941,30); break;
    case u+2:
            setStart (1111,99); break;
    case u+3:
            setStart (599,47); break;
    case u+4:
            setStart (742,123); break;
    case u+5:
            setStart (832,168); break;
    case u+6:
            setStart (862,188); break;
    case u+7:
            setStart (849,229); break;
    case u+8:
            setStart (575,100); break;
    case u+9:
            setStart (564,125); break;
    case u+10:
            setStart (485,272); break;
    case u+11:
            setStart (640,271); break;
    case u+12:
            setStart (433,378); break;
    case u+13:
            setStart (599,380); break;
    case u+14:
            setStart (545,435); break;
    case u+15:
            setStart (546,461); break;
    case u+16:
            setStart (649,469); break;
    case u+17:
            setStart (479,603); break;//65
    case u+18:
            setStart (599,662); break;
    case u+19:
            setStart (314,603); break;
    case u+20:
            setStart (447,674); break;
    case u+21:
            setStart (475,691); break;
    case u+22:
            setStart (556,744); break;
    case u+23:
            setStart (851,551); break;//71
    case u+24:
            setStart (875,847); break;
    case u+25:
            setStart (855,896); break;
    case u+26:
            setStart (181,852); break;
    case u+27:
            setStart (352,941); break;//75
    case u+28:
            setStart (437,970); break;
    case u+29:
            setStart (557,1088); break;
    case u+30:
            setStart (737,1110); break;
    case u+31:
            setStart (545,1117); break;
    case u+32:
            setStart (516,1178); break;
    case u+33:
            setStart (702,-136); break;
    case u+34:
            setStart (847,834); break;
    case u+35:
            setStart (855,806); break;
    case u+36:
            setStart (794,761); break;
    case u+37:
            setStart (811,707); break;
    case u+38:
            setStart (706,653); break;
    case u+39:
            setStart (244,727); break;//87
    case u+40:
            setStart (643,1165); break;
    case u+41:
            setStart (608,1226); break;
    case u+42:
            setStart (907,1249); break;

    }

}

void MainWindow::setEndStation ()
{
    const int u=49;
    switch (endComboBox->currentIndex ()) {
    case 0:
            setEnd(297,372); break;
        case 1:
            setEnd (589,467); break;	//o
        case 2:
            setEnd (507,436); break;
        case 3:
            setEnd (544,380); break;
    case 4:
            setEnd (596,325); break;
        case 5:
            setEnd (642,557); break;
        case 6:
            setEnd (644,209); break;
    case 7:
            setEnd (455,332); break;
    case 8:
            setEnd (525,195); break;
    case 9:
            setEnd (575,100); break;
    case 10:
            setEnd (433,-43); break;
    case 11:
            setEnd (393,-66); break;
    case 12:
            setEnd (1005,288); break;
    case 13:
            setEnd (704,829); break;
    case 14:
            setEnd (499,703); break;
    case 15:
            setEnd (375,637); break;
    case 16:
            setEnd (510,618); break;
    case 17:
            setEnd (500,1209); break;
    case 18:
            setEnd (1003,967); break;
    case 19:
            setEnd (-28,546); break;
    case 20:
            setEnd (474,-210); break;
    case 21:
            setEnd (966,948); break;
    case 22:
            setEnd (875,897); break;
    case 23:
            setEnd (857,847); break;
    case 24:
            setEnd (951,690); break;
    case 25:
            setEnd (828,582); break;
    case 26:
            setEnd (1050,224); break;
    case 27:
            setEnd (1094,151); break;
    case 28:
            setEnd (860,8); break;
    case 29:
            setEnd (702,-136); break;
    case 30:
            setEnd (778,-280); break;
    case 31:
            setEnd (695,219); break;
    case 32:
            setEnd (576,273); break;
    case 33:
            setEnd (647,419); break;
    case 34:
            setEnd (770,402); break;
    case 35:
            setEnd (449,742); break;
    case 36:
            setEnd (244,727); break;
    case 37:
            setEnd (392,857); break;
    case 38:
            setEnd (674,1216); break;
    case 39:
            setEnd (875,1318); break;
    case 40:
            setEnd (702,-136); break;
    case 41:
            setEnd (557,-144); break;
    case 42:
            setEnd (724,160); break;
    case 43:
            setEnd (575,100); break;
    case 44:
            setEnd (522,510); break;
    case 45:
            setEnd (399,441); break;
    case 46:
            setEnd (447,674); break;
    case 47:
            setEnd (244,727); break;
    case 48:
            setEnd (725,1144); break;
    case u+0:
            setEnd (658,-64); break;  //48
    case u+1:
            setEnd (941,30); break;
    case u+2:
            setEnd (1111,99); break;
    case u+3:
            setEnd (599,47); break;
    case u+4:
            setEnd (742,123); break;
    case u+5:
            setEnd (832,168); break;
    case u+6:
            setEnd (862,188); break;
    case u+7:
            setEnd (849,229); break;
    case u+8:
            setEnd (575,100); break;
    case u+9:
            setEnd (564,125); break;
    case u+10:
            setEnd (485,272); break;
    case u+11:
            setEnd (640,271); break;
    case u+12:
            setEnd (433,378); break;
    case u+13:
            setEnd (599,380); break;
    case u+14:
            setEnd (545,435); break;
    case u+15:
            setEnd (546,461); break;
    case u+16:
            setEnd (649,469); break;
    case u+17:
            setEnd (479,603); break;//65
    case u+18:
            setEnd (599,662); break;
    case u+19:
            setEnd (314,603); break;
    case u+20:
            setEnd (447,674); break;
    case u+21:
            setEnd (475,691); break;
    case u+22:
            setEnd (556,744); break;
    case u+23:
            setEnd (851,551); break;//71
    case u+24:
            setEnd (875,847); break;
    case u+25:
            setEnd (855,896); break;
    case u+26:
            setEnd (181,852); break;
    case u+27:
            setEnd (352,941); break;//75
    case u+28:
            setEnd (437,970); break;
    case u+29:
            setEnd (557,1088); break;
    case u+30:
            setEnd (737,1110); break;
    case u+31:
            setEnd (545,1117); break;
    case u+32:
            setEnd (516,1178); break;
    case u+33:
            setEnd (702,-136); break;
    case u+34:
            setEnd (847,834); break;
    case u+35:
            setEnd (855,806); break;
    case u+36:
            setEnd (794,761); break;
    case u+37:
            setEnd (811,707); break;
    case u+38:
            setEnd (706,653); break;
    case u+39:
            setEnd (244,727); break;//87
    case u+40:
            setEnd (643,1165); break;
    case u+41:
            setEnd (608,1226); break;
    case u+42:
            setEnd (907,1249); break;

    default:
        break;
    }
}
void MainWindow::setNextPos (int index)
{
    const int u=49;
    switch (index) {
    case 0:
            setEnd(297,372); break;
        case 1:
            setEnd (589,467); break;	//o
        case 2:
            setEnd (507,436); break;
        case 3:
            setEnd (544,380); break;
    case 4:
            setEnd (596,325); break;
        case 5:
            setEnd (642,557); break;
        case 6:
            setEnd (644,209); break;
    case 7:
            setEnd (455,332); break;
    case 8:
            setEnd (525,195); break;
    case 9:
            setEnd (575,100); break;
    case 10:
            setEnd (433,-43); break;
    case 11:
            setEnd (393,-66); break;
    case 12:
            setEnd (1005,288); break;
    case 13:
            setEnd (704,829); break;
    case 14:
            setEnd (499,703); break;
    case 15:
            setEnd (375,637); break;
    case 16:
            setEnd (510,618); break;
    case 17:
            setEnd (500,1209); break;
    case 18:
            setEnd (1003,967); break;
    case 19:
            setEnd (-28,546); break;
    case 20:
            setEnd (474,-210); break;
    case 21:
            setEnd (966,948); break;
    case 22:
            setEnd (875,897); break;
    case 23:
            setEnd (857,847); break;
    case 24:
            setEnd (951,690); break;
    case 25:
            setEnd (828,582); break;
    case 26:
            setEnd (1050,224); break;
    case 27:
            setEnd (1094,151); break;
    case 28:
            setEnd (860,8); break;
    case 29:
            setEnd (702,-136); break;
    case 30:
            setEnd (778,-280); break;
    case 31:
            setEnd (695,219); break;
    case 32:
            setEnd (576,273); break;
    case 33:
            setEnd (647,419); break;
    case 34:
            setEnd (770,402); break;
    case 35:
            setEnd (449,742); break;
    case 36:
            setEnd (244,727); break;
    case 37:
            setEnd (392,857); break;
    case 38:
            setEnd (674,1216); break;
    case 39:
            setEnd (875,1318); break;
    case 40:
            setEnd (702,-136); break;
    case 41:
            setEnd (557,-144); break;
    case 42:
            setEnd (724,160); break;
    case 43:
            setEnd (575,100); break;
    case 44:
            setEnd (522,510); break;
    case 45:
            setEnd (399,441); break;
    case 46:
            setEnd (447,674); break;
    case 47:
            setEnd (244,727); break;
    case 48:
            setEnd (725,1144); break;
    case u+0:
            setEnd (658,-64); break;  //48
    case u+1:
            setEnd (941,30); break;
    case u+2:
            setEnd (1111,99); break;
    case u+3:
            setEnd (599,47); break;
    case u+4:
            setEnd (742,123); break;
    case u+5:
            setEnd (832,168); break;
    case u+6:
            setEnd (862,188); break;
    case u+7:
            setEnd (849,229); break;
    case u+8:
            setEnd (575,100); break;
    case u+9:
            setEnd (564,125); break;
    case u+10:
            setEnd (485,272); break;
    case u+11:
            setEnd (640,271); break;
    case u+12:
            setEnd (433,378); break;
    case u+13:
            setEnd (599,380); break;
    case u+14:
            setEnd (545,435); break;
    case u+15:
            setEnd (546,461); break;
    case u+16:
            setEnd (649,469); break;
    case u+17:
            setEnd (479,603); break;//65
    case u+18:
            setEnd (599,662); break;
    case u+19:
            setEnd (314,603); break;
    case u+20:
            setEnd (447,674); break;
    case u+21:
            setEnd (475,691); break;
    case u+22:
            setEnd (556,744); break;
    case u+23:
            setEnd (851,551); break;//71
    case u+24:
            setEnd (875,847); break;
    case u+25:
            setEnd (855,896); break;
    case u+26:
            setEnd (181,852); break;
    case u+27:
            setEnd (352,941); break;//75
    case u+28:
            setEnd (437,970); break;
    case u+29:
            setEnd (557,1088); break;
    case u+30:
            setEnd (737,1110); break;
    case u+31:
            setEnd (545,1117); break;
    case u+32:
            setEnd (516,1178); break;
    case u+33:
            setEnd (702,-136); break;
    case u+34:
            setEnd (847,834); break;
    case u+35:
            setEnd (855,806); break;
    case u+36:
            setEnd (794,761); break;
    case u+37:
            setEnd (811,707); break;
    case u+38:
            setEnd (706,653); break;
    case u+39:
            setEnd (244,727); break;//87
    case u+40:
            setEnd (643,1165); break;
    case u+41:
            setEnd (608,1226); break;
    case u+42:
            setEnd (907,1249); break;

    default:
        break;
    }
}

void MainWindow::FindPath ()
{
    //Demo 在图片上绘线 在原有基础上 (+700, +440);
    QVector<QPoint> v;

    dj->dijkstra (startComboBox->currentIndex ());
    //设置下一处的终点
    nextPath = dj->get_Path (endComboBox->currentIndex ());
    for (int k=nextPath.size()-1;k>=0;k--)
    {
        qDebug() << nextPath[k] << "-";
    }
    //准备绘制
    Clear ();
    //将路线绘制下来
    QGraphicsPathItem *item = new QGraphicsPathItem();

    QPen pen;
    pen.setWidth (4);
    pen.setColor (Qt::red);
    item->setPen (pen);
    item->setFlag (QGraphicsItem::ItemIsPanel);

    //qDebug() << startX << " " << startY << " " << endX << " " << endY;

    //for (int i = 1; i < nextPath.size (); i++) {
      //  qDebug() << nextPath[i] << " , ";
    //}
    scene->addItem (item);

    QPainterPath pa;               //path

    pa.moveTo (startX , startY);

    //将路径用坐标存入到路径
    for (int i = 1; i < nextPath.size() ; i++) {
        qDebug() <<nextPath[i];
        setNextPos (nextPath[i]);
        pa.lineTo (endX , endY);
    }
    item->setPath (pa);

}

void MainWindow::Clear ()
{
    QList<QGraphicsItem*> listItem = scene->items ();
    while (!listItem.empty ())
    {
        scene->removeItem (listItem.at (0));
        listItem.removeAt (0);
    }
    QGraphicsPixmapItem *item =scene->addPixmap (QPixmap("haiwei.png"));
   item->setFlag (QGraphicsItem::ItemIsMovable);
    item->setPos (-400, -600);
}

void MainWindow::Revise ()
{
    QDialog *reviseDlg = new QDialog;
    QLabel *reviseLabel = new QLabel(QStringLiteral("修改图片路径："));
    QLineEdit *revison = new QLineEdit(QStringLiteral("\\image\\library.png"));
    QPushButton *SureBtn = new QPushButton(QStringLiteral("确定"));
    QPushButton *CancelBtn = new QPushButton(QStringLiteral("取消"));


    revison->setEnabled (false);

    reviseComboBox = new QComboBox;
    reviseComboBox->addItem (QStringLiteral("图书馆"));
    reviseComboBox->addItem (QStringLiteral("食堂"));
    reviseComboBox->addItem (QStringLiteral("西操"));
    reviseComboBox->addItem (QStringLiteral("jsj教学楼"));

    connect(reviseComboBox, SIGNAL(activated(int)), this, SLOT(ShowDialog()));
    connect (SureBtn, SIGNAL(clicked(bool)), reviseDlg, SLOT(close()));
    connect (CancelBtn, SIGNAL(clicked(bool)), reviseDlg, SLOT(close ()));

    revison->setText (strPath);

    QGridLayout *mainlayout = new QGridLayout(reviseDlg);
    mainlayout->addWidget (reviseLabel, 0, 0); mainlayout->addWidget (revison, 0, 1);
    mainlayout->addWidget (reviseComboBox, 0 , 2);

    mainlayout->addWidget (SureBtn, 2, 1, 1, 1); mainlayout->addWidget (CancelBtn, 2, 2, 1, 1);


    reviseDlg->setWindowTitle (QStringLiteral("修改景点信息"));
    reviseDlg->show ();
}

void MainWindow::ShowDialog ()
{
    strPath = QFileDialog::getOpenFileName (this, "打开", "/", "PNG图像(*.png)::JPEG图像(*.jpg)");
    switch (reviseComboBox->currentIndex ()) {
    case 0:
       // library.load (strPath);
        break;
    case 1:
      //  canteen.load (strPath);
        break;
    case 2:
       // westground.load (strPath);
        break;
    case 3:
       // jxjBuilding.load (strPath);
        break;
    default:
        break;
    }
}

//鼠标事件
void MainWindow::mouseDoubleClickEvent (QMouseEvent *e)
{
    QDialog *dialog = new QDialog;
    QGridLayout *layout = new QGridLayout(dialog);

    //图片与介绍信息
    label = new QLabel;
    QTextEdit *label1=new QTextEdit;

    //按钮
    QPushButton *startFrome=new QPushButton(QStringLiteral("从这里出发"));
    QPushButton *endFrome=new QPushButton(QStringLiteral("到这里去"));
    QPushButton *news1 = new QPushButton(QStringLiteral("了解详情"));
    QPushButton *news2 = new QPushButton(QStringLiteral("了解详情"));
    QPushButton *morenews=new QPushButton(QStringLiteral("更多活动"));
    connect (startFrome, SIGNAL(clicked(bool)), this, SLOT(setStartFrome()));
    connect (endFrome, SIGNAL(clicked(bool)), this, SLOT(setEndFrome()));
    connect (news1, SIGNAL(clicked(bool)), this, SLOT(news1show()));
    connect (news2, SIGNAL(clicked(bool)), this, SLOT(news2show()));
    connect (morenews, SIGNAL(clicked(bool)), this, SLOT(callMorenews()));

    //动态字幕
    m_curIndex = 0;//当前角码
    m_label = new QLabel(this);
    m_label->setMinimumWidth(300);

    m_curIndex1 = 0;//当前角码
    m_label1 = new QLabel(this);
    m_label1->setMinimumWidth(300);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::showTicker);
    timer->start(500);//定时器

    //QGraphicesView 坐标
    QPoint viewPoint = e->pos ();   //鼠标事件位置
    QPointF scenePoint = view->mapToScene (viewPoint);


    //输出坐标
    qDebug() << "x : " << scenePoint.x () << ", y : " << scenePoint.y ();

    if ( (scenePoint.x () >= 600-60 &&scenePoint.x ()<= 600 + 40) &&
         (scenePoint.y () >= -165 - 60 && scenePoint.y () <= -165 + 60 ))
    {

        int pic=hash->Search_HT(hash->ha,1);
        strPath = hash->ha[pic].pixAdress;
        qDebug() <<strPath;
        pix.load (strPath);
        label->setPixmap (pix);

        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,1);
        txtPath=hash->ha[txt].txtAdress;

        num=40;
        num2=1;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("N楼"));
        dialog->show ();
    }
    else if ((scenePoint.x () >= 731-100 && scenePoint.x () <= 731 + 100) &&
             (scenePoint.y ()>= 1276 - 100 &&scenePoint.y () <= 1276 + 100 ) ) {
        int pic=hash->Search_HT(hash->ha,2);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);

        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,2);
        txtPath=hash->ha[txt].txtAdress;

        num=38;
        num2=2;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("研学楼"));
        dialog->show ();
    }
    else if ((scenePoint.x () >= 870-70 && scenePoint.x () <= 870 +70) &&
             (scenePoint.y () >= -190 - 70 && scenePoint.y () <= -190 + 70 ) ) {
        int pic=hash->Search_HT(hash->ha,3);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,3);
        txtPath=hash->ha[txt].txtAdress;

        num=30;
        num2=3;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("图书馆")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 400-40 && scenePoint.x () <= 400 +40) &&
             (scenePoint.y () >= 630 - 70 && scenePoint.y () <= 630 + 70 ) ) {
        int pic=hash->Search_HT(hash->ha,4);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,4);
        txtPath=hash->ha[txt].txtAdress;

        num=15;
        num2=4;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("M楼")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 520-30 && scenePoint.x () <= 520 +30) &&
             (scenePoint.y () >= 690 - 30 && scenePoint.y () <= 690 + 30 ) ) {
        int pic=hash->Search_HT(hash->ha,5);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,5);
        txtPath=hash->ha[txt].txtAdress;

        num=14;
        num2=5;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("G楼")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 670-100 && scenePoint.x () <= 670 +100) &&
             (scenePoint.y () >= 930 - 100 && scenePoint.y () <= 930 + 100 ) ) {
        int pic=hash->Search_HT(hash->ha,6);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,6);
        txtPath=hash->ha[txt].txtAdress;

        num=0;
        num2=6;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("主楼大道")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 720-50 && scenePoint.x () <= 720 +50) &&
             (scenePoint.y () >= 69 - 50 && scenePoint.y () <= 69 + 50 ) ) {
        int pic=hash->Search_HT(hash->ha,7);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,7);
        txtPath=hash->ha[txt].txtAdress;

        num=0;
        num2=7;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("丁香园")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 735-100 && scenePoint.x () <= 735 +100) &&
             (scenePoint.y () >= 770 - 100 && scenePoint.y () <= 770 + 100 ) ) {
        int pic=hash->Search_HT(hash->ha,8);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,8);
        txtPath=hash->ha[txt].txtAdress;

        num=13;
        num2=8;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("主楼")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 500-50 && scenePoint.x () <= 500 +50) &&
             (scenePoint.y () >= 1240 - 50 && scenePoint.y () <= 1240 + 50 ) ) {
        int pic=hash->Search_HT(hash->ha,9);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,9);
        txtPath=hash->ha[txt].txtAdress;

        num=17;
        num2=9;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("南大门")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 330-100 && scenePoint.x () <= 330 +100) &&
             (scenePoint.y () >= 780 - 100 && scenePoint.y () <= 780 + 100 ) ) {
        int pic=hash->Search_HT(hash->ha,10);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,10);
        txtPath=hash->ha[txt].txtAdress;

        num=46;
        num2=10;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("操场")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 462-50 && scenePoint.x () <= 462 +50) &&
             (scenePoint.y () >= 770 - 50 && scenePoint.y () <= 770 + 50 ) ) {
        int pic=hash->Search_HT(hash->ha,11);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,11);
        txtPath=hash->ha[txt].txtAdress;

        num=35;
        num2=11;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("篮球场")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 385-50 && scenePoint.x () <= 385 +50) &&
             (scenePoint.y () >= 890 - 50 && scenePoint.y () <= 890 + 50 ) ) {
        int pic=hash->Search_HT(hash->ha,12);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,12);
        txtPath=hash->ha[txt].txtAdress;

        num=37;
        num2=12;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("健身中心")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 900-50 && scenePoint.x () <= 900 +50) &&
             (scenePoint.y () >= 931- 50 && scenePoint.y () <= 931 + 50 ) ) {
        int pic=hash->Search_HT(hash->ha,13);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,13);
        txtPath=hash->ha[txt].txtAdress;

        num=22;
        num2=13;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("旧留学生中心")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 978-100 && scenePoint.x () <= 978 +100) &&
             (scenePoint.y () >= 665 - 100 && scenePoint.y () <= 665 + 100 ) ) {
        int pic=hash->Search_HT(hash->ha,14);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,14);
        txtPath=hash->ha[txt].txtAdress;

        num=24;
        num2=14;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("梅苑小区")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 847-80 && scenePoint.x () <= 847 +70) &&
             (scenePoint.y () >= 600 - 70 && scenePoint.y () <= 600 + 70 ) ) {
        int pic=hash->Search_HT(hash->ha,15);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,15);
        txtPath=hash->ha[txt].txtAdress;

        num=25;
        num2=15;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("校史馆")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 612-70 && scenePoint.x () <= 612 +70) &&
             (scenePoint.y () >= 560 - 70 && scenePoint.y () <= 560 + 70 ) ) {
        int pic=hash->Search_HT(hash->ha,16);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,16);
        txtPath=hash->ha[txt].txtAdress;

        num=5;
        num2=16;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("学生5公寓")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 464-70 && scenePoint.x () <= 464 +70) &&
             (scenePoint.y () >= 534 - 70 && scenePoint.y () <= 534 + 70 ) ) {
        int pic=hash->Search_HT(hash->ha,17);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,17);
        txtPath=hash->ha[txt].txtAdress;

        num=45;
        num2=17;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("大学生服务中心")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 549-50 && scenePoint.x () <= 549 +50) &&
             (scenePoint.y () >= 492 - 50 && scenePoint.y () <= 492 + 50 ) ) {
        int pic=hash->Search_HT(hash->ha,18);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,18);
        txtPath=hash->ha[txt].txtAdress;

        num=1;
        num2=18;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("学生1公寓")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 500-50 && scenePoint.x () <= 500 +50) &&
             (scenePoint.y () >= 453 - 50 && scenePoint.y () <= 453 + 50 ) ) {
        int pic=hash->Search_HT(hash->ha,19);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,19);
        txtPath=hash->ha[txt].txtAdress;

        num=2;
        num2=19;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("学生2公寓")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 542-50 && scenePoint.x () <= 542 +50) &&
             (scenePoint.y () >= 395 - 50 && scenePoint.y () <= 395 + 50 ) ) {
        int pic=hash->Search_HT(hash->ha,20);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,20);
        txtPath=hash->ha[txt].txtAdress;

        num=3;
        num2=20;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("学生3公寓")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 643-60 && scenePoint.x () <= 643 +60) &&
             (scenePoint.y () >= 427 - 60 && scenePoint.y () <= 427 + 60 ) ) {
        int pic=hash->Search_HT(hash->ha,21);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,21);
        txtPath=hash->ha[txt].txtAdress;

        num=33;
        num2=21;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("学苑餐厅")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 746-90 && scenePoint.x () <= 746 +90) &&
             (scenePoint.y () >= 441 - 90 && scenePoint.y () <= 441 + 90 ) ) {
        int pic=hash->Search_HT(hash->ha,22);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,22);
        txtPath=hash->ha[txt].txtAdress;

        num=34;
        num2=22;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("特种陶瓷实验室")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 1030-100 && scenePoint.x () <= 1030 +100) &&
             (scenePoint.y () >= 190 - 100 && scenePoint.y () <= 290 + 100 ) ) {
        int pic=hash->Search_HT(hash->ha,23);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,23);
        txtPath=hash->ha[txt].txtAdress;

        num=12;
        num2=23;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("学生12公寓")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 1126-50 && scenePoint.x () <= 1126 +50) &&
             (scenePoint.y () >= 289 - 50 && scenePoint.y () <= 289 + 50 ) ) {
        int pic=hash->Search_HT(hash->ha,24);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,24);
        txtPath=hash->ha[txt].txtAdress;

        num=26;
        num2=24;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("天雅轩")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 790-70 && scenePoint.x () <= 790 +70) &&
             (scenePoint.y () >= -74 - 70 && scenePoint.y () <= -74 + 70 ) ) {
        int pic=hash->Search_HT(hash->ha,25);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,25);
        txtPath=hash->ha[txt].txtAdress;

        num=29;
        num2=25;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("大学生活动中心")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 890-100 && scenePoint.x () <= 890 +100) &&
             (scenePoint.y () >= -25 - 100 && scenePoint.y () <= -25 + 100 ) ) {
        int pic=hash->Search_HT(hash->ha,26);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,26);
        txtPath=hash->ha[txt].txtAdress;

        num=28;
        num2=26;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("综合球类馆")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 1120-90 && scenePoint.x () <= 1120 +90) &&
             (scenePoint.y () >= 201 - 60 && scenePoint.y () <= 201 + 60 ) ) {
        int pic=hash->Search_HT(hash->ha,27);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,27);
        txtPath=hash->ha[txt].txtAdress;

        num=27;
        num2=27;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("新留学生公寓")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 353-80 && scenePoint.x () <= 353 +80) &&
             (scenePoint.y () >= 360 - 80 && scenePoint.y () <= 360 + 80 ) ) {
        int pic=hash->Search_HT(hash->ha,28);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,28);
        txtPath=hash->ha[txt].txtAdress;

        num=7;
        num2=28;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("学生7公寓")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 482-50 && scenePoint.x () <= 482 +50) &&
             (scenePoint.y () >= 200 - 50 && scenePoint.y () <= 200 + 50 ) ) {
        int pic=hash->Search_HT(hash->ha,29);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,29);
        txtPath=hash->ha[txt].txtAdress;

        num=8;
        num2=29;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("学生8公寓")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 524-60 && scenePoint.x () <= 524 +60) &&
             (scenePoint.y () >= 201 - 60 && scenePoint.y () <= 201 + 60 ) ) {
        int pic=hash->Search_HT(hash->ha,30);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,30);
        txtPath=hash->ha[txt].txtAdress;

        num=9;
        num2=30;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("学生9公寓")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 467-50 && scenePoint.x () <= 467 +50) &&
             (scenePoint.y () >= -152 - 50 && scenePoint.y () <= -152 + 50 ) ) {
        int pic=hash->Search_HT(hash->ha,31);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,31);
        txtPath=hash->ha[txt].txtAdress;

        num=20;
        num2=31;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("北大门")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 1010-50 && scenePoint.x () <= 1010 +50) &&
             (scenePoint.y () >= 1015 - 50 && scenePoint.y () <=1015 + 50 ) ) {
        int pic=hash->Search_HT(hash->ha,32);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,32);
        txtPath=hash->ha[txt].txtAdress;

        num=18;
        num2=32;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("东大门")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 910-50 && scenePoint.x () <= 910 +50) &&
             (scenePoint.y () >= 873 - 50 && scenePoint.y () <= 873 + 50 ) ) {
        int pic=hash->Search_HT(hash->ha,33);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,33);
        txtPath=hash->ha[txt].txtAdress;

        num=23;
        num=23;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("留学生餐厅")) ;
        dialog->show ();
    }
    else if ((scenePoint.x () >= 667-40 && scenePoint.x () <= 667 +40) &&
             (scenePoint.y () >= 233 - 40 && scenePoint.y () <= 233 +40 ) ) {
        int pic=hash->Search_HT(hash->ha,34);
        strPath = hash->ha[pic].pixAdress;
        pix.load (strPath);
        label->setPixmap (pix);
        label->resize(100,200);
        label1->resize(100,200);
        int txt=hash->Search_HT(hash->ha,34);
        txtPath=hash->ha[txt].txtAdress;

        num=43;
        num2=34;
        qDebug()<<txtPath;
        //新建一个QFile对象，“txtPath"是描述建筑信息的文本文件

        QString displayString;
        QFile file(txtPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            displayString=QStringLiteral("暂时没有更多介绍");
            qDebug()<<"Can't open the file!"<<endl;
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            qDebug()<< str;
            displayString.append(str);
        }
           label1->clear();
           label1->setPlainText(displayString);


       // label1->setText ("fahqkjwfh;u   whg;kuwrgh; uwrho\n   ifwoihf 'io whgoeqre");
           QString mapName;
           QString newstxt=QString::number(num2)+".1.txt";
           QFile mapFile(newstxt);
           int ok = mapFile.open (QIODevice::ReadOnly);
           if (ok)
           {
               QTextStream ts(&mapFile);
                   ts >> mapName;              //储存字符串
                   m_showText =mapName;
           }else{
               m_showText=QStringLiteral("暂无更多活动信息");
           }

           QString mapName1;
           QString newstxt1=QString::number(num2)+".2.txt";
           QFile mapFile1(newstxt1);
           int ok1 = mapFile1.open (QIODevice::ReadOnly);
           if (ok1)
           {
               QTextStream ts(&mapFile1);
                   ts >> mapName1;              //储存字符串
                   m_showText1 =mapName1;
           }else{
               m_showText1=QStringLiteral("暂无更多活动信息");
           }

       // m_showText = "This is a textTicker Text!";//显示的文字

        layout->addWidget (label,0,0);
        layout->addWidget (label1,0,1);
        layout->addWidget(m_label,1,0,1,1);
        layout->addWidget(m_label1,2,0,1,1);
        layout->addWidget(news1,1,1,1,1);
        layout->addWidget(news2,2,1,1,1);
        layout->addWidget(morenews,3,0,1,2);
        layout->addWidget (startFrome,4,0,1,1);
        layout->addWidget (endFrome,4,1,1,1);

        dialog->setMinimumSize (400, 400);
        dialog->setWindowTitle (QStringLiteral("学子餐厅")) ;
        dialog->show ();
    }
}

 void MainWindow::setStartFrome(){
       startComboBox->setCurrentIndex(num);
       qDebug()<<num;
 }
 void MainWindow::setEndFrome(){
       endComboBox->setCurrentIndex(num);
       qDebug()<<num;
 }

// 放大
void MainWindow::magnify()
{
    scaling(1+m_scalingOffset);
    qDebug()<<1+m_scalingOffset;
}
// 缩小
void MainWindow::shrink()
{
    scaling(1-m_scalingOffset);
    qDebug()<<1-m_scalingOffset;
}
// 缩放 - scaleFactor：缩放的比例因子
void MainWindow::scaling(qreal scaleFactor)
{
    qreal factor = view->transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100) return;
    qDebug()<<view->sceneRect();
    view->scale(scaleFactor,scaleFactor);
     m_scale *= scaleFactor;
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    QPoint sroll=event->angleDelta();
    sroll.y()>0?magnify():shrink();
}


//跳转界面
void MainWindow::callOtherMap ()
{
    mapWidget = new MapWidget;
     mapWidget->setWeb(1);
    mapWidget->show ();
}
void MainWindow::callMorenews ()
{
    mapWidget = new MapWidget;
    mapWidget->setWeb(2);
    mapWidget->show ();
}

//滚动字幕
void MainWindow::showTicker()
{
    int iSize = m_showText.size();
    if (m_curIndex >= iSize)
        m_curIndex = 0;

    int iSize1 = m_showText1.size();
    if (m_curIndex1 >= iSize)
        m_curIndex1 = 0;

    m_label->setText(m_showText.right(iSize - m_curIndex++));
    m_label1->setText(m_showText1.right(iSize1 - m_curIndex1++));
}
//活动信息弹窗
void MainWindow::news1show(){
    QDialog *newsDialog = new QDialog;
    QGridLayout *newslayout = new QGridLayout(newsDialog);
    QTextEdit *textEdit=new QTextEdit;
    textEdit->resize(100,100);

    QString newstxt=QString::number(num2)+".1.txt";
    QString displayString;
    QFile file(newstxt);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        displayString=QStringLiteral("暂时无更多活动");
        qDebug()<<"Can't open the file!"<<endl;
    }else{
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        qDebug()<< str;
        displayString.append(str);
    }
    }
       textEdit->clear();
       textEdit->setPlainText(displayString);

   // textEdit->setText("1111111111111");
    newslayout->addWidget(textEdit);
    newsDialog->setMinimumSize (400, 400);
    newsDialog->setWindowTitle (QStringLiteral("活动详情"));
    newsDialog->show ();
}
void MainWindow::news2show(){
    QDialog *newsDialog = new QDialog;
    QGridLayout *newslayout = new QGridLayout(newsDialog);
    QTextEdit *textEdit=new QTextEdit;
    textEdit->resize(100,100);

    QString newstxt=QString::number(num2)+".2.txt";
    QString displayString;
    QFile file(newstxt);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        displayString=QStringLiteral("暂时无更多活动");
        qDebug()<<"Can't open the file!"<<endl;
    }else{
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        qDebug()<< str;
        displayString.append(str);
    }
    }
       textEdit->clear();
       textEdit->setPlainText(displayString);

    //textEdit->setText("2222222222222");

    newslayout->addWidget(textEdit);
    newsDialog->setMinimumSize (400, 400);
    newsDialog->setWindowTitle (QStringLiteral("活动详情"));
    newsDialog->show ();
}
