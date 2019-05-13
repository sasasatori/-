#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define SElemType char

typedef enum {
    ERROR,
    OK,
    OVERFLOW,
    TRUE = 1,
    FALSE = 0
}Status;
/* c3-1.h 栈的顺序存储表示 */
#define STACK_INIT_SIZE 40 /* 存储空间初始分配量 */
#define STACKINCREMENT 2 /* 存储空间分配增量 */

typedef struct SqStack
{
    SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
    SElemType *top; /* 栈顶指针 */
    int stacksize; /* 当前已分配的存储空间，以元素为单位 */
}SqStack; /* 顺序栈 */

/*API*/
Status InitStack(SqStack *S);
Status StackEmpty(SqStack S);
Status Pop(SqStack *S,SElemType *e);
Status Push(SqStack *S,SElemType e);
Status GetTop(SqStack S,SElemType *e);

/*主函数*/
int main()
{
    SqStack stack;
    char str[STACK_INIT_SIZE],ch;
    int i=0;
    InitStack(&stack);
    gets(str);
    while(str[i] != '\0')
    {
        if(str[i]=='{' || str[i]=='}' || str[i]=='[' || str[i]==']' || str[i]=='(' || str[i]==')')
        {
            if(str[i]==')')
            {
                GetTop(stack,&ch);
                if(ch == '(')
                {
                    Pop(&stack,&ch);
                }
                else
                    break;
            }
            else if(str[i]==']')
            {
                GetTop(stack,&ch);
                if(ch == '[')
                {
                    Pop(&stack,&ch);
                }
                else
                    break;
            }
            else if(str[i]=='}')
            {
                GetTop(stack,&ch);
                if(ch == '{')
                {
                    Pop(&stack,&ch);
                }
                else
                    break;
            }
            else
                Push(&stack,str[i]);
        }
        i++;
    }
    if(StackEmpty(stack)) printf("括号配对\n");
    else printf("括号不配对\n");
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

Status GetTop(SqStack S,SElemType *e)
{ /* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
    if(S.top>S.base)
    {
        *e=*(S.top-1);
        return OK;
    }
    else
        return ERROR;
}
