#include <stdio.h>

#define Max 10

int main()
{
    int arr_test[Max] = {8, 4, 2, 3, 5, 1, 6, 9, 0, 7};
    show(arr_test, Max); //排序前数组序列
    bubbleSort(arr_test, 10);//冒泡升序(降)

    //选择
    //插入
    //堆
    //选择
    show(arr_test, Max); //排序后
    return 0;
}

//快排 left right 是下标
void quick(int arr[],  int left, int right)
{
	int i;
	if(left < right)
	{
		int key = arr[left];
        	int low = left;
        	int high = right;
        	while(low < high)
    		{
                        while(low < high && arr[high] > key)
			{
                                high--;
                        }

                        arr[low] = arr[high];

                        while(low < high && arr[low] < key)
			{
                                low++;
                        }

                        arr[high] = arr[low];

		}

        	arr[low] = key;
		
		// 确认效果，观察标兵的位置 
		for(i=0; i< 9; i++)
			printf("%d, ", arr[i]);
		printf("\n");
		
		quick(arr,left,low-1);
		quick(arr,low+1,right);
		
    }
}

int test()
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
}

//二分排序
int minSort()
{
	int i,j,tmp;
	int data[] = {3,6,2,8,1,7}; 
	for (j = 1; j < sizeof(data)/4; j++)					//用来全部浏览整个数据，辅助i
	{
		for (i = 0; i < sizeof(data)/4 - j; i++)			//用来比较相邻的两个值
		{
			if(data[i] > data[i+1])
			{
				tmp = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp;
			}
		}

		for(i=0 ;i<sizeof(data)/4; i++)
	    {
        	printf("%d,",data[i]);
        }
        	printf("  j=%d\n", j);
	}
		return 0;
}


// 冒泡排序
void bubbleSort(int *arr, int n)
{
    int i, j, flag = 1;                  // i,j控制循环,flag是个标志
    for (i = 1; i < n && flag == 1; i++) // 进行n-1次循环。
    {
        flag = 0; //每次开始flag置零
        for (j = 0; j < n - i; j++)
        { //如果前一个数比后一个数大，交换位置
            if (arr[j] > arr[j + 1])
            {
                Swap(&arr[j], &arr[j + 1]);
                flag = 1; //如果有数据交换，则flag为1
            }
        }
    }
}

//改进版的冒泡排序(双向冒泡)
void BidBubbleSort(int array[], int n)
{
    int low, high, flag, i;
    low = 0;
    high = n - 1;
    while (low < high)
    {
        flag = 0;
        for (i = low; i < high; i++) //正向冒泡
        {
            if (array[i] > array[i + 1]) //找到剩下中最大的
            {
                Swap(&array[i], &array[i + 1]);
                flag = 1; //标志， 有数据交换
            }
        }
        if (!flag)
            break;
        high--;
        for (i = high; i > low; i--) //反向冒泡
        {
            if (array[i] < array[i - 1]) //找到剩下中最小的
                Swap(&array[i], &array[i - 1]);
        }
        low++;
    }
}

// 交换数组元素位置
void swap(int *num_a, int *num_b)
{
    int temp = *num_b;
    *num_b = *num_a;
    *num_a = temp;
}

// 打印结果
void show(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}
