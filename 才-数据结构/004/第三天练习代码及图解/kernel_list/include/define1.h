#ifndef __DEFINE_H_
#define __DEFINE_H_

#include "list.h"
typedef struct list_head node; 

typedef struct big
{
	int data;
 	node list;
}big;

/* 传小结构体的地址 */
#define INIT_LIST_HEAD(name) ( (name) -> next = ((name)) \
							 , (name) -> prev = ((name)) ) 

//#define INIT_HEAD(name)  name=INIT_LIST_HEAD(name)


#endif
