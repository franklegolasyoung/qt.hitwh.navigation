#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>
#include <QLabel>
#include <QPainter>
#include <QBrush>
#include <QPen>

int MainWindow::cnt = 0;
int MainWindow::cntRoad = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->start = 0;
    this->end = 0;
    this->initSite();
    this->initWeight();
    this->initUiweidget();
    this->initDownBox();
    this->Floyd();
    this->setWindowTitle("山东理工大学导游系统");

    this->speed = BusSpeed;

    //信号连接
    this->connect(ui->pushButton_11,&QPushButton::clicked, //字典序排列
                  this,&MainWindow::FindData_1);
    this->connect(ui->pushButton_12,&QPushButton::clicked, //id序排序
                  this,&MainWindow::FindData_2);
    this->connect(ui->pushButton_31,&QPushButton::clicked, //查询最短路径
                  this,&MainWindow::SearchBest);
    this->connect(ui->pushButton,&QPushButton::clicked,    //单源最短路径
                  this,&MainWindow::Dijk);
    this->connect(ui->pushButton_41,&QPushButton::clicked, //查询限定方式路径
                  this,&MainWindow::SearchLimitTool);
    this->connect(ui->pushButton_42,&QPushButton::clicked, //查询限定工具路径
                  this,&MainWindow::SearchLimitTime);
    this->connect(ui->pushButton_51,&QPushButton::clicked, //增加景点
                  this,&MainWindow::AddSite);
    this->connect(ui->pushButton_52,&QPushButton::clicked, //删除景点
                  this,&MainWindow::DeleSite);
    this->connect(ui->pushButton_53,&QPushButton::clicked, //更新景点
                  this,&MainWindow::UpdateSite);
    this->connect(ui->pushButton_63,&QPushButton::clicked, //增加道路
                  this,&MainWindow::AddRoad);
    this->connect(ui->pushButton_61,&QPushButton::clicked, //删除道路
                  this,&MainWindow::DeleRoad);
    this->connect(ui->pushButton_62,&QPushButton::clicked, //更新道路
                  this,&MainWindow::UpdateRoad);
}

/*鼠标点击事件*/
void MainWindow::mousePressEvent(QMouseEvent *mouse)
{
    if(mouse->button() == Qt::LeftButton)
    {
        int x = mouse->x();
        int y = mouse->y();
        QString strx = QString::number(x);
        QString stry = QString::number(y);
        ui->label_53->setText(strx);
        ui->label_54->setText(stry);
    }
    else if(mouse->button() == Qt::RightButton)
    {
        int x = mouse->x();
        int y = mouse->y();
        if(x>=438 && x<=458 && y>=562 && y<=582)
        {
            mylog.ins("山东理工大学南门:是学校的正门，位于新村西路。");
            mylog.show();
        }
        else if(x>=445 && x<=465 && y>=447 && y<=467)
        {
            mylog.ins("山东理工大学鸿远楼：学校最主要办公楼，在南门正北方。");
            mylog.show();
        }
        else if(x>=366 && x<=386 && y>=445 && y<=465)
        {
            mylog.ins("山东理工大学3号教学楼：学校最主要教学楼，公共课上课地点。");
            mylog.show();
        }
        else if(x>=310 && x<=330 && y>=463 && y<=483)
        {
            mylog.ins("山东理工大学1号实验楼: 山东省基础力学示范中心。");
            mylog.show();
        }
        else if(x>=246 && x<=266 && y>=403 && y<=423)
        {
            mylog.ins("山东理工大学逸夫图书馆：馆藏图书总量611万册，并荣获2008年度“建筑工程鲁班奖”。");
            mylog.show();
        }
        else if(x>=321 && x<=341 && y>=123 && y<= 143)
        {
            mylog.ins("山东理工大学3号餐厅：三层建筑。");
            mylog.show();
        }
        else if(x>=259 && x<=279 && y>=121 && y<=141)
        {
            mylog.ins("山东理工大学6号宿舍楼：位于三餐西面。");
            mylog.show();
        }
        else if(x>=345 && x<=365 && y>=390 && y<=410)
        {
            mylog.ins("山东理工大学2号体育场：是举办运动会使用的场地。");
            mylog.show();
        }
        else if(x>=189 && x<=209 && y>=167 && y<=187)
        {
            mylog.ins("位于理工长廊。");
            mylog.show();
        }
        else if(x>=176 && x<=196 && y>=455 && y<=475)
        {
            mylog.ins("在南门进门的主要街道两旁，占地面积庞大.");
            mylog.show();
        }
    }
}

