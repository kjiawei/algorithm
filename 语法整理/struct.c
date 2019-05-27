#include <stdio.h>
#include "struct.h"

#define DEBUG 

struct s5 x ;//  全局变量 自动为0


struct s7 //定义结构体类型
{
	double a;
	char c;
} ss ; // 等价于  struct s7 ss 定义了结构体变量ss


typedef union result
{
	short a;
	short b;
	char c;
} result, RR, *R_P;   //  typedef union result     result ;  相当于定义了联合体union result类型result 
		//  typedef union result     RR;  相当于定义了联合体union result类型RR 
		//  typedef union result     *R_P ;  相当于定义了联合体union result结构体指针类型R_P 


int main(void)
{
	// #if 0
	#ifdef DEBUG
	printf("struct_s1 size is %d ,line %d\n", sizeof(struct s1), __LINE__ );// 12B
	printf("struct_s2 size is %d \n", sizeof(struct s2));// 
	printf("struct_s3 size is %d \n", sizeof(struct s3));// 
	printf("struct_s4 size is %d \n", sizeof(struct s4));// 
	printf("struct_s5 size is %d @ %s:%s \n", sizeof(struct s5), __DATE__, __TIME__);// 
	printf("struct_s6 size is %d @ %s %s\n", sizeof(struct s6) , __FILE__, __func__);// 
	#endif

	struct s5 a; // 局部变量 随机值

//	printf("UNION = %d \n", sizeof(union result));
	printf("UNION = %d \n", sizeof(result));

	RR stu = {.a = 99};// union result stu
	R_P p = &stu;// union result * p

	printf("p.a= %d \n", p->a);
	
	



	return 0;
}
