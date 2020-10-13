/* 二叉树的顺序存储结构
    20200208    */
#ifndef SEQBINARYTREE_H
#define SEQBINARYTREE_H
#include <stdio.h>
#include <math.h>
#include "../Status.h"

#define MAX_TREE_SIZE 100

typedef char TElemType;
typedef TElemType SqBiTree[MAX_TREE_SIZE];

typedef struct {
    int level;
    int order;
}Position;

Status InitBiTree_Sq(SqBiTree &T);

Status DestoryBiTree_Sq(SqBiTree &T);

Status ClearBiTree_Sq(SqBiTree &T);

Status CreateBiTree_Le_Sq(FILE *fp, SqBiTree &T);

Status CreateBiTree_Pre_Sq(FILE *fp, SqBiTree &T, int i);

Status BiTreeEmpty_Sq(SqBiTree T);

int BiTreeDepth_Sq(SqBiTree T);

TElemType Root_Sq(SqBiTree T);

TElemType Value_Sq(SqBiTree T, Position e);

Status Assign_Sq(SqBiTree T, Position e, TElemType value);

TElemType Parent_Sq(SqBiTree T, Position e);

TElemType LeftChild_Sq(SqBiTree T, Position e);

TElemType RightChild_Sq(SqBiTree T, Position e);

TElemType LeftSibling_Sq(SqBiTree T, Position e);

TElemType RightSibling_Sq(SqBiTree T, Position e);

Status PreOrderTraverse_Sq(SqBiTree T, Status(Visit)(TElemType), int i);

Status InOrderTraverse_Sq(SqBiTree T, Status(Visit)(TElemType), int i);

Status PostOrderTraverse_Sq(SqBiTree T, Status(Visit)(TElemType), int i);

Status LevelOrderTraverse_Sq(SqBiTree T, Status(Visit)(TElemType));

#endif