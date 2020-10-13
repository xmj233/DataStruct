#ifndef EXTENLINKEDLIST_H
#define EXTENLINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

#ifndef POLYNOMIAL_H
typedef int ElemType;
#endif

typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *Link, *Position;

typedef struct {
    Link head, tail;
    int len;
}LinkList;

Status MakeNode(Link &p, ElemType e);
    //分配由p指向的值为e的结点，并返回OK

void FreeNode(Link &p);
    //释放p所指结点

Status InitList(LinkList &L);
    //构造一个空的线性表L

Status DestoryList(LinkList &L);
    //销毁线性表L

Status ClearList(LinkList &L);
    //将线性链表L重置为空表，并释放原链表的结点空间。

Status InsFirst(LinkList &L, Link h, Link s);
    //h指向线性链表L的头结点，将s所指结点插入到第一个结点之前 

Status DelFirst(LinkList &L, Link h, Link &q);
    //h指向线性链表L的头结点，删除链表中的第一个结点并以q返回

Status Append(LinkList &L, Link s);
    //将s所指的一串结点链接到线性链表L的最后一个结点之后，并改变尾指针。

Status Remove(LinkList &L, Link &q);
    //删除线性链表L的最后一个结点并以q返回，改变链表的尾指针。

Status InsBefore(LinkList &L, Link &p, Link s);
    //将s所指结点插入到p所指结点之前，并修改p指针为插入的结点

Status InsAfter(LinkList &L, Link &p, Link s);
    //将s所指结点插入到p所指结点之后，并修改p指针为插入的结点

Status SetCurElem(Link &p, ElemType e);
    //用e更新p所指结点数据元素的值

ElemType GetCurElem(Link &p);
    //返回p所指结点数据元素的值

Status ListEmpty(LinkList L);
    //判空

int ListLength(LinkList L);
    //求长

Position GetHead(LinkList L);
    //返回线性链表中头结点的位置

Position GetLast(LinkList L);
    //返回线性链表中最后一个结点的位置

Position PriorPos(LinkList L, Link p);
    //返回p所指结点直接前驱的位置

Position NextPos(LinkList L, Link p);
    //返回p所指结点直接后继的位置

Status LocatePos(LinkList L, int i, Link &p);
    //用p返回第i个结点的位置

Position LocateElem(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType));
    //返回线性链表中第一个满足Compare判定关系的位置，若不存在则返回NULL

Status ListTraverse(LinkList L, void(Visit)(ElemType));
    //遍历

Status ListInsert(LinkList &L, int i, ElemType e);

Status ListDelete(LinkList &L, int i, ElemType &e);

#endif