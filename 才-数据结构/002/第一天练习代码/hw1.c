#include <stdio.h>
#include <stdlib.h>


struct student
{
	char name[100];
	int number;
};

struct node
{
	struct student stu;
	struct node *next;
};

struct node *init()
{
	struct node *myhead=malloc(sizeof(struct node));
	myhead->next=NULL;
	return myhead;
}

struct node *create_newnode()
{
	struct node *newnode=malloc(sizeof(struct node));
	printf("请输入学生的名字");
	scanf("%s",newnode->stu.name);
	printf("请输入学生的学号\n");
	scanf("%d",&(newnode->stu.number));
	return newnode;
}


//尾部插入
int insert_tail(struct node *my,struct node *node)
{
	struct node *myhead=my;
	struct node *newnode=node;
	while((myhead->next)!=NULL)
	{
		myhead=myhead->next;
	}
	myhead->next=node;	
}

int insert_mid(struct node *my,struct node *node,char *name)
{
	char *insert_name=name;
	struct node *myhead=my;
	struct node *newnode=node;
	while(myhead->next!=NULL)
	{
		if((strcmp(insert_name,myhead->stu.name)) ==0)
			break;
		myhead=myhead->next;
	}
	if((myhead->next)==NULL)
	{
		printf("您所输入的学生不存在\n");
		insert_tail(myhead,newnode);
	}
	else
	{
		newnode->next=myhead->next;
		myhead->next=newnode;	
	}
}

int print(struct node *my)
{
	struct node *myhead=my;
	while(myhead->next!=NULL)
	{
		myhead=myhead->next;
		printf("此节点的学生的姓名是%s\n",myhead->stu.name);
		printf("此节点的学生的学号是%d\n",myhead->stu.number);
	}
}

int move_prev(struct node *my,char *node,char *node1)
{
	struct node *myhead=my;
	struct node *myhead1=my;
	char *insert_need_name=node;
	char *insert_tail_name=node1;
	static struct node *insert_get;
/* 	while(myhead->next!=NULL)
	{
		myhead=myhead->next;
		if((strcmp(insert_need_name,myhead->stu.name))==0)
			break;
		
	} */
	while(myhead->next!=NULL)
	{
		if((strcmp(insert_need_name,myhead->next->stu.name)) ==0)
			break;
		myhead=myhead->next;
	}
	printf("%s",myhead->stu.name);
	if((myhead->next)==NULL && strcmp(insert_need_name,myhead->next->stu.name)!=0)
	{
		printf("您所输入的学生不存在2\n");
		return 0;
	}
	else
	{
		insert_get=myhead->next;
		myhead->next=insert_get->next;
		insert_get->next=NULL;	
	}
	printf("扣下来的节点是%s",insert_get->stu.name);
	while(myhead1->next!=NULL)
	{
		if(strcmp(insert_tail_name,myhead1->stu.name)==0)
			break;
		myhead1=myhead1->next;
	}
	if((myhead1->next)==NULL)
	{
		printf("您所输入的学生不存在\n");
		insert_tail(myhead1,insert_get);
	}
	else
	{
		insert_get->next=myhead1->next;
		myhead1->next=insert_get;	
	}
	
}

int func()
{
	int i;
	char insert_need_name[100];
	char insert_tail_name[100];
	char insert_name[100];
	struct node *myhead=init();
	for(i=0;i<5;i++)
	{
		struct node *newnode=create_newnode();
		insert_tail(myhead,newnode);
	}
	//printf("请输入你需要插入的同学的前面\n");
	//scanf("%s",insert_name);
	//struct node *newnode1=create_newnode();
	//insert_mid(myhead,newnode1,insert_name);
	/* printf("请输入你需要转移的学生\n");
	scanf("%s",insert_need_name);
	printf("请输入你需要插入到那个同学的后面\n");
	scanf("%s",insert_tail_name);
	move_prev(myhead,insert_need_name,insert_tail_name); */
	print(myhead);
		
}



int main(void)
{

	func();
	
	return 0;	

}


