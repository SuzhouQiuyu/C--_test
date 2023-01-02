#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elemtype;
typedef struct
{
    Elemtype* arr;
    int len;
}SSTable;

void InitST(SSTable& ST, Elemtype n)
{
    ST.len = n;
    ST.arr = (Elemtype*)malloc(sizeof(Elemtype) * ST.len);
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
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
//��ȡ10����������12 63 58 95 41 35 65  0 38 44��
//Ȼ��ͨ��ð�����򣬿������򣬲������򣬷ֱ�Ը������ݽ�������
//���3����������ÿ���������ռ3���ո�
void BubbleSort(SSTable& ST)
{
    int i, j;
    bool flag;
    for (i = 0; i < ST.len - 1; i++)
    {
        for (j = ST.len - 1; j > i; j--)
        {
            if (ST.arr[j] < ST.arr[j - 1])
            {
                swap(ST.arr[j], ST.arr[j - 1]);
                flag = true;
            }
        }
        if (flag == false)
        {
            return;  //�ڲ�ѭ�����ζԱ�����Ԫ�أ�һ�ζ�û��ִ�н�����˵����������
        }
    }
}

int partition(SSTable& ST, int low, int high)
{
    Elemtype pivot = ST.arr[low];
    while (low < high)
    {
        while (low < high && ST.arr[high] >= pivot)
        {
            high--;
        }
        ST.arr[low] = ST.arr[high];
        while (low < high && ST.arr[low] <= pivot)
        {
            low++;
        }
        ST.arr[high] = ST.arr[low];
    }
    ST.arr[low] = pivot;
    return low;
}

void QuickSort(SSTable& ST, int low, int high)
{
    if (low < high)
    {
        int pivot_pos = partition(ST, low, high);
        QuickSort(ST, low, pivot_pos - 1);
        QuickSort(ST, pivot_pos + 1, high);
    }
}

void InsertST(SSTable& ST)
{
    int i, j;
    for (i = 1; i < ST.len; i++)
    {
        Elemtype InsertVal = ST.arr[i];
        for (j = i - 1; j >= 0 && ST.arr[j] > InsertVal; j--)
        {
            ST.arr[j + 1] = ST.arr[j];
        }
        ST.arr[j + 1] = InsertVal;
    }
}

int main()
{
    SSTable ST;
    InitST(ST, 10);
    int i;
    Elemtype A[10];
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &A[i]);
    }
    memcpy(ST.arr, A, sizeof(A));
    BubbleSort(ST);
    Print(ST);
    memcpy(ST.arr, A, sizeof(A));
    QuickSort(ST, 0, 9);
    Print(ST);
    memcpy(ST.arr, A, sizeof(A));
    InsertST(ST);
    Print(ST);
    return 0;
}