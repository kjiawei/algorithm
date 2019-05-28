#ifndef __DEFINE_H_
#define __DEFINE_H_

#include "list.h"

struct node 
{
	struct node *next;
	struct node *prev;

};

typedef struct node node;

struct node_b 
{
	struct node *next;
	struct node *prev;

};

typedef struct node node_B;

#define INIT_LIST_HEAD(name) { &(name),&(name) }

#define INIT_HEAD(name) node name=INIT_LIST_HEAD(name)


#endif