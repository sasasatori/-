#include "lib.h"

SqList library;

void InsertSort(SqList *L)
 { /* 对顺序表L作直接插入排序。算法10.1 */
   int i,j;
   for(i=2;i<=(*L).length;++i)
     if LT((*L).r[i].key,(*L).r[i-1].key) /* "<",需将L.r[i]插入有序子表 */
     {
       (*L).r[0]=(*L).r[i]; /* 复制为哨兵 */
       for(j=i-1;LT((*L).r[0].key,(*L).r[j].key);--j)
	 (*L).r[j+1]=(*L).r[j]; /* 记录后移 */
       (*L).r[j+1]=(*L).r[0]; /* 插入到正确位置 */
     }
 }

int search(SqList L,int key)
{
    int i;
    int flag = 0;
    for (i = 1; i <= L.length; i++)
    {
        if((int)L.r[i].key == key)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        return i;
    }
    else
    {
        return 0;
    }
}

int delete(SqList *L,int key)
{
    int num = search(*L,key);
    if(num == 0)
    return 0;
    else
    {
        for(int i = num;i<L->length;i++)
        {
            L->r[i] = L->r[i+1];
        }
        L->length--;
        return 1;
    }
}

 int load_in_information(void)
{
    int  num;
   printf("please input the number of book you will load in\n") ;
   scanf("%d",&num);
   getchar();
   library.length = num;
    for (int i = 1; i <= num; i++)
    {
        printf("please input  the catagory of the book-%d\n",i);
        scanf("%c",&library.r[i].otherinfo.catagory);
        getchar();
        printf("please input the name of the book-%d\n",i);
        scanf("%s",library.r[i].otherinfo.name);
        getchar();
        printf("please input the writer of the book-%d\n",i);
        scanf("%s",library.r[i].otherinfo.writer);
        getchar();
        printf("please input the date of the book-%d\n",i);
        scanf("%s",library.r[i].otherinfo.date);
        getchar();
        printf("please input the price of the book-%d\n",i);
        scanf("%f",&library.r[i].otherinfo.price);
        getchar();
        printf("\n");
    }
    printf("load done\n");
}

int add_information(void)
{
    int length = library.length;
    printf("please input  the catagory of the book-%d\n",length+1);
    scanf("%c",&library.r[length].otherinfo.catagory);
    getchar();
    printf("please input the name of the book-%d\n",length+1);
    scanf("%s",library.r[length].otherinfo.name);
    getchar();
    printf("please input the writer of the book-%d\n",length+1);
    scanf("%s",library.r[length].otherinfo.writer);
    getchar();
    printf("please input the date of the book-%d\n",length+1);
    scanf("%s",library.r[length].otherinfo.date);
    getchar();
    printf("please input the price of the book-%d\n",length+1);
    scanf("%f",&library.r[length+1].otherinfo.price);
    getchar();
    library.length++;
    printf("add done\n");
    printf("\n");
}

int change_information(void)
{
    char user_choice;
    char key_1;
    int key_2;

    printf("input your wanna keyword\n");
    printf("1.catagory  2.price\n");
    user_choice = getchar();
    getchar();
    switch (user_choice)
    {
    case '1':
        for (int i = 1; i <= library.length; i++)
        {
            library.r[i].key = library.r[i].otherinfo.catagory;
        }
        InsertSort(&library);
        for (int i = 1; i <= library.length; i++)
        {
            printf("the catagory of the book-%d----%c\n",i,library.r[i].otherinfo.catagory);
             printf("\n");
        }
    break;
    
    case '2':
        for (int i = 1; i <= library.length; i++)
        {
            library.r[i].key = library.r[i].otherinfo.price;
        }
        InsertSort(&library);
        for (int i = 1; i <= library.length; i++)
        {
            printf("the price of the book-%d----%f\n",i,library.r[i].otherinfo.price);
            printf("\n");
        }
    break;

    default:
        printf("error input\n");
        break;
    }

    printf("please input the keyword of the book you wanna change\n");

    switch (user_choice)
    {
    case '1':
        scanf("%c",&key_1);
        getchar();
        int num = search(library,key_1);
        if(num == 0)
        printf("not found\n");
        else
        {
            printf("please input  the catagory of the book-%d\n",num);
            scanf("%c",&library.r[num].otherinfo.catagory);
            getchar();
            printf("please input the name of the book-%d\n",num);
            scanf("%s",library.r[num].otherinfo.name);
            getchar();
            printf("please input the writer of the book-%d\n",num);
            scanf("%s",library.r[num].otherinfo.writer);
            getchar();
            printf("please input the date of the book-%d\n",num);
            scanf("%s",library.r[num].otherinfo.date);
            getchar();
            printf("please input the price of the book-%d\n",num);
            scanf("%f",&library.r[num].otherinfo.price);
            getchar();
        }
    break;
    
    case '2':
        scanf("%d",&key_2);
        getchar();
        int num_1 = search(library,key_2);
        if(num_1 == 0)
        printf("not found\n");
        else
        {
            printf("please input  the catagory of the book-%d\n",num_1);
            scanf("%c",&library.r[num_1].otherinfo.catagory);
            getchar();
            printf("please input the name of the book-%d\n",num_1);
            scanf("%s",library.r[num_1].otherinfo.name);
            getchar();
            printf("please input the writer of the book-%d\n",num_1);
            scanf("%s",library.r[num_1].otherinfo.writer);
            getchar();
            printf("please input the date of the book-%d\n",num_1);
            scanf("%s",library.r[num_1].otherinfo.date);
            getchar();
            printf("please input the price of the book-%d\n",num_1);
            scanf("%f",&library.r[num_1].otherinfo.price);
            getchar();
        }
    break;

    default:
        printf("error input\n");
        break;
    }
}

