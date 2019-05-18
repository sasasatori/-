#include "APIs.h"

//
// Created by 28617 on 2019/5/17.
//

//一个全局的链表
LinkList student_information;

//讨来的API

Status InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(struct LNode));
    if(!*L)
        exit(OVERFLOW);
    (*L)->next=NULL;
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

Status ListInsert(LinkList L,int i,ElemType e)
{
    int j=0;
    LinkList p=L,s;
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i-1)
        return ERROR;
    s=(LinkList)malloc(sizeof(struct LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

Status ListDelete(LinkList L,int i,ElemType *e)
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
    *e=q->data;
    free(q);
    return OK;
}

//下面是自己写的功能函数
Status load_in_information(void)
{
    char user_choice;
    LinkList p;
    int count;
    InitList(&student_information);
    InitList(&p);
    student_information->next = p;
    printf("please input your choice (number 1 or 2)\n");
    printf("(1)load in from input\t(2)load in from file\n");
    user_choice = getchar();
    switch (user_choice)
    {
        case '1':
        {
            printf("input the number of information to load in\n");
            scanf("%d",&count);
            printf("input the following information\n");
            for(int i=0; i<count; i++)
            {
                p->data.num = i+1;
                printf("please input the data of student-%d\n",p->data.num);
                printf("ID: ");
                scanf("%d",&p->data.ID);
                printf("name: ");
                scanf("%s",p->data.name);
                for(int j=0; j<5 ; j++)
                {
                    printf("score of lesson%d ",j+1);
                    scanf("%d",&p->data.score[j]);
                }
                p->next = (LinkList)malloc(sizeof(struct LNode));
                p = p->next;
            }
            p->next = NULL;
            break;
        }

        case '2':
        {
            FILE *fpRead=fopen("test.txt","r");
            int counter=0;
            if(fpRead==NULL)
            {
                return 0;
            }
            fgetc(fpRead);
            while(1)
            {
                if(feof(fpRead) == 0)
                {
                    p->data.num = ++counter;
                    fscanf(fpRead,"ID: %d\n",&p->data.ID);
                    fscanf(fpRead,"name: %s\n",p->data.name);
                    for (int i = 0; i < 5; i++)
                    {
                        fscanf(fpRead,"the score of lesson");
                        fgetc(fpRead);
                        fscanf(fpRead,": %d\n",&p->data.score[i]);
                    }
                    p->next = (LinkList)malloc(sizeof(struct LNode));
                    p = p->next;
                }
                else break;
            }
            p->next = NULL;
            fclose(fpRead);
            break;
        }

        default:
        {
            printf("wrong number :<\n");
            break;
        }
    }

}

Status add_information(void)
{
    LinkList p;
    InitList(&p);
    student_t student;
    int locate;
    int count = 1;
    p = student_information->next;
    printf("please input a number between 2 - %d\ndata will be inserted at the place of number\n",ListLength(student_information));
    scanf("%d",&locate);
    printf("please input the data of student-%d\n",locate);
    student.num = locate;
    printf("ID: ");
    scanf("%d",&student.ID);
    printf("name: ");
    scanf("%s",student.name);
    for(int j=0; j<5 ; j++)
    {
        printf("score of lesson%d ",j+1);
        scanf("%d",&student.score[j]);
    }
    ListInsert(student_information,locate,student);
    //插入之后num的顺序就乱了，因此需要遍历locate后面的元素，修改所有的num
    while(p->next != NULL)
    {
        p->data.num = count++;
        p = p->next;
    }
    save_information();
}

Status change_information(void)
{
    char user_choice;
    LinkList p;
    InitList(&p);
    p = student_information->next;
    printf("please input your choice (number 1 or 2 or 3)\n");
    printf("(1)search and change by number\t(2)search and change by ID\n");
    printf("(3)search and change by name\n");
    user_choice = getchar();
    getchar();
    switch (user_choice)
    {
        case '1':
        {
            int num;
            printf("input the num\n");
            scanf("%d",&num);
            while(p)
            {
                if(p->data.num == num)
                {
                    printf("\ndata of student-%d will be changed\n",p->data.num);
                    printf("please input the data of student-%d\n",p->data.num);
                    printf("ID: ");
                    scanf("%d",&p->data.ID);
                    printf("name: ");
                    scanf("%s",p->data.name);
                    for(int j=0; j<5 ; j++)
                    {
                        printf("score of lesson%d ",j+1);
                        scanf("%d",&p->data.score[j]);
                    }
                    break;
                }
                else
                {
                    p = p->next;
                }
            }
            if(p == NULL) printf("NOT FOUND!!\n");
            break;
        }

        case '3':
        {
            char name[name_max_length];
            printf("input the name\n");
            scanf("%s",name);
            while(p)
            {
                if(strcmp(p->data.name,name) == 0)
                {
                    printf("\ndata of student name:%s will be changed\n",p->data.name);
                    printf("please input the data of student-%d\n",p->data.num);
                    printf("ID: ");
                    scanf("%d",&p->data.ID);
                    printf("name: ");
                    scanf("%s",p->data.name);
                    for(int j=0; j<5 ; j++)
                    {
                        printf("score of lesson%d ",j+1);
                        scanf("%d",&p->data.score[j]);
                    }
                    break;
                }
                else
                {
                    p = p->next;
                }
            }
            if(p == NULL) printf("NOT FOUND!!\n");
            break;
        }

        case '2':
        {
            int ID;
            printf("input the ID\n");
            scanf("%d",&ID);
            while(p)
            {
                if(p->data.num == ID)
                {
                    printf("\ndata of student ID:%d will be changed\n",p->data.ID);
                    printf("please input the data of student-%d\n",p->data.num);
                    printf("ID: ");
                    scanf("%d",&p->data.ID);
                    printf("name: ");
                    scanf("%s",p->data.name);
                    for(int j=0; j<5 ; j++)
                    {
                        printf("score of lesson%d ",j+1);
                        scanf("%d",&p->data.score[j]);
                    }
                    break;
                }
                else
                {
                    p = p->next;
                }
            }
            if(p == NULL) printf("NOT FOUND!!\n");
            break;
        }

        default:
        {
            printf("wrong number :<\n");
            break;
        }
    }
    save_information();
}

Status delete_information(void)
{
    LinkList p;
    InitList(&p);
    student_t student;
    int locate;
    int count = 1;
    p = student_information->next;
    printf("please input a number between 1 - %d\ndata will be deleted at the place of number\n",ListLength(student_information)-1);
    scanf("%d",&locate);
    ListDelete(student_information,locate,&student);
    while(p->next != NULL)
    {
        p->data.num = count++;
        p = p->next;
    }
    save_information();
}

Status search_information(void)
{
    char user_choice;
    LinkList p;
    InitList(&p);
    p = student_information->next;
    printf("please input your choice (number 1 or 2 or 3)\n");
    printf("(1)search by number\t(2)search by ID\n");
    printf("(3)search by name\n");
    user_choice = getchar();
    getchar();
    switch (user_choice)
    {
        case '1':
        {
            int num;
            printf("input the num\n");
            scanf("%d",&num);
            while(p->next != NULL)
            {
                if(p->data.num == num)
                {
                    printf("\ndata of student-%d\n",p->data.num);
                    printf("ID: %d\n",p->data.ID);
                    printf("name: %s\n",p->data.name);
                    for(int j=0; j<5 ; j++)
                    {
                        printf("score of lesson%d \n",p->data.score[j]);
                    }
                    break;
                }
                else
                {
                    p = p->next;
                }
            }
            if(p == NULL) printf("NOT FOUND!!\n");
            break;
        }

        case '3':
        {
            char name[name_max_length];
            printf("input the name\n");
            scanf("%s",name);
            while(p)
            {
                if(strcmp(p->data.name,name) == 0)
                {
                    printf("\ndata of student-%d\n",p->data.num);
                    printf("ID: %d\n",p->data.ID);
                    printf("name: %s\n",p->data.name);
                    for(int j=0; j<5 ; j++)
                    {
                        printf("score of lesson%d \n",p->data.score[j]);
                    }
                    break;
                }
                else
                {
                    p = p->next;
                }
            }
            if(p == NULL) printf("NOT FOUND!!\n");
            break;
        }

        case '2':
        {
            int ID;
            printf("input the ID\n");
            scanf("%d",&ID);
            while(p->next != NULL)
            {
                if(p->data.num == ID)
                {
                    printf("\ndata of student-%d\n",p->data.num);
                    printf("ID: %d\n",p->data.ID);
                    printf("name: %s\n",p->data.name);
                    for(int j=0; j<5 ; j++)
                    {
                        printf("score of lesson%d \n",p->data.score[j]);
                    }
                    break;
                }
                else
                {
                    p = p->next;
                }
            }
            if(p == NULL) printf("NOT FOUND!!\n");
            break;
        }

        default:
        {
            printf("wrong number :<\n");
            break;
        }
    }
}

Status output_information(void)
{
    LinkList p;
    InitList(&p);
    p = student_information->next;
    while(p->next != NULL)
    {
        printf("\ndata of student-%d\n",p->data.num);
        printf("ID: %d\n",p->data.ID);
        printf("name: %s\n",p->data.name);
        for(int j=0; j<5 ; j++)
        {
            printf("score of lesson%d is %d\n",j+1,p->data.score[j]);
        }
        p = p->next;
    }
    p->next = NULL;
    save_information();
}

Status save_information(void)
{
    LinkList p;
    InitList(&p);
    p = student_information->next;

    FILE *fpWrite=fopen("test.txt","w");

    if(fpWrite==NULL)
    {
        return 0;
    }
    while(p->next != NULL)
    {
        fprintf(fpWrite,"\nID: %d\n",p->data.ID);
        fprintf(fpWrite,"name: %s\n",p->data.name);

        for (int i = 0; i < 4; i++)
        {
            fprintf(fpWrite,"the score of lesson%d: %d\n",i+1,p->data.score[i]);
        }
        fprintf(fpWrite,"the score of lesson5: %d",p->data.score[4]);
        p = p->next;
    }
    fclose(fpWrite);
}
