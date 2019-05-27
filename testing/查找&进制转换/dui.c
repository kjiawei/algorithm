#include "myhead.h"

#define SIZE 10

struct stack_note
{
	char note[SIZE];
	int  flag;
	int  dui;   //队列
};

struct stack_note *creat_stack()
{
	struct stack_note *creat_stack = malloc(sizeof(struct stack_note));
	bzero(creat_stack->note,SIZE);

	creat_stack->flag=-1;
	creat_stack->dui=-1;    //队列

	return creat_stack;
} 

int push_stack(struct stack_note *make_stack,int num,int choose) //余数逆序
{
	int buf;
	while(num!=0)
	{
		if((make_stack->flag)>=SIZE-1)
		{
			printf("stack is fulled!!!\n");
			return -1;
		}

		buf=num%choose;
		if(buf>9)
		{
			make_stack->note[++(make_stack->flag)]=buf-10+'A';
		}
		else
		{
			make_stack->note[++(make_stack->flag)]=buf+'0';
		}
		num=num/choose;
	}
	return 0;
}

int pop_stack(struct stack_note *make_stack)
{
	int i;
	char result;

	//result = make_stack->note[(make_stack->flag)]; //栈

	result = make_stack->note[(make_stack->dui)+1]; //队列
	for(i=(make_stack->dui)+1;i<(make_stack->flag);i++)
	{
		make_stack->note[i]=make_stack->note[i+1];
	}


	make_stack->note[(make_stack->flag)]=0;
	(make_stack->flag)--;

	return result;
}

int display(struct stack_note *make_stack,int back)
{
	if(back==-1)
	{
		return -1;
	}

	printf("转换的结果:");
	while((make_stack->flag)>=0)
	{
		printf("%c",pop_stack(make_stack));
	}
	printf("\n");

	return 0;
}

int main()
{
	int num,choose,back;
	struct stack_note *make_stack = creat_stack();

	printf("请输入想要转换的正整数：\n");
	scanf("%d",&num);

	printf("请输入想要转换的进制数：\n");
	while(1)
	{
		scanf("%d",&choose);

		switch(choose)
		{	
			case 2: back=push_stack(make_stack,num,choose);
								  display(make_stack,back);
								  return;
			case 8: back=push_stack(make_stack,num,choose);
								  display(make_stack,back);
								  return;
			case 16:back=push_stack(make_stack,num,choose);
								  display(make_stack,back);
								  return;
			default: printf("输入错误重新输入想要转换的进制数：\n");
		}
	}
	return 0;
}