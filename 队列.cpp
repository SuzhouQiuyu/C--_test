#define _CRT_SECURE_NO_WARNINGS
#include "function.h"

//���г�ʼ������ͷ�ڵ������ʵ��
void InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));  //ͷ�ڵ�
	Q.front->next = NULL;
}

//�ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q)
{
	return Q.front == Q.rear;  //�ж�Ϊ�棨��ȣ�����1��true��
}

//���
void EnQueue(LinkQueue& Q, Elemtype x)
{
	LinkNode* pnew = (LinkNode*)malloc(sizeof(LinkNode));
	pnew->data = x;
	pnew->next = NULL;
	Q.rear->next = pnew;  //ԭ��βrear��nextָ��NULL��pnew�Ӷ�β���룬rear��nextָ���¶�β
	Q.rear = pnew;  //rearָ���µĶ�β
}

//����
bool DeQueue(LinkQueue& Q, Elemtype& x)
{
	if (Q.front == Q.rear)
	{
		return false;
	}
	//x = Q.front->data;
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if (p == Q.rear)  //�ýڵ�Ϊ���������һ���ڵ�
	{
		Q.rear = Q.front;  //rearָ��frontָ��λ��
	}
	free(p);
	p = NULL;
	return true;
}