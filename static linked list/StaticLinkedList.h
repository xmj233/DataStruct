#ifndef STATICLINKEDLIST_H
#define STATICLINKEDLIST_H

#include <stdio.h>
#include "../Status.h"

#define MAXSIZE 1000
typedef int ElemType;

typedef struct {
    ElemType data;
    int cur;    
}component, SLinkList[MAXSIZE];

void InitList(SLinkList &L);

int Malloc(SLinkList &space);

void Free(SLinkList &space, int k);

void ClearList(SLinkList &L);

Status ListEmpty(SLinkList L);

int ListLength(SLinkList L);

Status GetElem(SLinkList L, int i, ElemType &e);

int LocateElem(SLinkList L, ElemType e);

Status PriorElem(SLinkList L, ElemType cur_e, ElemType &pre_e);

Status NextElem(SLinkList L, ElemType cur_e, ElemType &next_e);

Status ListInsert(SLinkList &L, int i, ElemType e);

Status ListDelete(SLinkList &L, int i, ElemType &e);

void ListTraverse(SLinkList L, void(Visit)(ElemType));

#endif