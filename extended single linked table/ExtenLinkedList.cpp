#ifndef EXTENLINKEDLIST_CPP
#define EXTENLINKEDLIST_CPP

#include "ExtenLinkedList.h"

Status MakeNode(Link &p, ElemType e) {
    if ( !(p=(Link)malloc(sizeof(LNode))) )
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    return OK;
}

void FreeNode(Link &p) {
    free(p);
    p = NULL;
}

Status InitList(LinkList &L) {
    Link p;
    if ( !(p=(Link)malloc(sizeof(LNode))) )
        exit(OVERFLOW);
    p->next = NULL;
    L.head = L.tail = p;
    L.len = 0;
    return OK;
}

Status DestoryList(LinkList &L) {
    ClearList(L);
    free(L.head);
    L.head = L.tail = NULL;
    return OK;
}

Status ClearList(LinkList &L) {
    Link p = L.head->next;
    Link q;
    while ( p ) {
        q = p->next;
        free(p);
        p = q;
    }
    L.head->next = NULL;
    L.tail = L.head;
    L.len = 0; 
    return OK;
}

Status InsFirst(LinkList &L, Link h, Link s) {
    s->next = h->next;
    h->next = s;
    if ( h==L.tail ) 
        L.tail = h->next;
    L.len ++;
    return OK;
}

Status DelFirst(LinkList &L, Link h, Link &q) {
    q = h->next;
    if ( q ) {
        h->next = q->next;
        if ( !h->next ) 
            L.tail = h;
        L.len --;
        return OK;
    }
    return ERROR;
}

Status Append(LinkList &L, Link s) {
    int count = 0;
    L.tail->next = s;
    while ( s ) {
        L.tail = s;
        s = s->next;
        count ++;
    }
    L.len += count;
    return OK;
}

Status Remove(LinkList &L, Link &q) {
    Link p = L.head->next;
    if ( !L.len ) {
        q = NULL;
        return ERROR;
    }
    q = L.tail;
    while ( p->next!=L.tail )
        p = p->next;
    p->next = NULL;
    L.tail = p;

    L.len --;
    return OK;
}

Status InsBefore(LinkList &L, Link &p, Link s) {
    Link q;
    q = PriorPos(L, p);
    if ( !q )
        q = L.head;
    s->next = q->next;
    q->next = s;
    p = s;
    L.len ++;
    return OK;
}

Status InsAfter(LinkList &L, Link &p, Link s) {
    if ( p== L.tail ) 
        L.tail = s;
    s->next = p->next;
    p->next = s;
    p = s;
    L.len ++;
    return OK;
}

Status SetCurElem(Link &p, ElemType e) {
    p->data = e;
    return OK;
}

ElemType GetCurElem(Link &p) {
    return p->data;
}

Status ListEmpty(LinkList L) {
    if ( !L.len ) 
        return TRUE;
    else 
        return FALSE;
} 

int ListLength(LinkList L) {
    return L.len;
}

Position GetHead(LinkList L) {
    return L.head;
}

Position GetLast(LinkList L) {
    return L.tail;
}

Position PriorPos(LinkList L, Link p) {
    Link q = L.head->next;
    if ( q==p ) 
        return NULL;
    while ( q->next!=p ) 
        q = q->next;
    return q;
}

Position NextPos(LinkList L, Link p) {
    return p->next;
}

Status LocatePos(LinkList L, int i, Link &p) {
    int j = 0;
    p = L.head;
    if ( i<0||i>L.len )
        return ERROR;
    while ( j<i ) {
        p = p->next;
        j++;
    }
    return OK;
}

Position LocateElem(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    Link p = L.head->next;
    while (p&&!Compare(e, p->data))
        p = p->next;
    return p;
}

Status ListTraverse(LinkList L, void(Visit)(ElemType)) {
    int i;
    Link p = L.head->next;
    for ( i=1; i<=L.len; i++ ) {
        Visit(p->data);
        p = p->next;
    }
    return OK;
}

Status ListInsert(LinkList &L, int i, ElemType e) {
    Link p, h;
    if ( !LocatePos(L, i-1, h) )
        return ERROR;
    if ( !MakeNode(p, e) )
        return ERROR;
    if ( !InsFirst(L, h, p) )
        return ERROR;
    return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e) {
    Link h, q;
    if ( !LocatePos(L, i-1, h) ) 
        return ERROR;
    if ( !DelFirst(L, h, q) )
        return ERROR;
    e = q->data;
    return OK;
}


#endif