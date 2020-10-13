#ifndef PATTERNMATCHING_CPP
#define PATTERNMATCHING_CPP

#include "PatternMatching.h"

int Index_BF(SString S, SString T, int pos) {
    int i, j;
    i = pos;
    j = 1;
    while ( i<=S[0]&&j<=T[0] ) {
        if ( S[i]==T[i] ) {
            i ++;
            j ++;
        } else {
            i = i-j+2;
            j = 1;
        }
    }
    if ( j>T[0] )
        return i-T[0];
    else 
        return 0;
}

int Index_KMP(SString S, SString T, int pos, int next[]) {
    int i, j;
    i = pos;
    j = 1;
    while ( i<=S[0]&&j<=T[0] ) {
        if ( j==0||S[i]==T[j] ) {
            i ++;
            j ++;
        }
        else 
            j = next[j];
    }
    if ( j>T[0] )
        return i-T[0];
    else 
        return 0;
}

void get_next(SString T, int next[]) {
    int i, j;
    next[1] =   0;
    i       =   1;
    j       =   0;
    while ( i<T[0] ) {
        if ( j==0||T[i]==T[j] ) {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

void get_nextval(SString T, int nextval[]) {
    int i, j;
    nextval[1]  =   0;
    i   =   1;
    j   =   0;
    while ( i<T[0] ) {
        if ( j==0||T[i]==T[j] ) {
            i ++;
            j ++;
            if ( T[i]!=T[j] )
                nextval[i] = j;
            else 
                nextval[i] = nextval[j];
        }
        else 
            j = nextval[j];
    }
}

#endif