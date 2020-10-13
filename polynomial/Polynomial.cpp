#ifndef POLYNOMIAL_CPP
#define POLYNOMIAL_CPP

#include "Polynomial.h"

void CreatePolyn(Polynomial &P, int m) {
    int i;
    ElemType e;
    Link h, p;
    InitList(P);
    h = GetHead(P);
    e.coef = 0.0;
    e.expn = -1;
    SetCurElem(h, e);
    for ( i=1; i<=m; i++ ) {
        scanf("%f,%d", &e.coef, &e.expn);
        MakeNode(p, e);
        InsFirst(P, h, p);
        h = h->next;
    } 
}

void DestoryPolyn(Polynomial &P) {
    DestoryList(P);
}

void PrintPolyn(Polynomial P) {
    Link p;
    int i;
    p = P.head->next;
    for ( i=1; i<=P.len; i++ ) {
        if ( i==1 )
            printf("%g", p->data.coef);
        else {
            if ( p->data.coef>0 ) {
                printf(" + ");
                printf("%g", p->data.coef);
            } else {
                printf(" - ");
                printf("%g", -p->data.coef);
            }
        }
        if ( p->data.expn ) {
            printf("x");
            if ( p->data.expn!=1 )
                printf("^%d", p->data.expn);
        }
        p = p->next;
    }
}

int PolynLength(Polynomial P) {
    return P.len;
}

void AddPolyn(Polynomial &Pa, Polynomial &Pb) {
    float sum;
    Position ha, hb, qa, qb;
    ElemType a, b;
    ha = GetHead(Pa);
    hb = GetHead(Pb);
    qa = NextPos(Pa, ha);
    qb = NextPos(Pb, hb);
    while ( qa&&qb ) {
        a = GetCurElem(qa);
        b = GetCurElem(qb);
        switch( cmp(a, b) ) {
            case -1:
                ha = qa;
                qa = NextPos(Pa, qa);
                break;
            case 0:
                sum = a.coef + b.coef;
                if ( sum!=0.0 ) {
                    qa->data.coef = sum;
                    ha = qa;
                } else {
                    DelFirst(Pa, ha, qa);
                    FreeNode(qa);
                }
                DelFirst(Pb, hb, qb);
                FreeNode(qb);
                qa = NextPos(Pa, ha);
                qb = NextPos(Pb, hb);
                break;
            case 1:
                DelFirst(Pb, hb, qb);
                InsFirst(Pa, ha, qb);
                qb = NextPos(Pb, hb);
                ha = NextPos(Pa, ha);
                break;
        } //switch
    } //while
    if ( qb ) 
        Append(Pa, qb);
    FreeNode(hb);
}

void SubtractPolyn(Polynomial &Pa, Polynomial &Pb) {
    Position ha, hb, qa, qb;
    ElemType a, b;
    float count;
    ha = GetHead(Pa);
    hb = GetHead(Pb);
    qa = NextPos(Pa, ha);
    qb = NextPos(Pb, hb);
    while ( qa&&qb ) {
        a = GetCurElem(qa);
        b = GetCurElem(qb);
        switch ( cmp(a, b) ) {
            case -1:
                ha = qa;
                qa = NextPos(Pa, qa);
                break;
            case 0:
                count = a.coef-b.coef;
                if ( count!=0 ) {
                    qa->data.coef = count;
                    ha = qa;
                } else {
                    DelFirst(Pa, ha, qa);
                    FreeNode(qa);
                }
                DelFirst(Pb, hb, qb);
                FreeNode(qb);
                qa = NextPos(Pa, ha);
                qb = NextPos(Pb, hb);
                break;
            case 1:
                DelFirst(Pb, hb, qb);
                qb->data.coef = -qb->data.coef;
                InsFirst(Pa, ha, qb);
                ha = NextPos(Pa, ha);
                qb = NextPos(Pb, hb);
                break;
        } //switch
    } //while
    if ( qb ) {
        Position r = qb;
        while ( r ) {
            r->data.coef = -r->data.coef;
            r = r->next;
        }
        Append(Pa, qb);
    }
    FreeNode(hb);
}

void MuLitiplyPolyn(Polynomial &Pa, Polynomial &Pb) {
    Polynomial Pc, Pcc;
    int i, j, la;
    Position qa, qb, ha;
    Link s;
    ha = GetHead(Pa);
    la = PolynLength(Pa);
    InitList(Pc);
    //for ( i=1; i<=PolynLength(Pa); i++ ) {  这是错误的。。。
    for ( i=1; i<=la; i++ ) {
        DelFirst(Pa, ha, qa);
        qb = Pb.head->next;
        InitList(Pcc);
        for ( j=1; j<=PolynLength(Pb); j++ ) {
            s = (Link)malloc(sizeof(LNode));
            s->data.coef = qa->data.coef * qb->data.coef;
            s->data.expn = qa->data.expn + qb->data.expn;
            s->next = NULL;
            Append(Pcc, s);
            qb = qb->next;
        }
        AddPolyn(Pc, Pcc);
    }
    AddPolyn(Pa, Pc);
    DestoryList(Pc);
}

int cmp(ElemType a, ElemType b) {
    int i;
    i = a.expn-b.expn;
    if ( i<0 ) 
        return -1;
    else if ( i==0 )
        return 0;
    else 
        return 1;
}


#endif