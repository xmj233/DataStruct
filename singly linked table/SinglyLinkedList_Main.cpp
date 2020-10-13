#include "SinglyLInkedList.cpp"

void Print(ElemType e) {
    printf("%d ", e);
}

Status equal(ElemType e1, ElemType e2) {
    return e1 == e2 ? TRUE : FALSE;
}

int main() {
    LinkList L;
    LinkList T;
    ElemType e, pre, next, get;
    /*printf("Test of CreateList_H function.\n");
    CreateList_H(L, 5);
    ListTraverse(L, Print);*/
    
    printf("\n\nTest of CreateList_T function.\n");
    CreateList_T(T, 6);
    ListTraverse(T, Print);

    printf("\n\nTestof ListEmpty and ListLength function.\n");
    InitList(L);
    if ( ListEmpty(L) )
        printf("L is empty\n");
    if ( !ListEmpty(T) ) 
        printf("T's length is %d.\n", ListLength(T));
    
    printf("\nTest of GetElem function.\n");
    GetElem(T, 5, e);
    printf("The five number is %d.\n", e);

    printf("\nTest of LocateElem function.\n");
    printf("%d\n", LocateElem(T, 4, equal) );

    printf("\nTest of PriorElem and NextElem function.\n");
    PriorElem(T, 6, pre);
    NextElem(T, 1, next);
    printf("%d, %d\n", pre, next);

    printf("\nTest of ListInsert function.\n");
    ListInsert(T, 2, 1111);
    ListTraverse(T, Print);
    printf("length: %d\n", ListLength(T));

    printf("\nTest of ListDelete function.\n");
    ListDelete(T, 1, get);
    ListTraverse(T, Print);
    printf("length: %d\n", ListLength(T));
    printf("%d\n", get);
    


    return 0;
}