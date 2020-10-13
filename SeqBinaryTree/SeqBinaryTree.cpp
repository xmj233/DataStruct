#ifndef SEQBINARYTREE_CPP
#define SEQBINARYTREE_CPP

#include "SeqBinaryTree.h"

Status InitBiTree_Sq(SqBiTree &T) {
    int i;
    for ( i=0; i<MAX_TREE_SIZE; i++ ) {
        T[i] = 0;
    }
    return OK;
}

Status DestoryBiTree_Sq(SqBiTree &T) {
    //不能销毁
}

Status ClearBiTree_Sq(SqBiTree &T) {
    int i;
    for ( i=0; i<MAX_TREE_SIZE; i++ ) {
        T[i] = 0;
    }
    return OK;
}

Status CreateBiTree_Le_Sq(FILE *fp, SqBiTree &T) {
    int i=0;
    TElemType ch;
    ch =getc(fp);
    while ( ch!='\n' ) {
        if ( ch=='^' ) 
            T[i++] = 0;
        else 
            T[i++] = ch;
    ch =getc(fp);
    }
    return OK;
}

Status CreateBiTree_Pre_Sq(FILE *fp, SqBiTree &T, int i) {
    TElemType ch;
    ch = getc(fp);
    if ( ch=='^' ) 
        T[i] = 0;
    else {
        T[i] = ch;
        CreateBiTree_Pre_Sq(fp, T, i*2+1);
        CreateBiTree_Pre_Sq(fp, T, i*2+2);
    }

    return OK;
}

Status BiTreeEmpty_Sq(SqBiTree T) {
    if ( T[0]==0 ) 
        return TRUE;
    else 
        return FALSE;
}

int BiTreeDepth_Sq(SqBiTree T) {
    int level=0;
    int len;
    for ( len=MAX_TREE_SIZE; len>=1; len-- ) {
        if ( T[len]!=0 )
            break;
    }
    while ( pow(2, level)-1<len ) {
        level ++;
    }
    return level;
}

TElemType Root_Sq(SqBiTree T) {
    return T[0];
}

TElemType Value_Sq(SqBiTree T, Position e) {
    int i;
    i = pow(2, e.level-1)+e.order-2;
    return T[i];
}

Status Assign_Sq(SqBiTree T, Position e, TElemType value) {
    int i = pow(2, e.level-1)+e.order-2;
    T[i] = value;

    return OK;
}

TElemType Parent_Sq(SqBiTree T, Position e) {
    int i = pow(2, e.level-1)+e.order-2;
    if ( i==0 ) 
        return '0';
    else {
        i = (i+1)/2-1;
        return T[i];
    }
}

TElemType LeftChild_Sq(SqBiTree T, Position e) {
    int i = pow(2, e.level-1)+e.order-2;
    i = i*2+1;
    return T[i];
}

TElemType RightChild_Sq(SqBiTree T, Position e) {
    int i = pow(2, e.level-1)+e.order-2;
    i = i*2+2;
    return T[i];
}

TElemType LeftSibling_Sq(SqBiTree T, Position e) {
    int i = pow(2, e.level-1)+e.order-2;
    if ( e.order==1 )
        return '0';
    else {
        i --;
        return T[i];
    }
}

TElemType RightSibling_Sq(SqBiTree T, Position e) {
    int i = pow(2, e.level-1)+e.order-2;
    int j, k;
    for ( j=pow(2, e.level-1); j>=1; j--) {
        k = pow(2, e.level-1)+j-2;
        if ( T[k]!=0 ) 
            break;
    }
    if ( e.order==j )
        return '0';
    else {
        i ++;
        return T[i];
    }
}

Status PreOrderTraverse_Sq(SqBiTree T, Status(Visit)(TElemType), int i) {
    if ( T[i]!=0 ) {
        Visit(T[i]);
        PreOrderTraverse_Sq(T, Visit, i*2+1);
        PreOrderTraverse_Sq(T, Visit, i*2+2);
    }
    return OK;
}

Status InOrderTraverse_Sq(SqBiTree T, Status(Visit)(TElemType), int i) {
    if ( T[i]!=0 ) {
        InOrderTraverse_Sq(T, Visit, i*2+1);
        Visit(T[i]);
        InOrderTraverse_Sq(T, Visit, i*2+2);
    }
    return OK;
}

Status PostOrderTraverse_Sq(SqBiTree T, Status(Visit)(TElemType), int i) {
    if ( T[i]!=0 ) {
        PostOrderTraverse_Sq(T, Visit, i*2+1);
        PostOrderTraverse_Sq(T, Visit, i*2+2);
        Visit(T[i]);
    }
    return OK;
}

Status LevelOrderTraverse_Sq(SqBiTree T, Status(Visit)(TElemType)) {
    int i;
    for ( i=0; i<MAX_TREE_SIZE; i++ ) {
        if ( T[i]!=0 ) 
            Visit(T[i]);
    }
    return OK;
}


#endif