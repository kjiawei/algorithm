#include <stdio.h>
#include <stdlib.h>

typedef struct link_list{				
	int data;
	struct link_list *next;
}list_node, *listp;					//定义链表数据类型

listp request_list_head(void)		//申请一个链表头
{
	listp p = malloc(sizeof(list_node));

	if(p != NULL)
		p->next = NULL;
	return p;
}

void remove_list(listp head)		//释放链表里的所有内存
{
	listp p = head;
	listp tmp;

	for(; p != NULL; )				//一个一个释放内存
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}

	return;
}


int insert_node(listp head, int rd)		//插入一个链表节点
{
	listp p,q,req;						//缓冲的指针

	for(p=head,q=head; p!=NULL; q=p, p=p->next);		//q用来记录当前位置，p用来记住下个节点的地址
	
	req = malloc(sizeof(list_node));					//申请节点内存
	if(req == NULL)									//申请错误则退出
	{
		printf("request node failed\n");
		return -1;
	}

	req->data = rd;										//将数据放入节点
	req->next = NULL;									//让节点的下一个指针为NULL

	q->next = req;										//将节点添加进链表

	return 0;
}

void remove_node(listp head)
{
	listp p,q;

	if(head->next == NULL)								//如果链表内容为NULL，则返回
		return;

	for(p=head; 										//指针一直偏移到链表最后，q用来记录倒数第二个节点，p用来记录最后一个节点
		p->next != NULL; 
			q=p, p=p->next);
	

	q->next = NULL;									//倒数第二个节点指向NULL

	free(p);											//释放最后一个节点的内存
	
	return;
}

void show_list(listp head)
{
	listp p;
	for(p=head->next; p!=NULL; p=p->next)
		printf("%d,", p->data);
	printf("\n");

}

int main(void)
{
	int rd;

	listp head;

	head = request_list_head();
	if(head == NULL)
	{
		printf("request list head failed\n");
		return -1;
	}

	while(1)
	{
		scanf("%d", &rd);

		if(rd == 0)
			break;

		if(rd > 0)
		{
			insert_node(head, rd);
			show_list(head);
		}
		else
		{
			remove_node(head);
			show_list(head);
		}
	
	}


	remove_list(head);

}
