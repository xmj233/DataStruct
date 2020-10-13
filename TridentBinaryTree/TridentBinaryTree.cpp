#ifndef TRIDENTBINARYTREE_CPP
#define TRIDENTBINARYTREE_CPP

#include "TridentBinaryTree.h"

Status InitBiTree_Tri(TriBiTree &T) {
    T = NULL;
    return OK;
}

Status Create_Tri(FILE *fp, TriBiTree &T) {
    TriElemType ch;
    ch = getc(fp);
    if ( ch=='^' )
        T = NULL;
    else {
        if ( !(T=(TriBiTNode*)malloc(sizeof(TriBiTNode))) )
            exit(OVERFLOW);
        T->data = ch;
        Create_Tri(fp, T->lchild);
        Create_Tri(fp, T->rchild);
    }
    return OK;
}

Status CreateBiTree_Tri(FILE *fp, TriBiTree &T) {
    QElemType e;
    LinkQueue Q;
    InitQueue(Q);
    if ( !Create_Tri(fp, T)||!T )
        return ERROR;
    EnQueue(Q, T);
    T->parent = NULL;
    while ( !QueueEmpty(Q) ) {
        DeQueue(Q, e);
        if ( e->lchild ) {
            e->lchild->parent = e;
            EnQueue(Q, e->lchild);
        }
        if ( e->rchild ) {
            e->rchild->parent = e;
            EnQueue(Q, e->rchild);
        }
    }
    return OK; 
}

Status LevelOrderTraverse_Tri(TriBiTree T, void(Visit)(TriElemType)) {
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
    printf("\n");
    return OK;
}

Status PreOrderTraverse_Tri(TriBiTree T, void(Visit)(TriElemType)) {
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
    printf("\n");
    return OK;
}

Status InOrderTraverse_Tri(TriBiTree T, void(Visit)(TriElemType)) {
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
    printf("\n");
    return OK;
}

Status PostOrderTraverse_Tri(TriBiTree T, void(Visit)(TriElemType)) {
    SqStack S;
    SElemType p, r;
    InitStack(S);
    p = T;
    while ( p||!StackEmpty(S) ) {
        if ( p ) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            GetTop(S, p);
            if ( p->rchild&&p->rchild!=r ) 
                p = p->rchild;
            else {
                Pop(S, p);
                Visit(p->data);
                r = p;
                p = NULL;
            }
        }
    }
    printf("\n");
    return OK;
}

Status ClearBiTree_Tri(TriBiTree &T) {
    if ( T ) {
        ClearBiTree_Tri(T->lchild);
        ClearBiTree_Tri(T->rchild);
        free(T);
        T=NULL;
    }
    return OK;
}

Status BiTreeEmpty_Tri(TriBiTree T) {
    if ( !T )
        return TRUE;
    else 
        return FALSE;
}

int BiTreeDepth_Tri(TriBiTree T) {
    int L, R;
    if ( !T )
        return 0;
    else {
        L = BiTreeDepth_Tri(T->lchild);
        R = BiTreeDepth_Tri(T->rchild);
        return (L>=R?L:R) + 1;
    }
}

TriBiTNode* Root_Tri(TriBiTree T) {
    return T;
}

TriElemType Value_Tri(TriBiTNode *e) {
    return e->data;
}

TriBiTNode* Parent_Tri(TriBiTree T, TriBiTNode *e) {
    if ( e ) 
        return e->parent;
    return NULL;
}

TriBiTNode* LeftChild_Tri(TriBiTree T, TriBiTNode *e) {
    if ( e ) {
        return e->lchild;
    }
    return NULL;
}

TriBiTNode* RightChild_Tri(TriBiTree T, TriBiTNode *e) {
    if ( e ) {
        return e->lchild;
    }
    return NULL;
}

TriBiTNode* LeftSibling_Tri(TriBiTree T, TriBiTNode *e) {
    if ( e ) {
        if ( e->parent->lchild!=e )
            return e->parent->lchild;
    }
    return NULL;
}

TriBiTNode* RightSibling_Tri(TriBiTree T, TriBiTNode *e) {
    if ( e ) {
        if ( e->parent->rchild!=e )
            return e->parent->rchild;
    }
    return NULL;
}

Status InsertChild_Tri(TriBiTree &T, TriBiTNode *p, int LR, TriBiTree c) {
    TriBiTNode *tmp;
    if ( !T||!p||!c ) 
        return ERROR;
    if ( LR==0 ) {
        tmp = p->lchild;
        p->lchild = c;
        c->rchild = tmp;
        c->parent = p;
        if ( tmp )
            tmp->parent = c;
    }
    if ( LR==1 ) {
        tmp = p->rchild;
        p->rchild = c;
        c->rchild = tmp;
        c->parent = p;
        if ( tmp )
            tmp->parent = c;
    }
    return OK;
}

Status DeleteChild_Tri(TriBiTree &T, TriBiTNode *p, int LR) {
    if ( T&&p ) {
        LR ? ClearBiTree_Tri(p->rchild) : ClearBiTree_Tri(p->lchild);
        return OK;
    }
    return ERROR;
}



#endif