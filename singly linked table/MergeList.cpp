#include "SinglyLinkedList.cpp"

void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc);

void Print(ElemType e);

int main() {
    LinkList L, T, C;
    printf("Establishing single chain table by head insertion.\n");
    CreateList_H(L, 5);
    printf("Establishing single chain table by tail insertion.\n");
    CreateList_T(T, 8);
    printf("Merge them.\n");
    MergeList(L, T, C);
    ListTraverse(C, Print);
}

void Print(ElemType e) {
    printf("%d ", e);
}

void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc) {
    LinkList pa, pb, pc;
    pa = La->next;
    pb = Lb->next;
    pc = Lc = La;
    while ( pa&&pb ) {
        if ( pa->data<=pb->data ) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next=pa ? pa : pb;
    free(Lb);
}