//
// Created by 28617 on 2019/5/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TElemType   char

typedef enum {
    ERROR,
    OK,
    OVERFLOW
}Status;


/* c6-2.h 二叉树的二叉链表存储表示 */
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild; /* 左右孩子指针 */
}BiTNode,*BiTree;

void CreateBiTree(BiTree *T);
int BiTreeDepth(BiTree T);
int BiTreeLeave(BiTree T);

int main()
{
    BiTree tree;
    int depth,leave;
    CreateBiTree(&tree);
    leave = BiTreeLeave(tree);
    printf("leafs=%d\n",leave);
    depth = BiTreeDepth(tree);
    printf("Depth=%d\n",depth);
    return 0;
}

void CreateBiTree(BiTree *T)
{ /* 算法6.4:按先序次序输入二叉树中结点的值（可为字符型或整型，在主程中 */
    /* 定义），构造二叉链表表示的二叉树T。变量Nil表示空（子）树。有改动 */
    TElemType ch;
    scanf("%c",&ch);
    if(ch == '#') /* 空 */
        *T=NULL;
    else
    {
        *T=(BiTree)malloc(sizeof(BiTNode));
        if(!*T)
            exit(OVERFLOW);
        (*T)->data=ch; /* 生成根结点 */
        CreateBiTree(&(*T)->lchild); /* 构造左子树 */
        CreateBiTree(&(*T)->rchild); /* 构造右子树 */
    }
}

int BiTreeDepth(BiTree T)
{ /* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
    int i,j;
    if(!T)
        return 0;
    if(T->lchild)
        i=BiTreeDepth(T->lchild);
    else
        i=0;
    if(T->rchild)
        j=BiTreeDepth(T->rchild);
    else
        j=0;
    return i>j?i+1:j+1;
}

int BiTreeLeave(BiTree T)
{
    static int i=0;
    if(T)
    {
        if((T->lchild == NULL) && (T->rchild == NULL)) i++;
        BiTreeLeave(T->lchild);
        BiTreeLeave(T->rchild);
    }
    return i;
}
