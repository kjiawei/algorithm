//单向循环链表：单链表的最后一个元素的next指针指向头部
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//学生信息结构体
struct student
{
	char name[15];
	float score;
};

//链表
struct siglewhile
{
	struct student stu;//存储学生信息
	struct siglewhile *next;//下一个节点的地址
};

//函数声明
struct siglewhile *init();
int append(struct siglewhile *head);
int insert(struct siglewhile *head,char *s);
void print_info(struct siglewhile *head);
/*
链表初始化:头结点的Next指针指向自己。
*/
struct siglewhile *init()
{
	struct siglewhile *head = (struct siglewhile *)malloc(sizeof(struct siglewhile));
    //判断是否创建失败
	if(NULL == head)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	
	head->next = head;
	return head;
}
/*
在尾部增加一个节点:遍历到链表中的最后一个节点
然后把新节点插入，新节点的next指向head
遍历:直到节点的next的地址为head
*/
int append(struct siglewhile *head)
{
	struct siglewhile *p = head;
	char name[15];//保存学生姓名
	//float score;//保存学生成绩
	while(p->next!=head)
	{
		p = p->next;
	}
	//创建一个新的节点
	struct siglewhile *new = (struct siglewhile *)malloc(sizeof(struct siglewhile));
	if(NULL == new)
	{
		printf("插入失败！\n");
		return -1;
	}
	printf("请输入学生姓名:");
	scanf("%s",name);
	strcpy(new->stu.name,name);
	printf("成绩:");
	scanf("%f",&new->stu.score);
	new->next = head;
	p->next = new;
	return 0;
}
/*
插入：
遍历到你想插入节点的前一个节点
然后保存插入节点的地址，将新节点的next指向插入节点的地址
最后将前一个节点的next指向新节点地址
*/
/* int insert(struct siglewhile *head,char *s)
{
	struct siglewhile *p = head;
	char name[15];
	int i = 0;
	while(p->next!=head)
	{
		printf("==\n");
		if(!strcmp(p->next->stu.name,s))
		{
			break;
		}
		p = p->next;
	}
	//如果没有这个人
	if(p->next == head)
	{
		printf("没有这个人！,插入失败!\n");
		return -1;
	}
	//printf("===");
	struct siglewhile *temp = p->next;
	//插入节点
	struct siglewhile *new = (struct siglewhile *)malloc(sizeof(struct siglewhile));
    printf("请输入学生姓名:");
	scanf("%s",name);
	strcpy(new->stu.name,name);
	printf("成绩:");
	scanf("%f",&new->stu.score);
	p->next = new;
	new->next = temp;
}


int insert1(struct siglewhile *head,char *s)
{
	struct siglewhile *p = head;
	char name[15];
	struct siglewhile *temp;
	if(strlen(s) != 0)
	{
		while(p->next!=head)
		{
			if(!strcmp(p->next->stu.name,s))
			{
				break;
			}
			p = p->next;
		}
		//如果没有这个人
		if(p->next == head)
		{
			printf("没有这个人！,插入失败!\n");
			return -1;
		}
		printf("中间插入~\n");
	
	}
    else 
	{
		while(p->next!=head)
		{
			p = p->next;
		}
		printf("尾部插入:\n");
	}
	if(p->next !=head)
	{
		temp = p->next;
	}
	else
	{
		temp = head;
	}
	struct siglewhile *new = (struct siglewhile *)malloc(sizeof(struct siglewhile));
    printf("请输入学生姓名:");
	scanf("%s",name);
	strcpy(new->stu.name,name);
	printf("成绩:");
	scanf("%f",&new->stu.score);
	p->next = new;
	new->next = temp;
} */

int insert2(struct siglewhile *head,char *s)
{
	struct siglewhile *p = head;
	char name[15];
	struct siglewhile *temp;
	char c;

	while(p->next!=head)
	{
		if(!strcmp(p->next->stu.name,s))
		{
			break;
		}
		p = p->next;
	}
/* 	//如果没有这个人
	if(p->next == head)
	{
		printf("没有这个人！要向链表尾部插入吗？(y确定)\n");
		scanf("%c",&c);
		if(c != 'y')
		{
			printf("插入失败！\n");
			return -1;
		}
	} */

	
	if(p->next !=head)
	{
		temp = p->next;
		printf("中间插入");
	}
	else
	{
		temp = head;
		printf("尾部插入！");
	}
	struct siglewhile *new = (struct siglewhile *)malloc(sizeof(struct siglewhile));
    printf("请输入学生姓名:");
	scanf("%s",name);
	strcpy(new->stu.name,name);
	printf("成绩:");
	scanf("%f",&new->stu.score);
	p->next = new;
	new->next = temp;
}



/*
删除:遍历到要删除节点的前一个节点
一开始用第一个存有效数据的节点（head->next）进行比较
p即保存要删除节点的上一个节点地址
q即保存要删除的节点
*/
int delete(struct siglewhile *head,char *name)
{
    struct siglewhile *p = head;
	struct siglewhile *q = head->next;
    while(q!=head)
	{
		if(!strcmp(q->stu.name,name))
		{
			break;
		}
		q = q->next;
		p = p->next;
	}
	if(q == head)
	{
		printf("没有这个人，删除失败！\n");
		return -1;
	}
	p->next = q->next;
	free(q);
	q = NULL;  	
}

//遍历输出
void print_info(struct siglewhile *head)
{
	struct siglewhile *p = head->next;
	while(p!=head)
	{
		printf("学生的姓名:%s,成绩:%f\n",p->stu.name,p->stu.score);
		p = p->next;
	}
	printf("\n");
}

/*
排序：使用for循环的双层嵌套
*/

void sort(struct siglewhile *head)
{
	struct siglewhile *p = head;
	struct siglewhile *q;
	struct student temp;
	for(p = p->next;p != head;p = p->next)
	{
		for(q = p;q !=head;q=q->next)
		{
			if(p->stu.score > q->stu.score)
			{
				temp = p->stu;
				p->stu = q->stu;
				q->stu= temp;
			}
		}
	}
}


int main(void)
{
	struct siglewhile *head = init();
	char name[15];//保存学生姓名
	int i = 0;
	int len;
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
	insert2(head,name);
	printf("插入后:");
	print_info(head);
	printf("请输入要删除学生的姓名:");
	while(getchar()!='\n');
	scanf("%s",name);
	delete(head,name);
	printf("删除后:");
	print_info(head);
	printf("正在排序...\n");
	sort(head);
	printf("排序后:");
	print_info(head);
	return 0;
}