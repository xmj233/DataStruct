#ifndef UGSPANNINGTREE_CPP
#define UGSPANNINGTREE_CPP


#include "UGSpanningTree.h"

void DFSForest(ALGraph G, CSTree &T) {
    int v;
    T   =   NULL;
    CSTree p, q;
    for ( v=1; v<=G.vexnum; v++ ) {
        Visited[v]  =   FALSE;
    }
    for ( v=1; v<=G.vexnum; v++ ) {
        if ( !Visited[v] ) {
            if ( !(p=(CSTree)malloc(sizeof(CSNode))) )
                exit(OVERFLOW);
            p->data =   GetVex_AL(G, v);
            p->firstchild   =   p->nextsibling  =   NULL;
            if ( !T ) 
                T   =   p;
            else 
                q->nextsibling  =   p;
            q   =   p;
            DFSTree(G, v, p);
        }
    }

} 

void DFSTree(ALGraph G, int v, CSTree &T ) {
    Status first;
    CSTree p, q;
    int w;
    Visited[v]  =   TRUE;
    first   =   TRUE;
    for ( w=FirstAdjVex_AL(G, G.vertices[v].data); w; w=NextAdjVex_AL(G, G.vertices[v].data, G.vertices[w].data) ) {
        if ( !Visited[w] ) {
            if ( !(p=(CSTree)malloc(sizeof(CSTree))) )
                exit(OVERFLOW);
            p->data =   GetVex_AL(G, w);
            p->firstchild   =   p->nextsibling  =   NULL;
            if ( first ) {
                T->firstchild   =   p;
                first   =   FALSE;
            }
            else 
                q->nextsibling  =   p;
            q   =   p;
            DFSTree(G, w, q);
        }
    }
}

#endif

