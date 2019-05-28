#include "myhead.h"

int main(void)
{
	struct student stu[SIZE] = {0};
	int i,j;
	float zong,ping;
	char ch;
	char name[20] = {0};
	
	printf("请输入学生信息:\n");
	for(i=0;i<SIZE;i++)
	{
		printf("第%d个学生信息：\n",i+1);		
		add_stu(stu,i);
	}
	
	while(1)
	{
		ch = caozuo_stu();
		switch(ch)
		{			
			case 'a':
				printf("请输入你要查看的学生的名字：\n");
				scanf("%s",name);				
				j = check_stu(stu,name);
				if(j>=SIZE)
				{
					printf("查无此人！\n");
					printf("=================================\n");
				}			
				else
					printf_stu(stu,j);
				break;
			
			case 'b':
				printf("每一个学生的成绩总分：\n");
				for(i=0;i<SIZE;i++)
				{
					zong = total_score(stu,i);
					printf("第%d个学生%s的总分为%f.\n",i+1,stu[i].name,zong);						
				}			
				break;
			
			case 'c':
				printf("每一个学生的平均分：\n");
				for(i=0;i<SIZE;i++)
				{
					ping = total_score(stu,i)/4;
					printf("第%d个学生%s的平均分为%f。",i+1,stu[i].name,ping);
					if(ping>=60)
						printf("\t成绩合格\n");
					else
						printf("\t成绩不合格\n");
				}				
				break;
			
			case 'd':
				for(i=0;i<SIZE;i++)
				{
					fail_score(stu,i);							
				}	
				break;
			
			case 'e':
				printf("系统退出！\n");
				goto goto_flag;
				break;
				
			case 't':
				printf("已输入学生信息为：\n");
				for(i=0;i<SIZE;i++)
				{	
					printf("第%d个学生信息：\n",i+1);	
					printf_stu(stu,i);
				}
				break;
				
			default:
				printf("你选择的操作不存在，请重新选择!\n");
				printf("=================================\n");	
				break;				
		}		
	}
	
goto_flag:		
	return 0;
}