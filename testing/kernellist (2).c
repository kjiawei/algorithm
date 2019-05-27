#include "myhead.h"
#include "kernel_list.h"

//模拟内核链表实现双向循环链表

struct student 
{
	char name[10];
	float score;
	
};

struct kernel_list  //宿主结构体
{
	struct student stu;
	struct list_head mylist;  //小结构体
};

// 内核链表的初始化
struct kernel_list *kernel_init()
{
	struct kernel_list *head=malloc(sizeof(struct kernel_list));
	INIT_LIST_HEAD(&(head->mylist));
	return head;
}

// 新建节点
struct kernel_list *create_new()
{
	struct kernel_list *newnode=malloc(sizeof(struct kernel_list));
	printf("名字！\n");
	scanf("%s",newnode->stu.name);
	printf("分数！\n");
	scanf("%f",&newnode->stu.score);
	INIT_LIST_HEAD(&(newnode->mylist));
	return newnode;
}

// 尾部插入
int kernel_list_tail(struct kernel_list *head,struct kernel_list *new)
{
	list_add_tail(&new->mylist,&head->mylist);
	return 0;
}
// 打印 版本一
/* int kernel_print(struct kernel_list *head)
{
	struct list_head *pos;
	struct kernel_list *curbigstruct;
	
	list_for_each(pos,&head->mylist) // 就是个for循环
	{
		// 通过小结构体指针得到大结构体
		curbigstruct=list_entry(pos,struct kernel_list,mylist);
		printf("目前学生是：%s  分数%f\n",curbigstruct->stu.name,curbigstruct->stu.score);
		
	}
	
} */
// 打印  版本二
int kernel_print(struct kernel_list *head)
{
	struct kernel_list *pos;
	list_for_each_entry(pos,&head->mylist,mylist) // 就是个for循环
	{
		printf("我目前通过大结构体指针pos访问到的学生是：%s  分数：%f\n",pos->stu.name,pos->stu.score);
	}
} 

// 删除
int rm_kernel(struct kernel_list *head,char *name)
{
	struct kernel_list *pos,*n;
	list_for_each_entry_safe(pos,n,&head->mylist,mylist)
	{
		if(strcmp(pos->stu.name,name)==0)
			break;
	}
	list_del(&pos->mylist);
	free(pos);
	return 0;
}

int main()
{
	int i;
	char buf[10];
	struct kernel_list *myhead=kernel_init();
	for(i=0; i<3; i++)
	{
		struct kernel_list *newnode=create_new();
		kernel_list_tail(myhead,newnode);
	}
	kernel_print(myhead);
	printf("请输入要删除的学生名字！\n");
	scanf("%s",buf);
	rm_kernel(myhead,buf);
	printf("删除之后！\n");
	kernel_print(myhead);
	return 0;
		
	
}


/*复杂语法解析
 (type *)

(char *)(ptr)-(unsigned long)(&((type *)0)->member)
A  ---->  (char *)(ptr)  ptr被强制转换成了char类型的指针
B  ---->  (unsigned long)(&((type *)0)->member)  得到了小结构体在内存中地址（）
                 &(struct kernel_list->mylist)
 */