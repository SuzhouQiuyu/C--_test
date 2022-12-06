#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//指针实现顺序表
typedef int Elemtype;
//定义顺序表
typedef struct
{
	Elemtype* elem;  //指针，类型自定，申请堆空间的起始地址存入elem
	int TableLen;  //存储在动态数组中元素的个数
}SSTable;

void ST_Init(SSTable& ST, int len)
{
	ST.TableLen = len + 1;  //需要多申请一个位置，原因是0号位置存放“哨兵”
	ST.elem = (Elemtype*)malloc(sizeof(Elemtype) * ST.TableLen);  //指针elem指向的每个元素都是Elemtype类型的（int）
	int i;
	srand(time(NULL));  //随机数生成
	for (i = 1; i < ST.TableLen; i++)  //0号位置是哨兵，随机数从1号位置开始
	{
		ST.elem[i] = rand() % 100;  //%100使得生成的随机数在0-99之间
	}
}

//打印顺序表
void ST_Print(SSTable ST)
{
	int i;
	for (i = 1; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);  //类似于数组访问，elem相当于数组名
	}
	printf("\n");
}

int search_seq(SSTable ST, Elemtype key)
{
	ST.elem[0] = key;  //key存在0号位置，作为哨兵，哨兵的存在可有可无，哨兵存在的意义是循环判断条件不用写i>=0
	int i;
	for (i = ST.TableLen - 1; ST.elem[i] != key; i--);
	return i;
}
int main()
{
	SSTable ST;
	ST_Init(ST, 10);
	ST_Print(ST);  //打印顺序表中的元素（顺序表中的元素位置从1开始）
	Elemtype key;
	printf("请输入要查找的key值\n");
	scanf("%d", &key);
	int pos;  //查找函数返回的下标位置
	pos = search_seq(ST, key);
	if (pos)
	{
		printf("找到了，位置为%d\n", pos);
	}
	else
	{
		printf("没有找到\n");
	}
	return 0;
}