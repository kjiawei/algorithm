// Btree.cpp : �������̨Ӧ�ó������ڵ㡣
//
//������ʵ��

#include "stdafx.h"

#include<iostream>
#include<string>
using namespace std;

//�������Ľṹ
struct node
{
	node * lchild;
	node * rchild;
	string data;
	//��ʼ��
	node()
	{
		lchild=rchild=NULL;
	}
};
//����������--�����������Ҫ���ɵĶ��������ݣ�#����ս��
void CreateTree(node * & root)
{
	 char data;
	 cin>>data;
	 if(data!='#')
	 {
		 root=new node;
		 root->data=data;
		 
		 CreateTree(root->lchild);
		
		 CreateTree(root->rchild);
		
	 }
}

//���������Ƿ��������aim,���򷵻���ָ��
node * Findnode(node * & root,string aim)
{
	node * p;
	if(root==NULL)//����
		return NULL;
	else if(root->data==aim)
		return root;
	else
	{	
		p=Findnode(root->lchild,aim);
		if(p!=NULL)
			return p;
		else
			return Findnode(root->rchild,aim);	
	}
}
void  PreOrder(node * root)//�������
{
	if(root!=NULL)
	{
		cout<<root->data;
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}
void  InOrder(node * root)//�������
{
	if(root!=NULL)
	{
		
		InOrder(root->lchild);
		cout<<root->data;
		InOrder(root->rchild);
	}
}
void  PostOrder(node * root)//�������
{
	if(root!=NULL)
	{
		
		PostOrder(root->lchild);
		PostOrder(root->rchild);
		cout<<root->data;
	}
}

int NodeHeight(node * root)//����������߶�
{
	int lchild,rchlid;
	if(root==NULL)
		return 0;
	else
	{
		lchild=NodeHeight(root->lchild);
		rchlid=NodeHeight(root->rchild);
		return (lchild>rchlid)?(lchild+1):(rchlid+1);
	}
}

void Showleaf(node * root)
{
	if(root!=NULL)
	{
		if(root->lchild==NULL&&root->rchild==NULL)
			cout<<root->data<<" ";
		Showleaf(root->lchild);//���������Ҷ�ӽڵ�
		Showleaf(root->rchild);//���������Ҷ�ӽڵ�
	}
}
int main()
{
	node * root=NULL;//���ڵ�
	CreateTree(root);//���ɶ�����
	int i=0;
	cout<<"������Ҫ���ҵĽ��"<<endl;
	string data;
	cin>>data;
	if(Findnode(root,data))
		cout<<"���ҳɹ�"<<endl;
	else
		cout<<"����ʧ��"<<endl;

	cout<<"�����������Ϊ�� "<<NodeHeight(root)<<endl;

	cout<<"��������������� ";
	PreOrder(root);
	cout<<endl;

	cout<<"��������������� ";
	InOrder(root);
	cout<<endl;

	cout<<"��������������� ";
	PostOrder(root);
	cout<<endl;

	cout<<"������Ҷ�ӽڵ��У� ";
	Showleaf(root);
	cout<<endl;
	
	return 0;
}

