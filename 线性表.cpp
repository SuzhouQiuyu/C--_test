#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>

//#define MaxSize 50
//typedef	int Elemtype;  //定义ElemSize为int类型，当ElemSize的类型发生改变时可以迅速完成代码修改
//typedef struct {
//	Elemtype data[MaxSize];
//	int length;  //顺序表长度
//}SqList;
//bool ListInsert(SqList& L, int i, Elemtype element)  //插入会改变顺序表L
//{
//	if (i >= 1 && i <= L.length + 1)  //判断插入位置i是否合法
//	{
//		if (MaxSize >= L.length)  //判断存储空间是否已满
//		{
//			for (int j = L.length; j >= i; j--)
//			{
//				L.data[j] = L.data[j - 1];  //要插入位置后的元素后移
//			}
//			L.data[i - 1] = element;  //放入要插入的元素
//			L.length++;  //插入后顺序表的长度+1
//			return true;  //插入成功返回true
//		}
//	}
//	return false;
//}
//void PrintSqList(SqList L)  //打印顺序表
//{
//	for (int i = 0; i < L.length ; i++)
//	{
//		printf("%3d", L.data[i]);
//	}
//	printf("\n");
//}
//bool ListDelete(SqList& L, int i, Elemtype& del)  //删除会改变顺序表L，del获取删除元素的值
//{
//	if (i < 1 || i > L.length + 1)  //判断删除位置i是否合法
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
//int LocateElem(SqList L, Elemtype element)  //查找元素
//{
//	for (int i = 0; i < L.length; i++)
//	{
//		if (element == L.data[i])
//		{
//			return i + 1;  //i是数组下标，i+1后才是顺序表的下标
//		}
//	}
//	return 0;
//}
//int main()
//{
//	SqList L;  //定义顺序表L
//	bool ret;  //bool是类型
//	//顺序表元素定义
//	L.data[0] = 3;
//	L.data[1] = 12;
//	L.data[2] = 73;
//	L.data[3] = 84;
//	L.data[4] = 25;
//	L.data[5] = 65;
//	L.length = 6;  //设置顺序表长度
//	PrintSqList(L);
//	ret = ListInsert(L, 2, 10);  //传入顺序表L、要插入的位置、要插入的数值
//	if (ret)  //true值为1，false值为0
//	{
//		printf("Insert SqList Success\n");
//		PrintSqList(L);
//	}
//	else
//	{
//		printf("Insert SqList failed\n");
//	}
//	Elemtype del;
//	ret = ListDelete(L, 3, del);  //传入顺序表L、要删除的位置、要删除的数值
//	if (ret)  //true值为1，false值为0
//	{
//		printf("Delete SqList Success\n");
//		PrintSqList(L);
//		printf("要删除的元素是：%d\n", del);
//	}
//	else
//	{
//		printf("Delete SqList failed\n");
//	}
//	int pos;  //存储元素位置
//	pos = LocateElem(L, 824);
//	if (pos)
//	{
//		printf("要查询的元素位置在顺序表中第%d个\n",pos);
//	}
//	else
//	{
//		printf("顺序表中没有要查询的元素\n");
//	}
//	return 0;
//}

//初始化顺序表（顺序表中元素为整型），里边的元素是1,2,3，
// 然后通过scanf读取一个元素（假如插入的是6），
//插入到第2个位置，打印输出顺序表，每个元素占3个空格，格式为1  6  2  3，
// 然后scanf读取一个整型数，是删除的位置（假如输入为1），
//然后输出顺序表  6  2  3，假如输入的位置不合法，输出false字符串

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


