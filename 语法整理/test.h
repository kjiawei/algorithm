#ifndef __TEST_H__
#define __TEST_H__

union result 
{
	short art;
	int phy;
};// 4


typedef struct info
{
	int num;// 4
	char name[16];// 16
	int age; // 4
	int birth; // 4
	int type; // 如果type ==0 表示是体育， ==1表示艺术
	union result res; // 4
}Info ;

enum n
{
	type_phy= 0,
	type_art ,
};

enum m
{
	Jan = 1,
	Feb ,
	Mar ,
	Apr ,
	May ,
	Jun ,
	Jul 
};

#endif
