#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>

//#define MaxSize 50
//typedef	int Elemtype;  //����ElemSizeΪint���ͣ���ElemSize�����ͷ����ı�ʱ����Ѹ����ɴ����޸�
//typedef struct {
//	Elemtype data[MaxSize];
//	int length;  //˳�����
//}SqList;
//bool ListInsert(SqList& L, int i, Elemtype element)  //�����ı�˳���L
//{
//	if (i >= 1 && i <= L.length + 1)  //�жϲ���λ��i�Ƿ�Ϸ�
//	{
//		if (MaxSize >= L.length)  //�жϴ洢�ռ��Ƿ�����
//		{
//			for (int j = L.length; j >= i; j--)
//			{
//				L.data[j] = L.data[j - 1];  //Ҫ����λ�ú��Ԫ�غ���
//			}
//			L.data[i - 1] = element;  //����Ҫ�����Ԫ��
//			L.length++;  //�����˳���ĳ���+1
//			return true;  //����ɹ�����true
//		}
//	}
//	return false;
//}
//void PrintSqList(SqList L)  //��ӡ˳���
//{
//	for (int i = 0; i < L.length ; i++)
//	{
//		printf("%3d", L.data[i]);
//	}
//	printf("\n");
//}
//bool ListDelete(SqList& L, int i, Elemtype& del)  //ɾ����ı�˳���L��del��ȡɾ��Ԫ�ص�ֵ
//{
//	if (i < 1 || i > L.length + 1)  //�ж�ɾ��λ��i�Ƿ�Ϸ�
//	{
//		return false;
//	}
//	del = L.data[i - 1];
//	for (i; i <= L.length; i++)
//	{
//		L.data[i - 1] = L.data[i];
//	}
//	L.length--;
//}
//int LocateElem(SqList L, Elemtype element)  //����Ԫ��
//{
//	for (int i = 0; i < L.length; i++)
//	{
//		if (element == L.data[i])
//		{
//			return i + 1;  //i�������±꣬i+1�����˳�����±�
//		}
//	}
//	return 0;
//}
//int main()
//{
//	SqList L;  //����˳���L
//	bool ret;  //bool������
//	//˳���Ԫ�ض���
//	L.data[0] = 3;
//	L.data[1] = 12;
//	L.data[2] = 73;
//	L.data[3] = 84;
//	L.data[4] = 25;
//	L.data[5] = 65;
//	L.length = 6;  //����˳�����
//	PrintSqList(L);
//	ret = ListInsert(L, 2, 10);  //����˳���L��Ҫ�����λ�á�Ҫ�������ֵ
//	if (ret)  //trueֵΪ1��falseֵΪ0
//	{
//		printf("Insert SqList Success\n");
//		PrintSqList(L);
//	}
//	else
//	{
//		printf("Insert SqList failed\n");
//	}
//	Elemtype del;
//	ret = ListDelete(L, 3, del);  //����˳���L��Ҫɾ����λ�á�Ҫɾ������ֵ
//	if (ret)  //trueֵΪ1��falseֵΪ0
//	{
//		printf("Delete SqList Success\n");
//		PrintSqList(L);
//		printf("Ҫɾ����Ԫ���ǣ�%d\n", del);
//	}
//	else
//	{
//		printf("Delete SqList failed\n");
//	}
//	int pos;  //�洢Ԫ��λ��
//	pos = LocateElem(L, 824);
//	if (pos)
//	{
//		printf("Ҫ��ѯ��Ԫ��λ����˳����е�%d��\n",pos);
//	}
//	else
//	{
//		printf("˳�����û��Ҫ��ѯ��Ԫ��\n");
//	}
//	return 0;
//}

//��ʼ��˳���˳�����Ԫ��Ϊ���ͣ�����ߵ�Ԫ����1,2,3��
// Ȼ��ͨ��scanf��ȡһ��Ԫ�أ�����������6����
//���뵽��2��λ�ã���ӡ���˳���ÿ��Ԫ��ռ3���ո񣬸�ʽΪ1  6  2  3��
// Ȼ��scanf��ȡһ������������ɾ����λ�ã���������Ϊ1����
//Ȼ�����˳���  6  2  3�����������λ�ò��Ϸ������false�ַ���

//#include <stdio.h>
//#define MaxSize 10
//typedef int Elemtype;
//typedef struct {
//	Elemtype data[MaxSize];
//	int length;
//}SqList;
//bool SqListInsert(SqList& L, int a)
//{
//	int i = 1;
//	if (i > 0 && i < L.length + 1)
//	{
//		if (MaxSize >= L.length)
//		{
//			for (int j = L.length; j >= i; j--)
//			{
//				L.data[j] = L.data[j - 1];
//			}
//			L.data[i] = a;
//			L.length++;
//			return true;
//		}
//	}
//	return false;
//}
//int DeleList(SqList &L,int b)
//{
//	if (b > 0 && b <= L.length)
//	{
//		for (int i = b; i <= L.length; i++)
//		{
//			L.data[i - 1] = L.data[i];
//		}
//		L.length--;
//		L.data[L.length] = NULL;
//		return true;
//	}
//	else
//	{
//		return 0;
//	}
//}
//void Print(SqList L)
//{
//	int i = 0;
//	for (i = 0; i < L.length; i++)
//	{
//		printf("%3d", L.data[i]);
//	}
//	printf("\n");
//}
//int main() 
//{
//	SqList  L;
//	L.data[0] = 1;
//	L.data[1] = 2;
//	L.data[2] = 3;
//	L.length = 3;
//	int ret = 0;
//	int a = 0;
//	scanf("%d", &a);
//	ret	= SqListInsert(L,a);
//	if (ret)
//	{
//		Print(L);
//	}
//	else
//	{
//		printf("false\n");
//	}
//	int b = 0;
//	scanf("%d", &b);
//	ret = DeleList(L, b);
//	if (ret)
//	{
//		free(L.data[b]);
//		Print(L);
//	}
//	else
//	{
//		printf("false\n");
//	}
//	return 0;
//}


