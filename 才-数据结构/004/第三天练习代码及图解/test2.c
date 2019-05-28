#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"


// （2）生成8节点并用内核链表连接，通过按n显示下一节点数据，按s显示上一个节点数据


struct kernel_list
{
	int data;
	struct list_head list;
};


// 初始化大结构体
struct kernel_list *init()
{
	struct kernel_list *p;

	p = (struct kernel_list *)malloc(sizeof(struct kernel_list));
	if(p == NULL) return NULL;

	// 初始化小结构体
	INIT_LIST_HEAD(&p->list);

	return p;
}

// 遍历输出链表数据
int show(struct kernel_list* head)
{
	if(head == NULL) return -1;

	struct list_head *pos;
	struct kernel_list *kerls;

	// 遍历小结构体链表
	list_for_each(pos, &head->list)
	{
		// 由小结构体得到大结构体的地址
		kerls = list_entry(pos, struct kernel_list, list);
		printf("%d\n", kerls->data);
	}
	return 0;
}
// 将节点插入到指定节点之前
int insert_before(struct kernel_list *basic,struct kernel_list *new)
{
	if(basic == NULL || new == NULL) return -1;

	// 对于循环链表而言,尾插也是对head的前插
	list_add_tail(&new->list, &basic->list);

	return 0;
}

// 指定数据将节点从链上解除
int del_by_data(struct kernel_list* head,int del)
{
	if(head == NULL) return -1;

	struct list_head *pos;

	// 遍历链表
	list_for_each(pos, &head->list)
	{
		// 找到要删除的节点
		if( list_entry(pos, struct kernel_list, list)->data == del)
		{
			// 从链上解除
			list_del(pos); //只是解除，还要手动free
			return 0;
		}
	}
	return -1;
}

// 查找数据所在节点
struct kernel_list *find_node(struct kernel_list *head,int data)
{
	struct list_head *pos,*n;
	struct kernel_list *tmp;
	
	list_for_each_safe(pos, n , &head->list)//安全遍历删除
	{
		tmp = list_entry(pos,struct kernel_list , list); 
		if(tmp->data == data)
			return tmp;
	}

	return NULL;
}

// 打印下一节点数据
struct kernel_list* show_next(struct kernel_list* head,struct kernel_list* now)
{	
	if(head == NULL || now == NULL) return NULL;

	struct kernel_list* next; //大结构体next指针

	// 确定当前的节点在链表上

	if( now != NULL)
	{
		// 找下一个节点
		next =  list_entry((now->list).next,struct kernel_list , list); //在接头时执行两条语句
		if(next == head)
			next =  list_entry((next->list).next,struct kernel_list , list); 

		printf("%d\n", next->data);
		return next;
	}

	return NULL;
}

// 打印上一节点数据
struct kernel_list* show_prev(struct kernel_list* head,struct kernel_list* now)
{	
	if(head == NULL || now == NULL) return NULL;

	struct kernel_list* prev;

/* 	// 确定当前的节点在链表上
	if(now != head)
		now = find_node(head,now->data); */
	if( now != NULL)
	{
		// 找上一个节点
		prev =  list_entry((now->list).prev,struct kernel_list , list);
		if(prev == head)
			prev =  list_entry((prev->list).prev,struct kernel_list , list);

		printf("%d\n", prev->data);
		return prev;
	}

	return NULL;
}

int main(void)
{
	char c;
	int i;
	struct kernel_list *head;
	struct kernel_list *new;
	struct kernel_list *now;
	head = init();  //定义头节点无数据

	for(i=0; i<5; i++)
	{
		new = init();
		printf("请输入数据：\n");
		scanf("%d",&new->data);
		printf("第%d节点地址：%p\n",i,new);
		insert_before(head,new); 
	}
	
	printf("按n查看下一个，p查看上一个,q退出\n");
	now = head;
	while( getchar() != '\n');
	while(1)
	{
		scanf("%c",&c);
		getchar();
		// printf("%c\n", c);

		if( c == 'q') break;

		switch(c)
		{
			case 'n':
				now = show_next(head,now); //返回遍历记录大结构体
				break;
			case 'p':
				now = show_prev(head,now); ////返回遍历记录大结构体
				break;
			default:
				printf("无效的指令!\n");
		}
	}
	
	return 0;
}



