#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>  //随机数使用
#include <stdlib.h>  //随机数使用
#include <string.h>  //memcpy使用

typedef int Elemtype;
typedef struct
{
    Elemtype arr[10];
    int len;
}SSTable;

void InitTable(SSTable& ST, Elemtype x)
{
    int i;
    ST.len = x;
    srand(time(NULL));
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

//分割函数(快速排序的核心)
int partition(Elemtype arr[], int low, int high)
//经过一次分割后，分割元素到达数组中间，小于分割元素的在分割元素左边，大于分割元素的在分割元素右边
{
    Elemtype pivot = arr[low];  //将数组最左边的元素值当作分割值并存储
    while (low < high)
    {
        //循环条件中的=可以解决生成随机数中含有相等数值的程序卡死问题
        while (low < high && arr[high] >= pivot)  //数组从后向前遍历，找到比分割值小的元素
        {
            high--;  //使high指向该元素
        }
        arr[low] = arr[high];  //比分割值小的元素覆盖掉low指向的元素（low原本指向的元素已经当作分割值存储在pivot中）
        while (low < high && arr[low] <= pivot)  //数组从前向后遍历，找到比分割值大的元素
        {
            low++;  //使low指向该元素
        }
        arr[high] = arr[low];  //比分割值大的元素覆盖掉high指向的元素（此时high原本指向的元素已经放在low指向的前一个元素）
    }
    arr[low] = pivot;  //将分割值放在数组元素中间位置（low=high）
    return low;  //将分割值的元素数组下标返回到QucikSort函数中
}

void QucikSort(Elemtype arr[], int low, int high)  //low表示数组最左边的元素，high表示数组最右边的元素
{
    if (low < high)  //当分割元素左右两边的数组中各只剩下一个元素时，即low=high时，无需再进行排序
    {
        int pivot_pos = partition(arr, low, high);  //存储分割元素的位置（分割元素的下标）
        QucikSort(arr, low, pivot_pos - 1);  //对分割元素之前的数组进行快速排序
        QucikSort(arr, pivot_pos + 1, high);  //对分割元素之后的数组进行快速排序
    }
}

int main()
{
    SSTable ST;
    InitTable(ST, 10);
    //代码调试时使用
    //Elemtype arr[10] = { 64,94,95,79,69,84,18,22,12,78 };
    //memcpy(ST.arr, arr, sizeof(arr));
    //分割函数较容易出错，调试时应将断点打在分割函数调用的下一句
    //调试过程中可以在内存视图中查看到16进制的数组元素
    Print(ST);
    QucikSort(ST.arr, 0, 9);
    Print(ST);
    return  0;
}