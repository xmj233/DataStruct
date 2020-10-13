#ifndef THREADBINARYTREE_CPP
#define THREADBINARYTREE_CPP

#include "ThreadBinaryTree.h"

Status CreateBiTree_Thr(FILE *fp, BiThrTree &T) {
    TElemType_Thr ch;
    ch = fgetc(fp);
    if ( ch=='^' )
        T=NULL;
    else {
        if ( !(T=(BiThrNode*)malloc(sizeof(BiThrNode))) )
            exit(OVERFLOW);
        T->data = ch;
        CreateBiTree_Thr(fp, T->lchild);
        T->LTag = Link;
        CreateBiTree_Thr(fp, T->rchild);
        T->RTag = Link;
    }
    return OK;
}

Status InThreading_Thr(BiThrTree p) {
    if ( p ) {
        InThreading_Thr(p->lchild);
        if ( p->lchild==NULL ) {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if ( pre->rchild==NULL ) {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading_Thr(p->rchild);
    }
    return OK;
}

Status InOrderThreading_Thr(BiThrTree &Thrt, BiThrTree T) {
    if ( !(Thrt=(BiThrNode*)malloc(sizeof(BiThrNode))) )
        exit(OVERFLOW);
    Thrt->LTag = Link;
    Thrt->RTag = Thread;
    Thrt->rchild = Thrt;
    if ( !T )
        Thrt->lchild = Thrt;
    else {
        Thrt->lchild = T;
        pre = Thrt;
        InThreading_Thr(T);
        pre->RTag = Thread;
        pre->rchild = Thrt;
        Thrt->rchild = pre;
    }
    return OK;
}

Status InOrderTraverse_Thr(BiThrTree T, void(Visit)(TElemType_Thr)) {
    BiThrNode *p;
    p = T->lchild;
    while ( p!=T ) {
        while ( p->LTag==Link ) 
            p = p->lchild;
        Visit(p->data);
        while ( p->RTag==Thread&&p->rchild!=T ) {
            p = p->rchild;
            Visit(p->data);
        }
        p = p->rchild;
    }
    return OK;
}

Status PreThreading_Thr(BiThrTree p) {
    if ( p ) {
        if ( !p->lchild ) {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if ( !pre->rchild ) {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        if ( p->LTag==Link )
            PreThreading_Thr(p->lchild);
        if ( p->RTag==Link )
            PreThreading_Thr(p->rchild);
    }
    return OK;
}

Status PreOrderThreading_Thr(BiThrTree &Thrt, BiThrTree T) {
    if ( !(Thrt=(BiThrTree)malloc(sizeof(BiThrNode))) )
        exit(OVERFLOW);
    Thrt->LTag = Link;
    Thrt->RTag = Thread;
    Thrt->rchild = Thrt;
    if ( !T ) 
        Thrt->lchild = Thrt;
    else {
        Thrt->lchild = T;
        pre = Thrt;
        PreThreading_Thr(T);
        pre->RTag = Thread;
        pre->rchild = Thrt;
        Thrt->rchild = pre;
    }
    return OK;
}

Status PreOrderTraverse_Thr(BiThrTree T, void(Visit)(TElemType_Thr)) {
    BiThrNode *p;
    p = T->lchild;
    while ( p!=T ) {
        while ( p->LTag==Link ) {
            Visit(p->data);
            p = p->lchild;
        }
        Visit(p->data);
        p = p->rchild;
    }
    return OK;
}

Status PostThreading_Thr(BiThrTree p) {
    if ( p ) {
        PostThreading_Thr(p->lchild);
        PostThreading_Thr(p->rchild);
        if ( !p->lchild ) {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if ( !pre->rchild ) {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
    }
    return OK;
}

Status PostOrderThreading_Thr(BiThrTree &Thrt, BiThrTree T) {
    if ( !(Thrt=(BiThrTree)malloc(sizeof(BiThrNode))) )
        exit(OVERFLOW);
    Thrt->LTag = Link;
    Thrt->RTag = Thread;
    Thrt->rchild = Thrt;
    if ( !T )
        Thrt->lchild = Thrt;
    else {
        Thrt->lchild = T;
        pre = Thrt;
        PostThreading_Thr(T);
        Thrt->rchild = pre;
    }
    return OK;
}

Status PostOrderTraverse_Thr(BiThrTree Thrt, void(Visit)(TElemType_Thr)) {
    BiThrTree p = Thrt->lchild;
    if ( p!=Thrt ) {
        while ( 1 ) {
            while ( p->LTag==Link )
                p = p->lchild;
            if ( p->RTag==Link )
                p = p->rchild;
            else 
                break;
        }
        while ( p!=Thrt ) {
            Visit(p->data);
            p = NextPtr_Thr(Thrt, p);
        }
    }
}

BiThrNode* Parent_Thr(BiThrTree T, BiThrNode *p) {
    BiThrNode *tmp;
    if ( T&&p ) {
        if ( p==T ) 
            return NULL;
        if ( (T->LTag==Link&&T->lchild==p) || (T->RTag==Link&&T->rchild==p))
            return T;
        else {
            if ( T->LTag==Link )
                if ( tmp=Parent_Thr(T->lchild, p) )
                    return tmp;
            if ( T->RTag==Link )
                if ( tmp=Parent_Thr(T->rchild, p) )
                    return tmp;
        }
    }
    return NULL;
}

BiThrNode* NextPtr_Thr(BiThrTree T, BiThrNode *p) {
    //if ( p==T->rchild )
    //    return T;
    //else {
        if ( p->RTag==Thread )              //右孩子为线索
            return p->rchild;
        else {
            if ( p==Parent_Thr(T, p)->rchild )  //p为右孩子
                return Parent_Thr(T, p);
            else {
                if ( Parent_Thr(T, p)->RTag!=Link ) //双亲没有右孩子
                    return Parent_Thr(T, p);
                else {
                    p = Parent_Thr(T, p)->rchild;
                    while ( 1 ) {
                        while ( p->LTag==Link )
                            p = p->lchild;
                        if ( p->RTag==Link )
                            p = p->rchild;
                        else 
                            break;
                    }
                    return p;
                }
            }
        }
    }
//}

#endif