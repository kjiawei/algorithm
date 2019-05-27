#include "myhead.h"

int main()
{
	int i;
	char *s="abc.txt";
	printf("s[7] is:%d\n",s[7]);

	printf("strlen(s) is:%d\n",strlen(s));
	//从后面往前面
	for(i=strlen(s)-1; i>=0; i--)
	{
		//从最后一个字符往前读取，没有读到小数就继续
		if(s[i]=='.')
			break;
		
	}
	printf("此文件的后缀名是：%s\n",&s[i]);
	return 0;
	
	
}