#ifndef TOOL_H
#define TOOL_H
#include <iostream>
#include<QVector>
using namespace std;

#define MAX_VERTEX_NUM 20  // 顶点数量上限
static const int INF = 99999999;

class MGraph{
public:
    int vertex[MAX_VERTEX_NUM];                                    //顶点集合
    //临接矩阵
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int verNum;                                           //顶点数
    int arcNum;                                           //边数
};


static bool ShortestPath_Floyd(MGraph &G,int start,int end,QVector<int>& R)
{
    if(start == end)return false;
    const int N = G.verNum;
    int Path[N][N];      //表示vi和vj之间的最短路上的前驱顶点
    long long D[N][N];   //表示vi和vj之间的最短路径长度

    for(int i = 0; i < N ; ++ i){
        for(int j = 0; j < N; ++ j){
            D[i][j] = G.arcs[i][j];
            Path[i][j] = D[i][j] != INF ? i : -1;
        }
    }

    for(int k = 0; k < N; ++ k){
        for(int i = 0; i < N; ++ i){
            for(int j = 0; j < N; ++ j){
                if(D[i][k] + D[k][j] < D[i][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    Path[i][j] = Path[k][j];
                }
            }
        }
    }

    /* 输出每对最短路径 */
    for(int i = 0; i < N; ++ i){
        for(int j = 0; j < N; ++ j){
            if(G.vertex[i] == start && G.vertex[j] == end){

                R.clear();
                R.push_front(end);

                //显示
                cout << G.vertex[i] << "→" << G.vertex[j] << ": " << G.vertex[j];
                for(int vi = Path[i][j]; vi != i; vi = Path[i][vi]){
                    cout << "←" << G.vertex[vi];

                    R.push_front(G.vertex[vi]);
                }
                cout << "←" << G.vertex[i] << " (" << D[i][j] << ")" << endl;

                R.push_front(start);

                return R.size()>=2;
            }

        }
    }
    return R.size()>=2;
}

#endif // TOOL_H
