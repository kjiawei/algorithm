#include "myhead.h"

int main()
{
	char a[5];
	char b[5]="def";
	char *p=a; // a等价于&a[0];
	
	// a真的是按照大家理解的数组名只要是出现在表达式中就一定是表示首元素的地址吗？？
	   // 数组名作为右值才是首元素的地址
	   
	//a="abc";  //incompatible types when assigning to type ‘char[5]’ from type ‘char *’ 错误
	//a=b; //incompatible types when assigning to type ‘char[5]’ from type ‘char *’ 错误
	strcpy(a,b);    正确
	
	printf("a is:%s\n",a);
	return 0;
	
}
//const int a=10;
//a=12;