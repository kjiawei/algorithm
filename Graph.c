#ͼ
## ����

1.�ڽӱ�(����ͼ[���ĳ���,ȱ��:���������];����ͼ[ÿ������Ҫ����ڵ��ʾ->�ڽӶ��ر���]) ���ڽӱ�(����ͼ[�������)->ʮ������])
2.�ڽӾ���
3.ʮ������(ͬʱ������ߺͳ���)
4.�ڽӶ��ر�(һ���ڵ㼴�ɴ���һ����)

## �߼��ṹ

## �洢�ṹ

## ʵ�ִ���
float MGraph[5][5];//��Ȩͼ ���ڴ洢��
for(int i=0;i<5;i++i)
    for(int j=0;j<5;++j)
        MGraph[5][5] = MAX;//������û�б�

2.�ڽӾ���
char vertex[5] = {'A','B','C','D','E'};//�ڽӾ���Ķ�������
float Edge[5][5];
for(int i=0;i<5;++i)
    for(int j=0;j<5;++j)
        Edge[i][j] = MAX;

1.1 �ڽӱ�(�������ʳ���,�������ĺ��Ӵ洢�ṹ)
typedef struct ArcNode//�߽ڵ�
{
    int adjV;//�ڽӶ��� �洢����Ϊ���ı�
    struct ArcNode* next;//ָ����һ���߽ڵ��ָ��
}ArcNode;

typedef struct
{
    int data;//
    ArcNode* first;
}VNode;

typedef struct//ͼ�ṹ��
{
        VNode adjList[maxSize];
        int n,e;
}AGraph;
    
1.2 ���ڽӱ�(�����������)
//�ڽӶ��� �洢����Ϊ�յ�ı�
    
3.ʮ������(������ͼ�Ľ�)
����ṹ�����:Data *firstIn *firstOut
�߽ڵ����:start end(���յ�) *nextIn *nextOut(�붥����������һ������)
�����������:ÿ�������Ӧһ��������±�

4.�ڽӶ��ر�(������ͼ�Ľ� �ڵ���ֻ��֮ǰһ�� ÿ����ֻ��ҪΨһ�ڵ�)
����ṹ�����:Data *first
�߽ڵ�ṹ�����:Vi *ViNext(��Vi��ص���һ�߽ڵ�) Vj(���յ�) *VjNext
�����������:ÿ�������Ӧһ��������±�

## �㷨
����
### DFS�������(������������)  ���Ӷ�:
void DFS(int v,AGraph *G)
{
    visit[v] = 1;//ȫ�ֱ��� ������� �ѷ��ʹ�����λ
    Visit(v);
    ArcNode* q = G->adjList[v].first//ȡ��
    while(q != NULL)
    {
        if(visit[q->adjV] == 0)//�ж϶����Ƿ��ѷ��ʹ� 0Ϊû���ʹ�
            DFS(q->adjV,G);
        q = q->next;
    }
}

### BFS�������(����������)

��С������

