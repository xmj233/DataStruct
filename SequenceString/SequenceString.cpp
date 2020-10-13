#ifndef SEQUENCESTRING_CPP
#define SEQUENCESTRING_CPP

#include "SequenceString.h"

Status StrAssign_Sq(SString &T, char *chars) {
    int i, len;
    len = 0;
    for ( i=0; chars[i]!='\0'; i++ ) 
        len ++;
    if ( len<=MAXSTRLEN ) {
        T[0] = len;
        for ( i=1; i<=len; i++ ) {
            T[i] = chars[i-1];
        }
        return OK;
    }
    return ERROR;
}

void StrCopy_Sq(SString &T, SString S) {
    int i;
    for ( i=0; i<=S[0]; i++ ) {
        T[i] = S[i];
    }
}

Status StrEmpty_Sq(SString S) {
    if ( S[0]==0 ) 
        return TRUE;
    else 
        return FALSE;
}

int StrCompare_Sq(SString S, SString T) {
    int i, len_s, len_t;
    len_s = StrLength_Sq(S);
    len_t = StrLength_Sq(T);
    i = 1;
    while ( i<=len_s&&i<=len_t ) {
        if ( S[i]==T[i] ) 
            i ++;
        else 
            return (S[i]-T[i]);
    }
    return (S[0]-T[0]);
}

int StrLength_Sq(SString S) {
    return S[0];
}

Status ClearString_Sq(SString &S) {
    S[0] = 0;

    return OK;
}

Status DestroyString_Sq(SString &S) {
    //无法销毁
}

Status Concat_Sq(SString &T, SString S1, SString S2) {
    int i;
    Status uncat;
    if ( S1[0]+S2[0]<=MAXSTRLEN ) {
        for ( i=1; i<=S1[0]; i++ ) 
            T[i] = S1[i];
        for ( i=1; i<=S2[0]; i++ )
            T[S1[0]+i] = S2[i];
        T[0] = S1[0] + S2[0];
        uncat = TRUE;
    }
    else if ( S1[0]<MAXSTRLEN ) {
        for ( i=1; i<=S1[0]; i++ ) 
            T[i] = S1[i];
        for ( i=1; i<=MAXSTRLEN-S1[0]; i++ ) 
            T[S1[0]+i] = S2[i];
        T[0] = MAXSTRLEN;
        uncat = FALSE;
    }
    else {
        for ( i=1; i<=S1[0]; i++ )
            T[i] = S1[i];
            T[0] = MAXSTRLEN;
            uncat = FALSE;
    }
    return uncat;
}

Status SubString_Sq(SString &Sub, SString S, int pos, int len) {
    int i;
    if ( pos<1 || pos>StrLength_Sq(S) || len<0 || len>StrLength_Sq(S)-pos+1 )
        return ERROR;

    for ( i=1; i<=len; i++ )
        Sub[i] = S[pos+i-1];
    Sub[0] = len;

    return OK;
}

int Index_Sq(SString S, SString T, int pos) {
    int len_s, len_t;
    SString sub;
    int i;
    if ( pos >0 ) {
        i = pos;
        len_s = StrLength_Sq(S);
        len_t = StrLength_Sq(T);

        while ( i<=len_s-len_t+1 ) {
            SubString_Sq(sub, S, i, len_t);
            if ( !StrCompare_Sq(T, sub) ) 
                return i;
            i ++;
        }
    }
    return 0;
}

Status Replace_Sq(SString &S, SString T, SString V) {
    int i;
    i = Index_Sq(S, T, 1);
    while ( i&&S[0]-T[0]+V[0]<=MAXSTRLEN ) {
        StrDelete_Sq(S, i, T[0]);
        StrInsert_Sq(S, V, i);
        i += V[0];

        i = Index_Sq(S, T, i);
    }
    if ( i==0 )         //替换完毕
        return OK;
    else                //S中依然存在T，但是V已经差不进去了 
        return FALSE;
}

Status StrInsert_Sq(SString &S, SString T, int pos) {
    int i;
    if ( pos<1 || pos>StrLength_Sq(S)+1 || S[0]+T[0]>MAXSTRLEN ) 
        return ERROR;
    
    for ( i=S[0]; i>=pos; i-- ) {
        S[i+T[0]] = S[i];
    }
    for ( i=pos; i<=pos+T[0]-1; i++ ) {
        S[i] = T[i-pos+1];
    }
    S[0] += T[0];

    return OK;
}

Status StrDelete_Sq(SString &S, int pos, int len) {
    int i;
    if ( pos<1 || pos>StrLength_Sq(S)-len+1 || len<0 ) 
        return ERROR;

    for ( i=pos+len; i<=S[0]; i++ ) 
        S[i-len] = S[i];
    S[0] -= len;

    return OK;
}

Status StrTraverse_Sq(SString S) {
    int i;
    for ( i=1; i<=S[0]; i++ ) {
        printf("%c ", S[i]);
    }
    printf("\n");
    return OK;
}

#endif