#ifndef LIB_H
#define LIB_H

#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

 /* c10-1.h 待排记录的数据类型 */
 #define MAXSIZE 20 /* 一个用作示例的小顺序表的最大长度 */
 typedef int KeyType; /* 定义关键字类型为整型 */

 #define TRUE 1
 #define FALSE 0

 /* c9.h 对两个数值型关键字的比较约定为如下的宏定义 */
 #define EQ(a,b) ((a)==(b))
 #define LT(a,b) ((a)<(b))
 #define LQ(a,b) ((a)<=(b))

typedef struct 
{
    char catagory;
    char name[10];
    char writer[10];
    char date[10];
    float price;
}InfoType;

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

int load_in_information(void);

int add_information(void);

int change_information(void);

int delete_information(void);

int search_information(void);

int output_information(void);

#endif