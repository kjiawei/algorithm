#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info
{
    char name[10];
    char data[20];
	float Clanguage;
	float English;
	float Match;
	float History;
	float Sports;
	float Computer;
	
	struct info *prev;
	struct info *next;
};

struct info *data_init(void)
{
    struct info *P=(struct info *)malloc(sizeof(struct info));
	if(P == NULL)
	{    
	    printf("初始化失败\n");
		return NULL;
	}
	P->prev = P;
	P->next = P;
	
	return P;
}
//前插
// int data_insert(struct info *head,struct info *new)
// {
    // struct info *P1 = head;
    // struct info *P2 = new;
	
	// if(head != NULL || new != NULL)
	// {
	    // P2->next = P1 -> next;
		// P2->prev = P1;
		// P1->next ->prev = P2;
		// P1->next = P2;
	// }
	
// }

//后插
int data_insert(struct info *basic,struct info *new)
{
    if(basic != NULL || new != NULL)
	{
	//写法一：
	    // new ->next = basic;
		// new ->prev = basic ->prev;
		// basic ->prev = new;
		// new ->prev ->next = new;
	//写法二：
		new ->next = basic;
		new ->prev = basic ->prev;
		basic ->prev ->next = new;
		basic ->prev =new;
		return 0;
	}
	return -1;
}

void Display_menu(void)
{
    printf("输入字符选择以下功能\n");
	printf("i。插入学生信息\n");
	printf("j。显示链表\n");
	printf("k。查找学生数据\n");
	printf("l。删除数据节点\n");
	printf("m。移动数据节点\n");
	
	printf("e。退出系统\n");
}

struct info *data_find(struct info *head,char *data)
{
	
	if(head ->next ==NULL)
	    return NULL;
		
	struct info *P=head->next;
		
    for(;P != head;P = P -> next)
	{
		if(!strcmp(P->data,data))
		{    
		    return P;
		}
	}
	
    return NULL;
}

struct info *Del_node(struct info *del)
{
    if(del ==NULL)
	    return NULL;
	
	del ->prev->next = del ->next;
	del ->next->prev = del ->prev;
	
	del ->next =del;
	del ->prev =del;
   
    return del;
}

int data_Display(struct info *head)
{
    int i;
    struct info *P = head->next;
	printf("==============================================================\n");
	for(;P != head;P = P -> next)
	{
	    printf("同学       %s\n",P->name);
	    printf("学号       %s\n",P->data);
	    printf("C语言成绩  %f\n",P->Clanguage);
	    printf("英语成绩   %f\n",P->English);
	    printf("数学成绩   %f\n",P->Match);
	    printf("历史成绩   %f\n",P->History);
	    printf("体育成绩   %f\n",P->Sports);
	    printf("计算机成绩 %f\n",P->Computer);
		printf("--------------------------------------------------------------\n");
	}
	printf("==============================================================\n");
    printf("\n");
    return 0;
}

int data_find_display(struct info *head,struct info *find)
{
    struct info *P=head->next;
	printf("==============================================================\n");
    for(;P != head;P = P -> next)
	{
		if(P == find)
		{
				printf("同学       %s\n",P->name);
				printf("学号       %s\n",P->data);
				printf("C语言成绩  %f\n",P->Clanguage);
				printf("英语成绩   %f\n",P->English);
				printf("数学成绩   %f\n",P->Match);
				printf("历史成绩   %f\n",P->History);
				printf("体育成绩   %f\n",P->Sports);
				printf("计算机成绩 %f\n",P->Computer);
		}
	}
	printf("==============================================================\n");
}


int main(void)
{
    int i;
	char data[20];
	char ch;
	struct info *head,*new,*find,*move,*P;
	head = data_init();
	
	while(1)
	{
	    Display_menu();
		scanf("%c",&ch);
		getchar();
		if(ch == 'e')
		    break;
		switch(ch)
		{    
		    case 'i':
					new = data_init();
					
					printf("请输入名字\n");
					scanf("%s",new->name);
					getchar();
					
					printf("请输入学号\n");
					scanf("%s",new->data);
					getchar();
					
					printf("请输入C语言成绩\n");
					scanf("%f",&new->Clanguage);
					
					printf("请输入英语成绩\n");
					scanf("%f",&new->English);
					
					printf("请输入数学成绩\n");
					scanf("%f",&new->Match);
					
					printf("请输入历史成绩\n");
					scanf("%f",&new->History);
					
					printf("请输入体育成绩\n");
					scanf("%f",&new->Sports);
					
					printf("请输入计算机成绩\n");
					scanf("%f",&new->Computer);
					getchar();
					
					
					data_insert(head,new);
					printf("---------------------------\n");
					
			    break;
			
			case 'j':
			        printf("asda\n");
					data_Display(head);
				break;
			
			case 'k':
					printf("请输入学号\n");
					memset(data,0,sizeof(data));
					scanf("%s",data);
					getchar();
					
					find=data_find(head,data);
					data_find_display(head,find);
				break;
			
			
			case 'l':
					printf("请输入要删除的数据\n");
					memset(data,0,sizeof(data));
					scanf("%s",data);
					getchar();
					find=data_find(head,data);
					if(find != NULL)
					{	
					    printf("找到节点\n");
					    Del_node(find);
						free(find);
						
					}
				break;
				
			case 'm':
					printf("请输入需要移动的数据\n");
					memset(data,0,sizeof(data));
					scanf("%s",data);
					getchar();
					
					move=data_find(head,data);
					if(find != NULL)
					{	
					    printf("找到节点\n");
					    Del_node(move);
					}
					printf("请输入需要移动的位置\n");
					scanf("%s",data);
					getchar();
					find=data_find(head,data);
					data_insert(find,move);
				break;

			        
					
					break;
					
			default:
			    printf("输入有误\n");
			
		}	
	}
    return 0;
}