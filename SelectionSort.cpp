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
        int min = i;  //起始时认为0号元素是最小元素
        for (j = i + 1; j < ST.len; j++)
            //使用数组中i元素之后的每一个元素都和最小元素arr[min]比较，找到最小元素的下标
        {
            if (ST.arr[min] > ST.arr[j])  //当下标为j的元素小于最小元素时
            //将>改成<可以将排序后的数组变为由大到小
            {
                min = j;  //将最小元素的下标min改为j
            }
        }
        if (min != i)
        {
            swap(ST.arr[min], ST.arr[i]);  //同一位置的元素不用交换（交换也不影响）
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
