#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ElemType int
#define LIST_MAX_SIZE 100

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
Status ListDelete(LinkList L,int i);
int ListLength(LinkList L);

int main()
{
    LinkList list,q;
    int e,locate,length;
    char c;
    InitList(&list);
    InitList(&q);
    list->next = q;
    while(c != '\n')
    {
        scanf("%d",&(q->data));
        c = getchar();
        q->next = (LinkList)malloc(sizeof(struct LNode));
        q = q->next;
    }
    q->next = NULL;
    length = ListLength(list);
    scanf("%d",&e);
    locate = LocateElem(list,e);
    if(locate == 1)
    {
        printf("该结点没有前驱结点\n");
    }
    else
    {
        ListDelete(list,--locate);
        q = list->next;
        for (int j = 0; j < (length-2); ++j)
        {
            printf("%d",q->data);
            if(j != (length-3))printf(" ");
            q = q->next;
        }
        printf("\n");   ;
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

Status ListDelete(LinkList L,int i)
{
    int j=0;
    LinkList p=L,q;
    while(p->next&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p->next||j>i-1)
        return ERROR;
    q=p->next;
    p->next=q->next;
    free(q);
    return OK;
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
