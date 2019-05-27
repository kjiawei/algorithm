#include <stdio.h>	//printf
#include "list.h"	//kernel list define infor		//自己整理的内核链表的头文件
#include <stdlib.h>	//malloc

typedef struct list_node{		//我们自行定义的结构体

	int data;

	struct list_head list;		//内核链表结构体，专门用来将链表链接起来的

}list_t, *listp;				

listp init_list(void)
{
	listp head = malloc(sizeof(list_t));

	if(head != NULL)
	{
		INIT_LIST_HEAD(&head->list);		//初始化自定义结构体内部的内核链表（其实就是让里面的指针，自己指向自己）
	}

	return head;
}

listp new_node(int rd)
{
	listp node = malloc(sizeof(list_t));	

	if(node != NULL)
	{
		node->data = rd;
		node->list.next = LIST_POISON1;		//这是内核链表给我们定义的两个宏，用于当没有将节点插入链表时又去用链表时就会出错
		node->list.prev = LIST_POISON2;		
	}

	return node;
}

int insert_node(listp head, listp node)
{

	if(head == NULL || node == NULL)
	{
		printf("insert list failed\n");
		return -1;
	}

	list_add_tail(&node->list, &head->list);		//这个函数用于将节点插入链表的上一个位置


	return 0;
}

void show_list(listp head)
{
	struct list_head *pos;
	listp node;

	
	//这是一个遍历，pos用来记录遍历的链表位置，&head->list你想要从哪里开始遍历
	//记得，这只是去偏移链表，他的单位不是大的结构体
	list_for_each(pos, &head->list)//for(....pos)	
	{
		node = list_entry(pos, list_t, list);	//通过晓得链表的指针，帮我们获取大的结构体的数据指针

		printf("%d,",node->data);
	}
	
	printf("\n");

}


void remove_node(listp head)
{
	listp node;

	if(list_empty(&head->list))			//判断当前list是否是空链表
	{
		printf("the list empty\n");
		return;
	}


	node = list_entry(head->list.prev, list_t, list);		//获取链表的上一个大节点的指针

	list_del(head->list.prev);								//从链表中删除head的上一个节点
	
	free(node);												//释放掉整个节点的内存空间

	return;
}


void remove_list(listp head)
{
	struct list_head *pos,*n;
	listp node;

	
	/*
	这是一个遍历，这个遍历是安全版本遍历，pos用来记录遍历的链表位置，n则是用来缓冲，实际上我们没用到，只是函数用到而已，
	&head->list你想要从哪里开始遍历记得，这只是去偏移链表，他的单位不是大的结构体
	*/
	list_for_each_safe(pos, n, &head->list)//for(....pos)	
	{
		node = list_entry(pos, list_t, list);	//通过晓得链表的指针，帮我们获取大的结构体的数据指针

		list_del(pos);							//把对应的pos节点从链表中踢出去

		printf("free -> %d\n",node->data);

		free(node);								//释放掉整个大的结构体内存（节点）
	}

	free(head);

	return;
}


int main(void)
{
	listp head, node;
	int rd;

	head = init_list();


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
			remove_node(head);
			show_list(head);
		}

	}

	remove_list(head);

	return 0;
}
