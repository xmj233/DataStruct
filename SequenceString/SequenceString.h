/*  串的定长顺序存储表示
    2020.0202
    周日     */


#ifndef SEQUENCESTRING_H
#define SEQUENCESTRING_H

#include <stdio.h>
#include <windows.h>
#include "../Status.h"

#define MAXSTRLEN 255
typedef unsigned char SString[255+1];

//生成一个值等于chars的串T
Status StrAssign_Sq(SString &T, char *chars);

//串复制
void StrCopy_Sq(SString &T, SString S);

//判空
Status StrEmpty_Sq(SString S);

//比较S和T的大小
int StrCompare_Sq(SString S, SString T);

//求串长
int StrLength_Sq(SString S);

//清空串
Status ClearString_Sq(SString &S);

//销毁串
Status DestroyString_Sq(SString &S);

//串连接
Status Concat_Sq(SString &T, SString S1, SString S2);

//用Sub返回串S中第pos个字符起长度为len的串
Status SubString_Sq(SString &Sub, SString S, int pos, int len);

//返回T在S中第pos个字符之后第一次出现的位置，不存在返回0
int Index_Sq(SString S, SString T, int pos);

//用V替换串S中所有的串T
Status Replace_Sq(SString &S, SString T, SString V);

//在第pos个字符前插入串T
Status StrInsert_Sq(SString &S, SString T, int pos);

//删除串S中第pos个字符起长度为len的字符
Status StrDelete_Sq(SString &S, int pos, int len);

//串遍历
Status StrTraverse_Sq(SString S);


#endif