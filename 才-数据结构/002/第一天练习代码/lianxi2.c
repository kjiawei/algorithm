#include<stdio.h>
#include<stdlib.h>

struct info *stu_Init();
void show_link(struct info *head);
int stru_insert(struct info *p,struct info *new);
void maopao(struct info *head);

struct info
{
	int date;
	struct info *next;
};

int main(int argc,char *argv[])
{
	struct info *del_result;
	struct info *find;
	struct info *head,*new;
	struct info *new_insert;
	int i=0,date;
	head=stu_Init();
	printf("head=%p\n",head);
	for(i=0;i<5;i++)
	{
		new=stu_Init();
		printf("请输入date:\n");
		scanf("%d",&new->date);
		stru_insert(head,new);
	}
	show_link(head);
	printf("=================\n");
	maopao(head);
	show_link(head);
	return 0;
}
//结构体插入
int stru_insert(struct info *p,struct info *new)
{
	if(p==NULL||new ==NULL)
	{
		return -1;
	}
	new->next=p->next;
	p->next=new;
	return 0;
}
//选择排序，节点里的数据交换
void maopao(struct info *head)
{
	struct info *p;
	struct info *last;  //最后节点
	p=head->next; //p等于头节点
	
	for(;p!=NULL;p=p->next)
	{
		last=p;
		for(;last!=NULL;last=last->next)
		{
			if(p->date>last->date)
			{
				//异或交换数据
				p->date=(p->date)^(last->date);
				last->date=(p->date)^(last->date);
				p->date=(p->date)^(last->date);
			}
		}
	}
}
//链表的显示
void show_link(struct info *head)
{
	int i=0;
	struct info *p;
	if(head->next==NULL)
	{
		return;
	}
	p=head->next;
	for(;p;p=p->next)
	{
		printf("%d的输出date=%d\n",i,p->date);
		i++;
	}
}
//结构体指针初始化
struct info *stu_Init()
{
	struct info *p;
	p=(struct info *)malloc(sizeof(struct info));
	if(p==NULL)
	{
		return NULL;
	}
	p->next=NULL;
	return p;
}