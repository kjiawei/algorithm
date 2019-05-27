// maze.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
using namespace std;

#define BLOCKNUM 4//�Թ���ͼ��С

//��Ҫ���⣬������������ѭ��

//����ջ�Ľṹ
struct node
{
	int x;//��
	int y;//��  ��Ӧmap[x][y]
	int direction;//1�������ң�2�������£�3��������4�������ϣ����̽������,��һ��̽���ķ���
	node *next;
	int above;//��һ�����ĸ�����̽�������ģ���ֹ����������ѭ��
	node()
	{
		next=NULL;
	}
};

//��ջ---���뵽head֮��
void Push(node * &head,int x,int y,int direction,int above)
{
	
     node * temp=new node;
	 temp->x=x;temp->y=y;temp->direction=direction;
	 temp->above=above;

	 if(head==NULL)
		 head=temp;
	 else
	 {
		 temp->next=head;
		 head=temp;
	 }

}

//��ջ--ȡhead��
void Pop(node * &head)
{
	node * ok;
	if(head!=NULL)
	{
		
		ok=head;
		head=head->next;
		delete ok;
	}
	
	
}

//��ȡջ��Ԫ��
node Getpop(node * head)
{
	node temp;
	temp.x=head->x;
	temp.y=head->y;
	temp.direction=head->direction;
	temp.above=head->above;
	return temp;
}


//�޸�ջ��Ԫ�ط���
void Change(node * & head,int drection)
{
	head->direction=drection;
}


int main()
{
	//0��ʾ����ͨ�У����Ϊ��0��0��������Ϊ��3��3��
	int map[BLOCKNUM][BLOCKNUM]={
		{0,1,1,0},
		{0,0,0,0},
		{0,0,1,1},
		{1,0,0,0}
	};
	node *head=NULL;//ջ��ͷָ��
	Push(head,0,0,1,0);//��ڽ�ջ
	//̽��·��
	while(true)
	{
	    if(Getpop(head).x==3&&Getpop(head).y==3)//�ҵ����ڣ�ֹͣѭ��
			break;
		//����һ�����̽��
		bool sea=true;
		node  temp;

		//ÿһ��·��̽��
		while(sea)
		{
			temp=Getpop(head);		
			//temp.above!=4������ֹ���һ�����ѭ����
			//temp.directionΪǰ������
			switch (temp.direction)
			{
			case 1:
				//̽���ɹ��������ҿ��ԣ�����һ�����ķ������󣬷�ֹ������ѭ����̽���ɹ��������һ�������´λ��ݻ�һ������̽��
				if((temp.y+1)<BLOCKNUM&&map[temp.x][temp.y+1]==0&&temp.above!=3)
				{
					Change(head,temp.direction+1);	
					Push(head,temp.x,temp.y+1,1,1);//̽���ɹ���ջ
					sea=false; //ֹͣѭ��
					
				}
				else
				{
					Change(head,temp.direction+1);		//����̽��ʧ�ܣ�̽�������һ������̽��
				}
			
				break;
			case 2:
				if((temp.x+1)<BLOCKNUM&&map[temp.x+1][temp.y]==0&&temp.above!=4)
				{
					Change(head,temp.direction+1);
					Push(head,temp.x+1,temp.y,1,2);
					sea=false;
				}
				else
				{
					Change(head,temp.direction+1);
				}
				break;
			case 3:
				if((temp.y-1)>=0&&map[temp.x][temp.y-1]==0&&temp.above!=1)
				{
					Change(head,temp.direction+1);
					Push(head,temp.x,temp.y-1,1,3);
					sea=false;
				}
				else
				{
					Change(head,temp.direction+1);
				}
				break;
			case 4:
				if((temp.x-1)>=0&&map[temp.x-1][temp.y]==0&&temp.above!=2)
				{
					Change(head,temp.direction+1);
					Push(head,temp.x-1,temp.y,1,4);
					sea=false;
				}
				else
				{
					Pop(head);
					sea=false;
				}
				break;
			default://����temp.direction==5���˷����Ѿ������з���̽�����ˣ�������ջ
				Pop(head);
				sea=false;
				break;
			}
		}
		
	}
	node *kk=head;
	cout<<"�߳��Թ�·��Ϊ��"<<endl;
	//�����Ƿ��ģ���Ϊջ�Ƚ�����������Լ����д���ʵ��˳��·��
	while(kk!=NULL)
	{		
		cout<<"("<<kk->x<<","<<kk->y<<")"<<endl;
		kk=kk->next;
	}

	
	return 0;
}

