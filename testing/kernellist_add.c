#include"myhead.h"
#include"kernel_list.h"

struct student
{
	char name[10];
	float score;
};

struct kernel_list  //宿主结构体
{
	struct student stu;
/* --------------------------------------------
	内核中定义
	struct list_head 
	{
	struct list_head *next, *prev;
	};
	--------------------------------------------
 */
	struct list_head mylist;//内核宏定义结构体（用于存放前后指针）
};

//链表初始化
struct kernel_list *kernel_init()
{
	struct kernel_list *head = malloc(sizeof(struct kernel_list));
	
/* --------------------------------------------------------------------------------
	内核中定义
	
	#define INIT_LIST_HEAD(ptr)		do { \
										(ptr)->next = (ptr); (ptr)->prev = (ptr); \
										} while (0) 
	--------------------------------------------------------------------------------	
*/
	INIT_LIST_HEAD(&(head->mylist));
	return head;
}

//创建新节点
struct kernel_list *create_new()
{
	struct kernel_list *newnode = malloc(sizeof(struct kernel_list));
	printf("请输入新学生名字：\n");
	scanf("%s",newnode->stu.name);
	printf("请输入新学生分数：\n");
	scanf("%f",&(newnode->stu.score));
	INIT_LIST_HEAD(&(newnode->mylist));
	return newnode;
	
} 
// 尾部插入
/* 
--------------内核中定义--------------------------------------------------
static inline void __list_add(struct list_head *new,
				struct list_head *prev,
				struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

 static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
	__list_add(new, head->prev, head);
} 
------------------------------------------------------------------------------
*/
/*
//尾插代码
int kernel_list_tail(struct kernel_list *head,struct kernel_list *new)
{
	list_add_tail(&new->mylist,&head->mylist);
	return 0;
} 
*/

//前插入
/*
-------------------------内核中定义--------------------------------------------
	static inline void __list_add(struct list_head *new,
					struct list_head *prev,
					struct list_head *next)
	{
		next->prev = new;
		new->next = next;
		new->prev = prev;
		prev->next = new;
	}
	static inline void list_add(struct list_head *new, struct list_head *head)
	{
		__list_add(new, head, head->next);
	}
---------------------------------------------------------------
		*new(新)=new    *prev（前）=head   *next（后）=head->next
		
		后->prev=new；
		new->next=后；
		new->prev=前;
		前->next=new；
--------------------------------------------------------------
*/
//前插代码
int kernel_list_add(struct kernel_list *head,struct kernel_list *new)
{
	list_add(&(new->mylist),&(head->mylist));
	return 0;
} 

//打印
int kernel_print(struct kernel_list *head)
{
	struct list_head *pos;
	struct kernel_list *curbigstruct;
	list_for_each(pos,&head->mylist)
	{
		//通过小结构体指针得到大结构体
		curbigstruct = list_entry(pos,struct kernel_list,mylist);
		printf("目前学生是：%s  分数：%f\n",curbigstruct->stu.name,curbigstruct->stu.score);
	}
}

int main()
{
	int i;
	struct kernel_list *myhead = kernel_init();
	
	/* for(i=0;i<3;i++)
	{
		struct kernel_list *newnode = create_new();
		kernel_list_tail(myhead,newnode);
	} */
	for(i=0;i<3;i++)
	{
		struct kernel_list *newnode = create_new();
		kernel_list_add(myhead,newnode);
	}
	kernel_print(myhead);
	return 0;
	
}