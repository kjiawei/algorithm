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
// 封装一个结构体，用于描述单链表
struct siglelist
{
    struct student stu;
	struct siglelist *next;
};
// 初始化单链表,空的头节点
struct siglelist *siglelist_init()
{
	struct siglelist *head=malloc(sizeof(struct siglelist));
	head->next=NULL;
	return head;
}
// 创建新的节点的函数
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
	// 准备好新的节点
	struct siglelist *newnode=creatnewnode();
	// 将新节点插入到目前链表中最后一个有效节点的尾部
    while(p->next!=NULL)
	{
		p=p->next;
	}
	// for 循环改写一下
	// 将新节点插入到p的后面
	p->next=newnode;
	return 0;
}
// 打印单链表
int siglelist_print(struct siglelist *head)
{
	struct siglelist *p=head;
	//遍历单链表，打印
	while(p->next!=NULL)
	{
		p=p->next;
		printf("目前我访问到的节点对应的学生名字：%s 分数：%f\n",p->stu.name,p->stu.score);
		
	}
	return 0;
}
int main()
{
	// 初始化单链表
	struct siglelist *myhead=siglelist_init();
	// 采用尾部插入
	siglelist_tail(myhead);
	siglelist_tail(myhead);
	siglelist_print(myhead);
	return 0;
}