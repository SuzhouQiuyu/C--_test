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
void find_mid(NODE* L, NODE*& L2)  //�ҵ������м�ڵ㲢���ú�L2
{
    L2 = (NODE*)malloc(sizeof(NODE));  //ΪL2����ͷ�ڵ�
    NODE* pppre, * pcur;
    pppre = pcur = L->next;  //pppreָ���м�ڵ㣬pcurָ�����һ���ڵ�
    while (pcur)  //ѭ����ĩβʱֹͣ
    {
        pcur = pcur->next;
        //����������������ÿ��һ������Ҫ�ж��Ƿ���������β��
        if (NULL == pcur)
        {
            break;
        }
        pcur = pcur->next;
        if (NULL == pcur)  //�ڵ���Ϊ����ʱ����Ҫ����жϣ�Ϊż��ʱ��Ҫ������pppre�����¶���һ��
        {
            break;
        }
        pppre = pppre->next;  //pcur���Գɹ������ߣ���pppreҲ���ԣ�����Ҫ�����ж�
    }
    //pppreָ���м�ڵ㣬����L��������һ���ڵ㣬pppre�Ժ�Ľڵ�����L2����
    L2->next = pppre->next;
    pppre->next = NULL;
}
void reverse(NODE*& L2)
{
    NODE* r, * s, * t;  //r��s��t�ֱ�ָ��L2��ǰ�����ڵ�
    r = L2->next;
    if (NULL == r)  //�ж������Ƿ�Ϊ�գ�û�нڵ㣩
    {
        return;
    }
    s = r->next;
    if (NULL == s)  //�ж��������Ƿ�ֻ��һ���ڵ�
    {
        return;
    }
    t = s->next;
    while (t)  //t����Ϊ�գ�tΪ�ղ�Ӱ������ָ��
    //while(t)��ͬ��while(t!=NULL)����ʾ�ڵ�t�����ڣ���t���������ָ���򶼲�����
    {
        s->next = r;  //�ڵ�����
        //����ָ��ͬʱ�����һ��
        r = s;
        s = t;
        t = t->next;  
        //����ѭ��ʱ�Ѿ�ȷ���ڵ�t�Ĵ��ڣ���t�����һ���ڵ�t->nextΪNULLʱ��whileѭ������
    }
    s->next = r;
    L2->next->next = NULL;  //L2ָ���һ���ڵ㣬���ú�ԭ���ĵ�һ���ڵ��Ϊ���һ����ָ����Ϊ��
    L2->next = s;  //��ʱ����ĵ�һ���ڵ��Ϊsָ��Ľڵ㣬ͷ�ڵ��nextָ�������һ���ڵ�
}

void merge(NODE* L, NODE* L2)  //L��L2������ͷ�ڵ㲻�䣬����Ҫ����&
{
    NODE* pcur, * p, * q;
    pcur = L->next;  //pcurָ���һ���ڵ�
    p = pcur->next;  //pҲ����ָ��pcur->next����p�ӵڶ����ڵ㿪ʼ��
    q = L2->next;
    while (q != NULL && p != NULL)  //while (q && p)
    {
        //pcurʼ��ָ��L��ĩβ��ÿ����L�з���һ���ڵ㣬pcur��Ҫ�����һ��
        pcur->next = q;
        q = q->next;  //q��������L2�б�
        pcur = pcur->next;  
        pcur->next = p;  //p��������L1�б�
        p = p->next;
        pcur = pcur->next;
    }

    //���������л�����һ��ʣ��ڵ�
    if (p==NULL)
    {
        pcur->next = q;
    }
    if(q==NULL)
    {
        pcur->next = p;
    }
    //�����£�
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
    find_mid(L, L2);  //L2ָ���м�ڵ�
    reverse(L2);
    print(L2);
    merge(L, L2);
    free(L2);
    print(L);
    return 0;
}