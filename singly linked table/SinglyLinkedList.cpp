#ifndef SINGLELINKEDLIST_CPP
#define SINGLELINKEDLIST_CPP

#include "SinglyLinkedList.h"

Status InitList(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    if ( !L ) 
        exit(OVERFLOW);
    L->next = NULL;
    return OK;
}

void DestoryList(LinkList &L) {
    LinkList p = L;
    while ( p ) {
        p = L->next;
        free(L);
        L = p;
    }
}

Status ListEmpty(LinkList L) {
    if ( L && L->next==NULL ) 
        return TRUE;
    else 
        return FALSE;
}

int ListLength(LinkList L) {
    int i;
    LinkList p;
    i = 0;
    p = L->next;
    while ( p ) {
        i ++;
        p = p->next; 
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType &e) {
    int j;
    LinkList p;
    j = 1;
    p = L->next;
    while ( p && j<i ) {
        j++;
        p = p->next;
    }
    if ( !p||j>i ) 
        return ERROR;
    e = p->data;
    return OK;
}

int LocateElem(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    int i;
    LinkList p;
    i = -1;                 //Does not exist, return -1;
    if ( L ) {
        i = 1;
        p = L->next;
        while ( p&&!Compare(e, p->data) ) {
            i ++;
            p = p->next;
        }
        if ( !p ) 
            i = -2;
    }
    return i;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e) {
    LinkList p, suc;
    if ( L ) {
        p = L->next;
        if ( p->data!=cur_e ) {
            while ( p->next ) {
                suc = p->next;
                if ( suc->data==cur_e ) {
                    pre_e = p->data;
                    return OK;
                }
                p = suc;
            }
        }
    }
    return ERROR;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e) {
    LinkList p, suc;
    if ( L ) {
        p = L->next;
        while ( p->next ) {
            suc = p->next;
            if ( p->data==cur_e ) {
                next_e = suc->data;
                return OK;
            }
            p = suc;
        }
    }
    return ERROR;
}

Status ListInsert(LinkList &L, int i, ElemType e) {
    LinkList p;
    LinkList s;
    int j;
    p = L;
    j = 0;
    while ( p&&j<i-1 ) {
        j++;
        p = p->next;
    }
    if ( !p||j>i-1 ) 
        return ERROR;
    s = (LinkList)malloc(sizeof(LNode));
    if ( !s )
        exit(OVERFLOW);
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e) {
    LinkList p, q;
    int j;
    p = L;
    j = 0;
    while ( p->next&&j<i-1 ) {
        p=p->next;
        j ++;
    }
    if ( !p->next||j>i-1 ) 
        return ERROR;
    q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return OK;
}

Status ListTraverse(LinkList L, void(Visit)(ElemType)) {
    LinkList p;
    p = L->next;
    if ( !L ) 
        return ERROR;
    while ( p ) {
        Visit(p->data);
        p = p->next;
    }
    return OK;
}

Status CreateList_H(LinkList &L, int n) {
    int i;
    LinkList p;
    L = (LinkList)malloc(sizeof(LNode));
    if ( !L )
        exit(OVERFLOW);
    L->next = NULL;
    for ( i=1; i<=n; i++ ) {
        p = (LinkList)malloc(sizeof(LNode));
        if ( !p ) 
            exit(OVERFLOW);
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
    return OK;
}

Status CreateList_T(LinkList &L, int n) {
    int i;
    LinkList p, q;
    L = (LinkList)malloc(sizeof(LNode));
    if ( !L ) 
        exit(OVERFLOW);
    L->next = NULL;
    q = L;
    for ( i=1; i<=n; i++ ) {
        p = (LinkList)malloc(sizeof(LNode));
        if ( !p ) 
            exit(OVERFLOW);
        scanf("%d", &p->data);
        q->next = p;
        q = q->next;
    }
    q->next = NULL;
    return OK;
}

#endif