/*  图的数组表示法
    20200218    */

#ifndef MGRAPH_H
#define MGRAPH_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../Status.h"
#include "../LinkQueue/LinkQueue.cpp"

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20

typedef enum {
    DG, DN, UDG, UDN
}GraphKind;

typedef int VRType;     //顶点关系类型

typedef struct {
    VRType adj;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef char VertexType;

typedef struct {
    VertexType  vexs[MAX_VERTEX_NUM];
    AdjMatrix   arcs; 
    int         vexnum, arcnum;
    GraphKind   kind;
}MGraph;

Status Visited[MAX_VERTEX_NUM];
void (*VisitFunc)(VertexType e);

Status CreateGraph_M(char *f, MGraph &G, GraphKind kind);

Status CreateDG_M(char *f, MGraph &G);

Status CreateDN_M(char *f, MGraph &G);

Status CreateUDG_M(char *f, MGraph &G);

Status CreateUDN_M(char *f, MGraph &G);

Status ClearGraph_M(MGraph &G);

int LocateVex_M(MGraph G, VertexType u);

VertexType GetVex_M(MGraph M, int order);

Status PutVex_M(MGraph &M, VertexType v, VertexType value);

int FirstAdjVex_M(MGraph M, VertexType v);

int NextAdjVex_M(MGraph M, VertexType v, VertexType w);

Status InsertVex_M(MGraph &G, VertexType v);

Status DeleteVex_M(MGraph &G, VertexType v);

Status InsertArc_M(MGraph &G, VertexType v, VertexType w, VRType adj);

Status DeleteArc_M(MGraph &G, VertexType v, VertexType w);

Status DFSTraverse_M(MGraph G, void(Visit)(VertexType));

Status DFS_M(MGraph G, int v);

Status BFSTraverse_M(MGraph G, void(Visit)(VertexType));

void ShowGraph_M(MGraph G);

#endif