//选择排序
//10个数字 从小到大排列 min是最小元素的下标
for(i=0; i<=1; i++)  // 循环了9次
{
	min=i;
	for(j=i+1; j<=2; j++)   
	{
		if(a[min]>a[j])    
			min=j;   //min  1
	}// 找到目前数组中最小的那个元素的下标

	temp=a[i];
	a[i]=a[min];
	a[min]=temp;
}

//冒泡
int buble(int num[])
{
	for(j=1; j<N; j++)
		for(i=0; i<N-j; i++)
			if(num[i]>num[i+1])
			{
				
			}
	
}