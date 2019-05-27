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
		head->next = NULL;
		head->prev = NULL;
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

	for(p=head; p->next!= NULL; p=p->next);	//定位到最后一个节点

	node->prev = p;					//让node记录的上一个节点等于p
	node->next = p->next;			//让node记录的下一个节点等于p->next

	//p->next->prev = node;
	p->next = node;					//让p的下一个节点等于node


	return 0;	
}

void show_list(listp head)
{
	listp p;

	p=head->next;
	while(p != NULL)
	{
		printf("%d,",p->data);
		p=p->next;
	}

	printf("\n");

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
			//remove_node(head);

			//show_list(head);
		
		}
	
	}

	//remove_list(head);

	return 0;

}
