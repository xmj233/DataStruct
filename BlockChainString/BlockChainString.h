#ifndef BLOCKCHAINSTRING_H
#define BLOCKCHAINSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

#define CHUNKSIZE 3

typedef struct Chunk {
    char ch[CHUNKSIZE];
    struct Chunk *next;
}Chunk;

typedef struct {
    Chunk *head, *tail;
    int curlen;
}LString;

Status InitString_L(LString &T);

Status StrAssign_L(LString &T, char *chars);

Status StrCopy_L(LString &T, LString S);

Status StrEmpty_L(LString S);

int StrCompare_L(LString S, LString T);

int StrLength_L(LString S);

Status ClearString_L(LString &S);

Status DestoryString_L(LString &S);

Status Concat_L(LString &T, LString S1, LString S2);

Status SubString_L(LString &Sub, LString S, int pos, int len);

int Index_L(LString S, LString T, int pos);

Status Replace_L(LString &S, LString T, LString V);

Status StrInsert_L(LString &S, int pos, LString T);

Status StrDelete_L(LString &S, int pos, int len);

Status StrTraverse_L(LString S);

#endif