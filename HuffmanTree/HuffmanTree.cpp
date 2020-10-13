#ifndef HUFFMANTREE_CPP
#define HUFFMANTREE_CPP
#include "HuffmanTree.h"

Status InitHuffmanTree(HuffmanTree &HT) {
    HT = NULL;
    return OK;
}

Status CreateHuffmanTree(HuffmanTree &HT, int *w, int n) {
    int m, i, j;
    int s1, s2;
    j = 0;
    m = 2*n-1;
    if ( n<=1 )
        return ERROR;
    if ( !(HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode))) )
        exit(OVERFLOW);
    HT[0].weight = n;
    for ( i=1; i<=m; i++ ) {
        if ( i<=n )
            HT[i].weight = w[j++];
        else 
            HT[i].weight = 0;
        
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].parent = 0;
    }

    for ( i=n+1; i<=m; i++ ) {
        Select(HT, i-1, s1, s2);
        HT[s1].parent = HT[s2].parent = i;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
    }
    return OK;
}

Status Select(HuffmanTree T, int end, int &s1, int &s2) {
    int count, i, m, n, tmp;
    count = 1;
    if (end<2)
        return ERROR;
    for ( i=1; i<=end; i++ ) {
        if ( T[i].parent==0 ) {
            if ( count==1 )
                m = i;
            if ( count==2 ) 
                n = i;
            count ++;
        }
        if ( count >2 ) 
            break;
    }

    if ( T[m].weight>T[n].weight ) {
        tmp = m;
        m = n;
        n = tmp;
    }
    i = (m>n?m:n) +1;

    for ( i; i<=end; i++ ) {
        if ( T[i].parent==0 ) {
            if ( T[i].weight<T[m].weight ) {
                n = m;
                m = i;
            }
            else {
                if ( T[i].weight>=T[m].weight&&T[i].weight<T[n].weight )
                    n = i;
            }
        }
    }
    s1 = T[m].weight<=T[n].weight?m:n;
    s2 = T[m].weight>T[n].weight?m:n;
    return OK;
}

Status HuffmanCoding_1(HuffmanTree HT, HuffmanCode &HC) {
    int n, i, start, c, f;
    char *cd;
    n = HT[0].weight;
    if ( !(HC=(HuffmanCode)malloc((n+1)*sizeof(char*))) )
        exit(OVERFLOW);
    cd = (char*)malloc(n*sizeof(char));
    cd[n-1] = '\0';
    for ( i=1; i<=n; i++ ) {
        start = n-1;
        for ( c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent ) {
            if ( HT[f].lchild==c ) 
                cd[--start] = '0';
            else 
                cd[--start] = '1';
        }
        HC[i] = (char*)malloc((n-start)*sizeof(char));
        strcpy(HC[i], &cd[start]);
    }
    free(cd);
}

Status HuffmanCoding_2(HuffmanTree HT, HuffmanCode &HC) {
    int n, m, p, cdlen, i;
    char *cd;
    n = HT[0].weight;
    m = 2*n-1;
    p = m;
    cdlen = 0;
    int mark[m+1];
    for ( i=1; i<=m; i++ )
        mark[i] = 0;
    //for ( i=1; i<=m; i++ )
    //    HT[i].weight = 0;
    HC = (HuffmanCode)malloc((n+1)*sizeof(char*));
    if ( !HC )
        exit(OVERFLOW);
    cd = (char*)malloc(n*sizeof(char));
    if ( !cd )
        exit(OVERFLOW);
    while ( p ) {
        if ( mark[p]==0 /*HT[p].weight==0*/ ) {
            //HT[p].weight = 1;
            mark[p] = 1;
            if ( HT[p].lchild!=0 ) {
                p = HT[p].lchild;
                cd[cdlen++] = '0';
            }
            else if(HT[p].rchild==0) {
                HC[p] = (char*)malloc((cdlen+1)*sizeof(char));
                cd[cdlen] = '\0';
                strcpy(HC[p], cd);
            }
        }
        else if ( mark[p]==1 /*HT[p].weight==1*/) {
            //HT[p].weight = 2;
            mark[p] = 2;
            if ( HT[p].rchild!=0 ) {
                p = HT[p].rchild;
                cd[cdlen++] = '1';
            }
        }
        else {
            //HT[p].weight = 0;
            mark[p] = 0;
            p = HT[p].parent;
            cdlen--;
        }
    }
}

void ShowHuffmanTree(HuffmanTree HT) {
    int i, m, n;
    n = HT[0].weight;
    m = 2*n-1;
    for ( i=0; i<=m; i++ ) {
        if ( i==0 ) {
            printf("order\tweight\tparent\tlchild\trchild\n");
            printf("%2d\t%2d\t%4c\t%4c\t%4c\n", i, HT[i].weight, 'X', 'X', 'X');
        }
        else {
            printf("%2d\t%2d\t%4d\t%4d\t%4d\n",i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
        }
    }
}

void ShowHuffmanCode(HuffmanCode HC, HuffmanTree HT) {
    int i;

    printf("order\tweight\t\tHuffmanCode\n");
    for ( i=1; i<=HT[0].weight; i++ ) {
        printf("%2d\t%4d\t\t%s\n", i, HT[i].weight, HC[i]);
    }
}

#endif