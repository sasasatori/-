//
// Created by 28617 on 2019/5/24.
//

#include "stack.h"

char OPSET[9] = {'+','-','*','/','(',')','#','^','%'};

unsigned char Prior[9][9] = {
        /*'+'*/'>','>','<','<','<','>','>','<','<',
        /*'-'*/'>','>','<','<','<','>','>','<','<',
        /*'*'*/'>','>','>','>','<','>','>','<','>',
        /*'/'*/'>','>','>','>','<','>','>','<','>',
        /*'('*/'<','<','<','<','<','=',' ','<','<',
        /*')'*/'>','>','>','>',' ','>','>','>','>',
        /*'#'*/'<','<','<','<','<',' ','=','<','<',
        /*'^'*/'>','>','>','>','<','>','>','>','>',
        /*“%”*/'>','>','>','>','<','>','>','<','>'
};

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

int returnopord(char op)
{
    for(int i=0;i<9;i++)
        if(op == OPSET[i]) return i;
}

char priority(char A,char B)
{
    return Prior[returnopord(A)][returnopord(B)];
}

char opertor(int a,int b,char ch)
{
    int result = 0;
    switch (ch)
    {
        case '+':
        {
            result = (a-'0')+(b-'0');
            break;
        }
        case '-':
        {
            result = (a-'0')-(b-'0');
            break;
        }
        case '*':
        {
            result = (a-'0')*(b-'0');
            break;
        }
        case '/':
        {
            result = (a-'0')/(b-'0');
            break;
        }
        case '%':
        {
            result = (a-'0')%(b-'0');
            break;
        }
        case '^':
        {
            result = pow((a-'0'),(b-'0'));
        }
        default:
            break;
    }
    return result+'0';
}

char calculator(char *ch)
{
    SqStack number,operator;
    char a,b,theta,result,optop='0';
    InitStack(&number);
    InitStack(&operator);
    Push(&operator,'#');
    while(*ch != '#' || optop != '#')
    {
        //如果是操作数则压入操作数栈
        if(*ch > '0' && *ch < '9')
        {
            Push(&number,*ch);
            ch++;
        }
        else
        {
            char top;
            GetTop(operator,&top);
            switch (priority(top,*ch))
            {
                case '<':

                    Push(&operator,*ch);
                    ch++;
                    break;

                case '=':

                    Pop(&operator,ch);
                    ch++;
                    break;

                case '>':

                    Pop(&operator,&theta);
                    Pop(&number,&a);
                    Pop(&number,&b);
                    Push(&number,opertor(b,a,theta));
                    break;

            }
        }
        GetTop(operator,&optop);
    }
    GetTop(number,&result);
    return result;
}
