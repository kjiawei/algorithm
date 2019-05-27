#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p = (int *) malloc(sizeof(int)*10);
	char *ss =(char *) malloc (1000);

	int * x = p; // 复制钥匙

	*x = 99;
	
	p = (int *)realloc ((void *)p, 60);
	
	printf("after realloc , p@%p, x@%p \n", p, x);	// p有可能已经不是之前的值，和x不相等，之前申请的堆空间也已经被释放了

	*x = 100;// realloc之后， 访问x是有隐患的

	printf("%d \n", *p);

//	p = p+1;// 钥匙被改了就不能free 
	
	printf("before free, p@%p\n", p);

	free( ss );
	printf("free 1\n");
	free ( p );// free(x); 
	return 0;


}

