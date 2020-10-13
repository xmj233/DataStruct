#ifndef MGRAPH_CPP
#define MGRAPH_CPP
#include "MGraph.h"

Status CreateGraph_M(char *f, MGraph &G, GraphKind kind) {
    G.kind = kind;
    switch(G.kind) {
        case DG:    CreateDG_M(f, G);   break;
        case DN:    CreateDN_M(f, G);   break;
        case UDG:   CreateUDG_M(f, G); break;
        case UDN:   CreateUDN_M(f, G); break;
    }
    return OK;
}

Status CreateDG_M(char *f, MGraph &G) {
    int i, j, k, l;
    l = 0;
    VertexType v1, v2;

    G.vexnum = f[l++]-'0';
    G.arcnum = f[l++]-'0';
    for ( i=0; i<G.vexnum; i++ ) {
        G.vexs[i] = f[l++];
    }
    for ( i=0; i<G.vexnum; i++ ) {
        for ( j=0; j<G.vexnum; j++ ) {
            G.arcs[i][j].adj = 0;
        }
    }

    for ( k=0; k<G.arcnum; k++ ) {
        v1 = f[l++];  v2 = f[l++];
        i = LocateVex_M(G, v1);
        j = LocateVex_M(G, v2);
        if ( i==-1||j==-1 )
            return ERROR;
        G.arcs[i][j].adj = 1;
    }

    return OK;
}

Status CreateDN_M(char *f, MGraph &G) {
    int i, j, k, l;
    VRType w;
    VertexType v1, v2;
    l = 0;
    G.vexnum = f[l++]-'0';
    G.arcnum = f[l++]-'0';
    for ( i=0; i<G.vexnum; i++ ) {
        G.vexs[i] = f[l++];
    }
    for ( i=0; i<G.vexnum; i++ ) 
        for ( j=0; j<G.vexnum; j++ )
            G.arcs[i][j].adj = INFINITY;
    
    for ( k=0; k<G.arcnum; k++ ) {
        l++;
        v1 = f[l++];
        v2 = f[l++];
        w = f[l++]-'0';
        i = LocateVex_M(G, v1);
        j = LocateVex_M(G, v2);
        if ( i==-1||j==-1 )
            return ERROR;
        G.arcs[i][j].adj = w;
    }
    return OK;
}

Status CreateUDG_M(char *f, MGraph &G) {
    int i, j, k, l;
    VertexType v1, v2;
    l = 0;
    G.vexnum = f[l++]-'0';
    G.arcnum = f[l++]-'0';
    for ( i=0; i<G.vexnum; i++ ) {
        G.vexs[i] = f[l++];
    }
    for ( i=0; i<G.vexnum; i++ ) {
        for ( j=0; j<G.vexnum; j++ ) {
            G.arcs[i][j].adj = 0;
        }
    }
    for ( k=0; k<G.arcnum; k++ ) {
        l++;
        v1 = f[l++];
        v2 = f[l++];
        i = LocateVex_M(G, v1);
        j = LocateVex_M(G, v2);
        if ( i==-1||j==-1 )
            return ERROR;
        G.arcs[i][j].adj = 1;
        G.arcs[j][i].adj = G.arcs[i][j].adj;
    }
    return OK;
}

Status CreateUDN_M(char *f, MGraph &G) {
    int i, j, k, l;
    VertexType v1, v2;
    VRType w;
    l = 0;
    G.vexnum = f[l++]-'0';
    G.arcnum = f[l++]-'0';
    for ( i=0; i<G.vexnum; i++ ) {
        G.vexs[i] = f[l++];
    }
    for ( i=0; i<G.vexnum; i++ ) {
        for ( j=0; j<G.vexnum; j++ ) {
            G.arcs[i][j].adj = INFINITY;
        }
    }
    for ( k=0; k<G.arcnum; k++ ) {
        l ++;
        v1 = f[l++];
        v2 = f[l++];
        w = f[l++]-'0';
        i = LocateVex_M(G, v1);
        j = LocateVex_M(G, v2);
        if ( i==-1||j==-2 )
            return ERROR;
        G.arcs[i][j].adj = w;
        G.arcs[j][i].adj = G.arcs[i][j].adj;
    }
    return OK;
}

Status ClearGraph_M(MGraph &G) {
    G.arcnum = 0;
    G.vexnum = 0;
    return OK;
}

int LocateVex_M(MGraph G, VertexType u) {
    int i;
    for ( i=0; i<G.vexnum; i++ ) {
        if ( G.vexs[i] == u )
            return i;
    }
    return -1;
}

VertexType GetVex_M(MGraph M, int order) {
    if ( order<1||order>M.vexnum )
        return '\0';
    else 
        return M.vexs[order-1];
}

Status PutVex_M(MGraph &M, VertexType v, VertexType value) {
    int i;
    i = LocateVex_M(M, v);
    if ( i==-1 )
        return ERROR;
    else {
        M.vexs[i] = value;
        return OK;
    }
}

int FirstAdjVex_M(MGraph M, VertexType v) {
    int i, j, t;
    i = LocateVex_M(M, v);
    if ( i==-1 )
        return -1;
    else {
        if ( M.kind==DG||M.kind==UDG )
            t = 0;
        else 
            t = INFINITY;
        for ( j=0; j<M.vexnum; j++ ) 
            if ( M.arcs[i][j].adj!=t )
                return j;
    }
    return -1;
}

