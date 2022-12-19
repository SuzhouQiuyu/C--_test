#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>  //memcpy使用

typedef int Elemtype;
typedef struct
{
	Elemtype* arr;
	int lenth;
}SSTable;

//初始化
void Init_ST(SSTable& ST, Elemtype len)
{
	ST.lenth = len;
	ST.arr = (Elemtype*)malloc(sizeof(Elemtype) * ST.lenth);
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.lenth; i++)  //没有哨兵
	{
		ST.arr[i] = rand() % 100;
	}
}

//打印顺序表
void ST_Print(SSTable ST)
{
	int i;
	for (i = 1; i < ST.lenth; i++)
	{
		printf("%3d", ST.arr[i]);
	}
	printf("\n");
}

//冒泡排序
void bubble_sort(Elemtype* arr, Elemtype len)  //数组ST.arr的类型是Elemtype*
{

}
int main()
{
	SSTable ST;
	//在使用随机数的代码中使用固定的数组有利于调试
	//Elemtype A[10] = { 64,94,95,79,69,84,18,22,12,78 };
	//memcpy(ST.arr, A, sizeof(A));
	Init_ST(ST, 10);
	ST_Print(ST);
	bubble_sort(ST.arr, 10);  //将数组ST.arr传入（也可以传ST）
	return 0;
}