#include "SequenceList.cpp"

void Union(SqList &La, SqList Lb);

Status equal(ElemType e1, ElemType e2);



void Union(SqList &La, SqList Lb) {
    int i;
    ElemType e;
    int La_len = ListLength(La);
    int Lb_len = ListLength(Lb);
    for ( i=1; i<=Lb_len; i++ ) {
        GetElem(Lb, i, e);
        if ( !LocateElem(La, e, equal) ) {
            ListInsert(La, ++La_len, e);
        }
    }
}

Status equal(ElemType e1, ElemType e2) {
    return e1==e2 ? TRUE : FALSE;
}

void Print(ElemType e) {
    printf("%d ", e);
}

int main() {
    int i;
    int a[5] = { 6, 2, 1, 4, 8};
    int b[5] = { 1, 10, 11, 22, 8                                                                                                                                                                                                                                                                                                                                   };
    SqList La, Lb;
    InitList(La);
    InitList(Lb);
    for ( i=1; i<=5; i++) {
        ListInsert(La, i, a[i-1]);
    }
    for ( i=1; i<=5; i++ ) {
        ListInsert(Lb, i, b[i-1]);
    }
    printf("Print La:");
    ListTraverse(La, Print);
    printf("\nPrint Lb:");
    ListTraverse(Lb, Print);
    printf("\nPrint La U Lb:");
    Union(La, Lb);
    ListTraverse(La, Print);
    return 0;
}