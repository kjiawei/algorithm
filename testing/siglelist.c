#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//学生类型的结构体
struct Student 
{
	char name[20];
	int math;
};
//单向链表结构体
struct singleList
{
	struct Student stu;
	struct singleList *pNext;
};

struct singleList *init(void)
{
	struct singleList *pHead = (struct singleList *)malloc(sizeof(struct singleList)); 
	if(pHead == NULL)
	{
		printf("动态内存分配失败!\n");
		exit(-1);
	}
	pHead->pNext = NULL;
	return pHead;
}
int append(struct singleList *pHead)
{
	//定义一个结构体临时变量保存头结点
	struct singleList *p = pHead;
	char name[20];
	//遍历，直到链表到了它现在的尾部
	while(p->pNext!=NULL)
	{
		p = p->pNext;
	}
	//创建一个新的节点
	struct singleList*pNew = (struct singleList *)malloc(sizeof(struct singleList));
	if(pNew == NULL)
	{
		printf("动态内存分配失败！\n");
		return -1;
	}
	//添加数据
	printf("请输入学生姓名:");
	scanf("%s",name);
	strcpy(pNew->stu.name,name);
	printf("请输入成绩:");
	scanf("%d",&(pNew->stu.math));
	p->pNext = pNew;
	pNew->pNext = NULL;
	return 0;
}

int length(struct singleList *pHead)
{
	struct singleList *p = pHead->pNext;
	int len = 0;
	while(p!=NULL)
	{
		len++;
		p = p->pNext;
	}
	return len;
}


int insert(struct singleList *pHead,int pos)
{
	struct singleList *p = pHead;
	struct singleList *temp;//临时保存节点地址的变量
	char name[20];
	int i = 0;
	//一直到要插入位置的前一个位置
	while(p!=NULL && i<pos-1)
	{
		p = p->pNext;
		i++;
	}
    //如果要插入到一个空节点的前面。代表失败！
    if(p == NULL)
	{
		printf("插入失败!\n");
		return -1;
	}		
	//创建新的节点
	struct singleList *pNew = (struct singleList *)malloc(sizeof(struct singleList));
    if(pNew == NULL)
	{
		printf("动态内存分配失败！\n");
		return -1;
	}
	printf("请输入学生的姓名:");
	scanf("%s",name);
	strcpy(pNew->stu.name,name);
	printf("请输入成绩:");
	scanf("%d",&(pNew->stu.math));
	temp = p->pNext;//保存一下插入节点的后一个节点的地址
	pNew->pNext = temp;
	p->pNext = pNew;
	

}
int find (struct singleList *pHead,char *s)
{
	struct singleList *p = pHead->pNext;
	int count = 0;
	while(p!=NULL)
	{
		count++;
		if(!strcmp(s,p->stu.name))
		{
			
			break;
		}
		p = p->pNext;
	}
	if(length(pHead) == count)
	{
		printf("没有这个东西!\n");
		return 0;
	}
	else
	{
		return count;
	}
	
	
}


//删除
int delete_listbypos(struct singleList *pHead,int pos)
{
	struct singleList *p = pHead;
	struct singleList *temp;
	int i = 0;
	while(p!=NULL && i<pos-1)
	{
		p = p->pNext;
		i++;
	}
	if(p == NULL)
	{
		printf("删除失败!\n");
		return -1;
	}
	//printf("%s\n",p->stu.name);
	temp = p->pNext;//保存下一个节点的地址
	p->pNext = temp->pNext;
	free(temp);
	temp = NULL;	
}

int deletelistbyName(struct singleList *pHead,char *s)
{
    struct singleList *p = pHead;
	struct singleList *q;
	/*
	要删除某个节点的数据，首先要获取节点前面的那个节点的地址保存起来
	如何把节点的地址保存起来，
	我们需要不断地和当前节点的下一个节点的名字是否和判断的一致
	如果数据不同的话，我们就可以把p移到下一个结顶啊
	如果数据相同，则退出
	*/
	while(p->pNext!=NULL)
	{
		if(!strcmp(s,p->pNext->str.name))
		{
			break;
		}
		else
			p = p->pNext;
		q = p->pNext;
		
	}
	 
	
}


/* int insertbyName(struct singleList *pHead,char *s)
{
	struct singleList *p = pHead->pNext;
	struct singleList *tempList = p;//保存要添加节点的上一个节点的位置
	struct singleList *temp;
	while(strcmp(s,p->stu.name))
	{
		temp
		
	}
	
	
} */
//遍历输出
void print_info(struct singleList *pHead)
{
	//把头结点传输进来，我们进行遍历操作
	struct singleList *p = pHead;
	int i = 1;
	while(p->pNext!=NULL)
	{
		p = p->pNext;
		printf("这是第%d个同学的信息:姓名:%s,成绩:%d\n",i,p->stu.name,p->stu.math);
		i++;
	}
	
	
	
}

//遍历输出for循环

void print_for(struct singleList *pHead)
{
	struct singleList *p = pHead;
	int i = 1;
	for(p = p->pNext;p!=NULL;p = p->pNext,i++)
	{
		printf("第%d个同学的姓名为%s,成绩为:%d\n",i,p->stu.name,p->stu.math);
	
	}
	
}


int main(void)
{
	struct singleList *pHead = init();
	int len;
	int i = 0;
	printf("请输入你要添加学生的个数:");
	scanf("%d",&len);
	for(i = 0;i < len;i++)
	{
		append(pHead);
	}
	
	printf("插入前:\n");
	printf("链表长度为:%d\n",length(pHead));
	print_info(pHead);
	//printf("请输入你要插入的位置:");
	//scanf("%d",&len);
	//insert(pHead,len);
	//printf("插入后:\n");
	//print_for(pHead);
	//printf("======\n");
	//printf("请输入你要删除的位置:");
	//scanf("%d",&len);
	//delete_listbypos(pHead,len);
	deletelistbyName(pHead,"lisi");
	print_for(pHead);
	printf("链表长度为:%d\n",length(pHead));
	return 0;
}