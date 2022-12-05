#define _CRT_SECURE_NO_WARNINGS
#include "function.h"

//前序遍历（深度优先遍历）
void PreOrder(BiTree tree)
{
    if (tree != NULL)
    {
        printf("%c", tree->data);  //打印当前节点
        PreOrder(tree->lchild);  //打印左子树
        PreOrder(tree->rchild);  //打印右子树
    }
}

//中序遍历
void InOrder(BiTree tree)
{
    if (tree != NULL)
    {
        InOrder(tree->lchild);  //打印左子树
        printf("%c", tree->data);  //打印当前节点
        InOrder(tree->rchild);  //打印右子树
    }
}

//后序遍历
void PostOrder(BiTree tree)
{
    if (tree != NULL)
    {
        PostOrder(tree->lchild);  //打印左子树
        PostOrder(tree->rchild);  //打印右子树
        printf("%c", tree->data);  //打印当前节点
    }
}

//层序遍历（广度优先遍历）
void LevelOrder(BiTree tree)
{
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;  //存储出队节点
    EnQueue(Q, tree);  //根节点入队
    while (!IsEmpty(Q))  //队列不为空则进入循环
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
    //层次建树
    BiTree pnew;  //pnew指向树申请的新节点的指针
    BiTree tree = NULL;  //tree指向树根（第一个节点，即根节点），用来代表树，树根需要初始化为NULL
    char data;  //要输入的元素（abcdefghij）
    ptag_t phead = NULL, ptail = NULL;  //队列头指针和队列尾指针初始化为NULL
    ptag_t list_pnew = NULL, pcur = NULL;  //辅助队列中list_pnew和树中pnew对应，pcur指向当前读进树中的节点的父亲节点
    while (scanf("%c", &data))  //把每一个字符作为树的节点存入树中
    {
        if (data == '\n')
        {
            break;  //读取输入内容时，末尾的\n不放入树
        }
        pnew = (BiTree)calloc(1, sizeof(BiTNode));  //每读入一个数据，都要开辟节点
        //使用malloc开辟节点时，读取的字符存在data中，但是左右孩子需要初始化为NULL，比较麻烦
        //calloc申请空间的大小是两个参数的乘积，calloc申请空间后会先将空间初始化为0
        pnew->data = data;  //将读进来的数据存进申请树的结构体的data中
        list_pnew = (ptag_t)calloc(1, sizeof(tag_t));  //该节点的地址放入辅助队列，给队列节点申请空间
        list_pnew->p = pnew;  //队列结构体中p存放的是树中对应结点pnew的地址
        //判断是否为树的第一个节点
        if (NULL == tree)  //当tree=NULL时，树为空，即此时树中开辟的节点是根节点，辅助队列中申请的是第一个节点
        {
            tree = pnew;  //树为空时，tree指向读入的第一个节点（根节点），其余字符读进来时tree不为空
            phead = ptail = list_pnew;  //起始时辅助队列中队列头和队列尾都指向第一个节点a
            pcur = list_pnew;  //pcur指向读入节点的父亲节点，只有一个根节点a时，pcur指向根节点a
        }
        else {
            //元素b先入队列
            ptail->pnext = list_pnew;  //读入新元素（b）的地址放在队列尾指针的pnext域
            ptail = list_pnew;  //新读入的元素b变为队列新的尾部，
            //节点b放入树中
            if (NULL == pcur->p->lchild)
            {
                pcur->p->lchild = pnew;  //当pcur指向的节点a的左孩子为NULL时，a的左孩子指向新节点b
            }
            else if (NULL == pcur->p->rchild)  //读入第三个元素c时
            {
                pcur->p->rchild = pnew;  //当pcur指向的节点a的左孩子不为NULL右孩子为NULL时，a的又孩子指向新节点c
                pcur = pcur->pnext;  //pcur->p即节点a的左右孩子都已经放了节点后，当前节点放满，pcur指向下一个节点b
            }
        }
    }
    printf("------------------前序遍历------------------\n");
    PreOrder(tree);
    printf("\n");
    printf("------------------中序遍历------------------\n");
    InOrder(tree);
    printf("\n");
    printf("------------------后序遍历------------------\n");
    PostOrder(tree);
    printf("\n");
    printf("------------------层序遍历------------------\n");
    LevelOrder(tree);
    printf("\n");
    return 0;
}