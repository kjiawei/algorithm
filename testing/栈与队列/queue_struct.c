/*二.
1.队列:先进先出;栈:后进先出*/ 
//出入对条件判断 2个栈都为空的
//拓展:车厢调度 两个队实现栈 

#include <stdio.h>
//两个栈实现一个队列,算法和思路   http://www.cnblogs.com/wanghui9072229/archive/2011/11/22/2259391.html
//两队实现栈 http://www.cnblogs.com/kaituorensheng/archive/2013/03/02/2939690.html

//"进栈"的首值赋给"出栈"的尾值,进栈的尾值赋给出栈的首值->常规方法->优化:第一次出栈元素直接返回不进下一个的栈(变种1)
//变种2:入队时，先判断s1是否为空，如不为空，说明所有元素都在s1，此时将入队元素直接压入s1；如为空，要将s2的元素逐个“倒回”s1，再压入入队元素
//出队时，先判断s2是否为空，如不为空，直接弹出s2的顶元素并出队；如为空，将s1的元素逐个“倒入”s2，把最后一个元素弹出并出队。
//s2永远都不会倒回s1

#define STACK_LEN 5

struct stack{
	int top;//栈顶
	int stack_size[20];//栈大小 顺序式
	//栈底指针 链式:data *p
};//注意点:记得分号

//初始化栈
struct stack *in_init(){
	struct stack *myStack = malloc(sizeof(struct stack));
	bzero(myStack->stack_size,80);
	myStack->top=-1;
	return myStack;
}

//压栈
int push(struct stack *myStack,int data)
{
	(myStack->top)++;//可以加上判断
	myStack->stack_size[myStack->top] = data;//新数据给到最高位
	return data;
}

//方式1弹栈:没有优化->栈1最后弹出那个不用进栈2
int pop(struct stack *myStack)
{
	int ret = myStack->stack_size[myStack->top];
	(myStack->top)--;
	return ret;
}

//变种2弹栈
int pop2(struct stack *myStack,struct stack *myStack2)
{
	int ret = myStack2->stack_size[myStack2->top];                
	
	if(isStackEmpty(myStack2)==0)//栈2不为空
	{
		while(isStackEmpty(myStack)==0)//栈1也不空
		{push(myStack2,pop(myStack));}//弹1压2     //1 1   1man 2kong
		pop(myStack2);
	}
	if(isStackEmpty(myStack2)==1)
	{
		printf("栈已空\n");
	}
	return ret;//栈1空栈2直接弹
}

int isStackEmpty(struct stack *myStack)//boolean的怎么做
{
	if((myStack->stack_size[myStack->top])<0)//宏定义
	{	
		printf("空栈\n");
		return 1;
	}else{
		printf("非空栈\n");
		return 0;
	}
}

int isStackFull(struct stack *myStack)
{
	if((myStack->stack_size[myStack->top])>=STACK_LEN)
	{
		printf("满栈\n");
		return 1;
	}
		
	else{
		printf("栈未满\n");
		return 0;
	}
}

int main()
{
	int i,j,data;
	int data2[STACK_LEN];//用于暂时存放栈1弹出的值
	struct in_init *main1 = in_init();//初始化空栈;
	struct in_init *main2 = in_init();//栈1->实际存储   //出栈2->缓冲作用
	//演示1:向栈1压5个数据
	for(i=0;i<STACK_LEN;i++)
	{
		printf("第%d次(入队-栈1压入)的数据:\n",i+1);
		scanf("%d",&data);
		push(main1,data);
	}
	//isStackEmpty(main1);
	isStackFull(main1);
	
	//方式1弹栈的出对操作:栈1弹出的数并压入栈2的过程
	for(i=0,j=0;i<STACK_LEN;i++,j++)
	{
		printf("\n");
		data2[j] = pop(main1);
		printf("栈1第%d次弹出的数据:%d\n",i+1,data2[j]);
		printf("栈2第%d次压入的数据:%d\n",i+1,push(main2,data2[j]));
	}
	
	for(i=0;i<STACK_LEN;i++)
	{
		printf("\n第%d次(出队-栈2弹出)的数据:%d",i+1,pop(main2));
	}

	//方式2弹栈的出对操作:栈1弹出的数并压入栈2的过程
	/*push(main2,6);//这里栈2不为空怎么处理？
	for(i=0,j=0;i<STACK_LEN;i++,j++)
	{
		printf("\n");
		
		printf("%d---%d",i+1,pop2(main1,main2));
	}*/
	
	return 0;
}

/*
1.static作用:全局作用域 控制可见性 存储位置
作用全局变量时存储不变区（静态变量区）但限制作用域，不能被模块外其它函数访问；
修饰局部变量时变存储区域"栈"为静态存储区（区别auto），代表该内存只被分配一次而且
下次调用时仍维持上次的值,函数中定义，static int j = 10; //此时作用等同为全局变量,静态局部变量只初始化一次
第二次调用不执行

2.const *结合使用 哪些(不)可变
const修饰内容不能做任何改变
例子：int *const  p = &test1;  //保护的是p里的内容,只能在定义里赋值
	//p = &test2; p为常量，不能再赋值
const char *p  == char const *p(修改*p)
（1）常量指针，不能通过这个指针改变变量的值，但是还是可以通过其他指针的引用或者变量来改变里面的值 
（2）常量指针指向的值不能改变，但是这并不意味着指针不能改变，指针可以指向其它变量的
	int test1 = 100;
	const int *p;
	int *pp;
	p = &test1; //指针与变量关联
	pp = &test1;
	test1 = 200; //通过变量改变里面的值
	*pp = 70;    //通过其他未用const指针来修改里面的值 
	//*p = 25; //error: assignment of read-only location ‘*p’
	printf("*p = %d\n",*p);
	printf("test1 = %d\n",test1);
	char *const p:
	（1）指针常量:指针本身是一个常量，不能再指向别的地址
	 (2) 指针常量里面的地址不能改变，但是地址中保存的值是可以改变的
	int test1 = 100;
	int test2 = 25;
	int *const  p = &test1;  //保护的是p里的内容,只能在定义里赋值
	 //p = &test2; p为常量，不能再赋值
	test1 =45;
	*p = 70;
	printf("*p = %d\n",*p);
	printf("test1 = %d\n",test1);
	const *int const p:指向常量的常指针。p里面的内容不可以改变，同时也不能通过*p改变地址指向的内存
3.数组
*/
