#ifndef SEQUENCELIST_CPP
#define SEQUENCELIST_CPP

#include "SequenceList.h"

Status InitList(SqList &L) {
    if ( !( L.elem=(ElemType*)malloc(INIT_LIST_SIZE*sizeof(ElemType)) ) ) 
        return ERROR;
    L.length = 0;
    L.listsize = INIT_LIST_SIZE;

    return OK;
}


void DestoryList(SqList &L) {
    free(L.elem);
    L.length = 0;
    L.listsize = 0;
}

Status ListEmpty(SqList L) {
    return L.length==0 ? TRUE : FALSE;
}

int ListLength(SqList L) {
    return L.length;
}

Status GetElem(SqList L, int i, ElemType &e) {
    if ( i<1||i>L.length ) 
        return ERROR;
    e = L.elem[i-1];
    return OK;
}

int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    int i = 1;
    while ( i<=L.length&&!(Compare(e, L.elem[i-1])) ) {
        i ++;
    }
    if ( i<=L.length ) 
        return i;
    else 
        return 0;
}

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e) {
    int i = 2;
    if ( L.elem[0]!=cur_e ) {
        while ( i<=L.length&&L.elem[i-1]!=cur_e )
            i ++;
        if ( i<=L.length ) {
            pre_e = L.elem[i-2];
            return OK;
        }
    }
    return ERROR;
}

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e) {
    int i = 1;
    while ( i<=L.length&&L.elem[i-1]!=cur_e )
        i ++;
    if ( i<L.length ) {
        next_e = L.elem[i];
        return OK;
    }
    return ERROR;
}

Status ListInsert(SqList &L, int i, ElemType e) {
    if ( i<1||i>L.length+1 ) 
        return ERROR;
    if ( L.length>=L.listsize ) {
        ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if ( !newbase )
            exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    ElemType *p = &(L.elem[i-1]);
    ElemType *q = &(L.elem[L.length-1]);
    for ( q; q>=p; q-- ) {
        *(q+1) = *q;
    }
    *p = e;
    L.length ++;

    return OK;
}

Status ListDelete(SqList &L, int i, ElemType &e) {
    if ( i<1||i>L.length ) 
        return ERROR;
    ElemType *p = &(L.elem[i-1]);
    e = *p;
    ElemType *q = L.elem + L.length -1;
    for ( ++p; p<=q; p++ ) {
        *(p-1) = *p;
    }
    L.length --;
    return OK;
}

void ListTraverse(SqList L, void(Visit)(ElemType)) {
    int i;
    for ( i=0; i<L.length; i++ ) {
        Visit(L.elem[i]);
    }
}

#endif