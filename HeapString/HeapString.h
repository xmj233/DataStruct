/* 串的堆分配存储表示
    20200203
    周一     */

#ifndef HEAPSTRING_H
#define HEAPSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

typedef struct {
    char *ch;
    int length;
}HString;

Status InitString(HString &T);

Status StrAssign_H(HString &T, char *chars);

Status StrCopy_H(HString &T, HString S);

Status StrEmpty_H(HString S);

int StrCompare_H(HString S, HString T);

int StrLength_H(HString S);

Status ClearString_H(HString &S);

Status DestoryString_H(HString &S);

Status Concat_H(HString &T, HString S1, HString S2);

Status SubString_H(HString &Sub, HString S, int pos, int len);

int Index_H(HString S, HString T, int pos);

Status Replace_H(HString &S, HString T, HString V);

Status StrInsert_H(HString &S, int pos, HString T);

Status StrDelete_H(HString &S, int pos, int len);

Status StrTraverse_H(HString S);

#endif