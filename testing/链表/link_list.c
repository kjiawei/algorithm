#include <stdio.h>	//printf
#include <stdlib.h>	//malloc

typedef struct link_list{

	int data;
	struct link_list *next;

}list_t,*listp;

listp init_list(void)
{
	listp head = malloc(sizeof(list_t));	//申请一个链表头

	if(head != NULL)
	{
		head->next = NULL;					//申请到之后，让链表的下一个位置指向NULL
	}

	return head;
}

listp new_node(int rd)						//新建一个节点node,把数据存放进去
{
	listp node = malloc(sizeof(list_t));
	if(node != NULL)
	{
		node->data = rd;		
		node->next = NULL;
	}


	return node;
}

int insert_node(listp head, listp node)			//插入一个节点
{
	listp p;
	
	for(p=head; p->next != NULL; p=p->next);	//把p定位到最后一个节点的位置

	node->next = p->next;						//先把之前下一个节点的指针给node
	p->next = node;								//再把上一个节点的指针指向node

	return 0;
}


void show_list(listp head)
{
	listp p;

	p=head->next;								//由于不需要打印head的数据，所以让指针记录有效的第一个节点
	while(p != NULL)							//保证不偏移出链表的有效区域
	{
		printf("%d,",p->data);
		p=p->next;								//指向下一个节点
	}

	printf("\n");

	return;

}


bool is_list_empty(listp head)					//判断链表是否为NULL
{
	return head->next == NULL;
}

int remove_node(listp head)						//删除一个节点
{
	listp p;

	if(is_list_empty(head))
	{
		printf("the list is empty\n");
		return -1;
	}

	p=head;

	while(p->next->next != NULL)			//判断当前节点的下一个节点的下一个节点是否为NULL，如果是NULL的话就证明p的下一个节点就是最后一个节点
	{
		p = p->next;
	}
	

	free(p->next);
	p->next = NULL;

	return 0;
}


void remove_list(listp head)				//删除链表
{
	listp p,tmp;

	if(head->next != NULL)					//判断当前链表是否为NULL
	{	
		p = head->next;						//p指向head的下一个节点
		
		while(p != NULL)					//判断p是否为NULL，如果都是NULL则证明我释放完了
		{
			tmp=p->next;					//tmp用来作为缓冲变量，把p->next记录下来
			free(p);						//释放p节点
			p=tmp;							//把p指向tmp记录的节点
		}

	}

	free(head);								//释放掉链表头

	return;
}


int main(void)
{
	listp head;
	listp node;
	int rd;

	head = init_list();
	if(head == NULL)
	{
		perror("request list head failed\n");
		return -1;
	}

	while(1)
	{
		scanf("%d", &rd);

		if(rd == 0)
			break;

		if(rd > 0)
		{
			node = new_node(rd);

			insert_node(head, node);

			show_list(head);

		}
		else
		{
			remove_node();

			show_list();
		
		}
	
	}

	remove_list();

}
