#ifndef DUCIRCULARLINKEDLIST_CPP
#define DUCIRCULARLINKEDLIST_CPP

#include "./DuCircularLinkedList.h"

Status InitList(DuLinkList &L) {
    if ( !( L=(DuLinkList)malloc(sizeof(DuLNode)) ) )
        exit(OVERFLOW);
    L->next = L->prior = L;

    return OK;
}

Status ClearList(DuLinkList &L) {
    DuLinkList p, q;
    p = L->next;
    while ( p!=L ) {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = L->prior = L;

    return OK;
}

void DestoryList(DuLinkList L) {
    ClearList(L);
    free(L);
    L = NULL;
}

Status ListEmpty(DuLinkList L) {
    if ( L&&L->next==L&&L->prior==L ) 
        return TRUE;
    else 
        return FALSE;
}

int ListLength(DuLinkList L) {
    DuLinkList p;
    int count;
    if ( L ) {
        p = L->next;
        count = 0;
        while ( p!=L ) {
            count ++;
            p = p->next;
        }
    }
    return count;
}

Status GetElem(DuLinkList L, int i, ElemType &e) {
    DuLinkList p;
    int j;
    if ( L ) {
        p = L->next;
        j = 1;
        while ( p!=L&&j<i ) {
            p = p->next;
            j++;
        }
        if ( p!=L ) {
            e = p->data;
            return OK;
        }
    }
    return ERROR;
}

int LocateElem(DuLinkList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    DuLinkList p;
    int j;
    if ( L ) {
        p = L->next;
        j = 1;
        while ( p!=L&&!Compare(e, p->data) ) {
            p = p->next;
            j ++;
        }
        if ( p!=L ) 
            return j;
    }
    return 0;
}

Status PriorElem(DuLinkList L, ElemType cur_e, ElemType &pre_e) {
    DuLinkList p;
    if ( L ) {
        p = L->next;
        while ( p!=L&&p->data!=cur_e ) 
            p = p->next;
        if ( p!=L&&p->prior!=L ) {
            pre_e = p->prior->data;
            return OK;
        }
    }
    return ERROR;
}

Status NextElem(DuLinkList L, ElemType cur_e, ElemType &next_e) {
    DuLinkList p;
    if ( L ) {
        p = L->next;
        while ( p!=L&&p->data!=cur_e )
            p = p->next;
        if ( p!=L&&p->next!=L ) {
            next_e = p->next->data;
            return OK;
        }
    }
    return ERROR;
}

DuLinkList GetElemPtr(DuLinkList L, int i) {
    DuLinkList p;
    int j;
    if ( L&&i>0 ) {
        p = L->next;
        j = 1;
        while ( p!=L&&j<i ) {
            p = p->next;
            j ++;
        }
        if ( p!=L )
            return p;
    }
    return NULL;
}

Status ListInsert(DuLinkList &L, int i, ElemType e) {
    DuLinkList p, s;
    if ( i<1||i>ListLength(L)+1 )
        return ERROR;
    if ( !(p=GetElemPtr(L, i)) ) 
        p = L;
    s = (DuLinkList)malloc(sizeof(DuLNode));
    if ( !s ) 
        exit(OVERFLOW);
    s->data = e;
    s->prior = p->prior;
    s->next = p;
    p->prior->next = s;
    p->prior = s;

    return OK;
}

Status ListDelete(DuLinkList &L, int i, ElemType &e) {
    DuLinkList p;
    if ( !(p=GetElemPtr(L, i)) ) 
        return ERROR;
    e = p->data;
    p->next->prior = p->prior;
    p->prior->next = p->next;
    free(p);

    return OK;
}

Status ListTraverse(DuLinkList L, void(Visit)(ElemType)) {
    DuLinkList p;
    if ( L ) {
        p = L->next;
        while ( p!=L ) {
            Visit(p->data);
            p = p->next;
        }
        printf("\n");
        return OK;
    }
    return ERROR;
}

#endif