#include <stdio.h>
#include <stdlib.h>

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
void Double_insert(struct node *basic,struct node *new)
{
	if(basic == NULL || new == NULL)
		return ;

	new->next 	= basic->next;  //结合图解（1）
	new->prev 	= basic;	//结合图解（2）
	basic->next->prev = new;	//结合图解（3）
	basic->next	=new;		//结合图解（4）
}

//链表后面插入节点，即head前面插入节点
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
		printf("%d node address = %p\n",i,P);
		printf("P->data: %d\n",P->data);
		i++;
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
}


int main(void)
{
	int i,data;
	char ch;
	struct node *head,*new,*tmp;
	
	head = Double_Init(); //生成一个节点，做为头节点
	

	
	while(1)
	{
		Display_menu();
		scanf("%c",&ch);
		getchar();
		if(ch == 'e')  //如果输入e退出系统
			break;
		
		switch(ch)
		{
			case 'i':
						new = Double_Init();
						printf("生成第%d节点地址:%p\n",i,new);
						printf("请输入节点的值：\n");
						scanf("%d",&new->data);
						getchar();
						Double_insert_tail(head,new);
						printf("-----------------------------\n");
				break;
				
			case 'p':
					Display_list(head);
				break;
				
			case 'f':
					printf("请输入要查找的数据：\n");
					scanf("%d",&data);
					getchar();
					tmp = Find_Data_Node(head,data);
					if(tmp != NULL)
						printf("找到节点，节点数据:%d,地址:%p\n",data,tmp);
					else
						printf("找不到节点\n");
				break;
				
			case 'd':
					printf("请输入要删除的数据节点：\n");
					scanf("%d",&data);
					getchar();
					tmp = Find_Data_Node(head,data);
					if(tmp != NULL)
					{
						printf("找到节点，节点数据:%d,地址:%p\n",data,tmp);
						Del_Node(tmp); //将节点从链表当解出来
						free(tmp);     //释放节点
					}
					else
						printf("找不到节点\n");
				break;			
			
			default:
					printf("输入有误！\n");
				break;
		
		}
	
	}
	
	
	

	//Display_list(head);
	
	
	return 0;
}