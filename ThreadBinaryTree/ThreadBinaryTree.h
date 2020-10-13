/* 线索二叉树的遍历操作
    20200212    */
#ifndef THREADBINARYTREE_H
#define THREADBINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

typedef char TElemType_Thr;

typedef enum {
    Link,
    Thread
}PointerTag;

typedef struct BiThrNode {
    TElemType_Thr       data;
    struct BiThrNode    *lchild;
    struct BiThrNode    *rchild;
    PointerTag          LTag;
    PointerTag          RTag;
}BiThrNode, *BiThrTree;

BiThrNode *pre;

Status CreateBiTree_Thr(FILE *fp, BiThrTree &T);

Status InThreading_Thr(BiThrTree p);

Status InOrderThreading_Thr(BiThrTree &Thrt, BiThrTree T);

Status InOrderTraverse_Thr(BiThrTree T, void(Visit)(TElemType_Thr e));

Status PreThreading_Thr(BiThrTree p);

Status PreOrderThreading_Thr(BiThrTree &Thrt, BiThrTree T);

Status PreOrderTraverse_Thr(BiThrTree T, void(Visit)(TElemType_Thr));

Status PostThreading_Thr(BiThrTree p);

Status PostOrderThreading_Thr(BiThrTree &Thrt, BiThrTree T);

Status PostOrderTraverse_Thr(BiThrTree T, void(Visit)(TElemType_Thr));

BiThrNode* Parent_Thr(BiThrTree T, BiThrNode *p);

BiThrNode* NextPtr_Thr(BiThrTree T, BiThrNode *p);

#endif