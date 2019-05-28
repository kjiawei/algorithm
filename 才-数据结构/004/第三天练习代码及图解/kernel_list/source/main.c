#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define1.h"
#include "list.h"



int main( void )
{
	int i, data_tmp; 
	char fun_c;
	node *pos;	/* 辅助指针  小结构体*/ 

	big *head = (big *)malloc( sizeof( big ) );
	INIT_LIST_HEAD( &(head -> list) );

	for (i = 0; i < 8; i++)
	{
		big *new = (big *)malloc( sizeof( big ) );  /* 创建节点 */
		INIT_LIST_HEAD( &new -> list );

		printf( "请输入data：\n" );  				/* 记录信息 */
		scanf( "%d", &new -> data );

		list_add( &new -> list, &head -> list );	/* 节点插入 */
	}

	while(getchar() != '\n');

	printf( "\n============== 第一次打印 ==============\n" );
	list_for_each(pos, &head -> list)
	{
		printf("%d ", list_entry(pos, big, list) -> data);
		printf("地址是 ：%p\n", list_entry(pos, big, list) );
	}
	printf( "================ 结束打印 =================\n" );



	pos = &head -> list ;

	while(1)
	{
		printf( "请输入功能：\n(n)查看下一个节点信息\n(s)查看上一个节点信息\n" );
		scanf( "%c", &fun_c ); //char
		while(getchar() != '\n');

		switch(fun_c)
		{
			case 'n' :
						pos = pos -> next;
						if (pos == &head -> list)
						{
							pos = pos -> next;
						}
						printf( "\n========== 下一个信息 ============\n" );
						printf("%d ", list_entry(pos, big, list) -> data);
						printf("地址是 ：%p\n", list_entry(pos, big, list) );
						printf( "=====================================\n" );
						break;

			case 's' :
						pos = pos -> prev;
						if (pos == &head -> list)
						{
							pos = pos -> prev;
						}
						printf( "\n========== 上一个信息 ============\n" );
						printf("%d ", list_entry(pos, big, list) -> data);
						printf("地址是 ：%p\n", list_entry(pos, big, list) );
						printf( "=====================================\n" );

						break;	

			default :
						printf( "输入有误请重新输入\n" );					

						break;
		}
	}


	return 0;
}



	// printf( "请输入要移动的数据：\n" );
	// scanf( "%d", &data_tmp );

	// list_for_each(pos, &head -> list)
	// {
	// 	if ( list_entry(pos, big, list) -> data == data_tmp )
	// 	{
	// 		break;
	// 	}
	// }


	// list_move(pos, &head -> list);


	// printf( "\n============== 移动节点到头节点后面打印 ==============\n" );
	// list_for_each(pos, &head -> list)
	// {
	// 	printf("%d\n", list_entry(pos, big, list) -> data);
	// }
	// printf( "================ 结束打印 =================\n" );