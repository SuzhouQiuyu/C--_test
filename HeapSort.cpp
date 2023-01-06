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

//将某个子树调整为大根堆，需要多次执行（每次只调整一棵子树）
void AdjustDown(Elemtype arr[], Elemtype k, Elemtype len)  //k为要调整的子树的父节点下标，len表示剩余的无序数组的长度
{
    int dad = k;  //要调整的子树的父节点下标
    int son = 2 * dad + 1;  //左孩子下标
    while (son < len)  //当新的父节点产生后，子节点的下标超出数组元素个数时，循环终止
    {
        if (son + 1 < len && arr[son] < arr[son + 1])
        //如果左孩子大于右孩子，下个if判断左孩子是子树中最大的叶子节点，用左孩子和父节点比较
        //存在子树中只有一个子节点的情况，如果不满足son+1<len，说明son指向数组中最后一个元素，该子树没有右孩子
        {
            son++;  //左孩子小于右孩子，进入循环，son++，son变为右孩子
        }
        if (arr[son] > arr[dad])  //右孩子是子树中最大的叶子节点，用右孩子和父节点比较
        {
            swap(arr[son], arr[dad]);  //叶子节点大于父节点，发生交换
            dad = son;  //父节点和子节点发生交换后，检查新的子节点下的子树是否满足大根堆，即将子节点变成父节点继续检查
            son = 2 * dad + 1;  //son变为新的子树左孩子下标
        }
        else
        {
            break;  //父节点和子节点没有发生交换时，即该子树满足大根堆要求，跳出循环，检查其他子树
        }
    }
}

//堆排序
void HeapSort(Elemtype arr[], Elemtype len)
{
    //先把每一个子树调整为大根堆
    int i;
    for (i = len / 2 - 1; i >= 0; i--)  //需要调整的子树的范围是从最后一个非叶子节点（父节点）到根节点
    {
        AdjustDown(arr, i,len);  //i为要调整为大根堆的子树的父节点
    }
    //调整成大根堆后，数组元素仍是无序的
    swap(arr[0], arr[len - 1]);  //交换根节点和最后一个节点元素，确定了最后一个元素位置
    for (i = len - 1; i > 1; i--)  //i表示剩余的无序数组的长度，数组长度-1=数组元素下标
    {
        AdjustDown(arr, 0, i);  //调整剩余元素变为大根堆
        //0表示要调整为大根堆的子树的父节点，每次都是根节点交换位置发生改变，只需要传入根节点下标0
        swap(arr[0], arr[i - 1]);  //交换根节点和最后一个节点元素，确定了最后一个元素位置
        //除最后一个元素，剩余的子树除了根节点所在的子树外都满足大根堆，传入子函数调整
        //根节点调整后，子函数内会依次检查下面调整后每一个不满足大根堆条件的子树，直到生成新的大根堆
        //回到堆排序中的for循环，将此时的大根堆根节点和最后一个节点元素交换，确定最大的一个元素位置，继续循环
    }
}

int main()
{
    SSTable ST;
    InitST(ST, 10);
    //Elemtype A[10] = { 3,87,2,93,78,56,61,38,12,40 };
    //memcpy(ST.arr, A, sizeof(A));
    Print(ST);
    HeapSort(ST.arr,10);
    Print(ST);
    return 0;
}