#include <stdio.h>

#define M 10
#define N 10
int map[M+2][N+2] = {
				1,1,1,1,1,1,1,1,1,1,1,1,
				1,0,1,0,0,0,1,1,1,1,1,1,
				1,0,1,0,1,0,1,1,1,1,1,1,
				1,0,1,0,1,0,1,1,1,1,1,1,
				1,0,0,0,0,0,1,1,1,1,1,1,
				1,1,1,1,1,0,1,0,0,0,0,1,
				1,1,1,1,1,0,0,0,1,0,1,1,
				1,1,1,1,1,1,0,1,0,0,0,1,
				1,1,1,1,1,1,0,0,0,1,0,1,
				1,1,1,1,1,1,0,1,0,1,0,1,
				1,0,0,0,0,0,0,0,0,0,0,1,
				1,1,1,1,1,1,1,1,1,1,1,1,
				};
struct maze
{
	int x;
	int y;
	int other;
	int count;
};



struct maze array[M*N]; // calloc   ;  set zero 
int line_arr[10]; // just can be 10 lines to arrive 

int success = 0;

int printf_map(int x, int y)
{
	int i, j;
	for(i=0;i<M+2;i++)  
	{   
		for(j=0;j<N+2;j++)   
		{    
			if(i == x && j == y)
				printf("$");    
			else if(map[i][j]==2)    
				printf("-");    
			else if(map[i][j]==1)    
				printf("*");   
			else    
				printf(" "); 
		}  
		printf("\n");  
	} 
}
void move(int i, int j,  int base)
{
	int a;
	int k=0;
	while(1)
	{
		usleep(500000);// 0.5秒
		system("clear");
		printf_map(i, j);
		printf(" %d %d\n" , i,j );
		
		map[i][j] = 2;
		k++;
		
		if(k != 0)
		{
			array[base + k].x = i;
			array[base + k].y = j;
			array[base + k].count = array[base + k-1].count +1 ;
			array[base + k].other = 0;
		}
		
		if(i==M  && j == N)
		{
			printf("success \n");
			success = array[base + k].count ;
			return ;
		}
		
		if(map[i+1][j] == 0)
			array[base + k].other ++;	// one way
		if( map[i][j+1]== 0 )
			array[base + k].other ++;	
		if( map[i][j-1]== 0 )
			array[base + k].other ++;	
		if( map[i-1][j]== 0 )
			array[base + k].other ++;	

		
		if(map[i+1][j] == 0)
		{
			i++;
			array[base + k].other --;
		}
		else if(map[i][j+1] == 0)
		{
			j++;
			array[base + k].other --;
		}
		else if(map[i-1][j] == 0)
		{
			i--;
			array[base + k].other --;
		}
		else if(map[i][j-1] == 0)
		{
			j--;
			array[base + k].other --;
		}
		else // no way
		{
			array[base + k].other  = 0;
			printf("no way %d:%d \n", k, array[base+k].other );
			
			for( a = base + k; a > 0; a -- )
			{
				if(array[a].other != 0)
				{
					i = array[a].x;
					j = array[a].y;
					k = a - base-1;
					printf("no way %d,%d ,%d,%d \n", i,j,array[a].other,a);
					break;
				}
			}
			if(a == base )
			{
				printf("can't find way for this solution!!!! \n");
				success = -1;
				return ;
			}
		}
	}
	return ;
}

int main(void)
{
	int i , j , k;
	int dirent;
	int a, b;
	int line = 0;
	int line_total = 0;
	for(i = 0; i<M+2; i++)
	{
		for(j = 0; j<N+2 ; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	
	array[0].x = 1;
	array[0].y = 1;
	array[0].count = 0; 
	array[0].other = 0;

	move(1,1,0 );		
	
	if( success > 0)
		line_arr[line_total ] = success ;
	
	for( b = 0 ; b < success ; b++)
	{
		printf(" %d,%d-" , array[b].x, array[b].y );
		if(array[b].other != 0)
			line ++;
	}
	printf("end \n");
	sleep(2);

	// but how to get the shortest way
	// check for other solution
	if(success > 0)
	{
		if(line == 1)
		{
			printf ("this is the only way\n");
		}	
		else
		{
			for( a = 0 ; a < M*N ;a++)
			{
				if(array[a].other != 0)
				{
					move(array[a].x, array[a].y , line_arr[line_total ] );
					
					if( success > 0)
						line_arr[++line_total ] = success ;
					
					for( b = a ; b < success; b++)
					{
						printf(" %d,%d-" , array[b].x, array[b].y );
					}
					printf("end \n");
					sleep(2);
				}
			}
		}
	}
}
