#include <stdio.h>

void insert(int arr[],int n)
{
	int key = arr[n];  //要插入的元素	
	int i = n;
	
	while(arr[i-1] > key )
	{
		arr[i] = arr[i-1];
		i--;
		if(i == 0)
			break;
	}
	arr[i] = key;

}

//n:元素个数
void insertionSort(int arr[],int n)
{
	int i;
	
	for(i=1; i<n; i++)
	{
		insert(arr,i);
	}

}


int main(void)
{
	int i;
	int arr[9] = {3,5,4,0,1,8,7,2,9};
	
	insertionSort(arr,(sizeof(arr)/4));
	
	for(i=0; i<(sizeof(arr)/4); i++)
		printf("%d\t",arr[i]);

	return 0;
}