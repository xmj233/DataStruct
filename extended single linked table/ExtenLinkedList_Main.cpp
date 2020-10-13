#include "ExtenLinkedList.cpp"

void Print(ElemType e) {
    printf("%d ", e);
} 

Status equal(ElemType e1, ElemType e2) {
    return e1==e2 ? TRUE : FALSE;
}

int main() {
    Link app,app1 , rem, inss, insp, insss, comp;
    LinkList L;
    ElemType e;
    int i;
    InitList(L);
    printf("Test of ListInsert function.\n");
    for ( i=1; i<=10; i++ ) 
        ListInsert(L, i, i);
    ListTraverse(L, Print);

    printf("\n\nTest of ListDelete function.\n");
    ListDelete(L, 1, e);
    ListTraverse(L, Print);

    printf("\n\n Test of Append function.\n");
    MakeNode(app, 333);
    MakeNode(app1, 222);
    app->next = app1;
    Append(L, app);
    ListTraverse(L, Print);

    printf("\n\nTest of Remove function.\n");
    Remove(L, rem);
    ListTraverse(L, Print);

    printf("\n\nTest of InsBefore.\n");
    printf("在第一个结点前插入ins结点:");
    MakeNode(inss, 999);
    LocatePos(L, 1, insp);
    InsBefore(L, insp, inss);
    ListTraverse(L, Print);

    printf("\n\nTest of InsAfter.\n");
    printf("在最后一个结点之后插入insss结点:\n");
    MakeNode(insss, 666);
    LocatePos(L, L.len, insp);
    ListTraverse(L, Print);
    printf("\n");
    InsAfter(L, insp, insss);
    ListTraverse(L, Print); 

    printf("\n\nTest of LocateElem function.\n");
    comp = LocateElem(L, 10, equal);
    printf("%d, %d, %d", comp->data, comp->next->data, PriorPos(L, comp)->data);

}