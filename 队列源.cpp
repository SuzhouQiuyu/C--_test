#define _CRT_SECURE_NO_WARNINGS
#include "function.h"

//ǰ�������������ȱ�����
void PreOrder(BiTree tree)
{
    if (tree != NULL)
    {
        printf("%c", tree->data);  //��ӡ��ǰ�ڵ�
        PreOrder(tree->lchild);  //��ӡ������
        PreOrder(tree->rchild);  //��ӡ������
    }
}

//�������
void InOrder(BiTree tree)
{
    if (tree != NULL)
    {
        InOrder(tree->lchild);  //��ӡ������
        printf("%c", tree->data);  //��ӡ��ǰ�ڵ�
        InOrder(tree->rchild);  //��ӡ������
    }
}

//�������
void PostOrder(BiTree tree)
{
    if (tree != NULL)
    {
        PostOrder(tree->lchild);  //��ӡ������
        PostOrder(tree->rchild);  //��ӡ������
        printf("%c", tree->data);  //��ӡ��ǰ�ڵ�
    }
}

//���������������ȱ�����
void LevelOrder(BiTree tree)
{
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;  //�洢���ӽڵ�
    EnQueue(Q, tree);  //���ڵ����
    while (!IsEmpty(Q))  //���в�Ϊ�������ѭ��
    {
        DeQueue(Q, p);
        putchar(p->data);
        if (NULL != p->lchild)
        {
            EnQueue(Q, p->lchild);
        }
        if (NULL != p->rchild)
        {
            EnQueue(Q, p->rchild);
        }

    }
}

int main()
{
    //��ν���
    BiTree pnew;  //pnewָ����������½ڵ��ָ��
    BiTree tree = NULL;  //treeָ����������һ���ڵ㣬�����ڵ㣩��������������������Ҫ��ʼ��ΪNULL
    char data;  //Ҫ�����Ԫ�أ�abcdefghij��
    ptag_t phead = NULL, ptail = NULL;  //����ͷָ��Ͷ���βָ���ʼ��ΪNULL
    ptag_t list_pnew = NULL, pcur = NULL;  //����������list_pnew������pnew��Ӧ��pcurָ��ǰ�������еĽڵ�ĸ��׽ڵ�
    while (scanf("%c", &data))  //��ÿһ���ַ���Ϊ���Ľڵ��������
    {
        if (data == '\n')
        {
            break;  //��ȡ��������ʱ��ĩβ��\n��������
        }
        pnew = (BiTree)calloc(1, sizeof(BiTNode));  //ÿ����һ�����ݣ���Ҫ���ٽڵ�
        //ʹ��malloc���ٽڵ�ʱ����ȡ���ַ�����data�У��������Һ�����Ҫ��ʼ��ΪNULL���Ƚ��鷳
        //calloc����ռ�Ĵ�С�����������ĳ˻���calloc����ռ����Ƚ��ռ��ʼ��Ϊ0
        pnew->data = data;  //�������������ݴ���������Ľṹ���data��
        list_pnew = (ptag_t)calloc(1, sizeof(tag_t));  //�ýڵ�ĵ�ַ���븨�����У������нڵ�����ռ�
        list_pnew->p = pnew;  //���нṹ����p��ŵ������ж�Ӧ���pnew�ĵ�ַ
        //�ж��Ƿ�Ϊ���ĵ�һ���ڵ�
        if (NULL == tree)  //��tree=NULLʱ����Ϊ�գ�����ʱ���п��ٵĽڵ��Ǹ��ڵ㣬����������������ǵ�һ���ڵ�
        {
            tree = pnew;  //��Ϊ��ʱ��treeָ�����ĵ�һ���ڵ㣨���ڵ㣩�������ַ�������ʱtree��Ϊ��
            phead = ptail = list_pnew;  //��ʼʱ���������ж���ͷ�Ͷ���β��ָ���һ���ڵ�a
            pcur = list_pnew;  //pcurָ�����ڵ�ĸ��׽ڵ㣬ֻ��һ�����ڵ�aʱ��pcurָ����ڵ�a
        }
        else {
            //Ԫ��b�������
            ptail->pnext = list_pnew;  //������Ԫ�أ�b���ĵ�ַ���ڶ���βָ���pnext��
            ptail = list_pnew;  //�¶����Ԫ��b��Ϊ�����µ�β����
            //�ڵ�b��������
            if (NULL == pcur->p->lchild)
            {
                pcur->p->lchild = pnew;  //��pcurָ��Ľڵ�a������ΪNULLʱ��a������ָ���½ڵ�b
            }
            else if (NULL == pcur->p->rchild)  //���������Ԫ��cʱ
            {
                pcur->p->rchild = pnew;  //��pcurָ��Ľڵ�a�����Ӳ�ΪNULL�Һ���ΪNULLʱ��a���ֺ���ָ���½ڵ�c
                pcur = pcur->pnext;  //pcur->p���ڵ�a�����Һ��Ӷ��Ѿ����˽ڵ�󣬵�ǰ�ڵ������pcurָ����һ���ڵ�b
            }
        }
    }
    printf("------------------ǰ�����------------------\n");
    PreOrder(tree);
    printf("\n");
    printf("------------------�������------------------\n");
    InOrder(tree);
    printf("\n");
    printf("------------------�������------------------\n");
    PostOrder(tree);
    printf("\n");
    printf("------------------�������------------------\n");
    LevelOrder(tree);
    printf("\n");
    return 0;
}