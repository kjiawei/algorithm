#include <stdio.h>

//查找(顺序 二分:前提数组有序 二分查找树 插值 斐波那契 树表 分块 哈希)
//http://blog.csdn.net/zengtian006/article/details/24034977
//http://www.cnblogs.com/yw09041432/p/5908444.html

#define LEN 10//扩展:LEN为获取数据源长度

//二分查找
//参数说明:数据源 长度 需值
int binarySearch(int a[],int n,int key)
{
	int mid;
	int low = 0;
	int count = 0;
	int high = n-1;
	/* 优化:0.临近的能不能减少(通用比较):量小/大做法;
	1.查找元素所出现的位置;
	2.小数等求值(思想);
	*/	
	while(low <= high)
	{
		int mid = (low+high)/2;
		int midVal = a[mid];
		if(midVal<key)
		{
			++count;
			low = mid + 1;
			printf("midVal<key,low=%d,mid=%d\n",low,mid);
		}
		else if(midVal>key)
		{
			++count;
			high = mid - 1;
			printf("midVal>key,high=%d,mid=%d\n",high,mid);
		}	
		else
		{
			printf("共查找了%d次\n",count);
			return mid;
		}	
	}
	return -1;
}

int main(void)
{
	int i,ret,p;
	int a[LEN]={-32,-12, 1, 12, 16, 24, 36, 45, 59, 98};//必须先排好序
	for(i=0;i<LEN;i++)
		printf("%d\t",a[i]);
	while(1)
	{
		printf("请输入想查找的值:\n");
		scanf("%d",&p);
	
		ret = binarySearch(a,LEN,p);
		if(ret == -1)
			printf("no found!\n");
		else
			printf("found!\n");
	}
	
	return 0;
}