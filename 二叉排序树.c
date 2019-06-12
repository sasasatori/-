//
// Created by 28617 on 2019/5/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define  MAXSIZE 100

typedef struct BiTNode{// 二叉树的儿二叉链表结点结构

    int data; // 结点结构
    struct BiTNode * lchild,* rchild;  // 左右孩子指针

}BiTNode, * BiTree;

/**
 * 递归查找二叉排序树 T 中是否存在 key
 * 指针 f 指向 T 的 双亲，其初始调用值为NULL
 * 若查找成功，则指针 p 指向该数据元素结点，并返回TRUE
 * 若查找不成功， 则指针 p 指向查找路径上访问的最后一个结点并返回FALSE
 */
int SearchBST(BiTree T, int key, BiTree f, BiTree *p){

    if (!T) {  // 查找不成功
        *p = f;
        return FALSE;

    }else if (key == T->data){

        *p = T;
        return TRUE;

    }else if (key < T->data){  // 在左子树中继续查找

        return SearchBST(T->lchild, key, T, p);

    }else{  // 在右子树中鸡血查找

        return SearchBST(T->rchild, key, T, p);
    }
}

int InsertBST(BiTree * T, int key){

    BiTree p,s;

    if (!SearchBST( *T, key, NULL, &p)) {  // 没找到key

        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;

        if (!p)
            *T = s;  // 插入 s 为新的根结点
        else if (key < p->data)
            p->lchild = s;  //插入 s 为左孩子
        else
            p->rchild = s; // 插入 s 为右孩子

        return TRUE;
    }else
        return FALSE;
}

int Delete(BiTree *p){

    BiTree q, s;

    if ((*p)->rchild == NULL) {  // 右子树空 则只需要重接它的左子树

        q = *p;
        *p = (*p)->lchild;
        free(q);

    }else if ((*p)->lchild == NULL){  // 左子树空 则只需要重接它的右子树

        q = *p;
        *p = (*p)->rchild;
        free(q);

    }else{  // 左右子树都不空

        q = *p;
        s = (*p)->lchild;

        while (s->rchild) {  // 向右到尽头，找到待删结点的前驱

            q = s;
            s = s->rchild;
        }

        (*p)->data = s->data;  // s 指向被删除结点的直接前驱 （将被删结点前驱的值取代被删结点的值）

        if (q != *p)
            q->rchild = s->lchild;  // 重接 q 的右子树
        else
            q->lchild = s->lchild;  // 重接 q 的左子树

        free(s);
    }

    return TRUE;
}

/**
 * 二叉排序树的删除
 * 当二叉排序树中存在关键字等于 key 的数据元素时，删除该数据元素并返回TRUE
 */
int DeleteBST(BiTree * T, int key){

    if (!*T)   // 不存在关键字等于 key 的元素
        return FALSE;
    else{

        if (key == (*T)->data)
            return Delete(T);
        else if (key < (*T)->data)
            return DeleteBST(&(*T)->lchild, key);
        else
            return DeleteBST(&(*T)->rchild, key);
    }
}

/**
 * 中序递归遍历
 */
void InOrderTraverse(BiTree T){

    if (!T)
        return;

    InOrderTraverse(T->lchild);
    printf("%d  ", T->data);
    InOrderTraverse(T->rchild);
}

int main()
{
    int num;
    int del;
    int data[MAXSIZE];
    BiTree T=NULL;

    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",&data[i]);
        getchar();
    }

    scanf("%d",&del);

    printf("原始数据：");
    for(int i=0;i<num;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");

    for (int j = 0; j < num; ++j)
    {
        InsertBST(&T,data[j]);
    }

    printf("中序遍历结果：");
    InOrderTraverse(T);
    printf("\n");

    printf("删除结点后结果：");
    if(DeleteBST(&T,del))
    {
        InOrderTraverse(T);
        printf("\n");
    }
    else
    {
        printf("没有%d结点。\n",del);
    }
}
