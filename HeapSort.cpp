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

//��ĳ����������Ϊ����ѣ���Ҫ���ִ�У�ÿ��ֻ����һ��������
void AdjustDown(Elemtype arr[], Elemtype k, Elemtype len)  //kΪҪ�����������ĸ��ڵ��±꣬len��ʾʣ�����������ĳ���
{
    int dad = k;  //Ҫ�����������ĸ��ڵ��±�
    int son = 2 * dad + 1;  //�����±�
    while (son < len)  //���µĸ��ڵ�������ӽڵ���±곬������Ԫ�ظ���ʱ��ѭ����ֹ
    {
        if (son + 1 < len && arr[son] < arr[son + 1])
        //������Ӵ����Һ��ӣ��¸�if�ж�����������������Ҷ�ӽڵ㣬�����Ӻ͸��ڵ�Ƚ�
        //����������ֻ��һ���ӽڵ����������������son+1<len��˵��sonָ�����������һ��Ԫ�أ�������û���Һ���
        {
            son++;  //����С���Һ��ӣ�����ѭ����son++��son��Ϊ�Һ���
        }
        if (arr[son] > arr[dad])  //�Һ���������������Ҷ�ӽڵ㣬���Һ��Ӻ͸��ڵ�Ƚ�
        {
            swap(arr[son], arr[dad]);  //Ҷ�ӽڵ���ڸ��ڵ㣬��������
            dad = son;  //���ڵ���ӽڵ㷢�������󣬼���µ��ӽڵ��µ������Ƿ��������ѣ������ӽڵ��ɸ��ڵ�������
            son = 2 * dad + 1;  //son��Ϊ�µ����������±�
        }
        else
        {
            break;  //���ڵ���ӽڵ�û�з�������ʱ������������������Ҫ������ѭ���������������
        }
    }
}

//������
void HeapSort(Elemtype arr[], Elemtype len)
{
    //�Ȱ�ÿһ����������Ϊ�����
    int i;
    for (i = len / 2 - 1; i >= 0; i--)  //��Ҫ�����������ķ�Χ�Ǵ����һ����Ҷ�ӽڵ㣨���ڵ㣩�����ڵ�
    {
        AdjustDown(arr, i,len);  //iΪҪ����Ϊ����ѵ������ĸ��ڵ�
    }
    //�����ɴ���Ѻ�����Ԫ�����������
    swap(arr[0], arr[len - 1]);  //�������ڵ�����һ���ڵ�Ԫ�أ�ȷ�������һ��Ԫ��λ��
    for (i = len - 1; i > 1; i--)  //i��ʾʣ�����������ĳ��ȣ����鳤��-1=����Ԫ���±�
    {
        AdjustDown(arr, 0, i);  //����ʣ��Ԫ�ر�Ϊ�����
        //0��ʾҪ����Ϊ����ѵ������ĸ��ڵ㣬ÿ�ζ��Ǹ��ڵ㽻��λ�÷����ı䣬ֻ��Ҫ������ڵ��±�0
        swap(arr[0], arr[i - 1]);  //�������ڵ�����һ���ڵ�Ԫ�أ�ȷ�������һ��Ԫ��λ��
        //�����һ��Ԫ�أ�ʣ����������˸��ڵ����ڵ������ⶼ�������ѣ������Ӻ�������
        //���ڵ�������Ӻ����ڻ����μ�����������ÿһ������������������������ֱ�������µĴ����
        //�ص��������е�forѭ��������ʱ�Ĵ���Ѹ��ڵ�����һ���ڵ�Ԫ�ؽ�����ȷ������һ��Ԫ��λ�ã�����ѭ��
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