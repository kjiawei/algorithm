#include <stdio.h>
/*冒泡与选择区别*/
#define MAX 10

int main()
{
	int i,j,temp;
	int num[MAX] = {2,5,8,3,9,4,1,6,7,0};
	for(i=0;i<MAX;i++)
		printf("num[%d]:%d\n",i+1,num[i]);
	/*选择排(升)序*/
	/*for(i=0;i<MAX;i++)
		for(j=i+1;j<MAX;j++)
		{
			if(num[i]>num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}*/
	/*冒泡*/
	/*for(j=0;j<MAX-1;j++)
		for(i=0;i<MAX-1;i++)
		{
			if(num[i]>num[i+1])
			{
				temp = num[i];
				num[i] = num[i+1];
				num[i+1] = temp;
			}
		}*/
		
	/*网友选择排序 min存放小的变量
	for(i=0;i<9;i++)
	{
		min=i;
		 for(j=i+1;j<=9;j++)
		 {
			if(a[min]>a[j])
			{
				min=j;//存放小的那个
			}
				temp=a[j];
				a[j]=a[min];
				a[min]=temp;
		 }
	}*/
	
	//网友冒泡排序
	/* for(i=0;i<9;i++)
		for(j=9;j>i;j--)
		{
			if(a[j]<a[j-1])//小的往前
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		} */
		/*for(j=0;j<9-i;j++)//有的j<9-i-1
		 {
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		 }大的气泡往下沉，小的气泡往上浮！！！注意：是a[j-1]还是a[j+1]；
		 深刻了解！！！*/
	
	
	for(i=0;i<MAX;i++)
		printf("排序后,num[%d]:%d\n",i+1,num[i]);
}