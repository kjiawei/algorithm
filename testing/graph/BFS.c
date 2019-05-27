#include <stdio.h>

#define maxSize 20

typedef struct{
    int no;
    char info;
}VertexType;//顶点类型

typedef struct{
    int edges[maxSize][maxSize];
    int n,e;//图的顶点 边
    VertexType vex[maxSize];
}MGraph;//图的邻接矩阵类型

int main()
{
    
    return 0;
}