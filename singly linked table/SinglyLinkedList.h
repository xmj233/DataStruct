#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

#ifndef BANKSIMULATION_H
typedef int ElemType;
#endif

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

Status InitList(LinkList &L);

void DestoryList(LinkList &L);

Status ListEmpty(LinkList L);

int ListLength(LinkList L);

Status GetElem(LinkList L, int i, ElemType &e);

int LocateElem(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType));

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e);

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e);

Status ListInsert(LinkList &L, int i, ElemType e);

Status ListDelete(LinkList &L, int i, ElemType &e);

Status ListTraverse(LinkList L, void(Visit)(ElemType));

Status CreateList_H(LinkList &L, int n);

Status CreateList_T(LinkList &L, int n);




#endif