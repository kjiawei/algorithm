#include <stdio.h>

int main()
{
    int i, j;
	
    for(i = 1;i <10; i++)// ���ѭ��
	{  
        j=1;
        for(;j <10; j++)// �ڲ�ѭ��
		{  
            printf("%d\t", i*j);
            
            if(j>4) break;  //�����ڲ�ѭ��
        }
        printf("\n");
        
        if(i>4) break;  // �������ѭ��
    }
    return 0;
}