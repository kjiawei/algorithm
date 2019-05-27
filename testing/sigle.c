#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//学生信息结构体
struct Student
{
	char name[15];
	float score;
};

//链表结构体
struct siglelist
{
	struct Student stu;
	struct siglelist *next;
};

//链表初始化
struct siglelist *init()
{
	struct siglelist *head;
	head = (struct siglelist *)malloc(sizeof(struct siglelist));
	if(NULL == head)
	{
		printf("动态分配内存失败！\n");
		exit(-1);
	}
	head->next = NULL;
	return head;
}

int append(struct siglelist *head)
{
	struct siglelist *p = head;
	char name[15];
	while(p->next !=NULL)
	{
		p = p->next;
	}
	//创建新节点
	struct siglelist *new = (struct siglelist *)malloc(sizeof(struct siglelist));
	if(NULL ==new)
	{
		printf("新节点创建失败！\n");
		return -1;
	}
	printf("请输入学生的姓名:");
	scanf("%s",name);
	strcpy(new->stu.name,name);
	printf("成绩为:");
	scanf("%f",&(new->stu.score));
	p->next = new;
	new->next = NULL;
	return 0;
}

//中间插入
int insert(struct siglelist *head,char *s)
{
	struct siglelist *p = head;
	char name[15];
	while(p->next!=NULL)
	{
		if(!strcmp(p->next->stu.name,s))
		{
			break;
		}
		p = p->next;
	}
	if(p->next == NULL)
	{
		printf("没有这个人！删除增加！\n");
		return -1;
	}
	struct siglelist *new = (struct siglelist *)malloc(sizeof(struct siglelist));
	if(new == NULL)
	{
		printf("动态内存分配失败！增加失败！\n");
		return -1;
	}
	printf("请输入学生的姓名:");
	scanf("%s",name);
	strcpy(new->stu.name,name);
	printf("成绩:");
	scanf("%f",&new->stu.score);
	new->next = p->next;
	p->next = new;
}

//插入 
int insert1(struct siglelist *head,char *s)
{
	struct siglelist *p = head;
	char name[15];
	struct siglelist *q;
	while(p->next!=NULL)
	{
		if(!strcmp(p->next->stu.name,s))
		{
			break;
		}
		p = p->next;
	}
	if(p->next == NULL)
	{
		printf("尾插:\n");
	}
	else
	{
		printf("中间插:\n");
	}
	//q = p;	
	struct siglelist *new = (struct siglelist *)malloc(sizeof(struct siglelist));
	if(new == NULL)
	{
		printf("动态内存分配失败！增加失败！\n");
		return -1;
	}
	printf("请输入学生的姓名:");
	scanf("%s",name);
	strcpy(new->stu.name,name);
	printf("成绩:");
	scanf("%f",&new->stu.score);
	new->next = p->next;
	p->next = new;
}


//删除
int delete(struct siglelist *head,char *s)
{
	struct siglelist *p = head;
	struct siglelist *q = head->next;
	while(q!=NULL)
	{
		if(!strcmp(q->stu.name,s))
		{
			break;
		}
		q = q->next;
		p = p->next;
	}
	if(q==NULL)
	{
		printf("没有这个人！删除失败！\n");
		return -1;
	}
	p->next=q->next;
	free(q);
	q = NULL;
	return 0;
}
//求链表长度
int length(struct siglelist *head)
{
	int count = 0;
	struct siglelist *p = head;
	while(p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

//遍历输出
void print_info(struct siglelist *head)
{
	struct siglelist *p = head->next;
	while(p != NULL)
	{
		printf("学生的姓名为:%s,成绩为：%f\n",p->stu.name,p->stu.score);
		p = p->next;
	}
	printf("\n");
}

void sort(struct siglelist *head)
{
	int i , j;
	struct Student temp;
	struct siglelist *p = head;
	struct siglelist *q;
	//654321
	//165432
	//126543
	//..
	//
	
	for(p = p->next;p!=NULL;p = p->next)
	{
		for(q = p->next;q!=NULL;q = q->next)
		{
			if(p->stu.score > q->stu.score )
			{
				temp = p->stu;
				p->stu = q->stu;
				q->stu = temp;
			}
		}
	}
}


//
void sort1(struct siglelist *head)
{
	struct siglelist *p = head;
	struct siglelist *q;
	struct Student temp;
	int len = length(head);
	int i ,j ;
	/*
		for(i = 0,p=p->pNext;i<len-1;i++,p=p->pNext)
	{
		for(j = i+1,q=p->pNext;j<len;j++,q=q->pNext)
		{
	*/
	for(i = 0;i < len;i++)
	{
		for(j = 0,q = p->next; j < len-i-1&&q->next!=NULL;j++,q = q->next)
		{
			if(q->stu.score > q->next->stu.score)
			{
				temp = q->stu;
				q->stu = q->next->stu;
				q->next->stu = temp;
			}
			
		}
		
	}
	
}

int main(void)
{
	struct siglelist *head = init();
	char name[15];//保存学生姓名
	int len;
	int i = 0;
	printf("请输入要插入学生的个数:");
    scanf("%d",&len);
	for(i = 0; i < len;i++)
	{
		append(head);
	}
	printf("插入%d个学生后的信息:",len);
	print_info(head);
	printf("请输入要插入哪个学生的前面:");
	scanf("%s",name);
	insert1(head,name);
	printf("插入后:");
	print_info(head);
	printf("请输入要删除学生的姓名:");
	while(getchar()!='\n');
	scanf("%s",name);
	delete(head,name);
	printf("删除后:");
	print_info(head);
	/* printf("正在排序...\n");
	sort(head);
	printf("排序后:"); */
	printf("正在排序...\n");
	sort1(head);
	printf("排序后:");
	print_info(head);
	return 0;
}