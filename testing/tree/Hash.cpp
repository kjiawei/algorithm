
//��ϣ��������
#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

#define MAX 13//��ϣ����

#define p 13  //�����ڹ�ϣ���ȵ�����

#define NULLKEY -1  //�չؼ���

#define DELKEY -2  //ɾ���ؼ���

//����������������̽����������ϣ��
struct node
{
	int key;//�ؼ���
	string data;//������
	int num;//̽�����
	//��ʼ��̽������Ϊ0���ؼ���Ϊ�չؼ���
	node()
	{
		num=0;
		key=NULLKEY;
	}
};

//������ϣ��
void Create(node hash[])
{
	int data[11]={16,74,60,43,54,90,46,31,29,88,77};//���ɹ�ϣ������

	

	for(int i=0;i<11;i++)
	{
		int count=0;
		int temp=data[i];

		//�ؼ��ֲ���
		while(true)
		{
			if(hash[temp%p].key==NULLKEY||hash[temp%p].key==DELKEY)//û��ͻ
			{
				
				count++;
				hash[temp%p].key=data[i];//�ؼ��ֲ���
				hash[temp%p].num=count;//̽������
				break;
			}
			else
			{
				temp=(temp+1)%p;//����̽�鷨
				count++;//̽�������һ
			}
		}
	}

	for(int i=0;i<13;i++)
		cout<<"�±�: "<<i<<"  key :  "<<hash[i].key<<" ̽������: "<<hash[i].num<<endl;

}

//��ϣ�����
int Search(node hash[],int key)
{
	int adr=key%p;

	while(hash[adr].key!=NULLKEY&&hash[adr].key!=key)
	{
		adr=(adr+1)%p;
	}
	if(hash[adr].key==key) //���ҳɹ����ص�ַ
		return adr;

	else     //����ʧ��
		return -1;
}
int main()
{
	node hash[MAX];//��ϣ������
    Create(hash);

	int result=Search(hash,88);
	cout<<result<<endl;
	return 0;
}