/*  图的邻接表表示法
    20200220    */
#ifndef ALGRAPH_H
#define ALGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"
#include "../LinkQueue/LinkQueue.cpp"

#define MAX_VERTEX_NUM 20

typedef enum {  DG, UDG }GraphKind;

typedef struct {
    int in;
}InfoType;

typedef struct ArcNode {
    int             adjvex;
    struct ArcNode  *nextarc;
    InfoType        info;
}ArcNode;

typedef char VertexType_AL;

typedef struct {
    VertexType_AL   data;
    ArcNode         *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM+1];

typedef struct {
    AdjList     vertices;
    int         vexnum, arcnum;
    int         kind;
    int         IncInfo;           //info为0则表示各弧不包含其他信息
}ALGraph;

Status Visited[MAX_VERTEX_NUM+1];
void(*VisitFunc)(VertexType_AL e);

Status CreateGraph_AL(ALGraph &G, char *f, GraphKind kind);

Status CreateDG_AL(ALGraph &G, char *f);

Status CreateUDG_AL(ALGraph &G, char *f);

int LocateVex_AL(ALGraph G, VertexType_AL v);

VertexType_AL GetVex_AL(ALGraph G, int order);

Status PutVex_AL(ALGraph &G, VertexType_AL v, VertexType_AL value);

int FirstAdjVex_AL(ALGraph G, VertexType_AL v);

int NextAdjVex_AL(ALGraph G, VertexType_AL v, VertexType_AL w);

Status DFSTraverse_AL(ALGraph G, void(Visit)(VertexType_AL e));

Status DFS_AL(ALGraph G, int v);

Status BFSTraverse_AL(ALGraph G, void(Visit)(VertexType_AL e));

void Input_AL(InfoType &info);

Status ShowGraph_AL(ALGraph G);

#endif