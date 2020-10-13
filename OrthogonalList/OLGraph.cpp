#ifndef OLGRAPH_CPP
#define OLGRAPH_CPP

#include "OLGraph.h"

Status CreateGraph_OL(OLGraph &G, char *f) {
    int i, j, k, m;
    VertexType_OL   v1, v2;
    ArcBox  *p;
    k   =   0;
    G.vexnum    =   f[k++]-'0';
    G.arcnum    =   f[k++]-'0';   
    k++;

    for ( i=0; i<G.vexnum; i++ ) {
        G.xlist[i].data =   f[k++];
        G.xlist[i].firstin  =   NULL;
        G.xlist[i].firstout =   NULL;
    }

    for ( m=0; m<G.arcnum; m++ ) {
        k++;
        v1  =   f[k++];
        v2  =   f[k++];
        i   =   LocateVex_OL(G, v1);
        j   =   LocateVex_OL(G, v2);

        if ( !(p=(ArcBox*)malloc(sizeof(ArcBox))) )
            exit(OVERFLOW);
        p->tailvex  =   i;
        p->headvex  =   j;
        p->hlink    =   G.xlist[j].firstin;
        p->tlink    =   G.xlist[i].firstout;
        G.xlist[i].firstout =   G.xlist[j].firstin  =   p;
    }
    return OK;
}

int LocateVex_OL(OLGraph G, VertexType_OL v) {
    int i;
    for ( i=0; i<G.vexnum; i++ ) 
        if ( G.xlist[i].data==v )
            return i;
    return -1;
}

int FirstAdjVex_OL(OLGraph G, VertexType_OL v) {
    int i;
    i   =   LocateVex_OL(G, v);
    if ( i!=-1 ) {
        if ( G.xlist[i].firstout )
            return G.xlist[i].firstout->headvex;
    }
    return -1;
}

int NextAdjVex_OL(OLGraph G, VertexType_OL w, VertexType_OL v) {
    int i, j;
    ArcBox *p, *q;;
    i   =   LocateVex_OL(G, w);
    j   =   LocateVex_OL(G, v);
    if ( i!=-1&&j!=-1 ) {
        if ( G.xlist[i].firstout&&G.xlist[i].firstout->tlink ) {
            p   =   G.xlist[i].firstout;
            q   =   p->tlink;
        }
        while ( p->headvex!=j&&q->tlink ) {
            p   =   q;
            q   =   p->tlink;
        }
        if ( p->headvex==j )
            return q->headvex;
    }
    return -1;
}

Status DFSTraverse_OL(OLGraph G, void(Visit)(VertexType_OL)) {
    int v;
    VisitFunc   =   Visit;
    for ( v=0; v<G.vexnum; v++ ) {
        Visited[v]  =   FALSE;
    }
    for ( v=0; v<G.vexnum; v++ )
        if ( !Visited[v] )
            DFS_OL(G, v);
    printf("\n");
    return OK;
}

Status DFS_OL(OLGraph G, int v) {
    int w;
    Visited[v]  =   TRUE;
    VisitFunc(G.xlist[v].data);
    for ( w=FirstAdjVex_OL(G, G.xlist[v].data); w!=-1; w=NextAdjVex_OL(G, G.xlist[v].data, G.xlist[w].data)) {
        if ( Visited[w]==FALSE )
            DFS_OL(G, w);
    }
    return OK;
}

Status BFSTraverse_OL(OLGraph G, void(Visit)(VertexType_OL)) {
    int i, w;
    QElemType e;
    LinkQueue Q;
    InitQueue(Q);
    for ( i=0; i<G.vexnum; i++ )
        Visited[i]=FALSE;
    for ( i=0; i<G.vexnum; i++ ) {
        if ( !Visited[i] ) {
            Visited[i] = TRUE;
            Visit(G.xlist[i].data);
            EnQueue(Q, i);
            while ( !QueueEmpty(Q) ) {
                DeQueue(Q, e);
                for ( w=FirstAdjVex_OL(G, G.xlist[e].data); w!=-1; w=NextAdjVex_OL(G, G.xlist[e].data, G.xlist[w].data)) {
                    if ( !Visited[w] ) {
                        Visited[w]  =   TRUE;
                        Visit(G.xlist[w].data);
                        EnQueue(Q, w);
                    }
                }
            }
        }
    }
    return OK;
}

#endif