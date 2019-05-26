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
void PreOrderTraverse(BiTree T);
Status InOrderTraverse1(BiTree T);
void PostOrderTraverse(BiTree T);

int main()
{
    BiTree tree;
    CreateBiTree(&tree);
    printf("前序遍历结果：");
    PreOrderTraverse(tree);
    printf("\n");
    printf("中序遍历结果：");
    InOrderTraverse1(tree);
    printf("\n");
    printf("后序遍历结果：");
    PostOrderTraverse(tree);
    printf("\n");
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

typedef BiTree SElemType; /* 设栈元素为二叉树的指针类型 */
/* c3-1.h 栈的顺序存储表示 */
#define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
#define STACKINCREMENT 2 /* 存储空间分配增量 */
typedef struct SqStack
{
    SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
    SElemType *top; /* 栈顶指针 */
    int stacksize; /* 当前已分配的存储空间，以元素为单位 */
}SqStack; /* 顺序栈 */

/* bo3-1.c 顺序栈（存储结构由c3-1.h定义）的基本操作（9个） */
Status InitStack(SqStack *S)
{ /* 构造一个空栈S */
    (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!(*S).base)
        exit(OVERFLOW); /* 存储分配失败 */
    (*S).top=(*S).base;
    (*S).stacksize=STACK_INIT_SIZE;
    return OK;
}

Status StackEmpty(SqStack S)
{ /* 若栈S为空栈，则返回TRUE，否则返回FALSE */
    if(S.top==S.base)
        return OK;
    else
        return ERROR;
}

Status Push(SqStack *S,SElemType e)
{ /* 插入元素e为新的栈顶元素 */
    if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */
    {
        (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!(*S).base)
            exit(OVERFLOW); /* 存储分配失败 */
        (*S).top=(*S).base+(*S).stacksize;
        (*S).stacksize+=STACKINCREMENT;
    }
    *((*S).top)++=e;
    return OK;
}

Status Pop(SqStack *S,SElemType *e)
{ /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
    if((*S).top==(*S).base)
        return ERROR;
    *e=*--(*S).top;
    return OK;
}

void PreOrderTraverse(BiTree T)
{ /* 初始条件: 二叉树T存在,Visit是对结点操作的应用函数。算法6.1，有改动 */
    /* 操作结果: 先序递归遍历T,对每个结点调用函数Visit一次且仅一次 */
    if(T) /* T不空 */
    {
        printf("%c ",T->data); /* 先访问根结点 */
        PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
        PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
    }
}

Status InOrderTraverse1(BiTree T)
{ /* 采用二叉链表存储结构，Visit是对数据元素操作的应用函数。算法6.3 */
    /* 中序遍历二叉树T的非递归算法(利用栈)，对每个数据元素调用函数Visit */
    SqStack S;
    InitStack(&S);
    while(T||!StackEmpty(S))
    {
        if(T)
        { /* 根指针进栈,遍历左子树 */
            Push(&S,T);
            T=T->lchild;
        }
        else
        { /* 根指针退栈,访问根结点,遍历右子树 */
            Pop(&S,&T);
            printf("%c ",T->data);
            T=T->rchild;
        }
    }
    return OK;
}

void PostOrderTraverse(BiTree T)
{ /* 初始条件: 二叉树T存在,Visit是对结点操作的应用函数 */
    /* 操作结果: 后序递归遍历T,对每个结点调用函数Visit一次且仅一次 */
    if(T) /* T不空 */
    {
        PostOrderTraverse(T->lchild); /* 先后序遍历左子树 */
        PostOrderTraverse(T->rchild); /* 再后序遍历右子树 */
        printf("%c ",T->data); /* 最后访问根结点 */
    }
}
