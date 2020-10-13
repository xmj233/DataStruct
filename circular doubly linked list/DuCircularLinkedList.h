#ifndef DUCIRCULARLINKEDLIST_H
#define DUCIRCULARLINKEDLISH_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

typedef int ElemType;

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode, *DuLinkList;

Status InitList(DuLinkList &L);

Status ClearList(DuLinkList &L);

void DestoryList(DuLinkList L);

Status ListEmpty(DuLinkList L);

int ListLenth(DuLinkList L);

Status GetElem(DuLinkList L, int i, ElemType &e);

int LocateElem(DuLinkList L, ElemType e, Status(Compare)(ElemType, ElemType));

Status PriorElem(DuLinkList L, ElemType cur_e, ElemType &pre_e);

Status NextElem(DuLinkList L, ElemType cur_e, ElemType &next_e);

DuLinkList GetElemPtr(DuLinkList L, int i);

Status ListInsert(DuLinkList &L, int i, ElemType e);

Status ListDelete(DuLinkList &L, int i, ElemType &e);

Status ListTraverse(DuLinkList L, void(Visit)(ElemType));

#endif 