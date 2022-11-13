#define _CRT_SECURE_NO_WARNINGS
////头插法，输入数据分别为3，4，5，6，7，9999,999表示输入结束，不作为数据
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int Elemtype;
//typedef struct LNode
//{
//	Elemtype data;
//	struct LNode* next;
//}LNode,*LinkList;
//LNode*是结构体指针，等同于LinkList，写*LinkList只是为了方便认为是链表而非结构体节点指针

//void list_head_insert(LNode* &L)
//{
//	L = (LinkList)malloc(sizeof(LNode));  //申请头节点空间（头指针指向头节点）
//	//malloc开辟的空间默认是void类型，上述代码中LinkList可以换成LNode*
//	Elemtype x;  //读取的元素值放在第一个节点上（头节点是空的），需要再申请一个节点
//	L->next = NULL;
//	scanf("%d", &x);
//	//申请第一个节点空间
//	LNode* s = (LinkList)malloc(sizeof(LNode));
//	s->data = x;
//	s->next = NULL;  //头插法中第一个创建的节点会变为最后一个节点，需要将next设置成NULL
//	L->next = s;  //使得L的next（指针域）指向第一个节点
//	while (x!=9999)
//	{
//		scanf("%d", &x);
//		s = (LinkList)malloc(sizeof(LNode));  //s指向新开辟的节点
//		s->data = x;
//		s->next = L->next;  //新节点的next值为头节点L的next，即指向上一个创建的节点
//		L->next = s;  //头节点的next指向新建的节点
//	}
//}
//
////上述函数在插入节点时会插入最后一个作为结束标志的9999的数据，函数改进如下：
//void list_head_insert(LNode*& L)
//{
//	L = (LinkList)malloc(sizeof(LNode));  //申请头节点空间（头指针指向头节点）
//	//malloc开辟的空间默认是void类型，上述代码中LinkList可以换成LNode*
//	Elemtype x;  //读取的元素值放在第一个节点上（头节点是空的），需要再申请一个节点
//	L->next = NULL;  //循环中将L的next赋给第一次循环创建的节点的next，即链表最后一个节点
//	scanf("%d", &x);  //供while循环判断是否结束
//	//申请第一个节点空间
//	LNode* s = (LinkList)malloc(sizeof(LNode));
//	while (x != 9999)
//	{
//		s = (LinkList)malloc(sizeof(LNode));  //s指向新开辟的节点
//		s->data = x;
//		s->next = L->next;  //新节点的next值为头节点L的next，即指向上一个创建的节点
//		L->next = s;  //头节点的next指向新建的节点（头插法新建的节点在头节点后面一个位置）
//		scanf("%d", &x);
//	}
//}
//
//void print_list(LinkList L)
//{
//	L = L->next;
//	while (L != NULL)
//	{
//		printf("%3d", L->data);
//		L = L->next;
//	}
//}
//int main()
//{
//	LinkList L;  //等同于LNode* L
//	list_head_insert(L);
//	print_list(L);
//	return 0;
//}


