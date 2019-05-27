// Floyd.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

#define INF 99999 //��ʾ���ɵ���

#define MAXSIZE 4 //��ʾͼ�Ľ����

//�ڽӾ���洢ͼ����Ϣ
/*int map[MAXSIZE][MAXSIZE]={
	{0,4,6,6,INF,INF,INF},
	{INF,0,1,INF,7,INF,INF},
	{INF,INF,0,INF,6,4,INF},
	{INF,INF,2,0,INF,5,INF},
	{INF,INF,INF,INF,0,INF,6},
	{INF,INF,INF,INF,1,0,8},
	{INF,INF,INF,INF,INF,INF,0}
};*/
int map[MAXSIZE][MAXSIZE]={
	{0,5,INF,7},
	{INF,0,4,2},
	{3,3,0,2},
	{INF,INF,1,0}
};

//���������㷨
void Floyd()
{
	int path[MAXSIZE][MAXSIZE];//�������·��

	int A[MAXSIZE][MAXSIZE];//a[i][j]��ʾ��ǰ����i��j����̾���

	//���ݳ�ʼ��
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			A[i][j]=map[i][j];
			path[i][j]=-1;//��ʼ��Ϊ-1
		}
	}
	//���ɨ�����е㣬û�г�ȥ�Խ��ߺͻ�ȥ���к�������ĵ�
	/*for(int diagonal=0;diagonal<MAXSIZE;diagonal++)//��Խ���
	{
		for(int k=0;k<MAXSIZE;k++)//��
		{
			
			for(int j=0;j<MAXSIZE;j++)//��
			{
				if(A[k][j]>A[k][diagonal]+A[diagonal][j])
				{
					A[k][j]=A[k][diagonal]+A[diagonal][j];
					path[k][j]=diagonal;
				}
			}
		}
	}
	*/
	for(int diagonal=0;diagonal<MAXSIZE;diagonal++)//��Խ���
	{
		for(int k=0;k<MAXSIZE;k++)//��
		{
			if(k!=diagonal)//��ȥ�������еĵ�
			{
				for(int j=0;j<MAXSIZE;j++)//��
				{
					 if(j!=diagonal)//��ȥ�������Եĵ�
					 {
						 if(k!=j)//��ȥ�Խ��ߵĵ�
						 {
							 if(A[k][j]>A[diagonal][j]+A[k][diagonal])//��������
							 {
								 A[k][j]=A[diagonal][j]+A[k][diagonal];
								 path[k][j]=diagonal;
							 }
						 }
					 }
				}
			}
		}
	}

	//��������
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			if(A[i][j]==INF)
				cout<<"�Ӷ���"<<i<<"������"<<j<<"������·��"<<endl;
			else
			{
				cout<<"�Ӷ���"<<i<<"������"<<j<<"��̾���Ϊ: "<<A[i][j]<<"  ��·��Ϊ��";
				vector<int>temp;
				temp.insert(temp.begin(),j);//���յ����
				int ok1=i,ok2=j;
				while(true)
				{
				   ok1=path[ok1][ok2];
				   if(ok1==-1)
					   break;
				   temp.insert(temp.begin(),ok1);
			   
				}
				
				temp.insert(temp.begin(),i);//��������

				for(int z=0;z<temp.size();z++)
					cout<<temp[z]<<" ";
				cout<<endl;
			}
		}
	}
	



}
int main()
{
	Floyd();
	return 0;
}

