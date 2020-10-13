#ifndef LINKBINARYTREE_CPP
#define LINKBINARYTREE_CPP

#include "LinkBinaryTree.h"

Status InitBiTree(BiTree &T) {
    T = NULL;
    return OK;
}

Status CreateBiTree(FILE *fp, BiTree &T) {
    char ch;
    ch = getc(fp);
    if ( ch=='^' )
        T=NULL;
    else {
        if ( !(T=(BiTNode*)malloc(sizeof(BiTNode))) )
            exit(OVERFLOW);
        T->data = ch;
        CreateBiTree(fp, T->lchild);
        CreateBiTree(fp, T->rchild);
    }
    return OK;
}

Status LevelOrderTraverse(BiTree T, void(Visit)(TElemType)) {
    QElemType e;
    LinkQueue Q;
    InitQueue(Q);
    if ( !T )
        return ERROR;
    EnQueue(Q, T);
    while ( !QueueEmpty(Q) ) {
        DeQueue(Q, e);
        Visit(e->data);
        if ( e->lchild ) 
            EnQueue(Q, e->lchild);
        if ( e->rchild )
            EnQueue(Q, e->rchild);
    }
    return OK;
}

Status PreOrderTraverse_1(BiTree T, void(Visit)(TElemType)) {
    if ( T ) {
        Visit(T->data);
        PreOrderTraverse_1(T->lchild, Visit);
        PreOrderTraverse_1(T->rchild, Visit);
    }
    return OK;
}

Status PreOrderTraverse_2(BiTree T, void(Visit)(TElemType)) {
    SqStack S;
    SElemType p;
    InitStack(S);
    p = T;
    while ( p||!StackEmpty(S) ) {
        if ( p ) {
            Visit(p->data);
            Push(S, p);
            p = p->lchild;
        }
        else {
            Pop(S, p);
            p = p->rchild;
        }
    }
    return OK;
}

Status InOrderTraverse_1(BiTree T, void(Visit)(TElemType)) {
    if ( T ) {
        InOrderTraverse_1(T->lchild, Visit);
        Visit(T->data);
        InOrderTraverse_1(T->rchild, Visit);
    }
    return OK;
}

Status InOrderTraverse_2(BiTree T, void(Visit)(TElemType)) {
    SqStack S;
    SElemType p;
    InitStack(S);
    p = T;
    while ( p||!StackEmpty(S) ) {
        if ( p ) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            Pop(S, p);
            Visit(p->data);
            p = p->rchild;
        }
    }
    return OK;
}

Status PostOrderTraverse_1(BiTree T, void(Visit)(TElemType)) {
    if ( T ) {
        PostOrderTraverse_1(T->lchild, Visit);
        PostOrderTraverse_1(T->rchild, Visit);
        Visit(T->data);
    }
    return OK;
}

Status PostOrderTraverse_2(BiTree T, void(Visit)(TElemType)) {
    SqStack S;
    SElemType p, r;
    InitStack(S);
    p = T;
    r = NULL;
    while ( p||!StackEmpty(S) ) {
        if ( p ) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            GetTop(S, p);
            if ( p->rchild&&p->rchild!=r ) {
                p = p->rchild;
            }
            else {
                Pop(S, p);
                Visit(p->data);
                r = p;
                p = NULL;
            }
        }
    }
    return OK;
}

Status ClearBiTree(BiTree &T) {
    if ( T ) { 
        if ( T->lchild )
            ClearBiTree(T->lchild);
        if ( T->rchild ) 
            ClearBiTree(T->rchild);
        free(T);
        T = NULL;
    }
    return OK;
}

Status BiTreeEmpty(BiTree T) {
    if ( !T ) 
        return TRUE;
    else 
        return FALSE;
}

int BiTreeDepth(BiTree T) {
    int L, R;
    if ( !T )
        return 0;
    else {
        L = BiTreeDepth(T->lchild);
        R = BiTreeDepth(T->rchild);
        return (L>=R?L:R) + 1;
    }
}

BiTNode* Root(BiTree T) {
    return T;
}

TElemType Value(BiTNode e) {
    return e.data;
}

Status Assign(BiTNode &e, TElemType value) {
    e.data = value;
    return OK;
}

BiTNode* Parent(BiTree T, BiTNode* e) {
    BiTNode *tmp = NULL;
    if ( T==NULL||e==NULL )
        return NULL;
    if ( T==e ) 
        return NULL;
    if ( T->lchild==e||T->rchild==e ) 
        return T;
    else {
        if ( tmp = Parent(T->lchild, e) ) 
            return tmp;
        if ( tmp = Parent(T->rchild,e ) )
            return tmp;
    }
    return NULL;
}

BiTNode *LeftChild(BiTree T, BiTNode* e) {
    BiTNode *tmp = NULL;
    if ( T&&e ) {
        if ( T==e )
            return T->lchild;
        else {
            if ( tmp=LeftChild(T->lchild, e) )
                return tmp;
            if ( tmp=LeftChild(T->rchild, e) )
                return tmp;
        }
    }
    return NULL;
}

BiTNode* RightChild(BiTree T, BiTNode* e) {
    BiTNode *tmp = NULL;
    if ( T&&e ) {
        if ( T==e )
            return T->rchild;
        else {
            if ( tmp=RightChild(T->lchild,e ) )
                return tmp;
            if ( tmp=RightChild(T->rchild, e) ) 
                return tmp;
        }
    }
    return NULL;
}

BiTNode* LeftSibling(BiTree T, BiTNode *e) {
    BiTNode *tmp;
    tmp = Parent(T, e);
    if ( tmp->lchild!=e ) 
        return tmp->lchild;
    else 
        return NULL;
}

BiTNode* RightSibling(BiTree T, BiTNode *e) {
    BiTNode *tmp;
    tmp = Parent(T, e);
    if ( tmp->rchild!=e ) 
        return tmp->rchild;
    else 
        return NULL;
}

Status InsertChild(BiTree &T, BiTNode* p, int LR, BiTree c) {
    BiTNode *tmp;
    if ( !T||!c||!p )
        return ERROR;
    if ( LR==0 ) {
        tmp = p->lchild;
        p->lchild=c;
        c->rchild=tmp;
    }
    if ( LR==1 ) {
        tmp=p->rchild;
        p->rchild=c;
        c->rchild=tmp;
    }
    return OK;
}

Status DeleteChild(BiTree &T, BiTNode *p, int LR) {
    if ( !T||!p ) 
        return ERROR;
    if ( LR==0 ) {
        ClearBiTree(p->lchild);
    }
    if ( LR==1 ) {
        ClearBiTree(p->rchild);
    }
    return OK;
}

#endif