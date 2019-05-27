#include <stdio.h>

enum abc // 几乎不被使用的枚举名
{
	key_a ,// 0 
	key_b , //  = -2 ,
	key_c ,
	key_d
};


int main(void)
{
	printf("key_a = %d \n", key_a);
	// NG key_a = 99;
	printf("key_b = %d \n", key_b);
	printf("key_c = %d \n", key_c);
	printf("key_d = %d \n", key_d);
	return 0;
}
