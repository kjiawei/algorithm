#include "fail_score.h"

int fail_score(struct student *stu,int i)
{
	if((stu+i)->C_score >= 60.0 &&(stu+i)->GS_score >= 60.0 
		&& (stu+i)->FB_score >= 60.0 && (stu+i)->DL_score >= 60.0)
	{
		printf("学生:%s\t学号:%s\t全部科目过关！\n",(stu+i)->name,(stu+i)->num);
	}		
	else
	{	
		printf("学生:%s\t学号:%s\n不合格的科目有：",(stu+i)->name,(stu+i)->num);
		if((stu+i)->C_score < 60.0)
		{
			printf("C语言,成绩为%f\t",(stu+i)->C_score);
		}
			
		if((stu+i)->GS_score < 60.0)
		{
			printf("高数,成绩为%f\t",(stu+i)->GS_score);
		}
			
		if((stu+i)->FB_score < 60.0)
		{
			printf("复变,成绩为%f\t",(stu+i)->FB_score);
		}
			
		if((stu+i)->DL_score < 60.0)
		{
			printf("电路,成绩为%f\t",(stu+i)->DL_score);
		}
				
		printf("\n");
	}
	printf("=========================================\n");
}