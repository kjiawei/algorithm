#include <stdio.h>

//4个数中输出任意3个数的组合

int main()
{
	int i,j,k;
	int a[4]={1,2,3,4};
	for(i=0; i<4; i++)
		for(j=1; j<4; j++)
			for(k=2; k<4; k++)
				printf("%d%d%d\n",a[i],a[j],a[k]);
	return 0;
}