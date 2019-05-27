/*
  author: peng
  Email:74874244554@qq.com  if bug find please
  
  版本的描叙：
  功能的描述：

*/
#include "myhead.h"

struct student 
{
	char name[10];
	float score; 
};

// 封装一个结构体，用于描述单向循环链表
typedef struct siglelist
{
    struct student stu;
	struct siglelist *next;
}sigle_list,*sigle_listp;  // 使用typedef去重定义了普通结构和结构体指针的名字

//初始化空头节点的单向循环链表
struct siglelist *siglelist_init()
{
	struct siglelist *head=malloc(sizeof(struct siglelist));
	head->next=head;//说明是循环链表
	return head;
}

// 创建新节点函数(新节点下一位为空节点)
struct siglelist *creatnewnode()
{
	struct siglelist *newnode=malloc(sizeof(struct siglelist));
	printf("请输入新插入的学生的名字！\n");
	scanf("%s",newnode->stu.name);
	printf("请输入新插入的学生的分数！\n");
	scanf("%f",&(newnode->stu.score));
	newnode->next=NULL;
	return newnode;
}

// 单链表尾部插入
int siglelist_tail(struct siglelist *head)
{
	struct siglelist *p=head;
	struct siglelist *newnode=creatnewnode();//准备新节点
    while(p->next!=NULL)//新节点插入到目前链表中最后一个有效节点的尾部
	{					//for循环实现
		p=p->next;
	}
	p->next=newnode;//新节点插入到p后面
	return 0;
}

// 单链表从中间(name的前面)插入
int siglelist_mid(struct siglelist *head,char *name)
{
	struct siglelist *p=head;
	// 使用p去遍历单链表
	while(p->next!=NULL)
	{
		if(strcmp(p->next->stu.name,name)==0) //判断p的下一个节点里面的名字是否符合要求
			break;
		p=p->next;
	}
	// 判断name在链表中根本就不存在
	if(p->next==NULL)
	{
		printf("对不起，没有这个人%s！\n",name);
		return -1;
	}
	// 创建一个新节点
	//写法一struct siglelist *newnode=creatnewnode(); 
	sigle_listp newnode=creatnewnode();//写法二
	// 将新节点插入到name的前面
	newnode->next=p->next;//这句重点掌握
	p->next=newnode;
	return 0;
}

//删除指定的节点
int remove_node(struct siglelist *head,char *name)
{
	if(head==NULL)
	{
		return -1;
	}
	struct siglelist *p=head;
	struct siglelist *q=head->next;
	
	while(q!=NULL)//q去遍历单链表
	{
		if(strcmp(q->stu.name,name)==0) // 判断p的下一个节点里面的名字是否符合要求
			break;	
		p=p->next;
		q=q->next;
	}
	p->next=q->next;//删除节点
	q->next=NULL;
	free(q);
	return 0;
}

//打印单链表
int siglelist_print(struct siglelist *head)
{
	struct siglelist *p=head;
	while(p->next!=NULL)//遍历单链表，打印
	{
		p=p->next;
		printf("目前我访问到的节点对应的学生名字：%s 分数：%f\n",p->stu.name,p->stu.score);
	}
	return 0;
}

int main()
{
	char buf[20];
	bzero(buf,20);
	struct siglelist *myhead=siglelist_init();//初始化单链表
	//尾部插入
	siglelist_tail(myhead);
	siglelist_tail(myhead);
	siglelist_tail(myhead);
	siglelist_tail(myhead);
	siglelist_print(myhead);
	//中间插入
	printf("请输入你打算插入的那个学生的名字：前面插入！\n");
	scanf("%s",buf);
	siglelist_mid(myhead,buf);
	siglelist_print(myhead);
	//删除某个节点
	remove_node(myhead,"li");
	siglelist_print(myhead);
	return 0;
}