#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>  //memcpyʹ��

typedef int Elemtype;
typedef struct
{
	Elemtype* arr;
	int lenth;
}SSTable;

//��ʼ��
void Init_ST(SSTable& ST, Elemtype len)
{
	ST.lenth = len;
	ST.arr = (Elemtype*)malloc(sizeof(Elemtype) * ST.lenth);
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.lenth; i++)  //û���ڱ�
	{
		ST.arr[i] = rand() % 100;
	}
}

//��ӡ˳���
void ST_Print(SSTable ST)
{
	int i;
	for (i = 1; i < ST.lenth; i++)
	{
		printf("%3d", ST.arr[i]);
	}
	printf("\n");
}

//ð������
void bubble_sort(Elemtype* arr, Elemtype len)  //����ST.arr��������Elemtype*
{

}
int main()
{
	SSTable ST;
	//��ʹ��������Ĵ�����ʹ�ù̶������������ڵ���
	//Elemtype A[10] = { 64,94,95,79,69,84,18,22,12,78 };
	//memcpy(ST.arr, A, sizeof(A));
	Init_ST(ST, 10);
	ST_Print(ST);
	bubble_sort(ST.arr, 10);  //������ST.arr���루Ҳ���Դ�ST��
	return 0;
}