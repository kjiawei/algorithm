#include <stdio.h>
#include <stdlib.h>
#include "kernel_list.h"

struct student
{
	int num;
	struct list_head mylist;
};

// �ں�����ĳ�ʼ��
struct student * list_init()
{
	struct student *head=malloc(sizeof(struct student));
	INIT_LIST_HEAD(&(head->mylist));
	return head;
}

// �����µĽڵ�
struct student * new_node(int data)
{
	struct student *new=malloc(sizeof(struct student));
	new->num=data;
	INIT_LIST_HEAD(&(new->mylist));
	return new;
}

// ����µĽڵ㵽�ں�������
int kernellist_add(struct student *new,struct student *head)
{
	list_add(&(new->mylist), &(head->mylist));
	return 0;
}

// ��ӡ�ں����������
int show(struct student *head)
{
	struct student *pos;
	list_for_each_entry(pos,&(head->mylist),mylist) //�ú꺯��ʵ���Ǹ�forѭ��
	//for (pos = list_entry((head)->next, typeof(*pos), member);  &pos->member != (head);  pos = list_entry(pos->member.next, typeof(*pos), member))
	{
		printf("pos->num is:%d\n",pos->num);
	}
	
	return 0;
}

int main()
{
	int n;
	int i;
	struct student *mynewnode;
	struct student *p=list_init();
	printf("please input num you want create node!\n");
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		mynewnode = new_node(i);
		kernellist_add(mynewnode,p);
	}
	show(p);
	return 0;
}