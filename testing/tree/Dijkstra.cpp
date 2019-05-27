// Dijkstra.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
#include<vector>
using namespace std;

#define INF 10000 //��ʾ���ɵ���

#define MAXSIZE 7 //��ʾͼ�Ľ����

//�ڽӾ���洢ͼ����Ϣ
int map[MAXSIZE][MAXSIZE]={
	{0,4,6,6,INF,INF,INF},
	{INF,0,1,INF,7,INF,INF},
	{INF,INF,0,INF,6,4,INF},
	{INF,INF,2,0,INF,5,INF},
	{INF,INF,INF,INF,0,INF,6},
	{INF,INF,INF,INF,1,0,8},
	{INF,INF,INF,INF,INF,INF,0}
};

void Dijkstra(int v)
{
	int away[MAXSIZE];//���浽���������̾���
	int path[MAXSIZE];//��̾���·��
	int already[MAXSIZE]={0};//�Ƿ��Ѿ��ҵ���̾��룬1��ʾ�ҵ���

	for(int i=0;i<MAXSIZE;i++)
	{
		away[i]=map[v][i];//��ȡȨֵ

		if(away[i]<INF)//����·��Ϊ0
			path[i]=0;
		else
			path[i]=-1;//������·��Ϊ-1

	}
	already[v]=1;//�Ѷ���v���뵽�ҵ�������

	//��ʼѰ����̾���
	int min,ok;
	for(int i=0;i<MAXSIZE;i++)
	{
		
		min=INF;
		for(int k=0;k<MAXSIZE;k++)
		{
			if(already[k]==0&&away[k]<min)//��away�����Сֵ���Ҹö��㲻��already��
			{
				min=away[k];
				ok=k;//��¼��С�Ķ���
			}
		}
		already[ok]=1;//�Ѷ���ok���뵽�ҵ�������

		//�޸�away��path����
		for(int j=0;j<MAXSIZE;j++)
		{
			if(already[j]==0)//�˽�㻹û����̾���
			{
				if(map[ok][j]<INF&&(away[ok]+map[ok][j])<away[j])
				{
					away[j]=away[ok]+map[ok][j];
					path[j]=ok;//�޸�path,�޸Ĺ�awayȨֵ�İ�path��Ϊ����ֵ
				}
			}
		}

		
	}

	//����path���·��
	
	for(int h=0;h<MAXSIZE;h++)
			cout<<away[h]<<" ";
	cout<<endl;
	for(int h=0;h<MAXSIZE;h++)
			cout<<path[h]<<" ";

	for(int s=0;s<MAXSIZE;s++)
	{
		if(s!=v)//��ȥ���
		{
			if(already[s]==1)
			{
				cout<<endl<<"�Ӷ���"<<v<<"������"<<s<<"����С����Ϊ�� "<<away[s]<<"  "<<"·��Ϊ: ";
				
				vector<int>temp;
				temp.insert(temp.begin(),s);//���յ����
				int ok=s;
				while(true)
				{
				   ok=path[ok];
				   if(ok==0)
					   break;
				   temp.insert(temp.begin(),ok);
			   
				}
				temp.insert(temp.begin(),v);//��������
				for(int z=0;z<temp.size();z++)
					cout<<temp[z]<<" ";
			}
			else
				cout<<endl<<"�Ӷ���"<<v<<"������"<<s<<"������·��"<<endl;
		}
	}
}

int main()
{
	Dijkstra(0);//����0���㵽�������������̾���
	return 0;
}