//尾插法，输入数据分别为3，4，5，6，7，9999,9999表示输入结束，不作为数据
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int Elemtype;
//typedef struct LNode
//{
//    Elemtype data;
//    struct LNode* next;
//}LNode, * Linklist;
//void linklist_tail_insert(LNode*& L)
//{
//    L = (LNode*)malloc(sizeof(LNode));  //头节点
//    L->next = NULL;
//    Elemtype x;
//    scanf("%d", &x);
//    LNode* s, * r = L;  //s指向新申请的节点，r始终指向链表尾部，起始时链表为空，r也和L一样指向头节点
//    while (x != 9999)
//    {
//        s = (LNode*)malloc(sizeof(LNode));  //为新节点申请空间
//        s->data = x;
//        r->next = s;  //r是LNode*类型的，同样具有data和next域
//        r = s;  //r变为新的尾部
//        scanf("%d", &x);
//    }
//    r->next = NULL;  //链表最后一个节点的next域为NULL
//}
//void print(LNode* L)
//{
//    L = L->next;
//    while (L != NULL)
//    {
//        printf("%3d", L->data);
//        L = L->next;
//    }
//}
////按位查找
//LNode* GetElem(LNode* L, Elemtype x)
//{
//    Elemtype i = 0;
//    if (x < 0)
//    {
//        return NULL;
//    }
//    while (L && i < x)  //while条件里L相当于L!=NULL
//    {
//        L = L->next;  //L指向下一个节点
//        i++;
//    }
//    return L;
//}
////按值查找
//LNode* LocateElem(LNode* L, Elemtype x)
//{
//    while (L)
//    {
//        L = L->next;  //向后遍历
//        if (L->data == x)
//        {
//            return L;  //找到对应值，返回此时节点的地址，即指针L
//        }
//    }
//    return NULL;
//}
//int main()
//{
//    LNode* L;
//    //linklist_head_insert(L);
//    linklist_tail_insert(L);
//    Linklist  search;  //search用来存储拿到的节点
//    search = GetElem(L, 2);  //查找第二个位置的数据
//    if (search != NULL)
//    {
//        printf("%d\n", search->data);
//    }
//    search = LocateElem(L, 6);  //查找值为6的数据
//    if (search != NULL)
//    {
//        printf("%d\n", search->data);
//    }
//    print(L);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int Elemtype;
//typedef struct LNode
//{
//	Elemtype data;
//	struct LNode* next;
//}LNode, * Linklist;
//void list_head_insert(Linklist& L) //头插法
//{
//	L = (LNode*)malloc(sizeof(LNode));   //头节点
//	Elemtype x;
//	L->next = NULL;
//	LNode* s = (LNode*)malloc(sizeof(LNode));
//	scanf("%d", &x);
// 	while (x != 9999)
//	{
//		s = (LNode*)malloc(sizeof(LNode));
//		s->data = x;
//		s->next = L->next;
//		L->next = s;
//		scanf("%d", &x);
//	}
//}
//void list_tail_insert(Linklist& L)
//{
//	L = (LNode*)malloc(sizeof(LNode));
//	L->next = NULL;
//	Linklist s,r = L;
//	Elemtype x;
//	scanf("%d", &x);
//	while (x != 9999)
//	{
//		s = (LNode*)malloc(sizeof(LNode));
//		r->next = s;
//		s->data = x;
//		r = s;
//		scanf("%d", &x);
//	}
//	r->next = NULL;
//}
//void print_list(LNode* L)
//{
//	L = L->next;
//	while (L != NULL)
//	{
//		printf("%3d", L->data);
//		L = L->next;
//	}
//	printf("\n");
//}
//int main()
//{
//	LNode* L;
//	list_head_insert(L);
//	print_list(L);
//	list_tail_insert(L);
//	print_list(L);
//}


//输入3 4 5 6 7 9999一串整数，9999代表结束，通过尾插法新建链表
//查找第二个位置的值并输出，在2个位置插入99，输出为  3 99  4  5  6  7
//删除第4个位置的值，打印输出为  3 99  4  6  7
#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct LNode
{
	Elemtype data;
	struct LNode* next;
}LNode, * Linklist;
//尾插法插入
void list_tail_insert(Linklist& L)
{
	L = (LNode*)malloc(sizeof(LNode));  //头节点
	L->next = NULL;
	LNode* s, * r = L;  //r->next=NULL;
	Elemtype x;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		r->next = s;
		s->data = x;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
}
//节点查找
LNode* value_find(LNode* L,Elemtype x)
{
	Elemtype a = 0;
	if (x < 0)
	{
		return NULL;
	}
	while (L && a < x)
	{
		L = L->next;
		a++;
	}
	/*printf("%d\n", L->data);*/
	return L;
}
//值插入
bool value_insert(LNode* L, Elemtype x, Elemtype y)  //在某位置上插入节点
{
	Elemtype i = 0;
	LNode* s = value_find(L, x - 1);  //找到要插入位置的前一个节点
	if (s == NULL)
	{
		return false;
	}
	LNode* q = (LNode*)malloc(sizeof(LNode));  //新节点
	q->data = y;
	q->next = s->next;
	s->next = q;
	return true;
}
//删除节点
bool Dele_list(LNode* L, Elemtype x)
{
	//1.调用位置查找函数
	//LNode* p = value_find(L, x - 1);  //要删除节点的前一个节点
	//if (p == NULL)
	//{
	//	return false;
	//}
	//LNode* q = p->next;  //要删除的节点
	//p->next = q->next;
	//free(q);
	//return true;
	//2.直接遍历查找
	Elemtype i = 0;
	while (L && i < x - 1)
	{
		L = L->next;
		i++;
	}
	LNode* s = L;
	L = L->next;
	s->next = L->next;
	free(L);
	return true;
}
//打印节点
void Print_list(LNode* L)
{
	L = L->next;
	while (L)
	{
		printf("%3d", L->data);
		L = L->next;
	}
	printf("\n");
}

int main()
{
	LNode* L;
	list_tail_insert(L);
	LNode* search = value_find(L, 2);
	if (search != NULL)
	{
		printf("%d\n", search->data);
	}
	int ret = 0;
	ret = value_insert(L, 2, 99);
	if (ret)
	{
		Print_list(L);
	}
	else
	{
		printf("false\n");
	}
	ret = Dele_list(L, 5);
	if (ret)
	{
		Print_list(L);
	}
	return 0;
}