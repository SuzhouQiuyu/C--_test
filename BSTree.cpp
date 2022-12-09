#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int Keytype;
//������Ľڵ�
typedef struct BSTNode
{
    Keytype data;
    struct BSTNode* lchild;
    struct BSTNode* rchild;
}BSTNode, * BiTree;

//�ǵݹ鷽ʽ��������������
//�����������Ľڵ����
int BST_Insert(BiTree& T, Keytype k)
{
    BiTree TreeNew = (BiTree)calloc(1, sizeof(BSTNode));  //�ڵ����󴴽��ڵ�洢������Ŀռ�
    TreeNew->data = k;
    if (NULL == T)
    {
        T = TreeNew;  //��Ϊ��ʱ���½ڵ�TreeNew��Ϊ����
        return 0;
    }
    BiTree p = T, parent = NULL;  //��������ʱʹ��p��������ʼ�����½ڵ�TreeNewӦ�ô�ŵ�λ��
    while (p)
    {
        parent = p;  //parentΪp�ĸ��ڵ�
        //������Ԫ����ȵ����
        if (k < p->data)
        {
            p = p->lchild;  //p��ΪNULL
            //k=T->lchild->data;
        }
        else if (k > T->data)
        {
            p = p->rchild;  //p��ΪNULL
            //k=T->rchild->data;
        }
        else
        {
            return -1;  //Ԫ�����
        }
    }
    //whileѭ��������p�ҵ�Ӧ�ô�ŵ�λ��
    //�ж��½ڵ�TreeNew����parent��λ��
    if (k < parent->data)
    {
        parent->lchild = TreeNew;  //С�ڷ��ڸ��ڵ����
    }
    else {
        parent->rchild = TreeNew;  //���ڷ��ڸ��ڵ��ұ�
    }
    return 0;
}

//�����������Ĵ���
void CreatBSTree(BiTree& T, Keytype* str, int len)  //��������ָ�룬len��ʾ������Ԫ�ظ���
{
    //ÿ��������������з���һ���ڵ�
    int i;
    for (i = 0; i < len; i++)
    {
        BST_Insert(T, str[i]);  //����֧���Ӻ�������
        //����CreatBSTreeʹ�����÷��ţ�ʵ�����ò��������ں���CreatBSTree�е�BST_Insert��
    }
}

//�������������������
void InOrder(BiTree T)
{
    if (NULL != T)
    {
        InOrder(T->lchild);
        printf("%3d", T->data);
        InOrder(T->rchild);
    }
}

//����
BiTree BST_Search(BiTree T, Keytype k, BiTree& parent)  //parentֵ��ı�
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
    BiTree T = NULL;  //ָ��������ָ��
    Keytype str[7] = { 54,20,66,40,28,79,58 };
    CreatBSTree(T, str, 7);
    InOrder(T);  //�������������������������С�����
    printf("\n");
    BiTree search, parent;
    search = BST_Search(T, 66, parent);  //�ҵ��󷵻ز���ֵ��λ�ú͸��ڵ�
    if (search)
    {
        printf("find key %d\n", search->data);
    }
    else {
        printf("not find\n");
    }
    return 0;
}