#include <stdio.h>
#include <string.h>
#include "test.h"

#define NUM  4

int main(void)
{
	struct info arr[NUM] = {
		{10, "zhangsan", 18 , Jan ,type_art, 80 }, 
		{.num=2,.name="lisi", .age=18 ,.birth=Jan ,.type = type_phy, .res.phy= 93 }, 
		{.num=5,.name="wangwu", .age=19 ,.birth=May ,.type=type_art, .res.art = 90 }, 
		{.num=3,.name="zhaoliu", .age=19 ,.birth=May ,.type=type_art, .res.art = 70 }, 
			    };

	int i;
	for(i=0; i<NUM; i++)
	{
		printf("num = %d ", arr[i].num);	
		printf(", %s ", arr[i].name);	
		printf(", %d \n", arr[i].res.art);

	/*	if(arr[i].birth == May)
		{
			printf("Lucky dog \n");
		}	*/
	}

	// 冒泡排序 升序
	int j;
	for(i=0; i<NUM; i++)
	{
		for(j=0; j<NUM-1-i; j++)
		{
			if( arr[j].num > arr[j+1].num  )
			{	
				struct info temp;
				memcpy(&temp , &arr[j], sizeof(struct info) );	
				memcpy(&arr[j] , &arr[j+1], sizeof(struct info) );	
				memcpy(&arr[j+1], &temp, sizeof(struct info) );	
				
			}
		}
	}
	
	for(i=0; i<NUM; i++)
	{
		printf("num = %d ", arr[i].num);	
		printf(", %s ", arr[i].name);	
		printf(", %d \n", arr[i].res.art);
	}
	

	return 0;
}
