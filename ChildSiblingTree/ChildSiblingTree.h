/*  树的孩子兄弟表示法
    */
#ifndef CHILDSIBLINGTREE_H
#define CHILDSIBLINGTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

typedef char TElemType_CS;

typedef struct CSNode {
    TElemType_CS    data;
    struct CSNode   *firstchild;
    struct CSNode   *nextsibling;
}CSNode, *CSTree;

int i   =   0;

Status InitTree_CS(CSTree &T);

Status CreateTree_CS(char *fp, CSTree &T);

Status ClearTree_CS(CSTree &T);

Status PreOrderTraverse_CS(CSTree T, void(Visit)(TElemType_CS));
//先根遍历

Status InOrderTraverse_CS(CSTree T, void(Visit)(TElemType_CS));
//后根遍历

#endif