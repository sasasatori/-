#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include <string.h>

#define TElemType   char
#define Nil         '#'
#define MAXSIZE    100

typedef enum {
    OK,
    OVERFLOW,
}Status;

/* c6-2.h 二叉树的二叉链表存储表示 */
typedef struct BiTNode
{
    TElemType data[MAXSIZE];
    struct BiTNode *lchild,*rchild; /* 左右孩子指针 */
}BiTNode,*BiTree;

int change(BiTree *tree);
int visit(BiTree *tree);
int animal_sys(void);
int working(BiTree *tree);

#endif