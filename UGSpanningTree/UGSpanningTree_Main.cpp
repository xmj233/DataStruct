#include "UGSpanningTree.cpp"

void Print(TElemType_CS e) {
    printf ( "%c ", e);
}

int main() {
    ALGraph G;
    CSTree T;
    char *f = "990 ABCDEFGHI AB AC AD AE BF EF EG FG HI";
    printf("Create an UG Graph.\n");
    CreateUDG_AL(G, f);
    ShowGraph_AL(G);

    printf("Create a Spanning Tree.\n");
    DFSForest(G, T);
    printf("PreOrderTraver.\n");
    PreOrderTraverse_CS(T, Print);
    printf("\nInOrderTraverse.\n");
    InOrderTraverse_CS(T, Print);
}