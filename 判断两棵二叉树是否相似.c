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
Status Compare(BiTree T_1,BiTree T_2);  
  
int main()  
{  
    BiTree tree_1,tree_2;  
    CreateBiTree(&tree_1);  
    getchar();  
    CreateBiTree(&tree_2);  
    if(Compare(tree_1,tree_2))  
        printf("A与B相似\n");  
    else  
        printf("A与B不相似\n");  
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
  
Status Compare(BiTree T_1,BiTree T_2)  
{  
    Status left,right;  
    if(T_1 == NULL && T_2 == NULL)  
    {  
        return OK;  
    }  
    else if(T_1 == NULL || T_2 == NULL)  
    {  
        return ERROR;  
    }  
  
    left = Compare(T_1->lchild,T_2->lchild);  
    right = Compare(T_1->rchild,T_2->rchild);  
  
    if(left == OK && right == OK)  
        return OK;  
    else  
        return ERROR;  
} 