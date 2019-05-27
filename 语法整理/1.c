#include <stdio.h>

int func(int a)
{
	printf("in func \n");
}



int main(void)
{
//	int (*a[10])(int) = {func };
	int (*(a[10]))(int) = {func };
	
	a[0](1); // func(1);

	return 0;

}
