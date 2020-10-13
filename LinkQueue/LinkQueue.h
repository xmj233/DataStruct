/* 单练队列------队列的链式存储结构
    2020.1,31
    周五    */
#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "../Status.h"

#if !defined BANKSIMULATION_H   && \
    !defined LINKBINARYTREE_H   && \
    !defined TRIDENTBINARYTREE_H   
typedef int QElemType;
#endif

typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q);

Status ClearQueue(LinkQueue &Q);

Status DestoryQueue(LinkQueue &Q);

Status QueueEmpty(LinkQueue Q);

int QueueLength(LinkQueue Q);

Status GetHead(LinkQueue Q, QElemType &e);

Status EnQueue(LinkQueue &Q, QElemType e);

Status DeQueue(LinkQueue &Q, QElemType &e);

Status QueueTraverse(LinkQueue Q, void(Visit)(QElemType));

#endif