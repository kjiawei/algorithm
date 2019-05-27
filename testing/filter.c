#include <stdio.h>

#define N 11
//2:滤波算法
/*
滤波概念与原理 http://blog.csdn.net/wangweijjj/article/details/51721191
//卡尔曼滤波 http://blog.csdn.net/tiandijun/article/details/72469471
卡在线性随机微分方程  kalman filter最为核心的内容是体现它最优化估计和递归特点的5条公式
10种简单的数字滤波算法(C语言源程序) http://www.elecfans.com/emb/danpianji/2009071678030.html
//中位值:变化慢的数据(温度/液位等)若干值排序的中位(有效克服因偶然因素引起的波动(脉冲)干扰)
//流量、速度等快速作用不佳
*/
char filter()
{
	char value_buf[N];//温度数组
	char count,j,i,temp;
	for(count = 0;count<N;count++)
	{
		value_buf[count] = get_ad();//这里获取温度值
		delay();//延时值设定
	}
	for(j=0;j<N-1;j++)//冒泡排序
	{
		for(i=0;i<N-j;i++)
		{
			if(value_buf[i]>value_buf[i+1])
			{
				temp = value_buf[i];
				value_buf[i] = value_buf[i+1];
				value_buf[i+1] = temp;
			}
		}
	}
	return value_buf[(N-1)/2];
}

//消抖滤波
/*#define N 12 
char filter() 
{ 
   char count=0; 
   char new_value; 
   new_value = get_ad(); 
   while (value !=new_value); 
   { 
      count++; 
      if (count>=N)   return new_value; 
       delay(); 
      new_value = get_ad(); 
   } 
   return value;     
}*/ 

int main(void){
	/*问题1类型转换:高+低->低(精度丢失)
	int a,b;
	double c;
	a='A'+1.6;//A->65
	b='A'+0.6;
	c='A'+1.6;
	printf("a:%d\n",a);//66
	printf("a:%c\n",a);//B
	//printf("a:%f\n",a); warning: format ‘%f’ expects argument of type ‘double’, but argument 2 has type ‘int’ [-Wformat]
	//printf("b:%f\n",b);//-0.000000
	printf("b:%d\n",b);//65
	printf("b:%c\n",b);//A
	printf("c:%d\n",c);//1717986918
	printf("c:%c\n",c);//f  ?   102
	printf("c:%f\n",c);//66.600000*/
	
	
	return 0;
}

/*
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double frand()
{
	return 2 * ((rand() / (double)RAND_MAX) - 0.5);//随机噪声
}

void main()
{
	float x_last = 0;
	float p_last = 0.02;
	float Q = 0.018;
	float R = 0.542;
	float kg;
	float x_mid;
	float x_now;
	float p_mid;
	float p_now;
	float z_real = 0.56;
	float z_measure;
	float summerror_kalman = 0;
	float summerror_measure = 0;
	int i;
	x_last = z_real + frand()*0.03;
	x_mid = x_last;
	for (i = 0; i < 20;i++)
	{
		x_mid = x_last;
		p_mid = p_last + Q;
		kg = p_mid / (p_mid + R);
		z_measure = z_real + frand()*0.03;//测量值
		x_now = x_mid + kg*(z_measure - x_mid);//估计出的最有值
		p_now = (1 - kg)*p_mid;//最优值对应的协方差

		printf("Real position:%6.3f\n", z_real);
		printf("Measure position:%6.3f [diff:%.3f]\n", z_measure, fabs(z_real - z_measure));
		printf("Kalman position: %6.3f [diff:%.3f]\n", x_now, fabs(z_real - x_now));
		printf("\n\n");
		summerror_kalman += fabs(z_real - x_now);
		summerror_measure += fabs(z_real - z_measure);
		p_last = p_now;
		x_last = x_now;
	}
	printf("总体测量误差      :%f\n", summerror_measure);
	printf("总体卡尔曼滤波误差:%f\n", summerror_kalman);
	printf("卡尔曼误差所占比例:%d%%\n", 100 - (int)((summerror_kalman / summerror_measure) * 100));

	getchar();
}
*/
