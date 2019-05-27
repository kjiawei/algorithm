// KMP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include<string>
using namespace std;

int BF(string s,string t)//Brute-Force,��ƥ���㷨
{
	int origin=-1;//ģʽƥ�����ʼλ�ã���ʼ��Ϊ-1������ʧ��ʱ����-1
	for(int i=0;i<s.size();i++)
	{
		int k;
		for(k=0;k<t.size();k++)
		{
			if(s[i+k]!=t[k])
				break;
		}
		if(k==t.size())//ƥ��ɹ�
		{
			origin=i;
			break;
		}
	}
	return origin;//ƥ��ɹ�������ʼλ�ã�ʧ�ܾͷ���-1
}

//����next���飬tΪ�����ַ���
void calculateNext(int * & next,string t)
{
	for(int j=0;j<t.size();j++)
	{
		bool state=true;//�Ƿ��ǵ���0�����
		if(j==0)
			*next=-1;
		else 
		{
			int k=j-1;//0<k<j,��ȡ����k
			while(k>0)
			{
				string str1="",str2="";
				for(int i=0;i<=k-1;i++)
				{
					str1=str1+t[i];
					str2=str2+t[j-k+i];
				}
				if(str1==str2)//����p[0....k-1]=p[j-k...j-1];
				{	
					*(next+j)=k;
					state=false;//���ǵ���0�����
					break;
				}
				k--;
				
			}
			if(state)//����������������Ϊ0
			 *(next+j)=0;
		}

	}
}

//kmpƥ���㷨,sΪ������tΪģʽ��
int KMP(int * next,string s,string t)
{
	int j=0,i=0;//iΪ����s����ƥ����ַ���jΪt����ƥ����ַ�
	
	while(i<s.size()&&j<t.size())
    {
        if(t[j] == s[i])
        {
            j++;i++;
        }
        else
        {
            if(j==0) 
            {
                i++;//����һ���ַ���ƥ��ʧ�ܣ����s����һ���ַ���ʼ
            }
            else
            {
				
                j = *(next+j);//,Ҳ����j=next[j],��nextȷ��tӦ���ݵ����ַ�
            }
        }
    }
    if(j < t.size())//��������ƥ��ʧ��
    {
        return -1;
    }
    return i-t.size();//ƥ��ɹ�
	//�ڶ���д��
	/*2. while(i < s.size())  
         {  
                  while(j > -1 && t[j] != s[i])  
                          j = next[j];  
                  i++, j++;  
                  if(j >= t.size()) return i - j;  
         }  
	 return -1;  */


	
}


int main()
{
	
	string s="ababcabcacbab";//����
	string t="acbab";//ģʽ��

	int *next=new int[t.size()];//ģʽ����next����

	calculateNext(next,t);//����nextƥ����Ϣ

	
	int BForigin=BF(s,t);
	if(BForigin==-1)
		cout<<"BFƥ��ʧ�ܣ�"<<endl;
	else
	
	cout<<"BF�㷨ģʽƥ���λ���ǣ�"<<BForigin<<"->"<<BForigin+t.size()<<endl;

    int KMPorigin=KMP(next,s,t);
	if(KMPorigin==-1)
		cout<<"KMPƥ��ʧ�ܣ�"<<endl;
	else
	cout<<"KMP�㷨ģʽƥ���λ���ǣ�"<<KMPorigin<<"->"<<KMPorigin+t.size()<<endl;
	return 0;
}

