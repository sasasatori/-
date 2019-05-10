#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ElemType int

typedef enum {
    ERROR,
    OK,
    OVERFLOW
}Status;

struct LNode
{
    ElemType data;
    struct LNode *next;
};
typedef struct LNode *LinkList;

Status InitList(LinkList *L);
int LocateElem(LinkList L,ElemType e);
int ListLength(LinkList L);

int main()
{
    LinkList list_1,list_2,list_3,p,q,m;
    char c,d;
    int length;
    InitList(&list_1);
    InitList(&list_2);
    InitList(&list_3);
    InitList(&p);
    InitList(&q);
    InitList(&m);
    list_1->next = p;
    list_2->next = q;
    list_3->next = m;
    while(c != '\n')
    {
        scanf("%d",&(p->data));
        c = getchar();
        p->next = (LinkList)malloc(sizeof(struct LNode));
        p = p->next;
    }
    p->next = NULL;
    p = list_1->next;

    while(d != '\n')
    {
        scanf("%d",&(q->data));
        d = getchar();
        q->next = (LinkList)malloc(sizeof(struct LNode));
        q = q->next;
    }
    q->next = NULL;
    q = list_2->next;

    while(p->next != NULL)
    {
        if(LocateElem(list_2,p->data)!=0)
        {
            m->data = p->data;
            m->next = (LinkList)malloc(sizeof(struct LNode));
            m = m->next;
        }
        p = p->next;
    }
    m->next = NULL;
    m = list_3->next;
    length = ListLength(list_3);
    if(length == 1)
    {
        printf("没有交集\n");
    }
    else
    {
        for (int i = 0; i < (length-1); ++i)
        {
            printf("%d ",m->data);
            m = m->next;
        }
        printf("\n");
    }
    return 0;
}

Status InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(struct LNode));
    if(!*L)
        exit(OVERFLOW);
    (*L)->next=NULL;
    return OK;
}

int LocateElem(LinkList L,ElemType e)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data == e)
            return i;
        p=p->next;
    }
    return 0;
}

int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}
