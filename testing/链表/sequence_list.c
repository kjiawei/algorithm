#include <stdio.h>	//printf
#include <stdlib.h>	//malloc
#include <stdbool.h>	//bool

#define SIZE 10		//表的可填充数据大小
/*定义顺序表*/
typedef struct sequence_list{
	int data[SIZE];			//表的内容
	int last;				//记录表的数组有效值的最大下表（这个表已经写入的数据长度-1）
}slist;


slist *init_list(void)
{
	slist *p = malloc(sizeof(slist));	//申请顺序表内存

	if(p != NULL)						//判断是否申请成功
		p->last = -1;

	return p;							//返回指针
}

void remove_list(slist *slp)
{
	return free(slp);
}

bool is_list_full(slist *slp)
{
	return (slp->last == SIZE-1);		//如果满了last的值就等于SIZE-1

}

int insert_data(slist *slp, int rd)
{
	if(is_list_full(slp))				//判断表格是否满了
	{
		printf("the list full\n");
		return -1;
	}

	slp->last += 1;						//让last的值加1
	slp->data[slp->last] = rd;			//把数据写入表格后面

	return 0;
}

void show_list(slist *slp)
{
	int count;
	for(count=0; count<=slp->last; count++)	//打印表格里面的内容
		printf("%d,",slp->data[count]);
	printf("\n");

	return;
}

bool is_list_empty(slist *slp)
{
	return (slp->last < 0);		//判断这个last是否小于0，小于0证明没有数据在这里
	
}

int remove_data(slist *slp)
{
	if(is_list_empty(slp))			//判断表格是否没有数据了
	{
		printf("the list empty\n");
		return -1;
		
	}
	
	slp->last -= 1;					//这个last-1，在操作表格的时候，数据不需要清空

	return 0;
}


int main(void)
{
	int rd;
	slist *slp; 	
	

	slp = init_list();					//初始化顺序表
	if(slp == NULL)					//申请表格失败
	{
		perror("request list failed\n");
		return -1;
	}

	while(1)
	{
		scanf("%d", &rd);
		
		if(rd == 0)
			break;
	
		if(rd > 0)
		{
			insert_data(slp, rd);		//数据插入表格
			show_list(slp);				//显示表格内容
		}
		else
		{
			remove_data(slp);				//删除一个数据
			show_list(slp);				//显示表格内容
		}
	}

	remove_list(slp);

	return 0;
}
