#include "MGraph.cpp"

void Print(VertexType e) {
    printf("%c ", e);
}

int main() {
    FILE *fp;
    MGraph DG1, DN1, UDG1, UDN1;
    char f1[100] = "44ABCDABBCCAAD";
    char f2[100] = "69ABCDEF AB1 AF3 BC5 CA6 CD5 DA9 DF8 ED4 FC7";
    char f3[100] = "56ABCDE AB AD BE CD CE DE";
    char f4[100] = "56ABCDE AB1 AC3 AE5 BC2 CD4 DE6";
    printf("Create a directed graph.\n");
    CreateGraph_M(f1, DG1, DG);
    ShowGraph_M(DG1);
    printf("\nCreate a directed net.\n");
    CreateGraph_M(f2, DN1, DN);
    ShowGraph_M(DN1);
    printf("\nCreate an undirected graph.\n");
    CreateGraph_M(f3, UDG1, UDG);
    ShowGraph_M(UDG1);
    printf("\nCreate an undirected net.\n");
    CreateGraph_M(f4, UDN1, UDN);
    ShowGraph_M(UDN1);

    printf("\nTest of DFSTraverse function.\n");
    DFSTraverse_M(DG1, Print);
    DFSTraverse_M(DN1, Print);
    DFSTraverse_M(UDG1, Print);
    DFSTraverse_M(UDN1, Print);

    printf("\nTest of BFSTraverse function.\n");
    BFSTraverse_M(DG1, Print);
    BFSTraverse_M(DN1, Print);
    BFSTraverse_M(UDG1, Print);
    BFSTraverse_M(UDN1, Print);

    printf("\nTest fo InsertVex_M function.\n");
    InsertVex_M(DG1, 'M');
    ShowGraph_M(DG1);
    InsertVex_M(DN1, 'M');
    ShowGraph_M(DN1);
    InsertVex_M(UDG1, 'M');
    ShowGraph_M(UDG1);
    InsertVex_M(UDN1, 'M');
    ShowGraph_M(UDN1);

    printf("\nTest of DeleteVex_M function.\n");
    DeleteVex_M(DG1, 'D');
    ShowGraph_M(DG1);
    DeleteVex_M(DN1, 'F');
    ShowGraph_M(DN1);
    DeleteVex_M(UDG1, 'D');
    ShowGraph_M(UDG1);
    DeleteVex_M(UDN1, 'D');
    ShowGraph_M(UDN1);
    
    printf("\nTest of InsertArc_M function.\n");
    InsertArc_M(DG1, 'C', 'M', 1);
    ShowGraph_M(DG1);
    InsertArc_M(DN1, 'C', 'M', 10);
    ShowGraph_M(DN1);
    InsertArc_M(UDG1, 'C', 'M', 1);
    ShowGraph_M(UDG1);
    InsertArc_M(UDN1, 'C', 'M', 10);
    ShowGraph_M(UDN1);

    printf("\nTest of DeleteArc_M function.\n");
    DeleteArc_M(DG1, 'C', 'M');
    ShowGraph_M(DG1);
    DeleteArc_M(DN1, 'C', 'M');
    ShowGraph_M(DN1);
    DeleteArc_M(UDG1, 'C', 'M');
    ShowGraph_M(UDG1);
    DeleteArc_M(UDN1, 'C', 'M');
    ShowGraph_M(UDN1);
    return 0;
}