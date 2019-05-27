#include <stdio.h>	//printf
#include <stdlib.h>	//malloc
#include <stdbool.h>	//bool

typedef struct link_list{

	int data;
	struct link_list *next, *prev;

}list_t,*listp;

listp init_list(void)
{
	listp head = malloc(sizeof(list_t));

	if(head != NULL)
	{
		head->next = head;
		head->prev = head;
	}
	
	return head;

}


listp new_node(int rd)
{
	listp node = malloc(sizeof(list_t));

	if(node != NULL)
	{
		node->data = rd;
		node->next = NULL;
		node->prev = NULL;
	}
	
	return node;
}


int insert_node(listp head, listp node)
{
	listp p;

	if(head == NULL || node == NULL)
	{
		printf("insert data error\n");
		return -1;
	}


	for(p=head; (p->next!= head) && (p->next->data <= node->data); p=p->next);
	
	node->prev = p;						//让node上一个记录指针指向p节点
	node->next = p->next;				//让node下一个记录指针指向p->next节点

	p->next->prev = node;				//让p节点的前一个位置的下一个指针指向node
	p->next = node;						//让p节点的下一个指针指向node


	return 0;	
}

void show_list(listp head)
{
	listp p;

	p=head->next;
	while(p != head)
	{
		printf("%d,",p->data);
		p=p->next;
	}

	printf("\n");

	return;

}
bool is_list_empty(listp head)
{
	return head->next == head;
}


int remove_node(listp head, int rd)
{
	listp p;

	if(is_list_empty(head))				
	{
		printf("the list is empty\n");
		return -1;
	}

	p=head;
	while(p->next != head && p->next->data <= rd)			//偏移p到最后一个节点的位置
	{
		p=p->next;
	}
	
	if(p->data == rd)
	{
		p->prev->next = p->next;		//让p节点的上一个位置的下一个指针指向p节点的下一个位置

		p->next->prev = p->prev;		//让p节点的下一个位置的上一个指针指向p节点的上一个位置
	
		free(p);

	}
	
	return 0;
}


void remove_list(listp head)
{
	listp p,tmp;

	if(head->next != head)
	{	
		p = head->next;
		
		while(p != head)
		{
			tmp=p->next;
			free(p);
			p=tmp;
		}

	}

	free(head);

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
			remove_node(head,-rd);

			show_list(head);
		
		}
	
	}

	remove_list(head);

	return 0;

}
