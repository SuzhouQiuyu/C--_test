#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int Keytype;
//存放树的节点
typedef struct BSTNode
{
    Keytype data;
    struct BSTNode* lchild;
    struct BSTNode* rchild;
}BSTNode, * BiTree;

//非递归方式创建二叉排序树
//二叉排序树的节点插入
int BST_Insert(BiTree& T, Keytype k)
{
    BiTree TreeNew = (BiTree)calloc(1, sizeof(BSTNode));  //节点进入后创建节点存储新申请的空间
    TreeNew->data = k;
    if (NULL == T)
    {
        T = TreeNew;  //树为空时，新节点TreeNew作为树根
        return 0;
    }
    BiTree p = T, parent = NULL;  //树根存在时使用p从树根开始查找新节点TreeNew应该存放的位置
    while (p)
    {
        parent = p;  //parent为p的父节点
        //不考虑元素相等的情况
        if (k < p->data)
        {
            p = p->lchild;  //p置为NULL
            //k=T->lchild->data;
        }
        else if (k > T->data)
        {
            p = p->rchild;  //p置为NULL
            //k=T->rchild->data;
        }
        else
        {
            return -1;  //元素相等
        }
    }
    //while循环结束后p找到应该存放的位置
    //判断新节点TreeNew放在parent的位置
    if (k < parent->data)
    {
        parent->lchild = TreeNew;  //小于放在父节点左边
    }
    else {
        parent->rchild = TreeNew;  //大于放在父节点右边
    }
    return 0;
}

//二叉排序树的创建
void CreatBSTree(BiTree& T, Keytype* str, int len)  //数组名是指针，len表示，数组元素个数
{
    //每次向二叉排序树中放入一个节点
    int i;
    for (i = 0; i < len; i++)
    {
        BST_Insert(T, str[i]);  //引用支持子函数传递
        //函数CreatBSTree使用引用符号，实际引用操作发生在函数CreatBSTree中的BST_Insert内
    }
}

//二叉排序树的中序遍历
void InOrder(BiTree T)
{
    if (NULL != T)
    {
        InOrder(T->lchild);
        printf("%3d", T->data);
        InOrder(T->rchild);
    }
}

//查找
BiTree BST_Search(BiTree T, Keytype k, BiTree& parent)  //parent值会改变
{
    parent = NULL;
    while (NULL != T && k != T->data)
    {
        parent = T;
        if (k < T->data)
        {
            T = T->lchild;
        }
        else {
            T = T->rchild;
        }
    }
    return T;
}

int main()
{
    BiTree T = NULL;  //指向树根的指针
    Keytype str[7] = { 54,20,66,40,28,79,58 };
    CreatBSTree(T, str, 7);
    InOrder(T);  //二叉排序树中序遍历后结果是由小到大的
    printf("\n");
    BiTree search, parent;
    search = BST_Search(T, 66, parent);  //找到后返回查找值的位置和父节点
    if (search)
    {
        printf("find key %d\n", search->data);
    }
    else {
        printf("not find\n");
    }
    return 0;
}