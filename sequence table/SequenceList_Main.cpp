#include "SequenceList.cpp"

void Print(ElemType e) {
    printf("%d ", e);
}

Status Compare(ElemType e1, ElemType e2) {
    return e1==e2 ? TRUE : FALSE;
}

int main() {
    SqList L;
    InitList(L);
    printf("Test of ListInsert function.\n");
    for ( int i=1; i<=10; i++ ) {
        ListInsert(L, i, i*2);
    }
    ListTraverse(L, Print);
    printf("\n");

    printf("Test of GetElem function.\n");
    ElemType e;
    GetElem(L, 2, e);
    printf("%d\n",e);

    printf("Test of PriorElem and NextElem function.j\n");
    ElemType pre_e;
    ElemType next_e;
    PriorElem(L, 10, pre_e);
    printf("%d\n",pre_e);
    PriorElem(L, 2, pre_e);
    printf("%d\n",pre_e);
    NextElem(L, 20, next_e);
    printf("%d\n",next_e);
    NextElem(L, 6, next_e);
    printf("%d\n",next_e);

    printf("Test of LocateElem function.\n");
    printf("%d\n", LocateElem(L, 12, Compare));

    printf("Test of ListDelete function.\n");
    ElemType ee;
    ListDelete(L, 3, ee);
    printf("%d\n", ee); 
    ListTraverse(L, Print);

    printf("\nTest of DestoryList.\n");
    DestoryList(L);
    printf("%d, %d\n", L.listsize, L.length);


    return 0;
}