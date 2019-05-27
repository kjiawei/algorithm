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
// 初始化单向循环链表,空的头节点
struct siglelist *siglelist_init()
{
	struct siglelist *head=malloc(sizeof(struct siglelist));
	head->next=head;
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
// 单链表从中间插入,插入到name的前面
// 功能？？  方不方便
int siglelist_mid(struct siglelist *head,char *name)
{
	struct siglelist *p=head;
	// 使用p去遍历单链表
	while(p->next!=NULL)
	{
		if(strcmp(p->next->stu.name,name)==0) // 判断p的下一个节点里面的名字是否符合要求 正确
		//if(strcmp(p->stu.name,name)==0) 错误，结合图片分析
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
	//struct siglelist *newnode=creatnewnode(); 写法一 正确
	sigle_listp newnode=creatnewnode();  //写法二，用了新的名字来定义的  正确
	// 将新节点插入到name的前面
	newnode->next=p->next;
	p->next=newnode;
	return 0;
}
// 删除指定的节点
int remove_node(struct siglelist *head,char *name)
{
	if(head==NULL)
	{
		return -1;
	}
	struct siglelist *p=head;
	struct siglelist *q=head->next;
	// 使用q去遍历单链表
	while(q!=NULL)
	{
		if(strcmp(q->stu.name,name)==0) // 判断p的下一个节点里面的名字是否符合要求 正确
		//if(strcmp(p->stu.name,name)==0) 错误，结合图片分析
			break;
			
		p=p->next;
		q=q->next;
	}
	//准备删除节点
	p->next=q->next;
	q->next=NULL;
	free(q);
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
	char buf[20];
	bzero(buf,20);
	// 初始化单链表
	struct siglelist *myhead=siglelist_init();
	// 采用尾部插入
	siglelist_tail(myhead);
	siglelist_tail(myhead);
	siglelist_tail(myhead);
	siglelist_tail(myhead);
	siglelist_print(myhead);
	// 中间插入
	printf("请输入你打算插入的那个学生的名字：前面插入！\n");
	scanf("%s",buf);
	siglelist_mid(myhead,buf);
	siglelist_print(myhead);
	// 删除某个节点
	remove_node(myhead,"li");
	siglelist_print(myhead);
	return 0;
}