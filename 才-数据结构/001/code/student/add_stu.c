#include "add_stu.h"

int add_stu(struct student *stu,int i)
{
	printf("名字：\n");
	scanf("%s",(stu+i)->name);
	printf("学号：\n");
	scanf("%s",(stu+i)->num);
	printf("C语言成绩：\n");
	scanf("%f",&(stu+i)->C_score);
	printf("高数成绩：\n");
	scanf("%f",&(stu+i)->GS_score);	
	printf("复变语言成绩：\n");
	scanf("%f",&(stu+i)->FB_score);
	printf("电路成绩：\n");
	scanf("%f",&(stu+i)->DL_score);	
}