/*绘图函数*/
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);

    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);

    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::Dense1Pattern);

    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawPixmap(0,0,width()*2/3,height(),QPixmap("../image/hua.png"));

    for(int i=1; i<=cnt; i++)
    {
        int x = site[i].getX().toInt();
        int y = site[i].getY().toInt();
        painter.drawEllipse(QPoint(x,y),10,10);
    }

    for(int i=1; i<=cntRoad; i++)
    {
        int u = road[i].getBeginSite();
        int v = road[i].getEndSite();
        int s,e;
        int flag1=0,flag2=0;
        for(int j=1; j<=cnt; j++)
        {
            if(u == site[j].getId().toInt())
            {
                s = j;
                flag1 = 1;
                break;
            }
        }
        for(int j=1; j<=cnt; j++)
        {
            if(v == site[j].getId().toInt())
            {
                e = j;
                flag2 = 1;
                break;
            }
        }
        if(flag1 && flag2)
        {
            int x1 = site[s].getX().toInt();
            int y1 = site[s].getY().toInt();
            int x2 = site[e].getX().toInt();
            int y2 = site[e].getY().toInt();
            painter.drawLine(x1,y1,x2,y2);
        }
    }

    if(this->start!=0 && this->end!=0)
    {
        int temp = this->start;
        while(temp != this->end)
        {
            int mid = path[temp][end];
            int x1 = site[temp].getX().toInt();
            int y1 = site[temp].getY().toInt();
            int x2 = site[mid].getX().toInt();
            int y2 = site[mid].getY().toInt();
            pen.setColor(Qt::blue);
            painter.setPen(pen);
            painter.drawLine(x1,y1,x2,y2);
            temp = mid;
        }
    }

    this->start = this->end = 0;
    painter.end();
}

/*顺序查找(按照名称查找编号)*/
int MainWindow::Search(QString key)
{
    for(int i = 1; i <= cnt; ++i)
    {
        if(site[i].getName() == key)
        {
            return site[i].getId().toInt();
        }
    }
    return -1;
}


/*哈希建表*/
void MainWindow::HashCreate(int k)
{
    int id = site[k].getId().toInt();
    int i = id % 99;
    while(1)
    {
        if(hash[i].getId() == NULL)
        {
            this->hash[i] = site[k];
            break;
        }
        else
        {
            i++;
            i %= 99;
        }
    }
}

/*哈希查找(根据编号查找名称)*/
QString MainWindow::HashSearch(int key)
{
    if(this->hash[key].getId() != NULL)
    {
        return this->hash[key].getName();
    }
    else
    {
        return "NULL";
    }
}

/*二分查找(根据编号查找名称2)*/
QString MainWindow::BinSearch(int key)
{
    this->MergeSort(1,cnt);
    int left,right;
    left = 1;
    right = cnt;
    while( left <= right)
    {
        int mid = (left + right)/2;
        if(site[mid].getId().toInt() == key)
        {
            return site[mid].getName();
        }
        else if(site[mid].getId().toInt() > key)
        {
            right = mid;
        }
        else
            left = mid + 1;
    }
    return "NULL";
}

//所有路径(top条)
int top = 0;
int line[100][100];
//栈
int p[100];
int step = 1;
//标记数组
int book[100];      //标记数组
//DFS(图的遍历)
void MainWindow::DFS(int s,int e)
{
    if(s == e)
    {
        if(top<=10)
        {
            ++top;
            for(int i=1; i<=step ;i++)
            {
                line[top][i] = p[i];
            }
        }
    }
    else
    {
        for(int next=1; next<=cnt ;next++)
        {
            if(dis[s][next]!=MAX && dis[s][next]!=0 && book[next]==0)
            {
                step++;
                p[step] = next;
                book[next] = 1;
                DFS(next,e);
                book[next] = 0;
                step--;
            }
        }
    }
}

/*查询所有路径*/
void MainWindow::SearchAll()
{
    top = 0;

    QString startSite = ui->comboBox_21->currentText();
    QString endSite = ui->comboBox_22->currentText();
    ui->listWidgetAll->clear();
    qDebug()<<startSite<<endSite;
    int s = this->Search(startSite);
    int e = this->Search(endSite);
    qDebug()<<s<<e;
    for(int i = 1; i<=99 ;i++)
    {
        book[i] = 0;
        p[i] = 0;
        for(int j=1; j<=cnt ;j++)
        {
            line[i][j] = 0;
        }
    }

    book[s] = 1;
    p[1] = s;
    this->DFS(s,e);
    for(int i=1; i<=top ;i++)
    {
        QString str;
        QString pos = BinSearch(s);
        str += pos;
        for(int j=2; j<=cnt ;j++)
        {
            if(line[i][j])
            {
                str += "-->";
                str += this->BinSearch(line[i][j]);
            }
            else
            {
                break;
            }
        }
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(str);
        ui->listWidgetAll->addItem(item);
    }
}

/*最优路径*/
void MainWindow::SearchBest()
{
    QString start = ui->comboBox_31->currentText();
    QString end = ui->comboBox_32->currentText();
    this->start = this->Search(start);
    this->end = this->Search(end);
    ui->listWidgetBest->clear();
    if(ui->comboBox_33->currentIndex() == 0) //最优时间
    {
        this->SearchDis();
        update();
    }
    else if(ui->comboBox_33->currentIndex() == 1)  //最优距离
    {
        this->SearchTime();
        update();
    }
}

