/*单链表定义*/
typedef struct LNode
{
    int data;
    struct LNode *next;
    struct LNode *prior;
}LNode;

LNode *L;
L = (LNode *)malloc(sizeof(LNode));
A->next = B;
B->next = C;
C->next = D;

/*单链表考点*/
1.特性对比 操作问题 比较或移动次数计算 静态链表  等4类问题