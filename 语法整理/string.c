#include "myhead.h"

int main()
{
	char a[5];
	char b[5]="def";
	char *p=a; // a�ȼ���&a[0];
	
	// a����ǰ��մ������������ֻҪ�ǳ����ڱ��ʽ�о�һ���Ǳ�ʾ��Ԫ�صĵ�ַ�𣿣�
	   // ��������Ϊ��ֵ������Ԫ�صĵ�ַ
	   
	//a="abc";  //incompatible types when assigning to type ��char[5]�� from type ��char *�� ����
	//a=b; //incompatible types when assigning to type ��char[5]�� from type ��char *�� ����
	strcpy(a,b);    ��ȷ
	
	printf("a is:%s\n",a);
	return 0;
	
}
//const int a=10;
//a=12;