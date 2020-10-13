#ifndef SEQUENCELISH_H
#define SEQUENCELISH_H

#define INIT_LIST_SIZE 100
#define LISTINCREMENT 10

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

typedef int ElemType;

typedef struct {
    ElemType* elem;
    int length;
    int listsize;
}SqList;

Status InitList(SqList &L);

void DestoryList(SqList &L);

Status ListEmpty(SqList L);

int ListLength(SqList L);

Status GetElem(SqList L, int i, ElemType &e);

int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e);

Status ListInsert(SqList &L, int i, ElemType e);

Status ListDelete(SqList &L, int i, ElemType &e);

void ListTraverse(SqList L, void(Visit)(ElemType));

#endif