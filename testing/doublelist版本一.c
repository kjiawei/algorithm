#include "myhead.h"

struct student 
{
	char name[10];
	float score;
};
struct double_list
{
	struct student stu;
	struct double_list *next;
	struct double_list *prev;
};

// 双链表的初始化
struct double_list *double_listinit()
{
	struct double_list *head=malloc(sizeof(struct double_list));
	if(head==NULL)
	{
		perror("malloc memory failed!\n");
		return NULL;
	}
	head->next=NULL;
	head->prev=NULL;
	return head;
}