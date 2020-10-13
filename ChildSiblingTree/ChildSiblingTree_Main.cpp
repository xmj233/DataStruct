#include "ChildSiblingTree.cpp"

void Print(TElemType_CS e) {
    printf("%c ", e);
}

int main() {
    char fp[100]    =   "RAD^E^^B^CFG^H^K^^^^^";
    CSTree T;
    InitTree_CS(T);
    CreateTree_CS(fp, T);
    PreOrderTraverse_CS(T, Print);
    printf("\n");
    InOrderTraverse_CS(T, Print);

    return 0;
}