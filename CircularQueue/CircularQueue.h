/* -----循环队列--------
    队列的顺序存储结构
    2020.2.1 
    周六            */
#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

#define MAXSIZE 8

typedef int QElemType;

typedef struct {
    QElemType *base;
    int front;
    int rear;
}SqQueue;

Status InitQueue(SqQueue &Q);

Status ClearQueue(SqQueue &Q);

Status DestoryQueue(SqQueue &Q);

Status QueueEmpty(SqQueue Q);

int QueueLength(SqQueue Q);

Status GetHead(SqQueue Q, QElemType &e);

Status EnQueue(SqQueue &Q, QElemType e);

Status DeQueue(SqQueue &Q, QElemType &e);

Status QueueTraverse(SqQueue Q, void(Visit)(QElemType));

#endif