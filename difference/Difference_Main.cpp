#include "Difference.cpp"

void Print(ElemType e) {
    printf("%d ", e);
}

int main() {
    SLinkList space;
    Difference(space);
    ListTraverse(space, Print);
    return 0;
}