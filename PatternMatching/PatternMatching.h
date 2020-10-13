#ifndef PATTERNMATCHING_H
#define PATTERNMATCHING_H

#include "../SequenceString/SequenceString.cpp"

int Index_BF(SString S, SString T, int pos);

int Index_KMP(SString S, SString T, int pos, int next[]);

void get_next(SString T, int next[]);

void Get_nextval(SString T, int nextval[]);

#endif