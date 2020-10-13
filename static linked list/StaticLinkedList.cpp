#ifndef STATICLINKEDLIST_CPP
#define STATICLINKEDLIST_CPP

#include "StaticLinkedList.h"

void InitList(SLinkList &L) {
    int i;
    for ( i=0; i<MAXSIZE-2; i++ ) 
        L[i].cur = i+1;
    L[MAXSIZE-2].cur = 0;
    L[MAXSIZE-1].cur = 0;
}

int Malloc(SLinkList &space) {
    int i;
    i = space[0].cur;
    if ( i ) 
        space[0].cur = space[i].cur;
    return i;
}

void Free(SLinkList &space, int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

void ClearList(SLinkList &L) {
    int i, k;
    i = L[MAXSIZE-1].cur;
    L[MAXSIZE-1].cur = 0;
    k = L[0].cur;
    L[0].cur = i;
    while ( i ) {
        i = L[i].cur;
    }
    L[i].cur = k;
}

Status ListEmpty(SLinkList L) {
    if ( L[MAXSIZE-1].cur==0 ) 
        return TRUE;
    else 
        return FALSE;
}

int ListLength(SLinkList L) {
    int i;
    int count = 0;
    i  = L[MAXSIZE-1].cur; 
    while ( i ) {
        count ++;
        i = L[i].cur;
    }
    return count;
}

Status GetElem(SLinkList L, int i, ElemType &e) {
    int j, k=1;
    if ( i<1||i>ListLength(L) ) 
        return ERROR;
    j = L[MAXSIZE-1].cur; 
    while ( k<i ) {
        j = L[j].cur;
        k ++;
    }
    e = L[j].data;
    return OK;
}

int LocateElem(SLinkList L, ElemType e) {
    int i;
    i = L[MAXSIZE-1].cur;
    while ( i&&L[i].data!=e ) 
        i = L[i].cur;
    return i;
}

Status PriorElem(SLinkList L, ElemType cur_e, ElemType &pre_e) {
    int i, j;
    i = L[MAXSIZE-1].cur;
    while ( i&&L[i].data!=cur_e ) {
        j = i;
        i = L[i].cur;
    }
    if ( i==L[MAXSIZE-1].cur || i==0 )
        return ERROR;
    else 
        pre_e = L[j].data;
    return OK;
}

Status NextElem(SLinkList L, ElemType cur_e, ElemType &next_e) {
    int i, j;
    i = L[MAXSIZE-1].cur;
    while ( i&&L[i].data!=cur_e ) {
        i = L[i].cur;
    }
    if (L[i].cur==0 || i==0 )
        return ERROR;
    else 
        next_e = L[L[i].cur].data;
    return OK;
}

Status ListInsert(SLinkList &L, int i, ElemType e) {
    int j, k, c;
    if ( i<1||i>ListLength(L)+1 ) 
        return ERROR;
    if ( !(j = Malloc(L)) )
        return ERROR;
    c = MAXSIZE-1;
    k = 0;
    while ( k<i-1 ) {
        c = L[c].cur;
        k ++;
    }
    L[j].data = e;
    L[j].cur = L[c].cur;
    L[c].cur = j;
    return OK;
}

Status ListDelete(SLinkList &L, int i, ElemType &e) {
    int c, k, q;
    if ( i<1||i>ListLength(L) )
        return ERROR;
    c = MAXSIZE-1;
    k = 0;
    while ( k<i-1 ) {
        c = L[c].cur;
        k ++;
    }
    q = L[c].cur;
    L[c].cur = L[q].cur;
    e = L[q].data;
    Free(L, q);
    return OK;
}

void ListTraverse(SLinkList L, void(Visit)(ElemType)) {
    int i;
    i = L[MAXSIZE-1].cur;
    while ( i ) {
        Visit(L[i].data);
        i = L[i].cur;
    }
    printf("\n");
}

#endif