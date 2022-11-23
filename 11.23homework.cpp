#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5

typedef int Elemtype;
typedef struct
{
	Elemtype data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack& S)
{
	S.top = -1;
 }
void Push(SqStack& S, Elemtype& x)  //入栈
{
	if (S.top != MaxSize - 1)
	{
		S.data[++S.top] = x;
	}
}
void Pop(SqStack& S, Elemtype& x)  //出栈
{
	if (-1 != S.top)
	{
		x = S.data[S.top--];
	}
}
//循环队列
typedef struct
{
	Elemtype data[MaxSize];
	int front, rear;
}SqQueue;
void InitSqQueue(SqQueue& Q)
{
	Q.front = Q.rear = 0;
}
bool EnQueue(SqQueue& Q, Elemtype x)  //入队
{
	if ((Q.rear + 1) % MaxSize == Q.front)
	{
		return false;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}
bool DeQueue(SqQueue& Q,Elemtype& x)  //出队
{
	if (Q.front == Q.rear)
	{
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}
int main()
{
	SqStack S;
	int x = 0;  //保存输入值
	int i = 0;  //遍历
	InitStack(S);
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &x);
		Push(S, x);
	}
	for (i = 0; i < 3; i++)
	{
		Pop(S, x);
		printf("%2d", x);
	}
	printf("\n");
	SqQueue Q;
	InitSqQueue(Q);
	bool ret;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &x);
		ret = EnQueue(Q, x);
		if (ret == 0)
		{
			printf("false\n");
		}
	}
	for (i = 0; i < 4; i++)
	{
		ret = DeQueue(Q, x);
		if (ret == 0)
		{
			printf("false\n");
		}
		printf("%2d", x);
	}
	return 0;
}