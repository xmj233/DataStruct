#include "DuCircularLinkedList.cpp"

void Print(ElemType e) {
    printf("%d ", e);
}

Status equal(ElemType e1, ElemType e2) {
    return e1==e2 ? TRUE : FALSE;
}

int main() {
    DuLinkList L;
    int i;
    ElemType e, pre, next;
    InitList(L);
    printf("Test of ListInsert function.\n");
    printf("创建一个双循环链表.\n");
    for ( i=1; i<=5; i++ ) 
        ListInsert(L, i, i*2);
    ListTraverse(L, Print);
    printf("在第一个元素前插入111.\n");
    ListInsert(L, 1, 111);
    ListTraverse(L, Print);

    printf("\nTest of ListDelete function.\n");
    printf("删除最后一个元素.\n");
    ListDelete(L, ListLength(L), e);
    ListTraverse(L, Print);

    printf("\nTest of PriorElem and NextElem function.\n");
    PriorElem(L, 2, pre);
    printf("求元素2的前驱：%d.\n", pre);
    printf("求元素111的前驱：");
    if ( !PriorElem(L, 111, pre) )
        printf("ERROR.\n");

    NextElem(L, 2, next);
    printf("求元素2的后继：%d.\n", next);
    printf("求元素8的后继：");
    if ( !NextElem(L, 8, next) )
        printf("ERROR.\n");

    printf("\nTest of LocateElem function.\n");
    printf("元素6的位序为%d.\n", LocateElem(L, 6, equal));

    printf("\nTest of GetElem function.\n");
    GetElem(L, 1, e);
    printf("%d\n", e);

    printf("\nTest of ClearList and ListLength and ListEmpty function.\n");
    printf("L的长度为：%d.\n", ListLength(L));
    if ( !ListEmpty(L) )
        printf("L不为空.\n");
    else printf("L空.\n");
    printf("清空L.\n");
    ClearList(L);
    printf("L的长度为：%d.\n", ListLength(L));
    if ( !ListEmpty(L) )
        printf("L不为空.\n");
    else printf("L空.\n");
    printf("销毁L");
    DestoryList(L);
    return 0;
}