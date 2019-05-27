#include <stdio.h>

int num;//待转换数 -任意进制数
int target;//目标进制

int tran_to_2(num,target)
{
	
	//用哪些代表值来设计这个进制转换(二:6 110 5->2 101 4 100 3 11)
	//递归的用if-else还是while好
	//对传进来的target进行判断-10直接调用 其余公用代码
	//不要掉进以代码来反推算术运算->先列正确运算顺序->伪代码->目标代码
	//6.12自己实现超时(1小时内实现不出来)-卡在了循环实现过程
	
	//第一步:转换为10进制数
	//第二步:转换为目标进制数
	
	int y = num%target;//余数 例:5->2  1(整除值2) 0(整除值1)
	int z = num/target;//整除
	while(y!=0 && z!=1)
	{
		while(z!=0)
		{
			z = z%target;
			//return
		}
		//return
	}
	
	int count = 0;
	if(y==0)//刚好整除
	{
		//int z = num/target;z作用域在分支判断里
		//res = z;
		
		/* if(z!=0) */
		//{
			
		//}
		printf("result is:%d0\n",z);
	}else
	{
		//res = res;
	}
	//printf("result is:%d0\n",z);
}

int tran_to_8(num,target)
{
	printf("123\n");
}

int tran_to_10(num,target)
{
	
}

int tran_to_16(num,target)
{
	
}

int main(void)
{
	while(1)
	{
		printf("请输入你想转换进制的数和目标进制:\n");
		scanf("%d%d",&num,&target);
		switch(target)//default不是必须的
		{
			case 2:{tran_to_2(num,target);break;}
			case 8:{tran_to_8(num,target);break;}
			case 10:{tran_to_10(num,target);break;}
			case 16:{tran_to_16(num,target);break;}
		}
		
	}
	return 0;
}