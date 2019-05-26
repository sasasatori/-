//
// Created by Satori on 2019/5/26.
//

#ifndef TEST_STACK_H
#define TEST_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include <math.h>

#define SElemType char
#define MAX_LENGTH 100

typedef enum {
    OK,
}Status;

/* c3-1.h 栈的顺序存储表示 */
#define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
#define STACKINCREMENT 2 /* 存储空间分配增量 */
typedef struct SqStack
{
    SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
    SElemType *top; /* 栈顶指针 */
    int stacksize; /* 当前已分配的存储空间，以元素为单位 */
}SqStack; /* 顺序栈 */

Status InitStack(SqStack *S);

Status GetTop(SqStack S,SElemType *e);

Status Push(SqStack *S,SElemType e);

Status Pop(SqStack *S,SElemType *e);

char priority(char A,char B);

char opertor(int a,int b,char ch);

char calculator(char *ch);

#endif //TEST_STACK_H
