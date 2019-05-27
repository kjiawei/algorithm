#include <stdio.h>

int main()
{
    int i, j;
	
    for(i = 1;i <10; i++)// 外层循环
	{  
        j=1;
        for(;j <10; j++)// 内层循环
		{  
            printf("%d\t", i*j);
            
            if(j>4) break;  //跳出内层循环
        }
        printf("\n");
        
        if(i>4) break;  // 跳出外层循环
    }
    return 0;
}