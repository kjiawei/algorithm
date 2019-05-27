#include<stdio.h>
#include<stdlib.h>

//位非
char bit_not(char ch)
{
	ch = ~ch;
	return ch;
}

//位与
char bit_and(char ch,char ch1)
{
	return ch&ch1;
}

//位或
char bit_or(char ch,char ch1)
{
	return ch|ch1;
}

//异或
char bit_not_and(char ch,char ch1)
{
	ch = ch^ch1;
	ch1 = ch^ch1;
	ch  = ch^ch1;
	printf("ch,ch1      交换后：ch = %#x ch1 = %#x\n",ch,ch1);
	
	return 0;
}
//第2位清零  位且
char leftmv_zero(char ch)
{							//          31.....   3210

	ch = ch&(~(0x1<<2));     //ch = ch&0x...1111 1011
	return ch;
}
//第2位置1   位或
char leftmv_one(char ch)
{
	ch = ch|(0x1<<2);       //ch = ch|0x...0000 0100
	
}

int main()
{
	char ch = 0x45,ch1 = 0x56;
	
	printf("ch    按位取非后为：%#x\n",bit_not(ch));
	printf("ch,ch1  按位与后为：%#x\n",bit_and(ch,ch1));
	printf("ch,ch1  按位或后为：%#x\n",bit_or(ch,ch1));
	bit_not_and(ch,ch1);
	printf("ch  第三位清零后为：%#x\n",leftmv_zero(ch));
	printf("ch   第三位置1后为：%#x\n",leftmv_one(ch));
	
	return 0;
}



















