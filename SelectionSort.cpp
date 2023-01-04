#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int Elemtype;
typedef struct
{
    Elemtype* arr;
    int len;
}SSTable;

void InitST(SSTable& ST, int len)
{
    ST.len = len;
    ST.arr = (Elemtype*)malloc(sizeof(Elemtype) * ST.len);
    srand(time(NULL));
    int i;
    for (i = 0; i < ST.len; i++)
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

void swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void SelectionSort(SSTable& ST)
{
    int i, j;
    for (i = 0; i < ST.len - 1; i++)
    {
        int min = i;  //��ʼʱ��Ϊ0��Ԫ������СԪ��
        for (j = i + 1; j < ST.len; j++)
            //ʹ��������iԪ��֮���ÿһ��Ԫ�ض�����СԪ��arr[min]�Ƚϣ��ҵ���СԪ�ص��±�
        {
            if (ST.arr[min] > ST.arr[j])  //���±�Ϊj��Ԫ��С����СԪ��ʱ
            //��>�ĳ�<���Խ������������Ϊ�ɴ�С
            {
                min = j;  //����СԪ�ص��±�min��Ϊj
            }
        }
        if (min != i)
        {
            swap(ST.arr[min], ST.arr[i]);  //ͬһλ�õ�Ԫ�ز��ý���������Ҳ��Ӱ�죩
        }
    }
}

int main()
{
    SSTable ST;
    InitST(ST, 10);
    Print(ST);
    SelectionSort(ST);
    Print(ST);
    return 0;
}
