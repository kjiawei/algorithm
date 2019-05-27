#include "myhead.h"

int main()
{
	int i,len,count;
	char name[50];
	
	bzero(name,50);
	printf("请输入文件名:\n");
	scanf("%s",name);
	len = strlen(name);
	
	//找到最后一个小数点的位置
	for(i=0;i<len;++i)
	{
		if(name[i] == '.')
		count = i;
	}
	
	printf("文件类型为：%s\n",&name[count]);
	
	return 0;
}
