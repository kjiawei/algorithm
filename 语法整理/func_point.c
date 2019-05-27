#include <stdio.h>


int func (int a)
{
	if(a == 1)
		return a;
	else 
		return a+func(a-1);
	
}




int main(void)
{
	int num = 10;


	int val;//  = func(10);

//	int (*p)(int) = &func;
//	val = (*p)(10);
	int (*p)(int) = func; // p === func
	val = p(10);
	
	printf("val = %d \n", val);

	return 0;
	
}
