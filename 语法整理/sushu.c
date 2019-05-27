#include <stdio.h>
#include <stdlib.h>
#include <math.h>// 编译时候要 -lm  表示link libm.so

int func(int); // 声明

//int main(void)
int main(int argc, char *argv[])// argc表示的是传入参数个数， argv 表示指针数组，argv[n] 是个char 指针, argv[n]就是个字符串的首元素地址，字符串名
{
	int flag = 0;
	int i;
	for(i=0; i<argc ; i++)
	{
		printf("argv[%d] == %s \n", i, argv[i]);
	}
#if 0	// 预编译判断
	int num;
	num = atoi (argv[1]);

	for(i=2; i<= sqrt(num); i++)
	{
		if(num %i == 0) // 能被某数整除
		{
			flag = 1; // 非素数
			break;	
		}
	}
#else
	flag = func(atoi(argv[1]));	// 用func中的flag值给main函数中的flag赋值
#endif 
	if(flag == 0)
		printf("素数 \n");
	else
		printf("非素数 \n");


	return 0;
		
}

int func(int num) // int num = atoi(argv[1])
{
	int flag = 0;
	int i;

	for(i=2; i<= sqrt(num); i++)
	{
		if(num %i == 0) // 能被某数整除
		{
			flag = 1; // 非素数
			break;	
		}
	}
	
	return flag;
}

