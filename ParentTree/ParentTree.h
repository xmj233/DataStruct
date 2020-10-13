/* 树的存储结构
    --树的双亲表示法---
    20200213    */
#ifndef PARENTTREE_H
#define PARENTTREE_H

#include <stdio.h>
#include "../Status.h"

#define MAX_TREE_SIZE 100

typedef char TElemType_P;

typedef struct {
    TElemType_P data;
    int         parent;
}PTNode;

typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int n;
}PTree;

Status InitTree_P(PTree &T);

Status ClearTree_P(PTree &T);

Status CreateTree_P(FILE *fp, PTree &T);

Status LevelOrderTraverse_P(PTree T, void(Visit)(TElemType_P));

Status TreeEmpyt_P(PTree T);

int TreeDepth_P(PTree T);

TElemType_P Root_P(PTree T);

TElemType_P Value_P(PTree T, int i);

Status Assign_P(PTree &T, TElemType_P cur_e, TElemType_P value);

TElemType_P Parent_P(PTree T, TElemType_P cur_e);

TElemType_P LeftChild_P(PTree T, TElemType_P cur_e);

TElemType_P RightChild_P(PTree T, TElemType_P cur_e);

TElemType_P LeftSibling_P(PTree T, TElemType_P cur_e);

TElemType_P RightSibling_P(PTree T, TElemType_P cur_e);

#endif