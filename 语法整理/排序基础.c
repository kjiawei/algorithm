//ѡ������
//10������ ��С�������� min����СԪ�ص��±�
for(i=0; i<=1; i++)  // ѭ����9��
{
	min=i;
	for(j=i+1; j<=2; j++)   
	{
		if(a[min]>a[j])    
			min=j;   //min  1
	}// �ҵ�Ŀǰ��������С���Ǹ�Ԫ�ص��±�

	temp=a[i];
	a[i]=a[min];
	a[min]=temp;
}

//ð��
int buble(int num[])
{
	for(j=1; j<N; j++)
		for(i=0; i<N-j; i++)
			if(num[i]>num[i+1])
			{
				
			}
	
}