#ifndef CHILDSIBLINGTREE_CPP
#define CHILDSIBLINGTREE_CPP

#include "ChildSiblingTree.h"

Status InitTree_CS(CSTree &T) {
    T   =   NULL;
    return OK;
}

Status CreateTree_CS(char *fp, CSTree &T) {
    char ch;
    ch  =   fp[i];
    i   ++;
    if ( ch=='^' ) 
        T   =   NULL;
    else {
        if ( !(T=(CSTree)malloc(sizeof(CSNode))) )
            exit(OVERFLOW);
        T->data =   ch;
        CreateTree_CS(fp, T->firstchild);
        CreateTree_CS(fp, T->nextsibling);
    }
    return OK;
}

Status ClearTree_CS(CSTree &T) {
    if ( T ) {
        ClearTree_CS(T->firstchild);
        ClearTree_CS(T->nextsibling);

        free(T);
        T   =   NULL;

    }
    return OK;
}

Status PreOrderTraverse_CS(CSTree T, void(Visit)(TElemType_CS)) {
    if ( T ) {
        Visit(T->data);
        PreOrderTraverse_CS(T->firstchild, Visit);
        PreOrderTraverse_CS(T->nextsibling, Visit);
    }
    return OK;
}

Status InOrderTraverse_CS(CSTree T, void(Visit)(TElemType_CS)) {
    if ( T ) {
        InOrderTraverse_CS(T->firstchild, Visit);
        Visit(T->data);
        InOrderTraverse_CS(T->nextsibling, Visit);
    }
    return OK;
}

#endif