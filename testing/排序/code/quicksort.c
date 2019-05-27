#include <stdio.h>

void quicksort(int arr[],int L,int R)
{
	int i = L;
	int j = R;
	int tmp;
	
	int pivot = arr[(L+R)/2]; //取基点
	
	while(i <=j )
	{
		/*查找大于基点的数*/
		while(arr[i] < pivot)  
		{
			i++;
		}
		/*查找小于基点的数*/
		while(arr[j] > pivot)
		{
			j--;
		}
		if(i <= j)
		{
			tmp 	= arr[i]; 
			arr[i] 	= arr[j];
			arr[j] 	= tmp;
			i++;
			j--;
		}
	}
	if(L<j) //递归遍历左边
		quicksort(arr,L,j);
	if(i<R) //递归遍历右边
	quicksort(arr,i,R);
	
	
}





int main(void)
{
	int i;
	int arr[9] = {1,8,2,3,4,0,5,7,9};
	
	
	quicksort(arr,0,8);
	
	for(i=0; i<(sizeof(arr)/4); i++)
		printf("%d\t",arr[i]);
	
	printf("\n");

	return 0;
}