/*时间最优*/
void MainWindow::SearchTime()
{
    this->initPath();
    this->initMap();
    for(int k = 1; k <=cnt; k++)
    {
        for(int i = 1; i <=cnt; i++)
        {
            for(int j = 1; j <=cnt; j++)
            {
                if(map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
    int temp = start;
    QString t;
    t = site[start].getName();
    QListWidgetItem *item1 = new QListWidgetItem;
    item1->setText(t);
    ui->listWidgetBest->addItem(item1);
    while(temp != end)
    {
        for(int i = 1; i <= cnt; ++i)
        {
            if(site[i].getId().toInt() == path[temp][end])
            {
                t = site[i].getName();
            }
        }
        QListWidgetItem *item2 = new QListWidgetItem;
        item2->setText(t);
        ui->listWidgetBest->addItem(item2);
        temp = path[temp][end];
    }
    QListWidgetItem *cost = new QListWidgetItem;
    cost->setText(QString("花费时间: %1秒").arg(map[start][end]/this->speed));
    ui->listWidgetBest->addItem(cost);
}

/*距离最优*/
void MainWindow::SearchDis()
{
    this->initPath();
    this->initMap();
    for(int k = 1; k <=cnt; k++)
    {
        for(int i = 1; i <=cnt; i++)
        {
            for(int j = 1; j <=cnt; j++)
            {
                if(map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
    int temp = start;
    QString t;
    t = site[start].getName();
    QListWidgetItem *item1 = new QListWidgetItem;
    item1->setText(t);
    ui->listWidgetBest->addItem(item1);
    while(temp != end)
    {
        for(int i = 1; i <= cnt; ++i)
        {
            if(site[i].getId().toInt() == path[temp][end])
            {
                t = site[i].getName();
            }
        }
        QListWidgetItem *item2 = new QListWidgetItem;
        item2->setText(t);
        ui->listWidgetBest->addItem(item2);
        temp = path[temp][end];
    }
    QListWidgetItem *cost = new QListWidgetItem;
    cost->setText(QString("距离长度: %1米").arg(map[start][end]));
    ui->listWidgetBest->addItem(cost);
}

/*限定方式路径*/
void MainWindow::SearchLimitTool()
{
    QString s = ui->comboBox_41->currentText();
    QString e = ui->comboBox_42->currentText();
    this->start = this->Search(s);
    this->end = this->Search(e);
    this->initPath();
    this->initMap();
    ui->listWidgetLimit->clear();
    int choose = ui->comboBox_43->currentIndex();
    if(choose == 0) //步行
    {
        this->speed = 1;
        for(int k = 1; k <=cnt; k++)
        {
            for(int i = 1; i <=cnt; i++)
            {
                for(int j = 1; j <=cnt; j++)
                {
                    if(map[i][j] > map[i][k] + map[k][j])
                    {
                        map[i][j] = map[i][k] + map[k][j];
                        path[i][j] = path[i][k];
                    }
                }
            }
        }
        int temp = start;
        QString t;
        t = site[start].getName();
        QListWidgetItem *item1 = new QListWidgetItem;
        item1->setText(t);
        ui->listWidgetLimit->addItem(item1);
        while(temp != end)
        {
            for(int i = 1; i <= cnt; ++i)
            {
                if(site[i].getId().toInt() == path[temp][end])
                {
                    t = site[i].getName();
                }
            }
            QListWidgetItem *item2 = new QListWidgetItem;
            item2->setText(t);
            ui->listWidgetLimit->addItem(item2);
            temp = path[temp][end];
        }
        QListWidgetItem *cost = new QListWidgetItem;
        cost->setText(QString("步行花费时间: %1秒").arg(map[start][end]/this->speed));
        ui->listWidgetLimit->addItem(cost);
    }
    else if(choose == 1) //bus
    {
        this->speed = BusSpeed;
        for(int k = 1; k <=cnt; k++)
        {
            for(int i = 1; i <=cnt; i++)
            {
                for(int j = 1; j <=cnt; j++)
                {
                    if(map[i][j] > map[i][k] + map[k][j])
                    {
                        map[i][j] = map[i][k] + map[k][j];
                        path[i][j] = path[i][k];
                    }
                }
            }
        }
        int temp = start;
        QString t;
        t = site[start].getName();
        QListWidgetItem *item1 = new QListWidgetItem;
        item1->setText(t);
        ui->listWidgetLimit->addItem(item1);
        while(temp != end)
        {
            for(int i = 1; i <= cnt; ++i)
            {
                if(site[i].getId().toInt() == path[temp][end])
                {
                    t = site[i].getName();
                }
            }
            QListWidgetItem *item2 = new QListWidgetItem;
            item2->setText(t);
            ui->listWidgetLimit->addItem(item2);
            temp = path[temp][end];
        }
        QListWidgetItem *cost = new QListWidgetItem;
        cost->setText(QString("坐公交车花费时间: %1秒").arg(map[start][end]/this->speed));
        ui->listWidgetLimit->addItem(cost);
    }
    else if(choose == 2) //bike
    {
        this->speed = BikeSpeed;
        for(int k = 1; k <=cnt; k++)
        {
            for(int i = 1; i <=cnt; i++)
            {
                for(int j = 1; j <=cnt; j++)
                {
                    if(map[i][j] > map[i][k] + map[k][j])
                    {
                        map[i][j] = map[i][k] + map[k][j];
                        path[i][j] = path[i][k];
                    }
                }
            }
        }
        int temp = start;
        QString t;
        t = site[start].getName();
        QListWidgetItem *item1 = new QListWidgetItem;
        item1->setText(t);
        ui->listWidgetLimit->addItem(item1);
        while(temp != end)
        {
            for(int i = 1; i <= cnt; ++i)
            {
                if(site[i].getId().toInt() == path[temp][end])
                {
                    t = site[i].getName();
                }
            }
            QListWidgetItem *item2 = new QListWidgetItem;
            item2->setText(t);
            ui->listWidgetLimit->addItem(item2);
            temp = path[temp][end];
        }
        QListWidgetItem *cost = new QListWidgetItem;
        cost->setText(QString("骑共享单车花费时间: %1秒").arg(map[start][end]/this->speed));
        ui->listWidgetLimit->addItem(cost);
    }
    update();
}

/*限定时间路径*/
void MainWindow::SearchLimitTime()
{
    ui->listWidgetLimit->clear();
    int LimitTime = ui->spinBox_41->text().toInt();
    QString s = ui->comboBox_41->currentText();
    QString e = ui->comboBox_42->currentText();
    this->start = this->Search(s);
    this->end = this->Search(e);
    this->initPath();
    this->initMap();
    this->speed = 10;
    for(int k = 1; k <=cnt; k++)
    {
        for(int i = 1; i <=cnt; i++)
        {
            for(int j = 1; j <=cnt; j++)
            {
                if(map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }

    if(dis[start][end]/this->speed < LimitTime)
    {
        int temp = start;
        QString t;
        t = site[start].getName();
        QListWidgetItem *item1 = new QListWidgetItem;
        item1->setText(t);
        ui->listWidgetLimit->addItem(item1);
        while(temp != end)
        {
            for(int i = 1; i <= cnt; ++i)
            {
                if(site[i].getId().toInt() == path[temp][end])
                {
                    t = site[i].getName();
                }
            }
            QListWidgetItem *item2 = new QListWidgetItem;
            item2->setText(t);
            ui->listWidgetLimit->addItem(item2);
            temp = path[temp][end];
        }
        QListWidgetItem *cost = new QListWidgetItem;
        cost->setText(QString("花费时间: %1").arg(map[start][end]/this->speed));
        ui->listWidgetLimit->addItem(cost);
    }
    else
    {
        QListWidgetItem *mes = new QListWidgetItem;
        mes->setText("暂无");
        ui->listWidgetLimit->addItem(mes);
    }
    update();
}

/*归并排序*/
void MainWindow::MSort(int l,int mid,int r)
{
    int i = l;
    int j = mid+1;
    int k = l;
    while(i<=mid && j<=r)
    {
        if(tep[i].getId().toInt() <= tep[j].getId().toInt())
        {
            s[k++] = tep[i++];
        }
        else
        {
            s[k++] = tep[j++];
        }
    }
    while(i<=mid)
    {
        s[k++] = tep[i++];
    }
    while(j<=r)
    {
        s[k++] = tep[j++];
    }
    for(i=l; i<=r ;i++)
    {
        tep[i] = s[i];
    }
}

/*归并排序主函数*/
void MainWindow::MergeSort(int l,int r)
{
    int mid = (l+r)/2;
    if(l<r)
    {
        MergeSort(l,mid);
        MergeSort(mid+1,r);
        MSort(l,mid,r);
    }
}

/*快排*/
void MainWindow::QSort(int low,int hight)
{
    if(low >= hight)
        return ;
    int i = low;
    int j = hight;
    mySite temp = tep[i];
    QString key = tep[i].getPinyin();
    while(i < j)
    {
        while( i < j && tep[j].getPinyin() >= key)
            j--;
        tep[i] = tep[j];
        while( i < j && tep[i].getPinyin() <= key)
            i++;
        tep[j] = tep[i];
    }
    tep[i] = temp;
    QSort(low,i-1);
    QSort(i+1,hight);
}

/*查询景点信息(按照字典序)*/
void MainWindow::FindData_1()
{
    for(int i=1; i<=cnt ;i++)
    {
        tep[i] = site[i];
    }
    this->QSort(1,cnt);

    ui->tableWidgetFind->setRowCount(cnt); //行数
    ui->tableWidgetFind->setColumnCount(4); //列数
    QStringList lstr;
    lstr<<"编号"<<"名称"<<"X"<<"Y";
    ui->tableWidgetFind->setHorizontalHeaderLabels(lstr); //表头
    for(int i = 1; i <= cnt; i++)
    {

        QTableWidgetItem *item1 = new QTableWidgetItem; //id
        QTableWidgetItem *item2 = new QTableWidgetItem; //name
        QTableWidgetItem *item3 = new QTableWidgetItem; //x
        QTableWidgetItem *item4 = new QTableWidgetItem; //y
        QString str = tep[i].getName();
        QString id = tep[i].getId();
        QString x = tep[i].getX();
        QString y = tep[i].getY();
        item1->setText(id);
        item2->setText(str);
        item3->setText(x);
        item4->setText(y);
        ui->tableWidgetFind->setItem(i-1,0,item1);
        ui->tableWidgetFind->setItem(i-1,1,item2);
        ui->tableWidgetFind->setItem(i-1,2,item3);
        ui->tableWidgetFind->setItem(i-1,3,item4);
    }
}

/*查询景点信息(按照编号)*/
void MainWindow::FindData_2()
{
    for(int i=1; i<=cnt ;i++)
    {
        tep[i] = site[i];
    }
    this->MergeSort(1,cnt);

    ui->tableWidgetFind->setRowCount(cnt); //行数
    ui->tableWidgetFind->setColumnCount(4); //列数
    QStringList lstr;
    lstr<<"编号"<<"名称"<<"X"<<"Y";
    ui->tableWidgetFind->setHorizontalHeaderLabels(lstr); //表头
    for(int i=1; i<=cnt; i++)
    {
        QTableWidgetItem *item1 = new QTableWidgetItem; //id
        QTableWidgetItem *item2 = new QTableWidgetItem; //name
        QTableWidgetItem *item3 = new QTableWidgetItem; //x
        QTableWidgetItem *item4 = new QTableWidgetItem; //y
        QString str = tep[i].getName();
        QString id = tep[i].getId();
        QString x = tep[i].getX();
        QString y = tep[i].getY();
        item1->setText(id);
        item2->setText(str);
        item3->setText(x);
        item4->setText(y);
        ui->tableWidgetFind->setItem(i-1,0,item1);
        ui->tableWidgetFind->setItem(i-1,1,item2);
        ui->tableWidgetFind->setItem(i-1,2,item3);
        ui->tableWidgetFind->setItem(i-1,3,item4);
    }
}

/*新增景点*/
void MainWindow::AddSite()
{
    QString siteName = ui->lineEdit_51->text();
    QString sitePin = ui->lineEdit_52->text();
    QString x = ui->label_53->text();
    QString y = ui->label_54->text();

    site[++cnt].init(x,y,siteName,"",sitePin);

    ui->lineEdit_51->clear();
    ui->lineEdit_52->clear();
    ui->label_53->setText("点击图获取");
    ui->label_54->setText("点击图获取");

    this->initUiweidget();
    update();
}

/*删除景点*/
void MainWindow::DeleSite()
{
    int i = ui->tableWidgetSite->currentRow();

    for(int j=i+1;j<=cnt;j++)
    {
        site[j] = site[j+1];
    }

    this->cnt--;

    this->initUiweidget();
    update();
}

/*更新景点*/
void MainWindow::UpdateSite()
{
    int i = ui->tableWidgetSite->currentRow();

    QString siteName = ui->lineEdit_51->text();
    QString sitePin = ui->lineEdit_52->text();
    QString x = ui->label_53->text();
    QString y = ui->label_54->text();

    site[i+1].init(x,y,siteName,"",sitePin);

    ui->lineEdit_51->clear();
    ui->lineEdit_52->clear();
    ui->label_53->setText("点击图获取");
    ui->label_54->setText("点击图获取");

    this->initUiweidget();
    update();
}

/*增加道路*/
void MainWindow::AddRoad()
{
    QString start = ui->comboBox_61->currentText();
    QString end = ui->comboBox_62->currentText();
    QString weight = ui->lineEdit_61->text();
    int u = this->Search(start);
    int v = this->Search(end);
    int w = weight.toInt();
    dis[u][v] = dis[v][u] = w;
    road[++cntRoad].init(u,v,w);
    this->initUiweidget();
    ui->lineEdit_61->clear();
    update();
}

/*删除道路*/
void MainWindow::DeleRoad()
{
    int i = ui->tableWidgetRoad->currentRow();
    qDebug()<<"i:"<<i;
    QTableWidgetItem *item1 = ui->tableWidgetRoad->takeItem(i,0);
    QTableWidgetItem *item2 = ui->tableWidgetRoad->takeItem(i,1);
    QString start = item1->text();
    QString end = item2->text();
    this->start = start.toInt();
    this->end = end.toInt();
    dis[this->start][this->end] = dis[this->end][this->start] = MAX;
    for(int j=i+1; j<=cntRoad; j++)
    {
        road[j] = road[j+1];
    }
    cntRoad--;
    this->initUiweidget();
    update();
}

/*更新道路*/
void MainWindow::UpdateRoad()
{
    int i = ui->tableWidgetRoad->currentRow();
    QString start = ui->comboBox_61->currentText();
    QString end = ui->comboBox_62->currentText();
    QString weight = ui->lineEdit_61->text();
    int u = this->Search(start);
    int v = this->Search(end);
    int w = weight.toInt();
    dis[u][v] = dis[v][u] = w;
    road[i+1].init(u,v,w);
    ui->lineEdit_61->clear();
    this->initUiweidget();
    update();
}

/*初始化下拉框*/
void MainWindow::initDownBox()
{
    //allroad->Comboxox1
    for(int i = 1; i <= cnt; ++i)
    {
        QString siteName = site[i].getName();
        ui->comboBox_21->addItem(siteName);
        ui->comboBox_22->addItem(siteName);
        ui->comboBox_31->addItem(siteName);
        ui->comboBox_32->addItem(siteName);
        ui->comboBox_41->addItem(siteName);
        ui->comboBox_42->addItem(siteName);
        ui->comboBox_61->addItem(siteName);
        ui->comboBox_62->addItem(siteName);
        ui->comboBox->addItem(siteName);
    }
}

/*初始化ui容器*/
void MainWindow::initUiweidget()
{
    ui->tableWidgetAll->setRowCount(cnt); //行数
    ui->tableWidgetAll->setColumnCount(4); //列数
    QStringList lstr;
    lstr<<"编号"<<"名称"<<"X轴坐标"<<"Y轴坐标";
    ui->tableWidgetAll->setHorizontalHeaderLabels(lstr); //表头
    for(int i = 1; i <= cnt; i++)
    {
        QTableWidgetItem *item1 = new QTableWidgetItem; //id
        QTableWidgetItem *item2 = new QTableWidgetItem; //name
        QTableWidgetItem *item3 = new QTableWidgetItem; //x
        QTableWidgetItem *item4 = new QTableWidgetItem; //y
        QString str = site[i].getName();
        QString id = site[i].getId();
        QString x = site[i].getX();
        QString y = site[i].getY();
        item1->setText(id);
        item2->setText(str);
        item3->setText(x);
        item4->setText(y);
        ui->tableWidgetAll->setItem(i-1,0,item1);
        ui->tableWidgetAll->setItem(i-1,1,item2);
        ui->tableWidgetAll->setItem(i-1,2,item3);
        ui->tableWidgetAll->setItem(i-1,3,item4);
    }
    ui->tableWidgetBest->setRowCount(cnt); //行数
    ui->tableWidgetBest->setColumnCount(4); //列数
    ui->tableWidgetBest->setHorizontalHeaderLabels(lstr); //表头
    for(int i = 1; i <= cnt; i++)
    {
        QTableWidgetItem *item1 = new QTableWidgetItem; //id
        QTableWidgetItem *item2 = new QTableWidgetItem; //name
        QTableWidgetItem *item3 = new QTableWidgetItem; //x
        QTableWidgetItem *item4 = new QTableWidgetItem; //y
        QString str = site[i].getName();
        QString id = site[i].getId();
        QString x = site[i].getX();
        QString y = site[i].getY();
        item1->setText(id);
        item2->setText(str);
        item3->setText(x);
        item4->setText(y);
        ui->tableWidgetBest->setItem(i-1,0,item1);
        ui->tableWidgetBest->setItem(i-1,1,item2);
        ui->tableWidgetBest->setItem(i-1,2,item3);
        ui->tableWidgetBest->setItem(i-1,3,item4);
    }
    ui->tableWidgetLimit->setRowCount(cnt); //行数
    ui->tableWidgetLimit->setColumnCount(4); //列数
    ui->tableWidgetLimit->setHorizontalHeaderLabels(lstr); //表头
    for(int i = 1; i <= cnt; i++)
    {
        QTableWidgetItem *item1 = new QTableWidgetItem; //id
        QTableWidgetItem *item2 = new QTableWidgetItem; //name
        QTableWidgetItem *item3 = new QTableWidgetItem; //x
        QTableWidgetItem *item4 = new QTableWidgetItem; //y
        QString str = site[i].getName();
        QString id = site[i].getId();
        QString x = site[i].getX();
        QString y = site[i].getY();
        item1->setText(id);
        item2->setText(str);
        item3->setText(x);
        item4->setText(y);
        ui->tableWidgetLimit->setItem(i-1,0,item1);
        ui->tableWidgetLimit->setItem(i-1,1,item2);
        ui->tableWidgetLimit->setItem(i-1,2,item3);
        ui->tableWidgetLimit->setItem(i-1,3,item4);
    }
    ui->tableWidgetSite->setRowCount(cnt); //行数
    ui->tableWidgetSite->setColumnCount(4); //列数
    ui->tableWidgetSite->setHorizontalHeaderLabels(lstr); //表头
    for(int i = 1; i <= cnt; i++)
    {
        QTableWidgetItem *item1 = new QTableWidgetItem; //id
        QTableWidgetItem *item2 = new QTableWidgetItem; //name
        QTableWidgetItem *item3 = new QTableWidgetItem; //x
        QTableWidgetItem *item4 = new QTableWidgetItem; //y
        QString str = site[i].getName();
        QString id = site[i].getId();
        QString x = site[i].getX();
        QString y = site[i].getY();
        item1->setText(id);
        item2->setText(str);
        item3->setText(x);
        item4->setText(y);
        ui->tableWidgetSite->setItem(i-1,0,item1);
        ui->tableWidgetSite->setItem(i-1,1,item2);
        ui->tableWidgetSite->setItem(i-1,2,item3);
        ui->tableWidgetSite->setItem(i-1,3,item4);
    }

    ui->tableWidgetRoad->setRowCount(cntRoad); //行数
    ui->tableWidgetRoad->setColumnCount(3); //列数
    QStringList lstr2;
    lstr2<<"起始点"<<"终止点"<<"路径长度";
    ui->tableWidgetRoad->setHorizontalHeaderLabels(lstr2); //表头

    int count = 0;
    for(int i = 1; i <= cntRoad; i++)
    {
        int s = road[i].getBeginSite();
        int e = road[i].getEndSite();

        int flag1=0,flag2=0;
        for(int j=1; j<=cnt; j++)
        {
            if(site[j].getId().toInt() == s)
            {
                flag1 = 1;
                break;
            }
        }

        for(int j=1; j<=cnt; j++)
        {
            if(site[j].getId().toInt() == e)
            {
                flag2 = 1;

                break;
            }
        }

        if(flag1 && flag2)
        {
            QString str1 = this->BinSearch(s);
            QString str2 = this->BinSearch(e);
            int ww = road[i].getDistance();

            QTableWidgetItem *item1 = new QTableWidgetItem; //起始点
            item1->setText(str1);
            QTableWidgetItem *item2 = new QTableWidgetItem; //终止点
            item2->setText(str2);
            QTableWidgetItem *item3 = new QTableWidgetItem; //权重
            QString w = QString::number(ww);
            item3->setText(w);

            ui->tableWidgetRoad->setItem(count,0,item1);
            ui->tableWidgetRoad->setItem(count,1,item2);
            ui->tableWidgetRoad->setItem(count,2,item3);
            count++;
        }
    }
}

/*初始化景点函数*/
void MainWindow::initSite()
{
    site[++cnt].init("448","572","大门","","damen");   //1

    site[++cnt].init("455","457","办公楼","","bangonglou");   //2

    site[++cnt].init("376","455","教学楼","","jiaoxuelou");   //3

    site[++cnt].init("320","473","实验楼","","shiyanlou");   //4

    site[++cnt].init("256","413","图书馆","","tushuguan");   //5

    site[++cnt].init("331","133","食堂","","shitang");   //6

    site[++cnt].init("269","131","宿舍楼","","sushelou");   //7

    site[++cnt].init("355","400","体育场馆","","tiyuchangguan");   //8

    site[++cnt].init("199","177","商场","","shangchang");    //9

    site[++cnt].init("186","465","自然景区","","ziranjingqu");    //10
    //this->LoadObject();
    //this->SaveObject();
    for(int i=1; i<=cnt ;i++)
    {
        this->HashCreate(i);
    }

}

/*初始化道路*/
void MainWindow::initWeight()
{
    int i,j;
    for(i=0;i<=cnt;i++)
    {
        for(j=0;j<=cnt;j++)
        {
            if(i==j)
            {
                dis[i][j] = 0;
            }
            else
            {
                dis[i][j] =  MAX;
            }
        }
    }
    dis[1][2] = dis[2][1] = 300;
    dis[1][3] = dis[3][1] = 400;
    dis[1][10] = dis[10][1] = 800;
    dis[2][3] = dis[3][2] = 150;
    dis[2][8] = dis[8][2] = 300;
    dis[3][4] = dis[4][3] = 100;
    dis[3][8] = dis[8][3] = 110;
    dis[4][5] = dis[5][4] = 200;
    dis[4][10] = dis[10][4] = 250;
    dis[5][7] = dis[7][5] = 1000;
    dis[5][8] = dis[8][5] = 260;
    dis[5][10] = dis[10][5] = 180;
    dis[6][7] = dis[7][6] = 80;
    dis[6][8] = dis[8][6] = 900;
    dis[9][10] = dis[10][9] = 850;
    dis[7][9] = dis[9][7] = 120;
    road[++cntRoad].init(1,2,300);
    road[++cntRoad].init(1,3,400);
    road[++cntRoad].init(1,10,800);
    road[++cntRoad].init(2,3,150);
    road[++cntRoad].init(2,8,300);
    road[++cntRoad].init(3,4,100);
    road[++cntRoad].init(3,8,110);
    road[++cntRoad].init(4,5,200);
    road[++cntRoad].init(4,10,250);
    road[++cntRoad].init(5,7,1000);
    road[++cntRoad].init(5,8,260);
    road[++cntRoad].init(5,10,180);
    road[++cntRoad].init(6,7,80);
    road[++cntRoad].init(6,8,900);
    road[++cntRoad].init(9,10,850);
    road[++cntRoad].init(7,9,120);
}

/*初始化map[][]数组*/
void MainWindow::initMap()
{
    for(int i=0;i<=cnt;i++)
    {
        for(int j=0;j<=cnt;j++)
        {
            map[i][j] = dis[i][j];
        }
    }
}

/*初始化path[][]数组*/
void MainWindow::initPath()
{
    for(int i=0;i<=cnt;i++)
    {
        for(int j=0;j<=cnt;j++)
        {
            if(dis[i][j]!=MAX)
            {
                path[i][j] = j;
            }
            else
            {
                path[i][j] = 0;
            }
        }
    }
}

/*保存dis数组*/
void MainWindow::SaveData()
{
    QFile file("dis.txt");
    bool isOK = file.open(QIODevice::WriteOnly|QIODevice::Text);
    if(isOK)
    {
        QTextStream out(&file);
        for(int i = 1; i <= 99; i++)
        {
            for(int j = 1; j <= 99; j++)
            {
                out<<dis[i][j]<<',';
            }
            out<<'\n';
        }
        file.close();
    }
}

/*从文件中提取数组*/
void MainWindow::LoadData()
{
    int i = 0;
    int j = 0;
    QFile file("dis.txt");
    bool isOK = file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(true == isOK)
    {
        QTextStream t(&file);
        while(! t.atEnd())
        {
            i++;
            QString p = t.readLine();
            QStringList q = p.split(',',QString::SkipEmptyParts);
            for(j = 0; j < 99; ++j)
            {
                dis[i][j+1]=q[j].toInt();
            }
        }

    }
}

/*将对象数组保存到文件*/
void MainWindow::SaveObject()
{
    int len1 = sizeof(site[1]);
    fstream fs;
    fs.open("dataObject.txt",ios_base::out|ios_base::trunc);

    for(int i=1; i<=cnt ;i++)
    {
        fs.write((char*)&site[i],len1);
    }

    fs.close();
}

/*从文件中读取对象数组*/
void MainWindow::LoadObject()
{
    int len1 = sizeof(site[1]);
    fstream fs;
    fs.open("dataObject.txt",ios_base::in);

    for(int i=1; !fs.eof(); i++)
    {
        ++cnt;
        fs.read((char*)&site[i],len1);
    }

    fs.close();
}

/*单源最短路径*/
bool visited[100];//dijkstra 标记
int pass[100]; //路径
int dist[100]; //源点至其他最短距离
void MainWindow::Dijk()
{
    ui->listWidget->clear();
    QString source = ui->comboBox->currentText();
    int id = this->Search(source);
    this->Dijkstra(id);
    int t;
    for(int i = 1; i <= cnt; ++i)
    {
        QString p;
        QString q;
        QString name;
        name = this->BinSearch(i);
        p += "到" + name + "的距离为: ";
        p += QString::number(dist[i]);
        p += " 路径为：";
        if(i != id)
        {
            q = this->BinSearch(i);
            p += q;
            t = pass[i];
            while(t != id)
            {
                p += "<--";
                q = this->BinSearch(t);
                p += q;
                t = pass[t];
            }
            p += "<--";
            q = this->BinSearch(id);
            p += q;
        }
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(p);
        ui->listWidget->addItem(item);
    }

}

/*Floyd:求两点之间最短路*/
void MainWindow::Floyd()
{
    this->initPath();
    this->initMap();
    for(int k = 1; k <=cnt; k++)
    {
        for(int i = 1; i <=cnt; i++)
        {
            for(int j = 1; j <=cnt; j++)
            {
                if(map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
}

/*Dijkstra:求单源最短路径*/
void MainWindow::Dijkstra(int source)
{
    for(int i = 1; i <= cnt; ++i)
    {
        visited[i] = false;
        dist[i] = dis[source][i];
        pass[i] = source;
    }
    visited[source] = true;
    int minCost,minCostIndex;
    for(int i = 1; i <= cnt; ++i)
    {
        minCost = MAX;
        for(int j = 1; j <= cnt; ++j)
        {
            if(visited[j] == false && dist[j] < minCost)
            {
                minCost = dist[j];
                minCostIndex = j;
            }
        }
        visited[minCostIndex] = true;
        for(int j = 1 ; j <= cnt; j++)
        {
            if(visited[j] == false &&
                    dis[minCostIndex][j] != MAX &&
                    dis[minCostIndex][j] != 0   &&
                    dis[minCostIndex][j] + minCost < dist[j])
            {
                dist[j] = dis[minCostIndex][j] + minCost;
                pass[j] = minCostIndex;
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_21_clicked()
{
    this->SearchAll();
}
