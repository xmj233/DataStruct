/*  栈的基本操作
    2020.1.20
    Monday      */

#ifndef SEQUENCESTACK_H
#define SEQUENCESTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#if !defined MAZE_H     &&  \
    !defined LINKBINARYTREE_H   && \
    !defined TRIDENTBINARYTREE_H
typedef int SElemType;
#endif

typedef struct {
    SElemType *top;
    SElemType *base;
    int stacksize;
}SqStack;

Status InitStack(SqStack &S);

void ClearStack(SqStack &S);

void DestoryStack(SqStack &S);

Status StackEmpty(SqStack S);

int StackLength(SqStack S);

Status GetTop(SqStack S, SElemType &e);

Status Push(SqStack &S, SElemType e);

Status Pop(SqStack &S, SElemType &e);

Status StackTraverse(SqStack S, void(Visit)(SElemType));

#endif