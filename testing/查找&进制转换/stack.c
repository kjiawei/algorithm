#include "myhead.h"
//定义一个结构体表示
struct stack
{
	int a[20];
	int top;  // 指向栈顶的位置
};
// 初始化栈
struct stack *stack_init()
{
	struct stack *mystack=malloc(sizeof(struct stack));
	bzero(mystack->a,80);
	mystack->top=-1;
	return mystack;
}
// 压栈函数
int push(struct stack *mystack,int data)
{
	(mystack->top)++;
	mystack->a[mystack->top]=data;
	
	return 0;
}
// 出栈函数
int pop(struct stack *mystack)
{
	int ret=mystack->a[mystack->top];
	(mystack->top)--;
	return ret;
	
}
int main()
{
	int i;
	int data;
	// 初始化一个空的顺序栈
	struct stack *emptystack=stack_init();
	// 压栈
	for(i=0; i<5; i++)
	{
		printf("请输入你要进栈的数据!\n");
		scanf("%d",&data);
		push(emptystack,data);
	}
	// 弹栈
	for(i=0; i<5; i++)
	{
		printf("弹出的值分别是：%d\n",pop(emptystack));
	}
	return 0;
}