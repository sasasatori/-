#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    int num;
    char top[100];
    int matrix[100][100]={0};
    int pos[100][100]={0};
    int weight[100][100]={0};
    int k,counter;

    scanf("%d",&num);
    getchar();
    for(int i=0;i<num;i++)
    {
        scanf("%c",&top[i]);
        getchar();
    }

    for(int j=0;j<num; ++j)
    {
        k = 0;
        while(matrix[j][k-1] != -1)
        {
            scanf("%d",&matrix[j][k]);
            getchar();
            k++;
        }
    }

    for (int m = 0; m < num; ++m)
    {
       k=0;
        for(int i = 0; i < 2*num; i=i+2)
        {
          pos[m][k] = matrix[m][i];
          k++;
        }
    }

    for (int n = 0; n < num; ++n)
    {
        k=0;
        for (int i = 1; i < 2*num; i=i+2)
        {
            weight[n][k] = matrix[n][i];
            k++;
        }
    }

    for (int l = 0; l < num; ++l)
    {
        k=0;
        printf("%c  ",top[l]);
        while(pos[l][k] != -1)
        {
            k++;
        }
        if(k!=0)
        {
            for (int i = k-1; i >= 0; i--)
            {
                printf("(%d,%d)%d  ",l,pos[l][i],weight[l][i]);
            }
        }

        printf("\n");
    }
}
