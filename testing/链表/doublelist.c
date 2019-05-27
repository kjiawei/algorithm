#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
		char name[10];
		float score;
	};

struct doubleList{
		struct student stu;
		struct doubleList *prev;
		struct doubleList *next;
	};
	
//链表初始化
struct doubleList *slist_init(){
	//涉及操作:头节点
	struct doubleList *head=malloc(sizeof(struct doubleList));
	
	if(head==NULL)
	{
		perror("malloc memory failed!\n");
		return NULL;
	}
	head->next = NULL;
	head->prev = NULL;
	//printf("单链表初始化完成!\n");
	return head;
}

//创建新节点
struct doubleList *createNode(){
	struct doubleList *newNode=malloc(sizeof(struct doubleList));
	printf("请输入新插入学生的名字:\n");
	scanf("%s",newNode->stu.name);
	printf("请输入新插入学生的分数:\n");
	scanf("%f",&(newNode->stu.score));
	
	newNode->next=NULL;//prev是否还要处理
	return newNode;
}

//头部插入
int slist_insert_front(struct doubleList *head){
	struct doubleList *p=head;//head为空的头节点，p为移动的节点(做循环用)
	struct doubleList *newNode1=createNode();
	//找到需要插入的位置
	while(p->next!=NULL){
		if(strcmp(p->stu.name,name)==0){
			p->next=newNode1;
			newNode1->next=
		}
	}
	
	/* if(p->stu.name)==NULL){//判断p指向的节点的内容是否为空?
		p->next=p->next+1;//所有p往后挪一位,可能放在循环里
		p=p->next;
		p->next=newNode1;
	} */
	return 0;
} 

//中间插入,K房点歌系统
int slist_insert_mid(struct doubleList *head,char *sname,char *iname,float iscore){
	struct doubleList *p=head;
	
	//思路：得到输入条件学生位置(要判断是否存在这个名字)
	while(p->next!=NULL){
		if(strcmp( ->stu.name,sname)==0){
			break;
		}
		p=p->next;//将此位置的元素往后都退一位
	}
	struct doubleList *newNode1=createNode();
	newNode1->next=p->next;//后一位的给到新的一位，新的再给到前面的一位
	p->next=newNode1;//注意这里不用newNodel->next
	return 0;
}

//尾部插入
int slist_insert_tail(struct singleList *head){
	struct doubleList *p=head;//P用来做遍历
	struct doubleList *newNode1=createNode();//准备新节点
	 
	 while(p->next!=NULL){
		p=p->next;
	}
	
	p->next=newNode1;//p的next指向下一个节点,插入到目前链表中最后一个有效节点的尾部
	return 0;
}

//打印
int singleList_print(struct singleList *head){
	struct doubleList *p=head;
	while(p->next!=NULL){//遍历单链表
		p=p->next;
		printf("目前访问到的节点对应的学生名字为:%s,分数:%.1f\n",p->stu.name,p->stu.score);
	}
	return 0;
}

int main(void){
	char *sname,*iname;
	float iscore;
	struct doubleList *myhead=slist_init();//初始化好的空的头节点
	slist_insert_tail(myhead);
	//printf("请输入你想插入到学生位置的名字,新学生的名字和分数(并用，隔开->例:zhang,li,50):\n");
	scanf("%s,%s,%f",sname,iname,&iscore);
	slist_insert_mid(myhead,sname,iname,score);
	//slist_insert_front(myhead);
	//slist_insert_tail(myhead);
	singleList_print(myhead);//输出验证一下
	return 0;
}