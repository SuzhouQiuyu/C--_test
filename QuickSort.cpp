#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>  //�����ʹ��
#include <stdlib.h>  //�����ʹ��
#include <string.h>  //memcpyʹ��

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

//�ָ��(��������ĺ���)
int partition(Elemtype arr[], int low, int high)
//����һ�ηָ�󣬷ָ�Ԫ�ص��������м䣬С�ڷָ�Ԫ�ص��ڷָ�Ԫ����ߣ����ڷָ�Ԫ�ص��ڷָ�Ԫ���ұ�
{
    Elemtype pivot = arr[low];  //����������ߵ�Ԫ��ֵ�����ָ�ֵ���洢
    while (low < high)
    {
        //ѭ�������е�=���Խ������������к��������ֵ�ĳ���������
        while (low < high && arr[high] >= pivot)  //����Ӻ���ǰ�������ҵ��ȷָ�ֵС��Ԫ��
        {
            high--;  //ʹhighָ���Ԫ��
        }
        arr[low] = arr[high];  //�ȷָ�ֵС��Ԫ�ظ��ǵ�lowָ���Ԫ�أ�lowԭ��ָ���Ԫ���Ѿ������ָ�ֵ�洢��pivot�У�
        while (low < high && arr[low] <= pivot)  //�����ǰ���������ҵ��ȷָ�ֵ���Ԫ��
        {
            low++;  //ʹlowָ���Ԫ��
        }
        arr[high] = arr[low];  //�ȷָ�ֵ���Ԫ�ظ��ǵ�highָ���Ԫ�أ���ʱhighԭ��ָ���Ԫ���Ѿ�����lowָ���ǰһ��Ԫ�أ�
    }
    arr[low] = pivot;  //���ָ�ֵ��������Ԫ���м�λ�ã�low=high��
    return low;  //���ָ�ֵ��Ԫ�������±귵�ص�QucikSort������
}

void QucikSort(Elemtype arr[], int low, int high)  //low��ʾ��������ߵ�Ԫ�أ�high��ʾ�������ұߵ�Ԫ��
{
    if (low < high)  //���ָ�Ԫ���������ߵ������и�ֻʣ��һ��Ԫ��ʱ����low=highʱ�������ٽ�������
    {
        int pivot_pos = partition(arr, low, high);  //�洢�ָ�Ԫ�ص�λ�ã��ָ�Ԫ�ص��±꣩
        QucikSort(arr, low, pivot_pos - 1);  //�Էָ�Ԫ��֮ǰ��������п�������
        QucikSort(arr, pivot_pos + 1, high);  //�Էָ�Ԫ��֮���������п�������
    }
}

int main()
{
    SSTable ST;
    InitTable(ST, 10);
    //�������ʱʹ��
    //Elemtype arr[10] = { 64,94,95,79,69,84,18,22,12,78 };
    //memcpy(ST.arr, arr, sizeof(arr));
    //�ָ�������׳�������ʱӦ���ϵ���ڷָ�����õ���һ��
    //���Թ����п������ڴ���ͼ�в鿴��16���Ƶ�����Ԫ��
    Print(ST);
    QucikSort(ST.arr, 0, 9);
    Print(ST);
    return  0;
}