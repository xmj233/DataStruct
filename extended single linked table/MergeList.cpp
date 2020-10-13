#include "ExtenLinkedList.cpp"

Status MergeList(LinkList &La, LinkList &Lb, LinkList &Lc, int(Compare)(ElemType, ElemType));

int compare(ElemType e1, ElemType e2);

Status CreateList(LinkList &L, int n);

void Print(ElemType e);

int main() {
    LinkList La, Lb, Lc;
    printf("创建La:");
    CreateList(La, 3);
    printf("输入La：");
    ListTraverse(La, Print);
    printf("\n创建Lb:");
    CreateList(Lb, 5);
    printf("输出Lb：");
    ListTraverse(Lb, Print);
    printf("\n合体：");
    MergeList(La, Lb, Lc, compare);
    ListTraverse(Lc, Print);
    return 0;
}

void Print(ElemType e) {
    printf("%d ", e);
}

int compare(ElemType e1, ElemType e2) {
    return e1 - e2;
}

Status CreateList(LinkList &L, int n) {
    int i, tmp;
    if ( !InitList(L) )
        return ERROR;
    for ( i=1; i<=n; i++ )  {
        scanf("%d", &tmp);
        ListInsert(L, i, tmp);
    }
    return OK;
}

Status MergeList(LinkList &La, LinkList &Lb, LinkList &Lc, int(Compare)(ElemType, ElemType)) {
    Link ha, hb, pa, pb, q;
    ElemType a , b;
    if ( !InitList(Lc) )
        return ERROR;
    ha = GetHead(La);
    hb = GetHead(Lb);
    pa = NextPos(La, ha);
    pb = NextPos(Lb, hb);
    while ( !ListEmpty(La)&&!ListEmpty(Lb) ) {
        a = GetCurElem(pa);
        b = GetCurElem(pb);
        if ( Compare(a, b)<=0 ) {
            DelFirst(La, ha, q);
            InsFirst(Lc, Lc.tail, q);
            pa = NextPos(La, ha);
        } else {
            DelFirst(Lb, hb, q);
            InsFirst(Lc, Lc.tail, q);
            pb = NextPos(Lb, hb);
        }
    }
    if ( !ListEmpty(La) ) 
        Append(Lc, pa);
    else 
        Append(Lc, pb);
    FreeNode(ha);
    FreeNode(hb);
    return OK;
}
