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
	for (i = 1; i < len; i++)  //���ѭ������Ҫ��������֣�ÿ������ƶ�һ��λ��
	{
		InsertVal = arr[i];  //����Ҫ���������
		for (j = i - 1; j >= 0 && arr[j] > InsertVal; j--)  //�ڲ���ƺ�����������ÿһ�����ֵıȽ�
		{
			//if (arr[j] > InsertVal)  //ǰһ��λ���ϵ����ִ���Ҫ���������ʱ
			//{
				arr[j + 1] = arr[j];  //ǰһ��λ�õ����ָ��ǵ���һ��λ��
			//}
		}
		arr[j + 1] = InsertVal;  
		//�����±�j��ֵ����j+1��j��ֵ��j+1�ظ���Ӧ�ð�Ҫ��������ַ���j�ϣ���ѭ��ǰִ����j--����InsertValӦ����j+1
	}
}

int main()
{
	SSTable ST;  //����10��Ԫ�صĿռ�
	InitST(ST, 10);
	Print(ST);
	InsertSort(ST.arr, 10);
	Print(ST);
	return 0;
}