#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Elemtype;
typedef struct
{
    Elemtype* elem;  //整型指针
    int TableElem;  //存储在动态数组中的元素个数
}SSTable;
//随机树表初始化，没有使用哨兵
void InitTable(SSTable& ST, int len)
{
    ST.TableElem = len;
    ST.elem = (Elemtype*)malloc(sizeof(Elemtype));
    int i = 0;
    srand(time(NULL));
    for (i; i < ST.TableElem; i++)
    {
        ST.elem[i] = rand() % 100;
    }
}
//打印随机数
void PrintTable(SSTable ST)
{
    int i = 0;
    for (i; i < ST.TableElem; i++)
    {
        printf("%3d", ST.elem[i]);
    }
    printf("\n");
}
//二分查找
int binary_search(SSTable ST, Elemtype key)
{
    int low = 0, high = ST.TableElem - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key < ST.elem[mid])
        {
            high = mid - 1;
            mid = (low + high) / 2;

        }
        else if (key > ST.elem[mid])
        {
            low = mid + 1;
            mid = (low + high) / 2;

        }
        else
        {
            return mid;
        }
    }
    return -1;
}

//函数名compare中存放着函数入口地址，是函数指针类型
int compare(const void* left, const void* right)
{
    return *(int*)left - *(int*)right;  //从小到大排序，(int*)表示强制类型转换，*表示解引用，通过地址找到指针指向的元素
    //如果是升序，即left比right大，返回正值；如果是降序，left比right小，返回负值；left和right相等，返回0
    //return *(int*)right-*(int*)left;  //从大到小排序
}

int main() {
    SSTable ST;
    int x;
    scanf("%d", &x);
    InitTable(ST, x);
    PrintTable(ST);
    qsort(ST.elem, ST.TableElem, sizeof(Elemtype), compare);
    PrintTable(ST);
    Elemtype key;
    printf("input search key\n");
    scanf("%d", &key);
    int ret = binary_search(ST, key);
    if (ret != -1)
    {
        printf("search success,location %d\n", ret);
    }
    else {
        printf("seasrch faild\n");
    }
    return 0;
}
