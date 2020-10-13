#ifndef CIRCULARQUEUE_CPP
#define CIRCULARQUEUE_CPP

#include "CircularQueue.h"

Status InitQueue(SqQueue &Q) {
    if ( !(Q.base=(QElemType*)malloc(MAXSIZE*sizeof(QElemType))) )
        exit(OVERFLOW);
    Q.front = Q.rear = 0;

    return OK;
}

Status ClearQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;

    return OK;
}

Status DestoryQueue(SqQueue &Q) {
    if ( Q.base )
        free(Q.base);
    Q.base = NULL;
    Q.front = Q.rear = 0;

    return OK;
}

Status QueueEmpty(SqQueue Q) {
    if ( Q.front==Q.rear ) 
        return TRUE;
    else 
        return FALSE;
}

int QueueLength(SqQueue Q) {
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

Status GetHead(SqQueue Q, QElemType &e) {
    if ( Q.front==Q.rear )
        return ERROR;
    e = Q.base[Q.front];

    return OK;
}

Status EnQueue(SqQueue &Q, QElemType e) {
    if ( (Q.rear+1)%MAXSIZE==Q.front )
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1)%MAXSIZE;

    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e) {
    if ( Q.rear==Q.front )
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front+1)%MAXSIZE;

    return OK;
}

Status QueueTraverse(SqQueue Q, void(Visit)(QElemType)) {
    int i;
    for ( i=Q.front; i!=Q.rear; i=(i+1)%MAXSIZE ) {
        Visit(Q.base[i]);
    }
    printf("\n");

    return OK;
}


#endif