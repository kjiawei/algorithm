#include <stdio.h>


void get_memory(char *p) // char *p = str = NULL;
{
	p = "hello world";
}

int main(void)
{
	char *str = NULL;
	
	get_memory(str);//&str

//	printf("%s \n", str);
	int i ;
	for(i =0 ; *(str+i) /* str[i]*/ != '\0'; i++)// 段错误：
	{
		printf("123\n");
		printf("%hhd", str[i] );	
	}
}
