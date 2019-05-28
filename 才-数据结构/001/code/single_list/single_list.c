#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1、节点设计

struct node
{
	int data;
	struct node *next;

};	

//2、节点生成及初始化

struct node *List_Init(void)
{
	struct node *p;

	p = (struct node *)malloc(sizeof(struct node));//给结构体开辟开个空间
	if(p == NULL)      //判断是否malloc失败
		return NULL;
	
	p->next = NULL;   //结构体里成员next指针指向NULL;

	return p;
} 


//3、节点插入

int Insert_node(struct node *p,struct node *new)
{
	if(p == NULL || new == NULL) //判断传过来的p与new是否为空
		return -1;
	
	new->next = p->next;
	p->next   = new;
}

//4、显示链表

void Deplay_list(struct node *head)
{
	int i=0;
	struct node *P;
	

	if(head->next == NULL)  //判断有无后继节点，无则返回
		return;
		
	P = head->next; //指向第一个有数据的节点
	
	printf("=======================数据显示=======================\n");
	
	for(; P != NULL ; P=P->next) //判断退出条件及P移向下一个节点
	{
		printf("%d node address = %p\n",i,P);
		printf("P->data: %d\n",P->data);
		i++;
	}
	
}

//查找数据
struct node * Find_node(struct node *head,int find_data)
{
	int i=0;
	struct node *P;
	if(head->next == NULL)  //判断有无后继节点，无则返回
		return NULL;
		
	P = head->next; //指向第一个有数据的节点
	
	for(; P != NULL ; P=P->next) //判断退出条件及P移向下一个节点
	{
		if(P->data == find_data)  //判断节点里面的数据是否是查找的数据
			return P;      
	}
	
	return NULL;   //如果遍历整个链表都找不到数据，返回一个NULL
}


//删除操作
int Del_node(struct node *head,struct node *del)
{
	struct node *P;
	
	if(head == NULL || del == NULL)
		return -1;

	P = head;  //P指向头节点
	
	for(; P != NULL; P=P->next)
	{
		if(P->next == del)
		{
			P->next   = del->next;
			del->next = NULL;
			return 0;
		}
	}
	
	return -1;

}



int main(void)
{
	int i,data,flag;
	struct node *head,*new,*find_point;
	
	head = List_Init();  //生成一个节点做为头节点
	
	printf("head = %p\n",head);
	
	//创建两个节点，分别对节点data赋值
	for(i=0; i<5; i++)
	{
		new = List_Init();  //创建一个节点
		printf("%d new = %p\n",i,new);
		printf("请输入节点数据：\n");
		scanf("%d",&new->data);
		Insert_node(head,new);
	}

/*
	printf("请输入你要查找的数据：\n");
	
	scanf("%d",&data);
	find_point = Find_node(head,data);
	
	if(find_point == NULL)
	{
		printf("找不到对应的数据\n");
	}
	else
	{
		printf("找到对应的数据,数据节点地址 %p\n",find_point);
	}
	
*/

	Deplay_list(head);

	printf("请输入你要删除的数据节点：\n");
	
	scanf("%d",&data);
	find_point = Find_node(head,data);
	
	if(find_point != NULL)
	{
		printf("找到对应的数据,数据节点地址 %p\n",find_point);
		printf("删除节点\n");
		
		flag = Del_node(head,find_point);
		
		if(flag == -1)
			printf("删除数据失败\n");
		
		else
		{
			free(find_point);
			printf("删除数据成功\n");
		}
	}
	else
	{
		printf("找不到对应的数据\n");
		
	}

	Deplay_list(head);
	

	return 0;
}

