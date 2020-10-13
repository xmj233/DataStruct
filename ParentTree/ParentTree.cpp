#ifndef PARENTTREE_CPP
#define PARENTTREE_CPP

#include "ParentTree.h"

Status InitTree_P(PTree &T) {
    T.n = 0;
    return OK;
}

#define ClearTree_P InitTree_P

Status CreateTree_P(FILE *fp, PTree &T) {
    char ch, pa, tmp;
    int i, j;

    ch = fgetc(fp);
    printf("Enter the root node of the tree. %c\n", ch);
    tmp = fgetc(fp);

    if ( ch!='^' ) {
        i = 0;
        T.nodes[i].data = ch;
        T.nodes[i].parent = -1;
        
        j = -1;
        while ( !feof(fp) ) {
            pa = getc(fp);
            printf("Enter the child node of %c: ", pa);
            tmp = getc(fp);
            j++;
            while ( 1 ) {
                ch = getc(fp);
                if ( ch=='^'||ch=='\n' ) {
                    if (ch=='^') {
                        printf("%c ", ch);
                        tmp = getc(fp);
                    }
                    break;
                }
                else {
                    printf("%c ", ch);
                    T.nodes[++i].data = ch;
                    T.nodes[i].parent = j;
                }
            }
            printf("\n");
        }
    }
    T.n = i + 1;
    return OK;
}

Status LevelOrderTraverse_P(PTree T) {
    int i;
    for ( i=0; i<T.n; i++ ) {
        printf("%c ", T.nodes[i].data);
    }
    printf("\n");
    return OK;
}

Status TreeEmpty_P(PTree T) {
    return T.n?FALSE:TRUE;
}

int TreeDepth_P(PTree T) {
    int dep, n;
    n = T.n-1;
    dep = 1;
    while ( T.nodes[n].parent!=-1 ) {
        n = T.nodes[n].parent;
        dep ++;
    }
    return dep;
}

TElemType_P Root_P(PTree T) {
    int i;
    for ( i=0; i<T.n; i++ ) {
        if ( T.nodes[i].parent<0 )
            return T.nodes[i].data;
    }
    return '\0';
}

TElemType_P Value_P(PTree T, int i) {
    if ( i<T.n )
        return T.nodes[i].data;
    else
        return '\0';
}

Status Assign_P(PTree &T, TElemType_P cur_e, TElemType_P value) {
    int i;
    for ( i=0; i<T.n; i++ ) {
        if ( T.nodes[i].data==cur_e ) {
            T.nodes[i].data = value;
            return OK;
        }
    }
    return ERROR;
}

TElemType_P Parent_P(PTree T, TElemType_P cur_e) {
    int i;
    for ( i=0; i<T.n; i++ ) {
        if ( T.nodes[i].data==cur_e ) {
            return T.nodes[T.nodes[i].parent].data;
        }
    }
    return '\0';
}

TElemType_P LeftChild_P(PTree T, TElemType_P cur_e) {
    int i, j;
    for ( i=0; i<T.n; i++ ) {
        if ( T.nodes[i].data==cur_e ) 
            break;
    }
    for ( j=i+1; j<T.n; j++ ) {
        if ( T.nodes[j].parent==i )
            return T.nodes[j].data;
    }
    return '\0';
}

TElemType_P RightChild_P(PTree T, TElemType_P cur_e) {
    int i, j;
    for ( j=0; j<T.n; j++ )
        if ( T.nodes[j].data==cur_e )
            break;
    for ( i=T.n-1; i>=0; i-- ) {
        if ( T.nodes[i].parent==j )
            return T.nodes[i].data;
    }
    return '\0';
}

TElemType_P LeftSibling_P(PTree T, TElemType_P cur_e) {
    int i;
    for ( i=0; i<T.n; i++ ) {
        if ( T.nodes[i].data==cur_e )
            break;
    }
    if ( T.nodes[i-1].parent==T.nodes[i].parent )
        return T.nodes[i-1].data;
    return '\0';
}

TElemType_P RightSibling_P(PTree T, TElemType_P cur_e) {
    int i;
    for ( i=0; i<T.n; i++ ) {
        if ( T.nodes[i].data==cur_e )
            break;
    }
    if ( T.nodes[i+1].parent==T.nodes[i].parent )
        return T.nodes[i+1].data;
    return '\0';
}

#endif