#include <stdio.h>
#include <stdlib.h>
#include <math.h>// 编译时候要 -lm  表示link libm.so
#include <string.h>

char * func(char *); // 声明

//int main(void)
int main(int argc, char *argv[])// argc表示的是传入参数个数， argv 表示指针数组，argv[n] 是个char 指针, argv[n]就是个字符串的首元素地址，字符串名
{
	int i;
	for(i=0; i<argc ; i++)
	{
		printf("argv[%d] == %s \n", i, argv[i]);
	}

	

	char *p = func( argv[1]);

	printf("p = %s \n", p);


	return 0;
		
}

char * func(char *x) //函数定义    char *x= argv[1] 首元素地址        sizeof(x) === 4
{
	char flag[100] = "素数";
	int i;
	int num = atoi (x);


	for(i=2; i<= sqrt(num); i++)
	{
		if( num %i == 0) // 能被某数整除
		{
			strcpy(flag,"非素数") ; // 非素数
			break;	
		}
	}
	
	return flag;
}

