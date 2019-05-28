#include "check_stu.h"

int check_stu(struct student *stu,char *name)
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		if(strcmp((stu+i)->name,name) == 0)
		{
			break;
		}					
	}
	
	return i;	
}
