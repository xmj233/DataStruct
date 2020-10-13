#ifndef ALGRAPH_CPP
#define ALGRAPH_CPP

#include "ALGraph.h"

Status CreateGraph_AL(ALGraph &G, char *f, GraphKind kind) {
    G.kind = kind;
    switch(G.kind) {
        case DG:    CreateDG_AL(G, f);  break;
        case UDG:   CreateUDG_AL(G, f); break;
        default:    return ERROR;
    }
    return OK;
}

Status CreateDG_AL(ALGraph &G, char *f) {
    int i, j, k, t;
    ArcNode *p;
    VertexType_AL v1, v2;
    ArcNode *r[MAX_VERTEX_NUM+1];
    t = 0;
    G.vexnum    =   f[t++]-'0';
    G.arcnum    =   f[t++]-'0';
    G.IncInfo   =   f[t++]-'0';
    t   ++;
    for ( i=1;i<=G.vexnum; i++ ) {
        G.vertices[i].data   =   f[t++];
        G.vertices[i].firstarc  =   NULL;
        r[i]    =   NULL;
    }
    for ( k=1;k<=G.arcnum;k++ ) {
        t++;
        v1  =   f[t++];
        v2  =   f[t++];
        i   =   LocateVex_AL(G, v1);
        j   =   LocateVex_AL(G, v2);
        if ( !i||!j )
            return ERROR;
        if ( !(p=(ArcNode*)malloc(sizeof(ArcNode))) )
            exit(OVERFLOW);
        p->adjvex   =   j;
        p->nextarc  =   NULL;
        if ( G.IncInfo==1 )
            Input_AL(p->info);
        if ( r[i]==NULL )
            G.vertices[i].firstarc  =   p;
        else 
            r[i]->nextarc   =   p;
        r[i]    =   p;
    }
    return OK;
}

Status CreateUDG_AL(ALGraph &G, char *f) {
    int i, j, k, t;
    VertexType_AL v1, v2;
    ArcNode *p, *q;
    ArcNode *r[MAX_VERTEX_NUM+1];
    t   =   0;
    G.vexnum    =   f[t++]-'0';
    G.arcnum    =   f[t++]-'0';
    G.IncInfo   =   f[t++]-'0';
    t++;
    for ( i=1; i<=G.vexnum; i++ ) {
        G.vertices[i].data  =   f[t++];
        G.vertices[i].firstarc  =   NULL;
        r[i]    =   NULL;
    }

    for ( k=1; k<=G.arcnum; k++ ) {
        t ++;
        v1  =   f[t++];
        v2  =   f[t++];
        i   =   LocateVex_AL(G, v1);
        j   =   LocateVex_AL(G, v2);
        if ( !i||!j )
            return ERROR;
        if ( !(p=(ArcNode*)malloc(sizeof(ArcNode))) )
            exit(OVERFLOW);
        p->adjvex   =   j;
        p->nextarc  =   NULL;
        if ( G.IncInfo==1 )
            Input_AL(p->info);
        if ( r[i]==NULL )
            G.vertices[i].firstarc  =   p;
        else
            r[i]->nextarc   =   p;
        r[i]    =   p;

        if ( !(q=(ArcNode*)malloc(sizeof(ArcNode))) )
            exit(OVERFLOW);
        q->adjvex   =   i;
        q->nextarc  =   NULL;
        if ( G.IncInfo==1 )
            Input_AL(q->info);
        if ( r[j]==NULL )
            G.vertices[j].firstarc  =   q;
        else
            r[j]->nextarc   =   q;
        r[j]    =   q;
    }
    return OK;
}

int LocateVex_AL(ALGraph G, VertexType_AL v) {
    int i;
    for ( i=1; i<=G.vexnum; i++ )
        if ( G.vertices[i].data==v )
            return i;
    return 0;
}

VertexType_AL GetVex_AL(ALGraph G, int order) {
    if ( order<1||order>G.vexnum )
        return '\0';
    else
        return G.vertices[order].data;
}

Status PutVex_AL(ALGraph &G, VertexType_AL v, VertexType_AL value) {
    int i;
    i = LocateVex_AL(G, v);
    if ( !i )
        return ERROR;
    else {
        G.vertices[i].data  =   value;
        return OK;
    }
}

int FirstAdjVex_AL(ALGraph G, VertexType_AL v) {
    int i;
    i = LocateVex_AL(G, v);
    if ( i==0 )
        return 0;
    if ( G.vertices[i].firstarc )
        return G.vertices[i].firstarc->adjvex;
    else
        return 0;
}

int NextAdjVex_AL(ALGraph G, VertexType_AL v, VertexType_AL w) {
    int i, j;
    ArcNode *p;
    i   =   LocateVex_AL(G, v);
    j   =   LocateVex_AL(G, w);
    if ( i==0||j==0 )
        return 0;
    p   =   G.vertices[i].firstarc;
    while ( p ) {
        if ( G.vertices[p->adjvex].data==w )
            if ( p->nextarc )
                return p->nextarc->adjvex;
        p = p->nextarc;
    }
    return 0;
}

Status DFSTraverse_AL(ALGraph G, void(Visit)(VertexType_AL e)) {
    int i;
    VisitFunc = Visit;
    for ( i=1; i<=G.vexnum; i++ )
        Visited[i]  =   FALSE;
    for ( i=1; i<=G.vexnum; i++ ) {
        if ( !Visited[i] )
            DFS_AL(G, i);
    }
    printf("\n");
    return OK;
}

Status DFS_AL(ALGraph G, int v) {
    int i;
    Visited[v]  =   TRUE;
    VisitFunc(G.vertices[v].data);
    for ( i=FirstAdjVex_AL(G, G.vertices[v].data); i; i=NextAdjVex_AL(G, G.vertices[v].data, G.vertices[i].data))
        if ( !Visited[i] )
            DFS_AL(G, i);
}

Status BFSTraverse_AL(ALGraph G, void(Visit)(VertexType_AL e)) {
    int i, en, w;
    LinkQueue Q;
    InitQueue(Q);
    VisitFunc   =   Visit;
    for ( i=1; i<=G.vexnum; i++ ) 
        Visited[i]  =   FALSE;
    for ( i=1; i<=G.vexnum; i++ ) {
        if ( !Visited[i] ) {
            Visited[i]  =   TRUE;
            VisitFunc(G.vertices[i].data);
            EnQueue(Q, i);
            while ( !QueueEmpty(Q) ) {
                DeQueue(Q, en);
                for ( w=FirstAdjVex_AL(G, G.vertices[en].data); w; w=NextAdjVex_AL(G, G.vertices[en].data, G.vertices[w].data)) {
                    if ( !Visited[w] ) {
                        Visited[w]  =   TRUE;
                        VisitFunc(G.vertices[w].data);
                        EnQueue(Q, w);
                    }
                }
            }
        }
    }
    printf("\n");
    return OK;
}

Status ShowGraph_AL(ALGraph G) {
    int i;
    ArcNode *p;
    for ( i=1; i<=G.vexnum; i++ ) {
        p   =   G.vertices[i].firstarc;
        printf("%c", G.vertices[i].data);
        printf("---->");
        while ( p ) {
            printf(" %d(%c) ", p->adjvex, G.vertices[p->adjvex].data);
            p = p->nextarc;
        }
        printf("\n");
    }
}

void Input_AL(InfoType &info) {

}

#endif