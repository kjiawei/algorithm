#include <stdio.h>

int num;//待转换数 -任意进制数
int target;//目标进制
void tobase(int, int);

int main()
{
    while(1)
	{
		printf("请输入你想转换进制的数和目标进制:\n");
		scanf("%d%d",&num,&target);
		tobase(num,target);
	}
    return 0;
}

void tobase(int value, int base)
{
    static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char buf[(sizeof(long) << 3) + 1];
    char *ptr, *end;

    if (base < 2 || base > 36) {
        printf("error base range \n");
    }

    end = ptr = buf + sizeof(buf) - 1;
    *ptr = '\0';
    do {
        *--ptr = digits[value % base];
        value /= base;
    } while (ptr > buf && value);

    printf("result is:%s\n",ptr);/* base: %d, => */
}