#include "printf_stu.h"

int printf_stu(struct student *stu,int i)
{
	printf("名字：%s\t",(stu+i)->name);
	printf("学号：%s\n",(stu+i)->num);
	printf("C语言成绩：%f\t",(stu+i)->C_score);
	printf("高数成绩：%f\t",(stu+i)->GS_score);
	printf("复变成绩：%f\t",(stu+i)->FB_score);
	printf("电路成绩：%f\n",(stu+i)->DL_score);
	printf("=================================\n");		
}
