#include <stdio.h>

/*���Դ�С����*/
union result
{
	short a;
	short b;
	char c;
};

//trueΪС���� ����Ϊ��
bool isSmall()
{
	printf("UNION = %d \n", sizeof(union result));
	union result xx;
		
	xx.a = 0x12;
	printf("xx.a = 0x%x \n", xx.a);
	printf("xx.b = 0x%x \n", xx.b);
	printf("xx.c = 0x%x \n", xx.c);
	xx.b = 0x1234;
	printf("xx.a = 0x%x \n", xx.a);
	printf("xx.b = 0x%x \n", xx.b);
	printf("xx.c = 0x%x \n", xx.c);// xx.c��0x34֤����С���ֽ���
	if((xx.c-xx.a)>0) return true;
	else return false;
}
/*���Դ�С����*/

/*��Сдת��*/
//usage:char str[] = "aBcDesadjkh";int length = sizeof(str)/ sizeof(str[0]);upper_case(str, length);// ��Ԫ�صĵ�ַ������Ϊ4
void upper_case(char str[10] , int length) // �β��е����鶨����ƭ�˵ģ� �β��е�char str[] ������char *str �㿴������������ʵ�Ǹ�ָ����� , sizeof(str) ��ָ������Ĵ�С
{
	int i;
	printf("2 length : %d \n",sizeof(str)/ sizeof(str[0]));
	for(i=0; i<length; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 'a' -'A'; //���32  65A 97a
	}
}

void lower_case(char str[10] , int length)
{
	int i;
	printf("2 length : %d \n",sizeof(str)/ sizeof(str[0]));
	for(i=0; i<length; i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' -'A'; // 32
	}
}
/*��Сдת��*/