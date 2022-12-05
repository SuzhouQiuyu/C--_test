#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
//���Ķ���
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode, * BiTree;

//������������ʹ�ã�����������ʵ�ֵ�
typedef struct tag
{
    BiTree p;  //����ĳһ���ĵ�ַ����Ҫʹ��ָ��
    struct tag* pnext;  //�����е�nextָ�룬����ָ����һ���ڵ�
}tag_t, * ptag_t;

//���������������ʹ��
typedef BiTree Elemtype;
typedef struct LinkNode  //����
{
    Elemtype data;  //��������д�ŵ������Ľڵ�ָ�루BiTree���ͣ�
    struct LinkNode* next;
}LinkNode;
typedef struct  //����
{
    LinkNode* front, * rear;
}LinkQueue;

//��������
void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue& Q, Elemtype x);
bool DeQueue(LinkQueue& Q, Elemtype& x);
