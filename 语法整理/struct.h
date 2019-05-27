#ifndef __STRUCT_H__
#define __STRUCT_H__

struct s1
{
	int a ; // 4B
	char b;// 1B
	long c; // 4B
};

struct s2
{
	int a ; // 4B
	char b;// 1B
	char bb; // 1--4
	long c; // 4B
};


struct s3
{
	int a ; // 4B
	char b;// 1B-- 4
	long c; // 4B
	char cc;
};


struct s4
{
	char a;
	char b;
	char c;
};

struct s5
{
	char a;
	short aa;
	char b;
};
struct s6
{
	short aa;
	char b;
};
#endif
