#include "stdio.h"
#include "stdlib.h"

/*��������˼��:
ȡ�м������Ϊ���
*/ 

#if 0

void quick(int *a, int i, int j)
{
	int start, end,temp;
	int refer;
	int n;
	start = i;
	end = j;
	refer = a[(start+end)/2];
	printf ("\n %d %d \n" ,start ,end);
	do{
		while(a[start]<refer && start < j)// �ҵ���refer��Ĳ�ֹͣ
			start++;
		while(a[end]>refer && end>i) // �ҵ���referС�Ĳ�ֹͣ
			end--;
		if(start <= end)
		{
			temp = a[start];
			a[start] = a[end];
			a[end] = temp;
			start ++;
			end --;
		}
	}while(start<=end);
	
	for(n=0; n<10; n++)
		printf("%d \t", a[n]);
	
	// i = 0 ; j = 9
	// start = 9 , end = 8
	if(start<j)
		quick(a,start,j);
	if(end>i)
		quick(a,i,end);
}
#else// ȡ��ǰС�����еĵ�һ������Ϊ��������ҵ������ʵ�λ�ã��ҵ���һ��Ϊ���������ڵݹ����� (�ο�)
int quick(int *arr, int left, int right){
	int i;
	 
        if(left < right)
		{  //  left >= right ֹͣ�ݹ����
                int key = arr[left];
                int low = left;
                int high = right;
                while(low < high){
                        while(low < high && arr[high] > key){
                                high--;
                        }
                        arr[low] = arr[high];
                        while(low < high && arr[low] < key){
                                low++;
                        }
                        arr[high] = arr[low];
			for(i=0; i<10; i++)
				printf("%d ",arr[i]);
			printf("\n"); 
		}
        arr[low] = key; // ����Ѿ��Һ���λ����
		
		for(i=0; i<10; i++)
			printf("%d ",arr[i]);
		printf("\n\n");
		
		quick(arr,left,low-1);
		quick(arr,low+1,right);
	}
}
#endif

int main(void)
{
	int array[10] ={99,88,97,86,95,84,93,82,91,90};
	int i = 0;
		//array[i] = random()%200; // 0---200
	for(i=0; i<10; i++)
		printf("%d \t",array[i]);
	printf("\n");
	
	quick(array,0,9);
	
	for(i=0; i<10; i++)
		printf("%d \t",array[i]);
	printf("\n");
	return 0;
}
