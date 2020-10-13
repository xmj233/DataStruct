#include "SequenceList.cpp"

void MergeSqList_1(SqList La, SqList Lb, SqList &Lc);

void MergeSqList_2(SqList La, SqList Lb, SqList &Lc);

void Print(ElemType e);

int main() {
    int a[5] = {2, 4, 6, 8, 10};
    int b[5] = {1, 3, 5, 7, 9};
    SqList La, Lb;
    SqList Lc1, Lc2;
    int i;
    InitList(La);
    InitList(Lb);
    for ( i=1; i<=5; i++ ) {
        ListInsert(La, i, a[i-1]);
        ListInsert(Lb, i, b[i-1]);
    }
    printf("Print La: ");
    ListTraverse(La, Print);
    printf("\nPrint Lb: ");
    ListTraverse(Lb, Print);
    printf("\nMerge1: ");
    InitList(Lc1);
    MergeSqList_1(La, Lb, Lc1);
    ListTraverse(Lc1, Print);
    printf("\nMerge2: ");
    MergeSqList_2(La, Lb, Lc2);
    ListTraverse(Lc2, Print);
    
    return 0;
}

void Print(ElemType e) {
    printf("%d ", e);
}



void MergeSqList_1(SqList La, SqList Lb, SqList &Lc) {
    int i=1, j=1, k=0;
    ElemType ai, bj;
    int La_len = ListLength(La);
    int Lb_len = ListLength(Lb);

    while ( i<=La_len&&j<=Lb_len ) {
        GetElem(La, i, ai);
        GetElem(Lb, j, bj);
        if ( ai<=bj ) {
            ListInsert(Lc, ++k, ai);
            i++;
        }
        else {
            ListInsert(Lc, ++k, bj);
            j++;
        }
    }
    while ( i<=La_len ) {
        GetElem(La, i++, ai);
        ListInsert(Lc, ++k, ai);
    }
    while ( j<=Lb_len ) {
        GetElem(Lb, j++, bj);
        ListInsert(Lc, ++k, bj);
    }
}

void MergeSqList_2(SqList La, SqList Lb, SqList &Lc) {
    ElemType *pa, *pb, *pc, *La_last, *Lb_last;
    pa = La.elem;
    pb = Lb.elem;
    La_last = La.elem + La.length -1;
    Lb_last = Lb.elem + Lb.length -1;
    Lc.length = Lc.listsize = La.length + Lb.length;
    pc = Lc.elem = (ElemType*)malloc(Lc.listsize*sizeof(ElemType));
    if ( !pc )
        exit(OVERFLOW);
    while ( pa<=La_last&&pb<=Lb_last ) {
        if ( *pa <= *pb ) {
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }
    while ( pa<=La_last ) 
        *pc++ = *pa++;
    while ( pb<=Lb_last ) 
        *pc++ = *pb++;
}