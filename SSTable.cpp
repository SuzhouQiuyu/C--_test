#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Elemtype;
typedef struct
{
    Elemtype* elem;  //����ָ��
    int TableElem;  //�洢�ڶ�̬�����е�Ԫ�ظ���
}SSTable;
//��������ʼ����û��ʹ���ڱ�
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
//��ӡ�����
void PrintTable(SSTable ST)
{
    int i = 0;
    for (i; i < ST.TableElem; i++)
    {
        printf("%3d", ST.elem[i]);
    }
    printf("\n");
}
//���ֲ���
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

//������compare�д���ź�����ڵ�ַ���Ǻ���ָ������
int compare(const void* left, const void* right)
{
    return *(int*)left - *(int*)right;  //��С��������(int*)��ʾǿ������ת����*��ʾ�����ã�ͨ����ַ�ҵ�ָ��ָ���Ԫ��
    //��������򣬼�left��right�󣬷�����ֵ������ǽ���left��rightС�����ظ�ֵ��left��right��ȣ�����0
    //return *(int*)right-*(int*)left;  //�Ӵ�С����
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
