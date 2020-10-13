#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

typedef struct {
    float coef;
    int expn;
}ElemType;

#include "../extended single linked table/ExtenLinkedList.cpp"

typedef LinkList Polynomial;

void CreatePolyn(Polynomial &P, int m);

void DestoryPolyn(Polynomial &P);

void PrintPolyn(Polynomial P);

int PolynLength(Polynomial p);

void AddPolyn(Polynomial &Pa, Polynomial &Pb);

void SubtractPolyn(Polynomial &Pa, Polynomial &Pb);

void MulitiplyPolyn(Polynomial &Pa, Polynomial &Pb);

int cmp(ElemType a, ElemType b);


#endif