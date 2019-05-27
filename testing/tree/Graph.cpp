// Graph.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

#define MAXSIZE 5  //����ͼ�Ľ����


//ʹ���ڽӱ�洢ͼ����Ϣ

//�����ڽӱ���Ľṹ
struct node
{
	int data;//�����
	int weight;//Ȩֵ
	node * next;//��һ������ָ��
	node()
	{
		next=NULL;
	}
};

//�����ڽӱ�ı�ͷ
struct Head
{
	int data;//�����
	node * first;//ִ�е�һ�����
	Head()
    {
		first=NULL;
	}
};


//�����ڽӱ�
void Create(Head * & head)
{
	
	while(true)
	{
		int name,wg;
		cin>>name;//������
		if(name==-1)//����-1��ʾ�������
			break;
		cin>>wg;//����Ȩֵ
		node * temp=new node;//�������
		temp->data=name;
		temp->weight=wg;
		//�ѱ�����뵽head����
		if(head->first==NULL)
			head->first=temp;
		else
		{
			temp->next=head->first;
			head->first=temp;
		}


	}

}



//�ݹ������������

void DFS_DG(Head *head[],int v,int visited[])//head[]-ͷָ�����飬v-��ʼ���㣬visited[]--�������
{
	node * p;//����
	visited[v]=1;
	cout<<v;
	p=head[v]->first;//��ȡ��һ������
	while(p!=NULL)
	{
		if(visited[p->data]==0)
			DFS_DG(head,p->data,visited);
		p=p->next;
	}
}

//���������������--ʹ�ö���
void BFS(Head *head[],int v)
{
	node *p;//����ָ��
	
	int queue[MAXSIZE],front=0,rear=0;//˳����У�front��ͷ��rear��β�������ǲ�βɾͷ���Ƚ��ȳ�
	int visited[MAXSIZE]={0};//���ʱ�־�����ʼ��Ϊ0

	//��ʼ����
	cout<<v;
	visited[v]=1;
	rear=(rear+1)%MAXSIZE;
	queue[rear]=v;//���

	int ok;
	while(front!=rear)//���в�Ϊ��
	{
		front=(front+1)%MAXSIZE;
		ok=queue[front];//����
		p=head[ok]->first;//��ȡ��һ������
		while(p!=NULL)//ѭ�����������
		{
			if(visited[p->data]==0)//�ñ���û�з��ʹ�
			{
				cout<<p->data;
				visited[p->data]=1;
				rear=(rear+1)%MAXSIZE;
				queue[rear]=p->data;//���
			}
			p=p->next;//����һ�����
		}
	}
}

int main()
{
	
	int visited[MAXSIZE]={0};
	Head * head[MAXSIZE];//��ͷָ������
	for(int i=0;i<MAXSIZE;i++)
	{
		head[i]=new Head;
		head[i]->data=i;
		cout<<"��������"<<i<<"�ı��������Ȩֵ"<<endl;
		Create(head[i]);

	}
	cout<<endl<<"������������������Ϊ"<<endl;
	DFS_DG(head,0,visited);

	cout<<endl<<"������������������Ϊ"<<endl;
	BFS(head,0);

	return 0;
}

