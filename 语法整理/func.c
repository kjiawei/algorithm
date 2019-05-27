#include <stdio.h>

/*测试大小端序*/
union result
{
	short a;
	short b;
	char c;
};

//true为小端序 否则为大
bool isSmall()
{
	printf("UNION = %d \n", sizeof(union result));
	union result xx;
		
	xx.a = 0x12;
	printf("xx.a = 0x%x \n", xx.a);
	printf("xx.b = 0x%x \n", xx.b);
	printf("xx.c = 0x%x \n", xx.c);
	xx.b = 0x1234;
	printf("xx.a = 0x%x \n", xx.a);
	printf("xx.b = 0x%x \n", xx.b);
	printf("xx.c = 0x%x \n", xx.c);// xx.c是0x34证明是小端字节序
	if((xx.c-xx.a)>0) return true;
	else return false;
}
/*测试大小端序*/

/*大小写转换*/
//usage:char str[] = "aBcDesadjkh";int length = sizeof(str)/ sizeof(str[0]);upper_case(str, length);// 首元素的地址，长度为4
void upper_case(char str[10] , int length) // 形参中的数组定义是骗人的， 形参中的char str[] 等于是char *str 你看到的数组名其实是个指针变量 , sizeof(str) 是指针变量的大小
{
	int i;
	printf("2 length : %d \n",sizeof(str)/ sizeof(str[0]));
	for(i=0; i<length; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 'a' -'A'; //相隔32  65A 97a
	}
}

void lower_case(char str[10] , int length)
{
	int i;
	printf("2 length : %d \n",sizeof(str)/ sizeof(str[0]));
	for(i=0; i<length; i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' -'A'; // 32
	}
}
/*大小写转换*/