#include "StaticLinkedList.cpp"

void Print(ElemType e) {
    printf("%d ", e);
}

int main() {
    SLinkList L;
    int i;
    ElemType e, first, last, pre, next;
    InitList(L);
    printf("\nTest of ListInsert function.\n");
    printf("创建静态链表L：");
    for ( i=1; i<=5; i++ ) 
        ListInsert(L, i, i*2);
    ListTraverse(L, Print);
    printf("在第一个元素前插入222和111\n");
    ListInsert(L, 1, 222);
    ListInsert(L, 1, 111);
    ListTraverse(L ,Print);
    printf("在Length+1个元素前插入333\n");
    ListInsert(L, ListLength(L)+1, 333);
    ListTraverse(L, Print);

    printf("\nTest of ListDelete function.\n");
    printf("删除第二个元素.\n");
    ListDelete(L, 2, e);
    ListTraverse(L, Print);
    printf("删除第一个元素.\n");
    ListDelete(L, 1, e);
    ListTraverse(L, Print);
    printf("删除最后一个元素.\n");
    ListDelete(L, ListLength(L), e);
    ListTraverse(L, Print); 

    printf("\nTest of GetElem function.\n ");
    printf("得到第一个元素和最后一个元素\n");
    GetElem(L, 1, first);
    GetElem(L, ListLength(L), last);
    printf("第一个元素：%d，第二个元素：%d." , first, last);

    printf("\nTest of LocateElem function.\n");
    printf("返回第一个与8相同元素的位序:%d.\n", LocateElem(L, 8));

    printf("nTest of PriorElem and NextElem function.\n");
    PriorElem(L, 4, pre);
    printf("得到元素4的前驱:%d.\n", pre);
    printf("得到元素2的前驱:");
    if ( !PriorElem(L, 2, pre) )
        printf("ERROR\n");
    printf("得到元素100的前驱:");
    if ( !PriorElem(L, 100, pre) )
        printf("ERROR\n");
    NextElem(L, 6, next);
    printf("得到元素6的后继:%d.\n", next);
    printf("得到元素10的后继:");
    if ( !NextElem(L, 10, next) )
        printf("ERROR.\n");
    printf("得到元素100的后继:");
    if ( !NextElem(L, 100, next) )
        printf("ERROR.\n");
    return 0;
}