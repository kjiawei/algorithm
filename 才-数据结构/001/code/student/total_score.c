#include "total_score.h"

int total_score(struct student *stu,int i)
{
	int sum;
	sum = (stu+i)->C_score + (stu+i)->GS_score 
		+ (stu+i)->FB_score + (stu+i)->DL_score;
	
	return sum;	
}
