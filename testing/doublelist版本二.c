#include "myhead.h"

struct student 
{
	char name[10];
	float score;
};
struct double_list
{
	struct student stu;
	struct double_list *next;
	struct double_list *prev;
};

// 双链表的初始化
struct double_list *double_listinit()
{
	struct double_list *head=malloc(sizeof(struct double_list));
	if(head==NULL)
	{
		perror("malloc memory failed!\n");
		return NULL;
	}
	head->next=NULL;head->prev=NULL;return head;
}
// 创建新节点的函数
struct double_list *create_new()
{
	struct double_list *new=malloc(sizeof(struct double_list));
	printf("请输入学生的名字!\n");
	scanf("%s",new->stu.name);
	printf("请输入该学生的分数！\n");
	scanf("%f",&new->stu.score);
	new->next=NULL;
	new->prev=NULL;
	return new;
}
// 双链表的尾部插入和指定位置插入(前插);
int double_tail(struct double_list *head,struct double_list *new,char *name)
{
	struct double_list *p=head;//用于循环的节点
	while(p->next!=NULL)
	{
		p=p->next;
		if(strcmp(p->stu.name,name)==0)
		{
			break;
		}
	}
	if(p->next==NULL) // 100%确认p一定指向的是最后一个有效节点
	{
		if(strcmp(p->stu.name,name)==0)
		{
			//前插入
			p->prev->next=new;
			new->prev=p->prev;
			new->next=p;
			p->prev=new;
			return 2;
		}
		else
		{
			//尾部插入
			p->next=new;
			new->prev=p;
			return 1;
		}
	}
	//前插入;
	p->prev->next=new;
	new->prev=p->prev;
	new->next=p;
	p->prev=new;
	return 0;
}
/*  是将上面的那个double_tail（）代码优化了一下
 int double_tail(struct double_list *head,struct double_list *new,char *name)
{
	struct double_list *p=head;
	while(p->next!=NULL)
	{
		p=p->next;
		if(strcmp(p->stu.name,name)==0)
		{
			break;
		}
	}
	if(p->next==NULL) // 100%确认p一定指向的是最后一个有效节点
	{
		if(strcmp(p->stu.name,name)!=0)
		{
			//尾部插入
			p->next=new;
			new->prev=p;
			return 1;  
		}
	}
	//前插入;
	p->prev->next=new;
	new->prev=p->prev;
	new->next=p;
	p->prev=new;
	return 0;
} */

// 打印
int double_print(struct double_list *head)
{
	struct double_list *p=head;
	while(p->next!=NULL)
	{
		p=p->next;
		printf("目前p指向的学生是:%s  成绩是:%f\n",p->stu.name,p->stu.score);
	}
	return 0;
}
// 删除指定成员
int rm_node(struct double_list *head,char *name)
{
	struct double_list *p=head;
	while(p->next!=NULL)
	{
		p=p->next;
		if(strcmp(p->stu.name,name)==0)
		{
			break;
		}
	}
	// 没有考虑最后一个节点的问题，没有考虑是否存在
	p->prev->next=p->next;
	p->next->prev=p->prev;
	p->next=NULL;
	p->prev=NULL;
	free(p);
	return 0;
}
int main()
{
	int i;
	int ret;
	struct double_list *newnode;
	struct double_list *myhead=double_listinit();
	for(i=0; i<3; i++)
	{
		newnode=create_new();
		double_tail(myhead,newnode,"haha");
	}
	newnode=create_new();
	ret=double_tail(myhead,newnode,"sun");
	printf("ret is:%d\n",ret);
	
	double_print(myhead);
	rm_node(myhead,"wang");
	double_print(myhead);
}