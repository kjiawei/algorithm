// 封装一系列的关于顺序表操作的函数，方便日后直接调用
#include "myhead.h"
#define SIZE   20
enum returnvalue{full,failed,success};// 使用枚举类型，耍了小花招，阅读代码更加符合人类的阅读习惯
// 定义学生结构体
struct student
{
	char name[10];
	float score;
};
// 定义一个结构体表示顺序表
struct slist
{
	struct student stu[SIZE];
	int last; //表示当前顺序表中最后一个有效成员的下标
};
// 顺序表的初始化,自定义函数，想不清楚究竟返回值返回什么类型比较合适，不清楚究竟要不要形参，要几个形参
// 解决以上困惑的方法：你要想清楚你封装这个函数究竟要完成什么功能？
//                    当你封装完毕之后，调用它的时候方不方便？
struct slist *slist_init()
{
	struct slist *mylist=malloc(sizeof(struct slist));
	mylist->last=-1;
	return mylist;
}
// 尾部插入
enum returnvalue slist_tailinsert(struct slist *list) //???
{
	//判断顺序表有没有满
	if(list->last>=SIZE-1)
	{
		printf("this list is full!\n");
		return full;// 阅读方便
	}
	//初始化一个新的学生信息，然后将该学生插入这个顺序表的尾部
	struct student stu1;
	//stu1.name="zhangsan";//???????  严重的错误
	strcpy(stu1.name,"zhangsan");
	stu1.score=80.5;
	// 将初始化好的学生插入尾部
	list->stu[list->last+1]=stu1;
	// 更新last的值
	list->last++;
	return success;
	
}
// 打印顺序表
int print_list(struct slist *list)
{
	int i;
	for(i=0; i<=list->last; i++)
	{
		printf("第%d个学生名字是：%s\n",i,list->stu[i].name);
		printf("第%d个学生分数是：%f\n",i,list->stu[i].score);
	}
	return 0;
}
// 指定位置插入

int main()
{
	struct slist *listp=slist_init();
	// 往初始化好的顺序表中插入新的学生
	slist_tailinsert(listp);
	// 打印插入之后的结果
	print_list(listp);
	return 0;
	
}