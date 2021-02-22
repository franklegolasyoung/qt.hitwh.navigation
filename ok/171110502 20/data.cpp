#include "data.h"

#include<QDebug>

Data::Data()
{
    //从文本读取数据
    QString file = ":/Data";
    ReadData(file);
    calculate();

}

int Data::getId(QString name) const
{
    for(auto it = record.begin();it!=record.end();it++){
        if(it.key() == name)
            return it.value();
    }
    return -1;
}

QString Data::getName(int id) const
{
    for(auto it = record.begin();it!=record.end();it++){
        if(it.value() == id)
            return it.key();
    }
    return "";
}

ViewSpot Data::getById(int id) const
{
    if(id<viewSpots.size() && id>=0)
        return viewSpots[id];
    ViewSpot none;
    return none;
}

ViewSpot Data::getByName(QString name) const
{
    int id = getId(name);
    return getById(id);
}

int Data::getViewSpotNum() const
{
    return ViewSpotNum;
}

int Data::isExist(QString name) const
{

    int id = getId(name);

    if(id<0 || id>=ViewSpotNum)
        return -1;
    return id;
}

QVector<QString> Data::getNames() const
{
    QVector<QString> names;
    for(auto it = record.begin();it!=record.end();it++){
        names.push_back(it.key());
    }
    return names;
}

QVector<int> Data::getRoad(int startId, int endId)
{

    QVector<int> result;
    if(startId == endId)
        return result;

    for(int i=0;i<ViewSpotNum;i++)
    {
        for(int j=0;j<ViewSpotNum;j++)
        {
            if(map.vertexs[i] == startId && map.vertexs[j] == endId)
            {
                result.push_front(endId);
                int k = Road[i][j];
                while(k!=i)
                {
                    result.push_front(map.vertexs[k]);
                    k = Road[i][k];
                }
                result.push_front(startId);
            }
        }
    }

    return result;
}

QPoint Data::getPosition(int id)const
{
    return getById(id).getLocation();
}

QString Data::getInfo(int id) const
{
    return getById(id).getInfo();
}

void Data::Init()
{
    int position[ViewSpotNumMAX][2]={
        {512,777},
        {267,504},
        {154,92},
        {671,687},
        {354,332},
        {275,232},
        {328,386},
        {262,395},
        {259,364},
        {261,335},
        {353,425},
        {278,273},
        {156,398},
        {185,295},
        {180,242},
        {119,241}
    };
    QString infos[ViewSpotNumMAX]={
        "哈尔滨工业大学（威海）南门，学校正门",
        "M楼 明学楼，教学楼",
        "N楼 宁学楼，教学楼",
        "研究院 教师办公楼、学生实验室",
        "学苑餐厅 共两层，地方特色美食居多",
        "学子餐厅 共四层，家常菜居多",
        "一公寓 怡海楼，女生公寓",
        "二公寓 安海楼，女生公寓",
        "三公寓 山海楼，男生公寓",
        "四公寓 涉海楼，男生公寓",
        "五公寓 舞海楼，女生公寓",
        "六公寓 陆海楼，男生女生混合公寓",
        "七公寓 齐海楼，男生公寓",
        "八公寓 抱海楼，男生公寓",
        "九公寓 聚海楼，男生公寓",
        "十公寓 拾海楼，男生公寓"
    };

    for(int i=0;i<ViewSpotNum;i++)
    {
        ViewSpot vs(i,QPoint(position[i][0],position[i][1]),infos[i]);
        viewSpots.push_back(vs);
    }
    //名称映射
    QString names[ViewSpotNumMAX]={
        "南门",
        "M楼",
        "N楼",
        "研究院",
        "学苑餐厅",
        "学子餐厅",
        "一公寓",
        "二公寓",
        "三公寓",
        "四公寓",
        "五公寓",
        "六公寓",
        "七公寓",
        "八公寓",
        "九公寓",
        "十公寓"
    };
    for(int i=0;i<ViewSpotNum;i++)
    {
        record[names[i]]=i;
    }

    //景点间关系初始化
    for(int i=0;i<ViewSpotNum;i++)
    {
        map.vertexs[i] = i;
    }
    map.vern = ViewSpotNum;
    map.arcn = 18;
    //边权初始化
    for(int i=0;i<ViewSpotNum;i++){
        for(int j=0;j<ViewSpotNum;j++){
            if(i==j)
                map.arcs[i][j]=0;
            else
                map.arcs[i][j]=INF;
        }
    }
    map.arcs[0][3]=map.arcs[3][0]=247;
    map.arcs[2][5]=map.arcs[5][2]=187;
    map.arcs[7][8]=map.arcs[8][7]=229;
    map.arcs[8][9]=map.arcs[9][8]=20;
    map.arcs[10][9]=map.arcs[9][10]=106;
    map.arcs[7][4]=map.arcs[4][7]=161;
    map.arcs[8][4]=map.arcs[4][8]=68;
    map.arcs[9][4]=map.arcs[4][9]=88;
    map.arcs[11][4]=map.arcs[4][11]=195;
    map.arcs[6][7]=map.arcs[7][6]=75;
    map.arcs[10][6]=map.arcs[6][10]=159;
    map.arcs[11][5]=map.arcs[5][11]=87;
    map.arcs[12][13]=map.arcs[13][12]=141;
    map.arcs[1][7] = map.arcs[7][1] = 313;
    map.arcs[14][13]=map.arcs[13][14]=80;
    map.arcs[14][15]=map.arcs[15][14]=16;
    map.arcs[14][2]=map.arcs[2][14]=198;
    map.arcs[2][15]=map.arcs[15][2]=210;
    map.arcs[14][5]=map.arcs[5][14]=12;
}

