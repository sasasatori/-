#include "tree.h"

int change(BiTree *tree)
{
    while(1)
    {
        printf("%s\n",(*tree)->data);
        char choice;
        printf("input '1' to chage the data of this node\n"
               "input '2' to visit the lchild of the node\n"
               "input '3' to visit the rchild of the node\n"
               "input '4' to back to the upper node\n");
        scanf("%c",&choice);
        getchar();
        switch (choice)
        {
            case '1':
            {
                char input[MAXSIZE];
                scanf("%s",input);
                getchar();
                strcpy((*tree)->data,input);
                break;
            }
            case '2':
            {
                if((*tree)->lchild == NULL)
                {
                    printf("no left node,now creating\n");
                    (*tree)->lchild = (BiTree)malloc(sizeof(BiTNode));
                }
                else
                {
                    change(&(*tree)->lchild);
                }
                break;
            }
            case '3':
            {
                if((*tree)->rchild == NULL)
                {
                    printf("no right node,now creating\n");
                    (*tree)->rchild = (BiTree)malloc(sizeof(BiTNode));
                }
                else
                {
                    change(&(*tree)->rchild);
                }
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                printf("input error");
                break;
            }
        }
    }
}

int visit(BiTree *tree)
{
    printf("%s\n",(*tree)->data);
    if((*tree)->lchild == NULL && (*tree)->rchild == NULL)
        return 1;
    char choice;
    scanf("%c",&choice);
    getchar();
    if(choice == 'y')
        visit(&(*tree)->lchild);
    else if(choice == 'n')
        visit(&(*tree)->rchild);
    else
    {
        printf("error input\n");
        return 0;
    }
}

int working(BiTree *tree)
{
    char choice;
    int flag=0;
    printf("is this your expected answer?\n");
    scanf("%c",&choice);
    getchar();

    if(choice == 'y')
    {
        printf("great!!\n");
        return 1;
    }
    else if(choice == 'n')
    {
        change(tree);
        visit(tree);
        working(tree);
    }
    else if(choice == 'q')
    {
        flag = 1;
    }
    else
    {
        printf("error input\n");
    }
    while(flag == 1)
    {
        return 0;
    }

}



int animal_sys(void)
{
    BiTree* animal_system;
    *animal_system = (BiTree)malloc(sizeof(BiTNode));
    strcpy((*animal_system)->data,"ÊÇ²¸Èé¶¯ÎïÂð");

    (*animal_system)->lchild = (BiTree)malloc(sizeof(BiTNode));
    strcpy((*animal_system)->lchild->data,"»á·ÉÂð");
    (*animal_system)->lchild->lchild = (BiTree)malloc(sizeof(BiTNode));
    strcpy((*animal_system)->lchild->lchild->data,"òùòð");
    (*animal_system)->lchild->rchild = (BiTree)malloc(sizeof(BiTNode));
    strcpy((*animal_system)->lchild->rchild->data,"ºï×Ó");

    (*animal_system)->rchild = (BiTree)malloc(sizeof(BiTNode));
    strcpy((*animal_system)->rchild->data,"Éß");

    visit(animal_system);

    working(animal_system);
}
