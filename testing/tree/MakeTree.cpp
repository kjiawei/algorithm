// MakeTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

#define INF 100000 //��ʾ���ɵ���

#define MAXSIZE 6 //��ʾͼ�Ľ�����

//�ڽӾ���洢ͼ����Ϣ
int map[MAXSIZE][MAXSIZE]={
	{0,4,2,3,INF,INF},
	{4,0,5,4,3,INF},
	{2,5,0,1,INF,2},
	{3,4,1,0,6,2},
	{INF,3,INF,6,0,4},
	{INF,INF,2,2,4,0}
};

//�����洢��С�������ıߺ�Ȩֵ
struct path
{
	int start;
	int end;
	int weight;
};

//����ķ�㷨--��С������
void Prim(int v)//v��ʼ��
{
	path lowcost[MAXSIZE];//�ڽ��㣨δ����ǣ�����С����

	path tree[MAXSIZE-1];  //�����С������

	int visited[MAXSIZE]={0};  //�Ѿ����ʵĽ��Ϊ1

	path min;

	for(int i=0;i<MAXSIZE;i++)
	{
		lowcost[i].weight=map[v][i];
		lowcost[i].start=v;	
		lowcost[i].end=i;
	}

	//ѭ������·�������Ҵ���Ϊ�������1
	for(int j=0;j<MAXSIZE-1;j++)
	{
		//��ȡȨֵ��Ϊ0����С�ı�
		min.weight=INF;
		for(int i=0;i<MAXSIZE;i++)
		{
			
			if(lowcost[i].weight!=0&&lowcost[i].weight<min.weight)
			{
				min=lowcost[i];
			}
		}

		tree[j]=min;//��ȡ��СȨֵ��������С������������

		visited[v]=1;//�ѷ���

		v=min.end;//�޸���ʼ��

		//�޸�lowcost����
		for(int i=0;i<MAXSIZE;i++)
	    {
			//���µ�ȨֵС��֮ǰ��Ȩֵ�������
			if(map[v][i]<lowcost[i].weight)
			{
				lowcost[i].weight=map[v][i];
				lowcost[i].start=v;
				lowcost[i].end=i;
			}

			//�Ѿ����ʵĽ��Ϊ0
			if(visited[i]==1)
               lowcost[i].weight=0;

	    }

	}

	//������ɵ���С�������Ľ��
	for(int i=0;i<MAXSIZE-1;i++)
	{
		cout<<tree[i].start<<"->"<<tree[i].end<<"  "<<tree[i].weight<<"  "<<endl;
	}

}

int main()
{
	Prim(0);//��ʼ��Ϊ0
	return 0;
}

