void ShortestPath_FLOYD(MGraph G, PathMatrix &P[], DistancMatrix &D){
    // 用Floyd算法求有向网G中各对顶点v和w之间的最短路径P[v][w]及其
    // 带权长度D[v][w]。若P[v][w][u]为TRUE，则u是从v到w当前求得最短路径上的顶点
    for(v = 0; v < G.vexnum; ++ v)// 各对结点之间初始已知路径及距离
        for(w = 0; w < G.vexnum; ++ w){
            D[v][w] = G.arcs[v][w];
            for(u = 0; u < G.vexnum; ++ u) P[v][w][u] = FALSE;
            if(D[v][w] < INFINITY){// 从v到w有直接路径
                P[v][w][v] = TRUE; P[v][w][w] = TRUE;
            }// if
        }// for
    for(u = 0; u < G.vexnum; ++ u)
        for(v = 0; v < G.vexnum; ++ v)
            for(w = 0; w < G.vexnum; ++ w)
                if(D[v][u] + D[u][w] < D[v][w]){// 从v经u到w的一条路径更短
                    D[v][w] = D[v][u] + D[u][w];
                    for(i = 0; i < G.vexnum; ++ i)
                        P[v][w][i] = P[v][u][i] || P[u][w][i];
                }// if
}// ShortestPath_FLOYD

void ShortestPath_DIJ( MGraph G, int v0, PathMatrix &P, ShortPathTable &D){
    // 用Dijkstra算法求有向网G的v0顶点到其余顶点v的最短路径P[v]及其带权长度D[v]。
    // 若P[v][w]为TRUE，则w是从v0到v当前求得最短路径上的顶点。
    // final[v]为TRUE当且仅当v∈S，即已经求得从v0到v的最短路径。
    for (v = 0; v < G.vexnum; ++ v){
        final[v] = FALSE; D[v] = G.arcs[v0][v];
        for (w = 0; w < G.vexnum; ++ ww) P[v][w] = FALSE;// 设空路径
        if (D[v] < INFINITY) {P[v][v0] = TRUE; P[v][v] = TRUE;}
    }// for
    D[v0] = 0; final[v0] = TRUE;// 初始化，v0顶点属于S集
    // 开始主循环，每次求得v0到某个v顶点的最短路径，并加v到S集
    for (i = 1; i < G.vexnum; ++ i) {// 其余G.vexnum - 1个顶点
        min = INFINITY;// 当前所知离v0顶点的最近距离
        for (w = 0; w < G.vexnum; ++ w)
            if(!final[w])// w顶点在V-S中
                if(D[w] < min) {v = w; min = D[w];}// w顶点离v0顶点更近
        final[v] = TRUE;// 离v0顶点最近的v加入S集
        for(w = 0; w < G.vexnum; ++ w)// 更新当前最短路径及距离
            if(!final[w] && (min + G.arcs[v][w] < D[w])){// 修改D[w]和P[w],x∈V-S
                D[w] = min + G.arcs[v][w];
                P[w] = P[v]; P[w][w] = TRUE;// P[w] = P[v] + P[w]
            }// if
    }// for

}// ShortestPath_DIJ

int InsertionSearch(int A[],int high,int key,int low)//high当前数组下标的最大值，low为当前数组下标的最小值； 
{
    int mid=low+((key-A[low])/(A[high]-A[low]))*(high-low);
    if(key==A[low])
      return mid;
    if(key>A[mid])
      return InsertionSearch(A,high,key,mid+1); 
    if(key<A[mid])
      return InsertionSearch(A,mid-1,key,low);    
}