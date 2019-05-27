#include <stdio.h>

#define SEC_PER_YEAR (365*24*60*60L)

#define MIN(x,y)  (( (x) < (y))? (x) : (y) )

#define CHANGE(x,y)   { (x)^=(y); (y)^=(x) ; (x)^=(y); }// 多个表达式{ }


#define int_m int*
typedef int* int_t;

int main(void)
{
	printf("val = %ld \n", SEC_PER_YEAR);

	int a = 100 , b = 80;
	
	printf("min is %d \n", MIN(a,b));
	
	CHANGE(a,b);

	printf("a=%d , b=%d\n",a,b);

	int_m x,y ; // int *x, y; // 替换
	int_t w,z ; // int *w ,*z；// int_t是个类型
	

	return 0;


}
