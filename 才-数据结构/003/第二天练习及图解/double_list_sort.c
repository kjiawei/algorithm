#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

//节点生成及初始化
struct node *Double_Init(void)
{
	struct node *double_node; //定义一个结构体指针变量
	
	double_node = (struct node *)malloc(sizeof(struct node)); //为节点开辟空间
	if(double_node == NULL)
		return NULL;
	
	double_node->next = double_node;//指向自己
	double_node->prev = double_node;//指向自己
	
	//double_node->next = double_node->prev = double_node;
	
	return double_node; //返回指针
}

//节点插入
void Double_insert(struct node *basic,struct node *new)//插在basic和basci->next之间
{
	if(basic == NULL || new == NULL)
		return ;

	new->next 	= basic->next;  //结合图解（1）
	new->prev 	= basic;	//结合图解（2）
	basic->next->prev = new;	//结合图解（3）
	basic->next	=new;		//结合图解（4）
}

//链表后面插入节点，即head前面插入节点//其中basic为头节点，basic-prev为最后一个节点
void Double_insert_tail(struct node *basic,struct node *new)
{
	if(basic == NULL || new == NULL)
		return ;

/*链表后面插入节点写法1*/
/*
	new->next 		= basic;  //结合图解（1）
	new->prev 		= basic->prev;	//结合图解（2）
	basic->prev 	= new;	//结合图解（3）
	new->prev->next = new;		//结合图解（4）
	
*/

/*链表后面插入节点写法2*/

	new->next 		= basic;  //结合图解（1）
	new->prev 		= basic->prev;	//结合图解（2）
	basic->prev->next 	= new;	//结合图解（3）
	basic->prev = new;		//结合图解（4）

}


struct node *Find_Data_Node(struct node *head,int Find_data)
{
	struct node *P;
	
	if(head->next == NULL)  //判断有无后继节点，无则返回
		return;
		
	P = head->next; //指向第一个有数据的节点
	
	for(; P != head ; P=P->next) //判断退出条件及P移向下一个节点
	{
		if(P->data == Find_data)  //判断节点里面的数据是否等于查找的数据
			return P;
	}

	return NULL;
}



int Del_Node(struct node *del)
{
	if(del == NULL)
		return -1;

	del->prev->next = del->next; //结合图解（1）
	del->next->prev = del->prev; //结合图解（2）

	del->next = del;	//结合图解（3），让del->next指向自己
	del->prev = del;	//结合图解（4），让del->prev指向自己
		
}



//显示链表
void Display_list(struct node *head)
{
	int i=0;
	struct node *P;
	
	if(head->next == NULL)  //判断有无后继节点，无则返回
		return;
		
	P = head->next; //指向第一个有数据的节点
	printf("=======================数据显示=======================\n");
	
	for(; P != head ; P=P->next) //判断退出条件及P移向下一个节点
	{
		//printf("%d node address = %p\n",i,P);
		//printf("P->data: %d\n",P->data);
		printf("%d\t",P->data);
		//i++;
	}
}


void Display_menu(void)
{
	printf("选择以下按键选择功能：\n");
	printf("i:节点插入\n");
	printf("p:显示链表\n");
	printf("f:查找数据节点\n");
	printf("d:删除数据节点\n");
	printf("e:退出系统\n");
	printf("m:移动数据");
}
//从小到大排序
void sort_insert(struct node*head,struct node*new)//
{
	struct node*p;
	p=head->next;//p指向头节点
	

	if(p==head) //新节点后面插入
	{
		Double_insert_tail(head,new);
		return;
	}
	
	for(;p != head; p=p->next)
	{
		if(p->data > new->data)
		{
			Double_insert_tail(p,new);  //在p的前面插入链表
			return;
		}
	}
	
	if(p == head)
		Double_insert_tail(head,new); //遍历到最后没有找到数据，则在链表最后插入链表
	

	return;

}

int main(void)
{

	int i;
	struct node*head;
	head = Double_Init(); //生成一个节点，做为头节点
	for(i=0;i<SIZE;i++)
	         {
	         	struct node*new;
	         	new = Double_Init();
	         	 printf("请输入节点的值：\n");
		 scanf("%d",&new->data);
	             
		 sort_insert(head,new);
		 
		  Display_list(head);
	         }                                                       
	
                Display_list(head);
	//Display_list(head);
	
	
	return 0;
}