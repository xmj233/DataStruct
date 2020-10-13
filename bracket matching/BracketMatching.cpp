#ifndef BRACKETMATCHING_CPP
#define BRACKETMATCHING_CPP

#include "BracketMatching.h"

void BracketMatching() {
    SqStack S;
    int i, e;
    char s[50] = {0};
    InitStack(S);
    printf("请输入一个括号串：");
    scanf("%s", s);
    Push(S, s[0]);
    for ( i=1; s[i]!=0; i++ ) {
        if ( !StackEmpty(S) ) {
            GetTop(S, e);
            if ( s[i]==')'&&e==(int)'(' || s[i]==']'&&e==(int)'[' )
                Pop(S, e);
            else 
                Push(S, s[i]);
        }
        else {
            Push(S, s[i]);
        }
    }

    if ( StackEmpty(S) )
        printf("括号匹配");
    else 
        printf("括号不匹配");
}
#endif