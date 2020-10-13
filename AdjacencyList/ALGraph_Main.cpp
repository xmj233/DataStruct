#include "ALGraph.cpp"

void Print(VertexType_AL e) {
    printf("%c ", e);
}

int main() {
    ALGraph G1, G2;
    char f1[100] = "440 ABCD AB AD BC CA";
    char f2[100] = "560 ABCDE AB AD BE CD CE DE";
    printf("Create a directed graph.\n");
    CreateGraph_AL(G1, f1, DG);
    ShowGraph_AL(G1);

    printf("\nCreate an undirected graph.\n");
    CreateGraph_AL(G2, f2, UDG);
    ShowGraph_AL(G2);
    
    printf("\nTest of FirstAdjVex_AL function.\n");
    printf("%d ", FirstAdjVex_AL(G1, 'A'));
    printf("%d ", FirstAdjVex_AL(G1, 'B'));
    printf("%d ", FirstAdjVex_AL(G1, 'C'));
    printf("%d\n", FirstAdjVex_AL(G1, 'D'));
    printf("%d ", FirstAdjVex_AL(G2, 'A'));
    printf("%d ", FirstAdjVex_AL(G2, 'B'));
    printf("%d ", FirstAdjVex_AL(G2, 'C'));
    printf("%d ", FirstAdjVex_AL(G2, 'D'));
    printf("%d\n", FirstAdjVex_AL(G2, 'E'));

    printf("\nTest of NextAdjVex_AL function.\n");
    printf("%d ", NextAdjVex_AL(G1, 'A', 'B'));
    printf("%d \n", NextAdjVex_AL(G1, 'B', 'C'));
    printf("%d ", NextAdjVex_AL(G2, 'A', 'B'));
    printf("%d ", NextAdjVex_AL(G2, 'A', 'D'));
    printf("%d ", NextAdjVex_AL(G2, 'E', 'B'));
    printf("%d ", NextAdjVex_AL(G2, 'E', 'C'));

    printf("\nTest of DFSTraverse_AL function.\n");
    DFSTraverse_AL(G1, Print);
    DFSTraverse_AL(G2, Print);

    printf("\nTest of BFSTraverse_AL function.\n");
    BFSTraverse_AL(G1, Print);
    BFSTraverse_AL(G2, Print);
    return 0;
}