int NextAdjVex_M(MGraph M, VertexType v, VertexType w) {
    int i, j, k, t;
    i = LocateVex_M(M, v);
    j = LocateVex_M(M, w);
    if ( i==-1||j==-1 )
        return -1;
    else {
        if ( M.kind==DG||M.kind==UDG )
            t = 0;
        else 
            t = INFINITY;
        for ( k=j+1; k<M.vexnum; k++ )
            if ( M.arcs[i][k].adj!=t )
                return k;
    }
    return -1;
}

Status InsertVex_M(MGraph &G, VertexType v) {
    int i, j, k;
    if ( G.vexnum == MAX_VERTEX_NUM )
        return ERROR;
    if ( G.kind==DG||G.kind==UDG )
        j = 0;
    else 
        j = INFINITY;
    
    k = G.vexnum;
    G.vexs[k] = v;
    for ( i=0; i<=k; i++ ) {
        G.arcs[i][k].adj = j;
        G.arcs[k][i].adj = j;
    }
    G.vexnum ++;
    return OK;
}

Status DeleteVex_M(MGraph &G, VertexType v) {
    int i,j,k,t;
    k = LocateVex_M(G, v);
    if ( k==-1 )
        return ERROR;
    if ( G.kind==DG||G.kind==UDG )
        t = 0;
    else 
        t = INFINITY;
    for ( i=0; i<G.vexnum; i++ ) {
        if ( G.arcs[k][i].adj!=t )
            G.arcnum--;
        if ( G.kind==DG||G.kind==DN ) 
            if ( G.arcs[i][k].adj!=t )
                G.arcnum--;
    }

    for ( i=0; i<G.vexnum; i++ ) {
        for ( j=k+1; j<G.vexnum; j++ ) {
            G.arcs[i][j-1] = G.arcs[i][j];
        }
    }

    for ( i=0; i<G.vexnum-1; i++ ) {
        for ( j=k+1; j<G.vexnum; j++ ) {
            G.arcs[j-1][i] = G.arcs[j][i];
        }
    }

    for ( i=k+1; i<G.vexnum; i++ ) {
        G.vexs[i-1] = G.vexs[i];
    }
    G.vexnum--;
    return OK;
}

Status InsertArc_M(MGraph &G, VertexType v, VertexType w, VRType adj) {
    int i, j;
    i = LocateVex_M(G, v);
    j = LocateVex_M(G, w);
    if ( i==-1||j==-1 )
        return ERROR;
    G.arcs[i][j].adj = adj;
    if ( G.kind==UDG|| G.kind==UDN ) {
        G.arcs[j][i] = G.arcs[i][j];
    }
    G.arcnum --;
    return OK;
}

Status DeleteArc_M(MGraph &G, VertexType v, VertexType w) {
    int i, j;
    i = LocateVex_M(G, v);
    j = LocateVex_M(G, w);
    if ( i==-1||j==-1 )
        return ERROR;
    if ( G.kind==DG||G.kind==UDG )
        G.arcs[i][j].adj = 0;
    else 
        G.arcs[i][j].adj = INFINITY;
    
    if ( G.kind==UDG||G.kind==UDN )
        G.arcs[j][i] = G.arcs[i][j];
    G.arcnum --;
    return OK;
}

Status DFSTraverse_M(MGraph G, void(Visit)(VertexType)) {
    int i;
    VisitFunc = Visit;
    for ( i=0; i<G.vexnum; i++ )
        Visited[i] = FALSE;
    for ( i=0; i<G.vexnum; i++ )
        if ( !Visited[i] )
            DFS_M(G, i);
    printf("\n");
}

Status DFS_M(MGraph G, int v) {
    int w;
    Visited[v] = TRUE;
    VisitFunc(G.vexs[v]);
    for ( w=FirstAdjVex_M(G, G.vexs[v]); w!=-1; w=NextAdjVex_M(G, G.vexs[v], G.vexs[w])) {
        if ( !Visited[w] )
            DFS_M(G, w);
    }
    return OK;
}

Status BFSTraverse_M(MGraph G, void(Visit)(VertexType)) {
    int i, u, w;
    LinkQueue Q;
    InitQueue(Q);
    VisitFunc = Visit;
    for ( i=0; i<G.vexnum; i++ )
        Visited[i] = FALSE;
    for ( i=0; i<G.vexnum; i++ ) {
        if ( !Visited[i] ) {
            Visited[i] = TRUE;
            VisitFunc(G.vexs[i]);
            EnQueue(Q, i);
        }
        while ( !QueueEmpty(Q) ) {
            DeQueue(Q, u);
            for ( w=FirstAdjVex_M(G, G.vexs[u]); w!=-1; w=NextAdjVex_M(G, G.vexs[u], G.vexs[w])) {
                if ( !Visited[w] ) {
                    Visited[w] = TRUE;
                    VisitFunc(G.vexs[w]);
                    EnQueue(Q, w);
                }
            }
        }
    }
    printf("\n");
    return OK;
}

void ShowGraph_M(MGraph G) {
    int i, j;
    printf("  ");
    for ( i=0; i<G.vexnum; i++ ) {
        printf("  %c", G.vexs[i]);
    }
    printf("\n");
    for ( i=0; i<G.vexnum; i++ ) {
        printf("%c ", G.vexs[i]);
        for ( j=0; j<G.vexnum; j++ ) {
            if ( G.arcs[i][j].adj == INFINITY ) {
                printf("  -");
            }
            else 
                printf("%3d", G.arcs[i][j].adj);
        }
        printf("\n");
    }
}

#endif