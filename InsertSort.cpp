#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<time.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct
{
	Elemtype* arr;
	//Elemtype arr[10];
	int len;
}SSTable;

void InitST(SSTable& ST, Elemtype len)
{
	int i;
	ST.len = len;
	ST.arr = (Elemtype*)malloc(sizeof(Elemtype) * ST.len);
	srand(time(NULL));
	for (i = 0; i < len; i++)
	{
		ST.arr[i] = rand() % 100;
	}
}

void Print(SSTable ST)
{
	int i;
	for (i = 0; i < ST.len; i++)
	{
		printf("%3d", ST.arr[i]);
	}
	printf("\n");
}

void InsertSort(Elemtype* arr, Elemtype len)
{
	int i, j, InsertVal;
	for (i = 1; i < len; i++)  //外层循环控制要插入的数字，每次向后移动一个位置
	{
		InsertVal = arr[i];  //保存要插入的数字
		for (j = i - 1; j >= 0 && arr[j] > InsertVal; j--)  //内层控制和有序数组中每一个数字的比较
		{
			//if (arr[j] > InsertVal)  //前一个位置上的数字大于要插入的数字时
			//{
				arr[j + 1] = arr[j];  //前一个位置的数字覆盖到后一个位置
			//}
		}
		arr[j + 1] = InsertVal;  
		//数组下标j的值赋给j+1，j的值和j+1重复，应该把要插入的数字放在j上，出循环前执行了j--，即InsertVal应赋给j+1
	}
}

int main()
{
	SSTable ST;  //申请10个元素的空间
	InitST(ST, 10);
	Print(ST);
	InsertSort(ST.arr, 10);
	Print(ST);
	return 0;
}