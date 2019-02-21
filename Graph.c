#图
## 概念

1.邻接表(有向图[关心出边,缺点:不好找入边];无向图[每条边需要多个节点表示->邻接多重表解决]) 逆邻接表(有向图[关心入边)->十字链表])
2.邻接矩阵
3.十字链表(同时关心入边和出边)
4.邻接多重表(一个节点即可代表一条边)

## 逻辑结构

## 存储结构

## 实现代码
float MGraph[5][5];//带权图 用于存储边
for(int i=0;i<5;i++i)
    for(int j=0;j<5;++j)
        MGraph[5][5] = MAX;//两个点没有边

2.邻接矩阵
char vertex[5] = {'A','B','C','D','E'};//邻接矩阵的顶点数组
float Edge[5][5];
for(int i=0;i<5;++i)
    for(int j=0;j<5;++j)
        Edge[i][j] = MAX;

1.1 邻接表(经常访问出边,类似树的孩子存储结构)
typedef struct ArcNode//边节点
{
    int adjV;//邻接顶点 存储以它为起点的边
    struct ArcNode* next;//指向下一个边节点的指针
}ArcNode;

typedef struct
{
    int data;//
    ArcNode* first;
}VNode;

typedef struct//图结构体
{
        VNode adjList[maxSize];
        int n,e;
}AGraph;
    
1.2 逆邻接表(经常访问入边)
//邻接顶点 存储以它为终点的边
    
3.十字链表(对有向图改进)
顶点结构体设计:Data *firstIn *firstOut
边节点设计:start end(边终点) *nextIn *nextOut(与顶点相连的下一条出边)
顶点数组设计:每个顶点对应一个数组的下标

4.邻接多重表(对有向图改进 节点数只有之前一半 每条边只需要唯一节点)
顶点结构体设计:Data *first
边节点结构体设计:Vi *ViNext(与Vi相关的下一边节点) Vj(边终点) *VjNext
顶点数组设计:每个顶点对应一个数组的下标

## 算法
遍历
### DFS深度优先(类似树的先序)  复杂度:
void DFS(int v,AGraph *G)
{
    visit[v] = 1;//全局变量 标记数组 已访问过的置位
    Visit(v);
    ArcNode* q = G->adjList[v].first//取边
    while(q != NULL)
    {
        if(visit[q->adjV] == 0)//判断顶点是否已访问过 0为没访问过
            DFS(q->adjV,G);
        q = q->next;
    }
}

### BFS广度优先(类似树的序)

最小生成树

