#include "OLGraph.cpp"

void Print(VertexType_OL e) {
    printf("%c ", e);
}

int main() {
    OLGraph G;
    char f[100] =   "47 ABCD DC DB DA CD CA AC AB";
    CreateGraph_OL(G, f);
    DFSTraverse_OL(G, Print);
    BFSTraverse_OL(G, Print);
    return 0;
}