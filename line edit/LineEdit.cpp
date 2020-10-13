#ifndef LINEEDIT_CPP
#define LINEEDIT_CPP

#include "LineEdit.h"

void LineEdit() {
    SqStack S;
    InitStack(S);
    char c;
    int e;
    c = getchar();
    while ( c!=EOF ) {
        while ( c!=EOF&&c!='\n' ) {
            switch (c)
            {
            case '#':
                Pop(S, e);
                break;
            case '@':
                ClearStack(S);
                break;
            default:
                Push(S, c);
                break;
            }
            c = getchar();
        }
        StackTraverse(S, Print);
        ClearStack(S);
        c =getchar();
    }
    if ( c==EOF ) 
        StackTraverse(S, Print);
    DestoryStack(S);
}

void Print(SElemType ch) {
    printf("%c ", ch);
}

#endif