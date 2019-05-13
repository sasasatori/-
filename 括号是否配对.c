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
/* c3-1.h ջ��˳��洢��ʾ */
#define STACK_INIT_SIZE 40 /* �洢�ռ��ʼ������ */
#define STACKINCREMENT 2 /* �洢�ռ�������� */

typedef struct SqStack
{
    SElemType *base; /* ��ջ����֮ǰ������֮��base��ֵΪNULL */
    SElemType *top; /* ջ��ָ�� */
    int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ */
}SqStack; /* ˳��ջ */

/*API*/
Status InitStack(SqStack *S);
Status StackEmpty(SqStack S);
Status Pop(SqStack *S,SElemType *e);
Status Push(SqStack *S,SElemType e);
Status GetTop(SqStack S,SElemType *e);

/*������*/
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
    if(StackEmpty(stack)) printf("�������\n");
    else printf("���Ų����\n");
    return 0;
}

/*����ʵ��*/
Status InitStack(SqStack *S)
{ /* ����һ����ջS */
    (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!(*S).base)
        exit(OVERFLOW); /* �洢����ʧ�� */
    (*S).top=(*S).base;
    (*S).stacksize=STACK_INIT_SIZE;
    return OK;
}

Status StackEmpty(SqStack S)
{ /* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
    if(S.top==S.base)
        return TRUE;
    else
        return FALSE;
}

Status Pop(SqStack *S,SElemType *e)
{ /* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
    if((*S).top==(*S).base)
        return ERROR;
    *e=*--(*S).top;
    return OK;
}

Status Push(SqStack *S,SElemType e)
{ /* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
    if((*S).top-(*S).base>=(*S).stacksize) /* ջ����׷�Ӵ洢�ռ� */
    {
        (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!(*S).base)
            exit(OVERFLOW); /* �洢����ʧ�� */
        (*S).top=(*S).base+(*S).stacksize;
        (*S).stacksize+=STACKINCREMENT;
    }
    *((*S).top)++=e;
    return OK;
}

Status GetTop(SqStack S,SElemType *e)
{ /* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
    if(S.top>S.base)
    {
        *e=*(S.top-1);
        return OK;
    }
    else
        return ERROR;
}
