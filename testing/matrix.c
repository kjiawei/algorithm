#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <signal.h>

//动态数组的内存空间是从堆(heap)上分配(即动态分配)的。是通过执行代码而为其分配存储空间
//当程序执行到这些语句时，才为其分配。程序员自己负责释放内存

//1.动态分配二维数组并按需改值到数组
//2.顺时针判断插入数组值

int main()
{
	int m,n,i,j;
	printf("please input m,n:\n");
	scanf("%d%d",&m,&n);
	int **result;//分配数组
	result=(int**)malloc(sizeof(int*)*m);// 分配所有行的首地址
	for (i = 0; i < m; i ++) { // 按行分配每一列
		result[i]= (int *)malloc(sizeof(int) * n);
	}
	
	//赋值
	int val=1,x=0,y=0,minX=0,maxX=m-1,minY=0,maxY=n-1;
	while(minX <= maxX && minY <= maxY)
	{
		//左→右 
		while(y < maxY) 
			result[x][y++] = val++;
		minX++;//挪到第二行最后一列 的位置上
		//上→下 
		while(x < maxX) 
			result[x++][y] = val++; 
		maxY--;//挪到倒数第二列最后一行 的位置上 
		//右→左 
		while(y > minY) 
			result[x][y--] = val++; 
		maxX--; 
		//下→上 
		while(x > minX) 
			result[x--][y] = val++; 
		minY++;
	}
	result[x][y]=val;
	
	//输出
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			//result[i][j]=i+j;
			printf("%d",result[i][j]);
			printf("\t");
			//sleep(1);
		}
		printf("\n");
	}
	//释放数组
	free(result);
	return 0;
}