#define _CRT_SECURE_NO_WARNINGS
#include "function.h"

//队列初始化，带头节点的链表实现
void InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));  //头节点
	Q.front->next = NULL;
}

//判断队列是否为空
bool IsEmpty(LinkQueue Q)
{
	return Q.front == Q.rear;  //判断为真（相等）返回1（true）
}

//入队
void EnQueue(LinkQueue& Q, Elemtype x)
{
	LinkNode* pnew = (LinkNode*)malloc(sizeof(LinkNode));
	pnew->data = x;
	pnew->next = NULL;
	Q.rear->next = pnew;  //原队尾rear的next指向NULL，pnew从队尾插入，rear的next指向新队尾
	Q.rear = pnew;  //rear指向新的队尾
}

//出队
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
	if (p == Q.rear)  //该节点为链表中最后一个节点
	{
		Q.rear = Q.front;  //rear指向front指向位置
	}
	free(p);
	p = NULL;
	return true;
}