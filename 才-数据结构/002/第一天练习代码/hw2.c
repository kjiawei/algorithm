#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
//初始化节点
struct node *newnode()
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->next = NULL;
	
	return new;

}
//从链表最后面插入节点
int insert_node(struct node *head,struct node *new)
{
	struct node *p=head;
	
	if(p == NULL || new == NULL)
		return -1;
	while(p->next != NULL)
	{
		
		p = p->next;
	}
	p->next = new;	

	
}

//打印链表
void deplay_list(struct node *head)
{
	int i=1;
	struct node *p;
	if(head->next == NULL)
		return;
	p = head->next;
	
	printf("=========================================\n");
	for(; p!=NULL; p=p->next)
	{
		printf("第%d个节点的数据是%d\n",i,p->data);
		printf("第%d个节点的数据是%p\n",i,p);
		i++;		
	}
	
	printf("=========================================\n");
	
}
//冒泡排序，从大到小
int maopao_list(struct node *head)
{
	struct node *p = head ;  //p头节点
	struct node *q,*t;
	int i,j,count =0 ;
	
	if(p->next != NULL)
		q = p->next;   //q第一个有数据的节点
		
		
	while(q != NULL) //遍历节点个数
	{
		count++;
		q = q->next;
	}
	q = p->next;	//q第一个有数据的节点
	
	for(i=0; i<count; i++)
	{		
		while(q->next != NULL)
		{
			if((q->data) < (q->next->data))//从大到小
			{
				t = q->next;
				p->next = t;
				q->next = t->next;
				t->next = q;
			}
		
			p = p->next;
			q = p->next;
						
		}	
		p = head;  //每次操作p都要指向头
		q = p->next;
			
	}
	
}

int main (void)
{
	int i,data;
	struct node *head = newnode();
	struct node *new;
	
	for(i=0; i<6;i++)
	{
		new = newnode();
		printf("请输入第%d个数\n",i+1);
		scanf("%d",&new->data);
		
		insert_node(head,new);
	}
	printf("冒泡排列前:\n");
	deplay_list(head);
	
	maopao_list(head);
	printf("冒泡排列后:\n");
	deplay_list(head);
	
	return 0;

}