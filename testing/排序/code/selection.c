#include <stdio.h>

//记录数组最大值下标
int Find_MAX_pos(int arr[],int n)
{
	int i,pos=0;
	
	int max = arr[0];
	
	for(i=0; i<n; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
			pos  = i;  //记录最大值下标
		}
	
	}
	return pos;
}
//int arr[]数组 ，int 数据元素个数
void selectionsort(int arr[],int n)
{
	int pos,tmp;
	while(n>1)
	{
		pos = Find_MAX_pos(arr,n);
		
		tmp		 = arr[pos];
		arr[pos] = arr[n-1];
		arr[n-1] = tmp;
	
		n--;
	}


}


int main(void)
{
	int i;
	
	int arr[9]={4,8,7,1,2,6,4,9,3};
	
	selectionsort(arr,(sizeof(arr)/4));
	
	for(i=0; i<(sizeof(arr)/4); i++)
		printf("%d\t",arr[i]);

	return 0;
}