#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}NODE;
void insert_list(NODE*& L)
{
    L = (NODE*)malloc(sizeof(NODE));
    L->next = NULL;
    int x;
    scanf("%d", &x);
    NODE* s, * t;
    t = L;
    while (x != 9999)
    {
        s = (NODE*)malloc(sizeof(NODE));
        t->next = s;
        s->data = x;
        t = s;
        scanf("%d", &x);
    }
    t->next = NULL;
}
void find_mid(NODE* L, NODE*& L2)  //找到链表中间节点并设置好L2
{
    L2 = (NODE*)malloc(sizeof(NODE));  //为L2申请头节点
    NODE* pppre, * pcur;
    pppre = pcur = L->next;  //pppre指向中间节点，pcur指向最后一个节点
    while (pcur)  //循环到末尾时停止
    {
        pcur = pcur->next;
        //不能连续走两步，每走一步后需要判断是否来到链表尾部
        if (NULL == pcur)
        {
            break;
        }
        pcur = pcur->next;
        if (NULL == pcur)  //节点数为奇数时不需要这个判断，为偶数时需要，否则pppre会向下多走一步
        {
            break;
        }
        pppre = pppre->next;  //pcur可以成功向下走，则pppre也可以，不需要再做判断
    }
    //pppre指向中间节点，属于L链表的最后一个节点，pppre以后的节点属于L2链表
    L2->next = pppre->next;
    pppre->next = NULL;
}
void reverse(NODE*& L2)
{
    NODE* r, * s, * t;  //r、s、t分别指向L2的前三个节点
    r = L2->next;
    if (NULL == r)  //判断链表是否为空（没有节点）
    {
        return;
    }
    s = r->next;
    if (NULL == s)  //判断链表中是否只有一个节点
    {
        return;
    }
    t = s->next;
    while (t)  //t可以为空，t为空不影响其他指针
    //while(t)等同于while(t!=NULL)，表示节点t不存在，即t的数据域和指针域都不存在
    {
        s->next = r;  //节点逆置
        //三个指针同时向后走一步
        r = s;
        s = t;
        t = t->next;  
        //进入循环时已经确保节点t的存在，当t是最后一个节点t->next为NULL时，while循环跳出
    }
    s->next = r;
    L2->next->next = NULL;  //L2指向第一个节点，逆置后原来的第一个节点变为最后一个，指针域为空
    L2->next = s;  //此时链表的第一个节点变为s指向的节点，头节点的next指向链表第一个节点
}

void merge(NODE* L, NODE* L2)  //L和L2的两个头节点不变，不需要引用&
{
    NODE* pcur, * p, * q;
    pcur = L->next;  //pcur指向第一个节点
    p = pcur->next;  //p也可以指向pcur->next，即p从第二个节点开始加
    q = L2->next;
    while (q != NULL && p != NULL)  //while (q && p)
    {
        //pcur始终指向L的末尾，每次向L中放入一个节点，pcur都要向后走一步
        pcur->next = q;
        q = q->next;  //q用来遍历L2列表
        pcur = pcur->next;  
        pcur->next = p;  //p用来遍历L1列表
        p = p->next;
        pcur = pcur->next;
    }

    //两个链表中会有其一有剩余节点
    if (p==NULL)
    {
        pcur->next = q;
    }
    if(q==NULL)
    {
        pcur->next = p;
    }
    //或如下：
    //if (p != NULL)
    //{
    //    pcur->next = p;
    //}
    //if (q != NULL)
    //{
    //    pcur->next = q;
    //}
}

void print(NODE* L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%3d", L->data);
        L = L->next;
    }
    printf("\n");
}
int main()
{
    NODE* L;
    insert_list(L);
    print(L);
    NODE* L2 = NULL;
    find_mid(L, L2);  //L2指向中间节点
    reverse(L2);
    print(L2);
    merge(L, L2);
    free(L2);
    print(L);
    return 0;
}