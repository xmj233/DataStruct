/* 二叉树的链式存储结构
    2020.2.9    */
#ifndef LINKBINARYTREE_H
#define LINKBINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

typedef char TElemType;

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;

typedef BiTNode* SElemType;
#include "../sequence stack/SequenceStack.cpp"

typedef BiTNode* QElemType;
#include "../LinkQueue/LinkQueue.cpp"

Status InitBiTree(BiTree &T);

Status CreateBiTree(FILE *fp, BiTree &T);

Status LevelOrderTraverse(BiTree T, void(Visit)(TElemType));

Status PreOrderTraverse_1(BiTree T, void(Visit)(TElemType));

Status PreOrderTraverse_2(BiTree T, void(Visit)(TElemType));

Status InOrderTraverse_1(BiTree T, void(Visit)(TElemType));

Status InOrderTraverse_2(BiTree T, void(Visit)(TElemType));

Status PostOrderTraverse_1(BiTree T, void(Visit)(TElemType));

Status PostOrderTraverse_2(BiTree T, void(Visit)(TElemType));

Status ClearBiTree(BiTree &T);

Status BiTreeEmpty(BiTree T);

int BiTreeDepth(BiTree T);

BiTNode* Root(BiTree T);

TElemType Value(BiTNode e);

Status Assign(BiTNode &e, TElemType value);

BiTNode* Parent(BiTree T, BiTNode* e);

BiTNode* LeftChild(BiTree T, BiTNode* e);

BiTNode* RightChild(BiTree T, BiTNode* e);

BiTNode* LeftSibling(BiTree T, BiTNode* e);

BiTNode* RightSibling(BiTree T, BiTNode* e);

Status InsertChild(BiTree &T, BiTNode* p, int LR, BiTree c);

Status DeleteChild(BiTree &T, BiTNode* p, int LR);

#endif