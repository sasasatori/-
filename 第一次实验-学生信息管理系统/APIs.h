//
// Created by 28617 on 2019/5/17.
//

#ifndef DATASTRUCTURE_LAB_1_APIS_H
#define DATASTRUCTURE_LAB_1_APIS_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define student_t ElemType
#define name_max_length 10

//定义学生数据结构
typedef enum
{
    OK = 1,
    OVERFLOW = 2
}Status;

typedef struct
{
    int num;   //序号
    int ID;    //学号
    char name[name_max_length];
    int score[5];
}student_t;

struct LNode
{
    ElemType data;
    struct LNode *next;
};
typedef struct LNode *LinkList;

Status InitList(LinkList *L);
int ListLength(LinkList L);
Status ListInsert(LinkList L,int i,ElemType e);
Status ListDelete(LinkList L,int i,ElemType *e);

Status load_in_information(void);
Status add_information(void);
Status change_information(void);
Status delete_information(void);
Status search_information(void);
Status output_information(void);
Status save_information(void);
#endif //DATASTRUCTURE_LAB_1_APIS_H