void Data::calculate()
{
    int n = map.vern;
    int len[n][n];//len[i][j]表示和j间最短路径的长度
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            len[i][j]=map.arcs[i][j];
            Road[i][j]=len[i][j]!=INF?i:-1;
        }
    }
    for(int k = 0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(len[i][k]+len[k][j]<len[i][j])
                {
                    len[i][j] = len[i][k]+len[k][j];
                    Road[i][j]=Road[k][j];
                }
            }
        }
    }
}

void Data::ReadData(QString file)
{
    QFile F(file);
    if(F.open(QIODevice::ReadOnly)==true)//只读方式打开文件
    {
        QTextStream In(&F);
        int n,m;
        In>>n>>m;
        //点数和边数初始化
        ViewSpotNum = n;

        QString name;
        int ids[ViewSpotNumMAX];
        for(int i=0;i<n;i++)//读取地点信息
        {
            In>>name>>ids[i];
            record[name]=ids[i];
        }

        In.readLine();
        QString info;
        int position[ViewSpotNumMAX][2]={
            {512,777},
            {267,504},
            {154,92},
            {671,687},
            {354,332},
            {275,232},
            {328,386},
            {262,395},
            {259,364},
            {261,335},
            {353,425},
            {278,273},
            {156,398},
            {185,295},
            {180,242},
            {119,241}
        };
        for(int i=0;i<n;i++)
        {
            info = In.readLine();
            ViewSpot vs(ids[i],QPoint(position[i][0],position[i][1]),info);
            viewSpots.push_back(vs);
        }
        QString s1,s2;
        int len;
        for(int i=0;i<ViewSpotNum;i++)
        {
            map.vertexs[i] = i;
        }
        map.vern = n;
        map.arcn = m;
        //边权初始化
        for(int i=0;i<ViewSpotNum;i++){
            for(int j=0;j<ViewSpotNum;j++){
                if(i==j)
                    map.arcs[i][j]=0;
                else
                    map.arcs[i][j]=INF;
            }
        }
        for(int i=0;i<m;i++)//读取边权
        {
            In>>s1>>s2>>len;
            int id1=getId(s1);
            int id2=getId(s2);
            if(id1==-1 || id2==-1){
                qDebug()<<"读取边权数据错误";
                continue;
            }
            map.arcs[id1][id2]=map.arcs[id2][id1]=len;
        }
        F.close();
    }

}













