#define _CRT_SECURE_NO_WARNINGS
////ͷ�巨���������ݷֱ�Ϊ3��4��5��6��7��9999,999��ʾ�������������Ϊ����
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int Elemtype;
//typedef struct LNode
//{
//	Elemtype data;
//	struct LNode* next;
//}LNode,*LinkList;
//LNode*�ǽṹ��ָ�룬��ͬ��LinkList��д*LinkListֻ��Ϊ�˷�����Ϊ��������ǽṹ��ڵ�ָ��

//void list_head_insert(LNode* &L)
//{
//	L = (LinkList)malloc(sizeof(LNode));  //����ͷ�ڵ�ռ䣨ͷָ��ָ��ͷ�ڵ㣩
//	//malloc���ٵĿռ�Ĭ����void���ͣ�����������LinkList���Ի���LNode*
//	Elemtype x;  //��ȡ��Ԫ��ֵ���ڵ�һ���ڵ��ϣ�ͷ�ڵ��ǿյģ�����Ҫ������һ���ڵ�
//	L->next = NULL;
//	scanf("%d", &x);
//	//�����һ���ڵ�ռ�
//	LNode* s = (LinkList)malloc(sizeof(LNode));
//	s->data = x;
//	s->next = NULL;  //ͷ�巨�е�һ�������Ľڵ���Ϊ���һ���ڵ㣬��Ҫ��next���ó�NULL
//	L->next = s;  //ʹ��L��next��ָ����ָ���һ���ڵ�
//	while (x!=9999)
//	{
//		scanf("%d", &x);
//		s = (LinkList)malloc(sizeof(LNode));  //sָ���¿��ٵĽڵ�
//		s->data = x;
//		s->next = L->next;  //�½ڵ��nextֵΪͷ�ڵ�L��next����ָ����һ�������Ľڵ�
//		L->next = s;  //ͷ�ڵ��nextָ���½��Ľڵ�
//	}
//}
//
////���������ڲ���ڵ�ʱ��������һ����Ϊ������־��9999�����ݣ������Ľ����£�
//void list_head_insert(LNode*& L)
//{
//	L = (LinkList)malloc(sizeof(LNode));  //����ͷ�ڵ�ռ䣨ͷָ��ָ��ͷ�ڵ㣩
//	//malloc���ٵĿռ�Ĭ����void���ͣ�����������LinkList���Ի���LNode*
//	Elemtype x;  //��ȡ��Ԫ��ֵ���ڵ�һ���ڵ��ϣ�ͷ�ڵ��ǿյģ�����Ҫ������һ���ڵ�
//	L->next = NULL;  //ѭ���н�L��next������һ��ѭ�������Ľڵ��next�����������һ���ڵ�
//	scanf("%d", &x);  //��whileѭ���ж��Ƿ����
//	//�����һ���ڵ�ռ�
//	LNode* s = (LinkList)malloc(sizeof(LNode));
//	while (x != 9999)
//	{
//		s = (LinkList)malloc(sizeof(LNode));  //sָ���¿��ٵĽڵ�
//		s->data = x;
//		s->next = L->next;  //�½ڵ��nextֵΪͷ�ڵ�L��next����ָ����һ�������Ľڵ�
//		L->next = s;  //ͷ�ڵ��nextָ���½��Ľڵ㣨ͷ�巨�½��Ľڵ���ͷ�ڵ����һ��λ�ã�
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
//	LinkList L;  //��ͬ��LNode* L
//	list_head_insert(L);
//	print_list(L);
//	return 0;
//}


//β�巨���������ݷֱ�Ϊ3��4��5��6��7��9999,9999��ʾ�������������Ϊ����
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
//    L = (LNode*)malloc(sizeof(LNode));  //ͷ�ڵ�
//    L->next = NULL;
//    Elemtype x;
//    scanf("%d", &x);
//    LNode* s, * r = L;  //sָ��������Ľڵ㣬rʼ��ָ������β������ʼʱ����Ϊ�գ�rҲ��Lһ��ָ��ͷ�ڵ�
//    while (x != 9999)
//    {
//        s = (LNode*)malloc(sizeof(LNode));  //Ϊ�½ڵ�����ռ�
//        s->data = x;
//        r->next = s;  //r��LNode*���͵ģ�ͬ������data��next��
//        r = s;  //r��Ϊ�µ�β��
//        scanf("%d", &x);
//    }
//    r->next = NULL;  //�������һ���ڵ��next��ΪNULL
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
////��λ����
//LNode* GetElem(LNode* L, Elemtype x)
//{
//    Elemtype i = 0;
//    if (x < 0)
//    {
//        return NULL;
//    }
//    while (L && i < x)  //while������L�൱��L!=NULL
//    {
//        L = L->next;  //Lָ����һ���ڵ�
//        i++;
//    }
//    return L;
//}
////��ֵ����
//LNode* LocateElem(LNode* L, Elemtype x)
//{
//    while (L)
//    {
//        L = L->next;  //������
//        if (L->data == x)
//        {
//            return L;  //�ҵ���Ӧֵ�����ش�ʱ�ڵ�ĵ�ַ����ָ��L
//        }
//    }
//    return NULL;
//}
//int main()
//{
//    LNode* L;
//    //linklist_head_insert(L);
//    linklist_tail_insert(L);
//    Linklist  search;  //search�����洢�õ��Ľڵ�
//    search = GetElem(L, 2);  //���ҵڶ���λ�õ�����
//    if (search != NULL)
//    {
//        printf("%d\n", search->data);
//    }
//    search = LocateElem(L, 6);  //����ֵΪ6������
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
//void list_head_insert(Linklist& L) //ͷ�巨
//{
//	L = (LNode*)malloc(sizeof(LNode));   //ͷ�ڵ�
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


//����3 4 5 6 7 9999һ��������9999���������ͨ��β�巨�½�����
//���ҵڶ���λ�õ�ֵ���������2��λ�ò���99�����Ϊ  3 99  4  5  6  7
//ɾ����4��λ�õ�ֵ����ӡ���Ϊ  3 99  4  6  7
#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct LNode
{
	Elemtype data;
	struct LNode* next;
}LNode, * Linklist;
//β�巨����
void list_tail_insert(Linklist& L)
{
	L = (LNode*)malloc(sizeof(LNode));  //ͷ�ڵ�
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
//�ڵ����
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
//ֵ����
bool value_insert(LNode* L, Elemtype x, Elemtype y)  //��ĳλ���ϲ���ڵ�
{
	Elemtype i = 0;
	LNode* s = value_find(L, x - 1);  //�ҵ�Ҫ����λ�õ�ǰһ���ڵ�
	if (s == NULL)
	{
		return false;
	}
	LNode* q = (LNode*)malloc(sizeof(LNode));  //�½ڵ�
	q->data = y;
	q->next = s->next;
	s->next = q;
	return true;
}
//ɾ���ڵ�
bool Dele_list(LNode* L, Elemtype x)
{
	//1.����λ�ò��Һ���
	//LNode* p = value_find(L, x - 1);  //Ҫɾ���ڵ��ǰһ���ڵ�
	//if (p == NULL)
	//{
	//	return false;
	//}
	//LNode* q = p->next;  //Ҫɾ���Ľڵ�
	//p->next = q->next;
	//free(q);
	//return true;
	//2.ֱ�ӱ�������
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
//��ӡ�ڵ�
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