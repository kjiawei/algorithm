TARGET=kernel_list  #TARGET是一个变量
CC=gcc       #CC是一个变量
SRCS=$(wildcard *.c)        #wildcard函数查找所有.c
OBJ=$(patsubst %.c,%.o,$(SRCS))             #patsubst将所有的.c替换为.o文件

$(TARGET):$(OBJ)         
	$(CC)  $(OBJ) -o $(TARGET) 

clean:  #添加清除操作
	rm *.o $(TARGET)  #清除.o文件及执行文件