int delete_information(void)
{
    char user_choice;
    char key_1;
    int key_2;

    printf("input your wanna keyword\n");
    printf("1.catagory  2.price\n");
    user_choice = getchar();
    getchar();
    switch (user_choice)
    {
    case '1':
        for (int i = 1; i <= library.length; i++)
        {
            library.r[i].key = library.r[i].otherinfo.catagory;
        }
        InsertSort(&library);
        for (int i = 1; i <= library.length; i++)
        {
            printf("the catagory of the book-%d----%c\n",i,library.r[i].otherinfo.catagory);
             printf("\n");
        }
    break;
    
    case '2':
        for (int i = 1; i <= library.length; i++)
        {
            library.r[i].key = library.r[i].otherinfo.price;
        }
        InsertSort(&library);
        for (int i = 1; i <= library.length; i++)
        {
            printf("the price of the book-%d----%f\n",i,library.r[i].otherinfo.price);
            printf("\n");
        }
    break;

    default:
        printf("error input\n");
        break;
    }

    printf("please input the keyword of the book you wanna delete\n");

    switch (user_choice)
    {
    case '1':
        scanf("%c",&key_1);
        getchar();
        int num = search(library,key_1);
        if(num == 0)
        printf("not found\n");
        else
        {
            delete(&library,key_1);
        }
    break;
    
    case '2':
        scanf("%d",&key_2);
        getchar();
        int num_1 = search(library,key_2);
        if(num_1 == 0)
        printf("not found\n");
        else
        {
            delete(&library,key_2);
        }
    break;

    default:
        printf("error input\n");
        break;
    }
}

int search_information(void)
{
    char user_choice;
    char key_1;
    int key_2;

    printf("input your wanna keyword\n");
    printf("1.catagory  2.price\n");
    user_choice = getchar();
    getchar();
    switch (user_choice)
    {
    case '1':
        for (int i = 1; i <= library.length; i++)
        {
            library.r[i].key = library.r[i].otherinfo.catagory;
        }
        InsertSort(&library);
        for (int i = 1; i <= library.length; i++)
        {
            printf("the catagory of the book-%d----%c\n",i,library.r[i].otherinfo.catagory);
             printf("\n");
        }
    break;
    
    case '2':
        for (int i = 1; i <= library.length; i++)
        {
            library.r[i].key = library.r[i].otherinfo.price;
        }
        InsertSort(&library);
        for (int i = 1; i <= library.length; i++)
        {
            printf("the price of the book-%d----%f\n",i,library.r[i].otherinfo.price);
            printf("\n");
        }
    break;

    default:
        printf("error input\n");
        break;
    }

    printf("please input the keyword of the book you wanna search\n");

    switch (user_choice)
    {
    case '1':
        scanf("%c",&key_1);
        getchar();
        int num = search(library,key_1);
        if(num == 0)
        printf("not found\n");
        else
        {
            printf("the catagory of the book-%d----%c\n",num,library.r[num].otherinfo.catagory);
            printf("the name  of the book-%d----%s\n",num,library.r[num].otherinfo.name);
            printf("the writer of the book-%d----%s\n",num,library.r[num].otherinfo.writer);
            printf("the date of the book-%d----%s\n",num,library.r[num].otherinfo.date);
            printf("the price of the book-%d----%f\n",num,library.r[num].otherinfo.price);
            printf("\n");   
        }
    break;
    
    case '2':
        scanf("%d",&key_2);
        getchar();
        int num_1 = search(library,key_2);
        if(num_1 == 0)
        printf("not found\n");
        else
        {
            printf("the catagory of the book-%d----%c\n",num_1,library.r[num_1].otherinfo.catagory);
            printf("the name of the book-%d----%s\n",num_1,library.r[num_1].otherinfo.name);
            printf("the writer of the book-%d----%s\n",num_1,library.r[num_1].otherinfo.writer);
            printf("the date of the book-%d----%s\n",num_1,library.r[num_1].otherinfo.date);
            printf("the price of the book-%d----%f\n",num_1,library.r[num_1].otherinfo.price);
            printf("\n");
        }
    break;

    default:
        printf("error input\n");
        break;
    }
}

int output_information(void)
{
    char user_choice;
    printf("input your wanna keyword\n");
    printf("1.catagory  2.price\n");
    user_choice = getchar();
    getchar();
    switch (user_choice)
    {
    case '1':
        for (int i = 1; i <= library.length; i++)
        {
            library.r[i].key = library.r[i].otherinfo.catagory;
        }
    break;
    
    case '2':
        for (int i = 1; i <= library.length; i++)
        {
            library.r[i].key = library.r[i].otherinfo.price;
        }
    break;

    default:
        printf("error input\n");
        break;
    }

    InsertSort(&library);

    for (int i = 1; i <= library.length; i++)
    {
        printf("the catagory of the book-%d----%c\n",i,library.r[i].otherinfo.catagory);
        printf("the name of the book-%d----%s\n",i,library.r[i].otherinfo.name);
        printf("the writer of the book-%d----%s\n",i,library.r[i].otherinfo.writer);
        printf("the date of the book-%d----%s\n",i,library.r[i].otherinfo.date);
        printf("the price of the book-%d----%f\n",i,library.r[i].otherinfo.price);
        printf("\n");
    }
}
