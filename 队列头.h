#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
//树的队列
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode, * BiTree;

//建树辅助队列使用，队列是链表实现的
typedef struct tag
{
    BiTree p;  //树的某一结点的地址，需要使用指针
    struct tag* pnext;  //链表中的next指针，用于指向下一个节点
}tag_t, * ptag_t;

//层序遍历辅助队列使用
typedef BiTree Elemtype;
typedef struct LinkNode  //链表
{
    Elemtype data;  //层序遍历中存放的是树的节点指针（BiTree类型）
    struct LinkNode* next;
}LinkNode;
typedef struct  //队列
{
    LinkNode* front, * rear;
}LinkQueue;

//函数调用
void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue& Q, Elemtype x);
bool DeQueue(LinkQueue& Q, Elemtype& x);
