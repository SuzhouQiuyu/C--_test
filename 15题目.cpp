#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int keytype;
typedef struct Node
{
	keytype data;
	struct Node* lchild;
	struct Node* rchild;
}BSNode,*BiTree;

//����
void BSTreeInsert(BiTree& T, keytype x)
{
	BiTree NewNode = (BiTree)calloc(1, sizeof(BSNode));
	NewNode->data = x;
	if (NULL == T)
	{
		T = NewNode;
		return;
	}
	BiTree p = T;  //p�Ӹ���ʼѰ���½ڵ���λ��
	BiTree parent = NULL;
	while (p)
	{
		 parent = p;
		if (x < p->data)
		{
			p = p->lchild;
		}
		else
		{
			p = p->rchild;
		}
		//�����ǲ�������Ԫ����ȵ����
	}
	//�½ڵ����λ��
	if (x < parent->data)
	{
		parent->lchild = NewNode;
	}
	else
	{
		parent->rchild = NewNode;
	}
}
//��ȡ10��Ԫ�� 87 7 60 80 59 34 86 99 21 3��Ȼ�������������������������3 7 21 34 59 60 80 86 87 99��
//���������Ԫ�أ�����һ������Ϊ10�������У�ͨ���۰�����ҵ�21���±꣨�±�Ϊ2����Ȼ�����2
//�������������
void BSTree(BiTree& T, keytype* str, int len)
{
	int i = 0;
	for (i; i < len; i++)
	{
		BSTreeInsert(T, str[i]);
	}
}

//�������
void InOrder(BiTree T,int arr[10])
{
	static int i = 0;
	if (NULL == T)
	{
		return;
	}
	InOrder(T->lchild,arr);
	printf("%3d", T->data);
	arr[i] = T->data;
	i++;
	InOrder(T->rchild,arr);
}

//�۰����
int binary_search(int* arr, keytype x)
{
	int low = 0, high = 9, mid = (low + high) / 2;
	while (low <= high)
	{
		if (x < arr[mid])
		{
			high = mid - 1;
		}
		else if (x > arr[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
		mid = (low + high) / 2;
	}
}

int main()
{
	int str[10] = { 87,7,60,80,59,34,86,99,21,3 };
	BiTree T = NULL;
	BSTree(T, str, 10);
	int arr[10] = {};
	InOrder(T,arr);
	printf("\n");
	int a = 21;
	int ret = binary_search(arr,a);
	if (ret)
	{
		printf("%d", ret);
	}
	else
	{
		printf("û���ҵ�");
	}
	return 0;
}