#include "caozuo.h"

char caozuo_stu()
{
	char ch;
	
	while(getchar()!='\n');
	printf("请选择你要执行的操作:\n");
	printf("a:查看某个学生的成绩\n");
	printf("b:计算每一个学生的成绩总分\n");
	printf("c:计算每一个学生的平均分\n");
	printf("d:列出学生成绩不合格的科目\n");
	printf("t:列出学生所有信息\n");
	printf("e:退出系统\n");	
	printf("你的选择是：");
	scanf("%c",&ch);
		
	return ch;
}
