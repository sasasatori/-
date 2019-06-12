#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 100
 /* algo10-3.c 希尔排序 */
 typedef int InfoType; /* 定义其它数据项的类型 */
 typedef int KeyType; /* 定义关键字类型为整型 */

 #define EQ(a,b) ((a)==(b))
 #define LT(a,b) ((a)<(b))
 #define LQ(a,b) ((a)<=(b))

 typedef struct
 {
   KeyType key; /* 关键字项 */
   InfoType otherinfo; /* 其它数据项，具体类型在主程中定义 */
 }RedType; /* 记录类型 */

 typedef struct
 {
   RedType r[MAXSIZE+1]; /* r[0]闲置或用作哨兵单元 */
   int length; /* 顺序表长度 */
 }SqList; /* 顺序表类型 */
 
 void ShellInsert(SqList *L,int dk)
 { /* 对顺序表L作一趟希尔插入排序。本算法是和一趟直接插入排序相比， */
   /* 作了以下修改： */
   /* 1.前后记录位置的增量是dk,而不是1; */
   /* 2.r[0]只是暂存单元,不是哨兵。当j<=0时,插入位置已找到。算法10.4 */
   int i,j;
   for(i=dk+1;i<=(*L).length;++i)
     if LT((*L).r[i].key,(*L).r[i-dk].key)
     { /* 需将(*L).r[i]插入有序增量子表 */
       (*L).r[0]=(*L).r[i]; /* 暂存在(*L).r[0] */
       for(j=i-dk;j>0&&LT((*L).r[0].key,(*L).r[j].key);j-=dk)
         (*L).r[j+dk]=(*L).r[j]; /* 记录后移，查找插入位置 */
       (*L).r[j+dk]=(*L).r[0]; /* 插入 */
     }
 }

 void print(SqList L)
 {
   int i;
   for(i=1;i<=L.length;i++)
     printf("%d ",L.r[i].key);
   printf("\n");
 }

 void ShellSort(SqList *L,int dlta[],int t)
 { /* 按增量序列dlta[0..t-1]对顺序表L作希尔排序。算法10.5 */
   int k;
   for(k=0;k<t;++k)
   {
     ShellInsert(L,dlta[k]); /* 一趟增量为dlta[k]的插入排序 */
     printf("gap=%d ",dlta[k]);
     print(*L);
   }
   if(k = t-1)
   {
       printf("最后结果：");
       print(*L);
   }
 }


int main(void)
 {
    int num;
    SqList L;

    scanf("%d",&num);
    for (int i = 1; i <= num; i++)
    {
        scanf("%d",&L.r[i].key);
        getchar();
    }
    printf("原始数据:");
    for (int i = 1; i <= num; i++)
    {
        printf("%d ",L.r[i].key);
    }
    printf("\n");
    printf("排序过程：\n");

    int temp = num;
    int delta[MAXSIZE];
    int k=0;

    L.length = num;
    while (temp != 1)
    {
        temp = temp/2;
        delta[k] =  temp;
        k++;
    }
    
    ShellSort(&L,delta,k);
    return 0;
}
