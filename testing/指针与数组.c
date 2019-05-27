#include "myhead.h"

int main()
{
	char a[5];
	char b[5]="def";
	char *p=a; // a等价于&a[0]; 数组名作为右值才是首元素的地址
	//a="abc";  //incompatible types when assigning to type ‘char[5]’ from type ‘char *’ 错误
	//a=b; //incompatible types when assigning to type ‘char[5]’ from type ‘char *’ 错误
	strcpy(a,b);    正确
	printf("a is:%s\n",a);

/*
字符数组初始化的几种写法：
  写法一：
       char a[10]="hello"； 定义的同时立马初始化  正确
  写法二：
       char a[]="hello"; 正确
       char a[];
       a="hello"         错误 
  写法三：
       char a[10];
       a="zhangsan"      错误
       scanf("%s",stu.a);
       char a[10];
       strcpy(a,"zhangsan"); 正确
       
     //&a[0]=b;   test

     总结:要不声明时候定义,要不strcpy


	 test:
	 int arr[5][4];
//	int (*q[5])[4] = {arr};
	int (*q[5])[4] = {arr, &arr[1], &arr[2],&arr[3], &arr[4]};
*/

	return 0;
}