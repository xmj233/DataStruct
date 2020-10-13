#ifndef LINKQUEUE_CPP
#define LINKQUEUE_CPP

#include "LinkQueue.h"

Status InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if ( !Q.front )
        exit(OVERFLOW);
    Q.front->next = NULL; 

    return OK;
}

Status ClearQueue(LinkQueue &Q) {
    QueuePtr p, q;
    p = Q.front->next;
    while ( p ) {
        q = p->next;
        free(p);
        p =q;
    }
    Q.rear->next = NULL;
    Q.front = Q.rear;
    return OK;
}

Status DestoryQueue(LinkQueue &Q) {
    while ( Q.front ) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}

Status QueueEmpty(LinkQueue Q) {
    if ( Q.front==Q.rear ) 
        return TRUE;
    else 
        return FALSE;
}

int QueueLength(LinkQueue Q) {
    int count = 0;
    QueuePtr p = Q.front->next;
    while ( p ) {
        count ++;
        p = p->next;
    }
    return count;
}

Status GetHead(LinkQueue Q, QElemType &e) {
    if ( Q.front == Q.rear ) 
        return ERROR;
    e = Q.front->next->data;

    return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e) {
    QueuePtr p;
    if ( !(p = (QueuePtr)malloc(sizeof(QNode))) ) 
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;

    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e) {
    QueuePtr p;
    if ( Q.front==Q.rear )
        return ERROR;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if ( Q.rear==p )
        Q.rear = Q.front;
    
    return OK;
}

Status QueueTraverse(LinkQueue Q, void(Visit)(QElemType)) {
    QueuePtr p = Q.front->next;
    while ( p ) {
        Visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

#endif