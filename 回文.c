#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define SElemType char
#define QElemType char

typedef enum {
    ERROR,
    OK,
    OVERFLOW,
    TRUE = 1,
    FALSE = 0
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
/* bo3-1.c 顺序栈（存储结构由c3-1.h定义）的基本操作（9个） */
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
    QueuePtr front,rear; /* 队头、队尾指针 */
}LinkQueue;

/*API*/
Status InitStack(SqStack *S);
Status StackEmpty(SqStack S);
Status Pop(SqStack *S,SElemType *e);
Status Push(SqStack *S,SElemType e);
Status InitQueue(LinkQueue *Q);
Status DeQueue(LinkQueue *Q,QElemType *e);
Status EnQueue(LinkQueue *Q,QElemType e);

/*主函数*/
int main()
{
    SqStack stack;
    LinkQueue queue;
    InitStack(&stack);
    InitQueue(&queue);
    char c[STACK_INIT_SIZE],s=0,q=0;
    int i=0;
    gets(c);
    while(c[i] != '\0')
    {
        Push(&stack,c[i]);
        EnQueue(&queue,c[i]);
        i++;
    }
    while(s == q)
    {
        Pop(&stack,&s);
        DeQueue(&queue,&q);
        if(StackEmpty(stack))break;
    }
    if(StackEmpty(stack)) printf("是回文\n");
    else printf("不是回文\n");
    return 0;
}

/*函数实现*/
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
        return TRUE;
    else
        return FALSE;
}

Status Pop(SqStack *S,SElemType *e)
{ /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
    if((*S).top==(*S).base)
        return ERROR;
    *e=*--(*S).top;
    return OK;
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

/* bo3-2.c 链队列(存储结构由c3-2.h定义)的基本操作(9个) */
Status InitQueue(LinkQueue *Q)
{ /* 构造一个空队列Q */
    (*Q).front=(*Q).rear=(QueuePtr)malloc(sizeof(QNode));
    if(!(*Q).front)
        exit(OVERFLOW);
    (*Q).front->next=NULL;
    return OK;
}

Status DeQueue(LinkQueue *Q,QElemType *e)
{ /* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
    QueuePtr p;
    if((*Q).front==(*Q).rear)
        return ERROR;
    p=(*Q).front->next;
    *e=p->data;
    (*Q).front->next=p->next;
    if((*Q).rear==p)
        (*Q).rear=(*Q).front;
    free(p);
    return OK;
}

Status EnQueue(LinkQueue *Q,QElemType e)
{ /* 插入元素e为Q的新的队尾元素 */
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) /* 存储分配失败 */
        exit(OVERFLOW);
    p->data=e;
    p->next=NULL;
    (*Q).rear->next=p;
    (*Q).rear=p;
    return OK;
}
