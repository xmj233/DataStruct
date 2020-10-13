#ifndef SEQUENCESTACK_CPP
#define SEQUENCESTACK_CPP

#include "SequenceStack.h"

Status InitStack(SqStack &S) {
    if ( !(S.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType))) )
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;

    return OK;
}

void ClearStack(SqStack &S) {
    S.top = S.base;
}

void DestoryStack(SqStack &S) {
    ClearStack(S);
    free(S.base);
    S.top = NULL;
    S.base = NULL;
    S.stacksize = 0;
}

Status StackEmpty(SqStack S) {
    return S.top==S.base ? TRUE : FALSE;
}

int StackLength(SqStack S) {
    return S.top-S.base;
}

Status GetTop(SqStack S, SElemType &e) {
    if ( S.base==S.top ) 
        return ERROR;
    e = *(S.top-1);
    return OK;
}

Status Push(SqStack &S, SElemType e) {
    if ( S.top-S.base>=STACK_INIT_SIZE ) {
        S.base= (SElemType*)realloc(S.base, S.stacksize+STACKINCREMENT*sizeof(SElemType));
        if ( !S.base )
            exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    
    return OK;
}

Status Pop(SqStack &S, SElemType &e) {
    if ( S.top == S.base ) 
        return ERROR;
    e = *--S.top;

    return OK;
}

Status StackTraverse(SqStack S, void(Visit)(SElemType)) {
    SElemType *p = S.base;
    while ( p<S.top ) {
        Visit(*p++);
    }
    printf("\n");

    return OK;
}

#endif 