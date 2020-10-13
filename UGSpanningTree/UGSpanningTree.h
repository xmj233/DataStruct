/*  无向图的生成树
        */
#ifndef UGSPANNINGTREE_H
#define UGSPANNINGTREE_H

#include "../AdjacencyList/ALGraph.cpp"
#include "../ChildSiblingTree/ChildSiblingTree.cpp"

void DFSForest(ALGraph G, CSTree &T);

void DFSTree(ALGraph G, int v, CSTree &T);

#endif