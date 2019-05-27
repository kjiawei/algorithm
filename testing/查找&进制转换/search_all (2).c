#include <stdio.h>

//查找(顺序 二分:前提数组有序 二分查找树 插值 斐波那契 树表 分块 哈希)
//http://blog.csdn.net/zengtian006/article/details/24034977
//http://www.cnblogs.com/yw09041432/p/5908444.html

#define LEN 10

//参数说明:数据源 长度 需值
int binarySearch(int a[],int n,int key)
{
	int low = 0;
	int high = n-1;
	int mid = high/2;//大于用的第一次中位
	int mid2 = high/2;//小于用的第一次中位
	int midn;//第N次中位
	int midVal = a[mid];
	int count = 0;
	while(key>a[0] && key<a[high])//先把所有数找到->临近的能不能减少(通用比较):量小/大做法
	{
		if(key<midVal)
		{
			++count;
			//第N次中位
			midn = mid-(mid-low)/2;//找12用了3次 -32 98等边界找不到(能否第一次判断,24死循环)->比较优化->网上优化
			midVal = a[midn];
			/* if(key>a[midn])
			{
				
			}else{
				
			} */
			
			printf("key<midVal,%d\n",midVal);
			mid = midn;
		}else if(key>midVal)
		{
			++count;
			//第N次中位
			midn = mid+(high-mid)/2;
			midVal = a[midn];
			printf("key>midVal,%d\n",midVal);
			mid = midn;
		}
		else
		{
			printf("共查找了%d次\n",count);
			return mid;
		}
	}
	/*int low = 0;
	int high = n-1;
	int count=0;
	while(low<high)
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
	}*/
	return -1;
}

int main(void)
{
	//二分查找
	int i,ret,p;
	int a[LEN]={-32,-12, 1, 12, 16, 24, 36, 45, 59, 98};//必须先排好序
	for(i=0;i<LEN;i++)
		printf("%d\t",a[i]);
	while(1)
	{
		printf("请输入想查找的值:\n");
	scanf("%d",&p);
	
	ret = binarySearch(a,LEN,p);//怎么加上过程
	if(ret == -1)//防奔溃?
		printf("no found!\n");
	else
		printf("found!\n");
	}
	
	return 0;
}