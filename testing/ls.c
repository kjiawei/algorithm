#include <stdio.h>

int longestSubstring(char *str)
{
	int i,j,length=1,maxSubString=1,pos=-1;//count=0;
	for(i=0;i<sizeof(str)/sizeof(str[0]);++i)
	{
		for(j=i+1;j<sizeof(str)/sizeof(str[0])-1;++j)
		{
			if(str[i]!=str[j]) if(++length>maxSubString) maxSubString=length;
			else {pos=j;length=1;printf("pos:%d\n",pos);
		//continue;
		}
		}
	}
	
	return maxSubString;
}

int main()
{
	char str[]={'a','b','c','e','f','c','b','b'};//
	printf("longest length:%d\n",longestSubstring(str));
	return 0;
}