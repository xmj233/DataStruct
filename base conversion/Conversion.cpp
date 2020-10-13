#ifndef CONVERSION_CPP
#define CONVERSION_CPP

#include "Conversion.h"

void conversion() {
    SqStack S;
    int d, e;
    InitStack(S);
    scanf("%d", &d);
    while ( d ) {
        Push(S, d%8);
        d /= 8;
    }
    while ( !StackEmpty(S) ) {
        Pop(S, e) ;
        printf("%d", e);
    }
}

#endif