/* 二叉树的三叉链表存储结构
    2020.2.11   */

#ifndef TRIDENTBINARYTREE_H
#define TRIDENTBINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

typedef char TriElemType;

typedef struct TriBiTNode {
    TriElemType data;
    struct TriBiTNode *parent;
    struct TriBiTNode *lchild;
    struct TriBiTNode *rchild;
}TriBiTNode, *TriBiTree;

typedef TriBiTNode* QElemType;
#include "../LinkQueue/LinkQueue.cpp"

typedef TriBiTNode* SElemType;
#include "../sequence stack/SequenceStack.cpp"

Status InitBiTree_Tri(TriBiTree &T);

Status ClearBiTree_Tri(TriBiTree &T);

Status Create_Tri(FILE *fp, TriBiTree &T);

Status CreateBiTree_Tri(FILE *fp, TriBiTree &T);

Status LevelOrderTraverse_Tri(TriBiTree T, void(Visit)(TriElemType));

Status PreOrderTraverse_Tri(TriBiTree T, void(Visit)(TriElemType));

Status InOrderTraverse_Tri(TriBiTree T, void(Visit)(TriElemType));

Status PostOrderTraverse_Tri(TriBiTree T, void(Visit)(TriElemType));

Status BiTreeEmpty_Tri(TriBiTree T);

int BiTreeDepth_Tri(TriBiTree T);

TriBiTNode* Root_Tri(TriBiTree T);

TriElemType Value_Tri(TriBiTNode* e);

Status Assign_Tri(TriBiTNode &e, TriElemType value);

TriBiTNode* Parent_Tri(TriBiTree T, TriBiTNode *e);

TriBiTNode* LeftChild_Tri(TriBiTree T, TriBiTNode *e);

TriBiTNode* RightChild_Tri(TriBiTree T, TriBiTNode *e);

TriBiTNode* LeftSibling_Tri(TriBiTree T, TriBiTNode *e);

TriBiTNode* RightSibling_Tri(TriBiTree T, TriBiTNode *e);

Status InsertChild_Tri(TriBiTree &T, TriBiTNode* p, int LR, TriBiTree c);

Status DeleteChild_Tri(TriBiTree &T, TriBiTNode *p, int LR);

#endif