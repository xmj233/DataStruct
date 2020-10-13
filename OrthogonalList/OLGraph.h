/*  图的十字链表表示法
        */
#ifndef OLGRAPH_H
#define OLGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"
#include "../LinkQueue/LinkQueue.cpp"

#define MAX_VERTEX_NUM 20

typedef struct ArcBox {
    int     tailvex;
    int     headvex;
    struct ArcBox   *hlink;
    struct ArcBox   *tlink;
}ArcBox;

typedef char VertexType_OL;

typedef struct VexNode {
    VertexType_OL  data;
    ArcBox      *firstin;
    ArcBox      *firstout;
}VexNode;

typedef struct {
    VexNode     xlist[MAX_VERTEX_NUM];
    int         vexnum, arcnum;
}OLGraph;

Status Visited[MAX_VERTEX_NUM];
void (*VisitFunc)(VertexType_OL e);

Status CreateGraph_OL(OLGraph &G, char *f);

int LocateVex_OL(OLGraph G, VertexType_OL v);

int FirstAdjVex_OL(OLGraph G, VertexType_OL v);

int NextAdjVex_OL(OLGraph G, VertexType_OL w, VertexType_OL v);

Status DFSTraverse_OL(OLGraph G, void(Visit)(VertexType_OL));

Status DFS_OL(OLGraph G, int v);

Status BFSTraverse_OL(OLGraph G, void(Visit)(VertexType_OL));

#endif