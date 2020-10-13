#ifndef HEAPSTRING_CPP
#define HEAPSTRING_CPP

#include "HeapString.h"

Status InitString(HString &T) {
    T.ch = NULL;
    T.length = 0;

    return OK;
}

Status StrAssign_H(HString &T, char  *chars) {
    int i, j;
    char *ch;
    if ( T.ch )
        free(T.ch);

    for ( i=0,ch=chars; *ch; ch++, i++ );

    if ( !i ) {
        T.ch = NULL;
        T.length = 0;
    }
    else {
        if ( !(T.ch=(char*)malloc(i*sizeof(char))) ) 
            exit(OVERFLOW);
        for ( j=0; j<i; j++ ) {
            T.ch[j] = chars[j];
        }
        T.length = i;
    }

    return OK;
}

Status StrCopy_H(HString &T, HString S) {
    int i;
    if ( T.ch )
        free(T.ch);
    if ( !(T.ch=(char*)malloc(S.length*sizeof(char))) ) 
        exit(OVERFLOW);
    for ( i=0; i<S.length; i++ )
        T.ch[i] = S.ch[i];
    T.length = S.length;

    return OK;
}

Status StrEmpty_H(HString S) {
    if ( !S.length )
        return TRUE;
    else 
        return FALSE;
}

int StrCompare_H(HString S, HString T) {
    int i;
    for ( i=0; i<S.length&&i<T.length; i++ ) 
        if ( S.ch[i]!=T.ch[i] )
            return S.ch[i]-T.ch[i];
    
    return S.length-T.length;
}

int StrLength_H(HString S) {
    return S.length;
}

Status ClearString_H(HString &S) {
    if ( S.ch ) {
        free(S.ch);
        S.ch = NULL;
    }
    S.length = 0;

    return OK;
}

Status DestoryString_H(HString &S) {
    //因为定义S.ch=NULL时，S为空串，所以不可销毁
}

Status Concat_H(HString &T, HString S1, HString S2) {
    int i;
    if ( T.ch )
        free(T.ch);
    
    if ( !(T.ch=(char*)malloc((S1.length+S1.length)*sizeof(char))) )
        exit(OVERFLOW);
    
    for ( i=0; i<S1.length; i++ )
        T.ch[i] = S1.ch[i];
    T.length = S1.length +S2.length;

    for ( i=0; i<S2.length; i++ )
        T.ch[i+S1.length] = S2.ch[i];

    return OK;
}

Status SubString_H(HString &Sub, HString S, int pos, int len) {
    int i;
    if ( Sub.ch )
        free(Sub.ch);
    if ( pos<1 || pos>S.length || len<0 || len>S.length-pos+1 )
        return ERROR;
    if ( len==0 ) {
        Sub.ch = NULL;
        Sub.length = 0;
    }
    else {
        if ( !(Sub.ch=(char*)malloc(len*sizeof(char))) )
            exit(OVERFLOW);
        for ( i=0; i<len; i++ )
            Sub.ch[i] = S.ch[i+pos-1];
        Sub.length = len;
    }
    return OK;
}

int Index_H(HString S, HString T, int pos) {
    int i=pos, m, n;
    HString Sub;
    InitString(Sub);
    if ( pos>0 ) {
        m = S.length;
        n = T.length;
        while ( i<m-n+1 ) {
            SubString_H(Sub, S, i, T.length);
            if ( StrCompare_H(Sub, T) )
                i ++;
            else 
                return i;
        }
    }
    return 0;
}

Status Replace_H(HString &S, HString T, HString V) {
    int i;
    i = Index_H(S, T, 1);
    while ( i ) {
        StrDelete_H(S, i, T.length);
        StrInsert_H(S, i, V);
        i += V.length;

        i = Index_H(S, T, i);
    }
    return OK;
}

Status StrInsert_H(HString &S, int pos, HString T) {
    int i;
    if ( pos<1 || pos>S.length+1 ) 
        return ERROR;
    S.ch = (char*)realloc(S.ch, (S.length+T.length)*sizeof(char));
    if ( !S.ch )
        exit(OVERFLOW);
    for ( i=S.length-1; i>=pos-1; i-- ) 
        S.ch[i+T.length] = S.ch[i];
    for ( i=0; i<T.length; i++ ) 
        S.ch[i+pos-1] = T.ch[i];
    
    S.length += T.length;
    return OK;
}

Status StrDelete_H(HString &S, int pos, int len) {
    int i;
    if ( pos<1 || pos>S.length-len+1 || len<0 ) 
        return ERROR;
    for ( i=len+pos-1; i<S.length; i++ ) 
        S.ch[i-len] = S.ch[i];    
    S.length -= len;
    if ( !(S.ch=(char*)realloc(S.ch, S.length*sizeof(char))) )
        exit(OVERFLOW);

    return OK;
}

Status StrTraverse_H(HString S) {
    int i;
    if ( S.length==0 ) 
        printf("String is empty.");
    else 
        for ( i=0; i<S.length; i++ ) 
            printf("%c ", S.ch[i]);
    printf("\n");
    
    return OK;
}

#endif