#include "myhead.h"

int main()
{
	char a[5];
	char b[5]="def";
	char *p=a; // a�ȼ���&a[0]; ��������Ϊ��ֵ������Ԫ�صĵ�ַ
	//a="abc";  //incompatible types when assigning to type ��char[5]�� from type ��char *�� ����
	//a=b; //incompatible types when assigning to type ��char[5]�� from type ��char *�� ����
	strcpy(a,b);    ��ȷ
	printf("a is:%s\n",a);

/*
�ַ������ʼ���ļ���д����
  д��һ��
       char a[10]="hello"�� �����ͬʱ�����ʼ��  ��ȷ
  д������
       char a[]="hello"; ��ȷ
       char a[];
       a="hello"         ���� 
  д������
       char a[10];
       a="zhangsan"      ����
       scanf("%s",stu.a);
       char a[10];
       strcpy(a,"zhangsan"); ��ȷ
       
     //&a[0]=b;   test

     �ܽ�:Ҫ������ʱ����,Ҫ��strcpy


	 test:
	 int arr[5][4];
//	int (*q[5])[4] = {arr};
	int (*q[5])[4] = {arr, &arr[1], &arr[2],&arr[3], &arr[4]};
*/

	return 0;
}