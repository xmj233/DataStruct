#ifndef BLOCKCHAINSTRING_CPP
#define BLOCKCHAINSTRING_CPP

#include "BlockChainString.h"

Status InitString_L(LString &T) {
    T.head = NULL;
    T.tail = NULL;
    T.curlen = 0;
}

Status StrAssign_L(LString &T, char *chars) {
    int len, i, j, k, count;
    char *ch;
    Chunk *chunk;
    InitString_L(T);
    for ( len=0,ch=chars; *ch; len++,ch++ );
    if ( !len )
        return ERROR;
    
    i = len/CHUNKSIZE;
    j = len%CHUNKSIZE;
    if ( j )
        i ++;

    for ( k=1; k<=i; k++ ) {
        if ( !(chunk=(Chunk*)malloc(sizeof(Chunk))) )
            exit(OVERFLOW);
        chunk->next = NULL;
        if ( k==1 ) 
            T.head=T.tail=chunk;
        else {
            T.tail->next = chunk;
            T.tail = chunk;
        }
        for ( count=0; count<CHUNKSIZE&&count+(k-1)*CHUNKSIZE<len; count++ )
            T.tail->ch[count] = chars[count+(k-1)*CHUNKSIZE];
    }

    while ( count<CHUNKSIZE ) {
        T.tail->ch[count] = '#';
        count ++;
    }
    T.curlen = len;

    return OK;
}

Status StrCopy_L(LString &T, LString S) {
    int i;
    Chunk *p, *r;
    InitString_L(T);
    for ( p=S.head; p; p=p->next ) {
        r = (Chunk*)malloc(sizeof(Chunk));
        if ( !r ) 
            exit(OVERFLOW);
        r->next = NULL;
        if ( p==S.head ) 
            T.head = T.tail = r;
        else {
            T.tail->next = r;
            T.tail = r;
        }
        for ( i=0; i<CHUNKSIZE; i++ )
            T.tail->ch[i] = p->ch[i];
    }
    T.curlen = S.curlen;

    return OK;
}

Status StrEmpty_L(LString S) {
    if ( S.head==NULL&&S.tail==NULL&&S.curlen==0 )
        return TRUE;
    else 
        return FALSE;
}

int StrCompare_L(LString S, LString T) {
    int i;
    Chunk *p, *q;
    p = S.head;
    q = T.head;
    while ( p&&q ) {
        for ( i=0; i<CHUNKSIZE; i++ )
            if ( p->ch[i]!=q->ch[i] )
                return p->ch[i] = q->ch[i]; 
        p = p->next;
        q = q->next;
    }
    return S.curlen-T.curlen;
}

int StrLength_L(LString S) {
    return S.curlen;
}

Status ClearString_L(LString &S) {
    Chunk *p, *q;
    p = S.head;
    while ( p ) {
        q = p->next;
        free(p);
        p = q;
    }
    S.curlen = 0;

    return OK;
}

Status DestoryString_L(LString &S) {
    //不能销毁
}

Status Concat_L(LString &T, LString S1, LString S2) {
    int i,j,k,count;
    Chunk *p, *q, *r;
    r = T.head;
    p = S1.head;
    q = S2.head;
    i=j=k=0;
    InitString_L(T);
    while ( p||q ) {
        if ( !r ) {
            if ( !(r=(Chunk*)malloc(sizeof(Chunk))) )
                exit(OVERFLOW);
            r->next = NULL;
            if ( !T.head )
                T.head=T.tail=r;
            else {
                T.tail->next=r;
                T.tail=r;
            }
        }
        if ( p ) {
            while ( p ) {
                r->ch[i] = p->ch[j];
                i = (i+1)%CHUNKSIZE;
                j = (j+1)%CHUNKSIZE;
                if ( !j || p->ch[j]=='#' )
                    p = p->next;
                if ( !i ) {
                    r = r->next;
                    break;
                }
            }
        }
        else {
            while ( q ) {
                r->ch[i] = q->ch[k];
                i = (i+1)%CHUNKSIZE;
                k = (k+1)%CHUNKSIZE;
                if ( !k || q->ch[k]=='#' )
                    q = q->next;
                if ( !i ) {
                    r = r->next;
                    break;
                }
            }
        }
    }
    T.curlen = S1.curlen+S2.curlen;
    count = (T.curlen-1)%CHUNKSIZE+1;
    while ( count<CHUNKSIZE ) 
        T.tail->ch[count++] = '#';

    return OK;
}

Status SubString_L(LString &Sub, LString S, int pos, int len) {
    int i, j, k, count;
    Chunk *p, *r;
    InitString_L(Sub);
    if ( StrEmpty_L(S) )
        return ERROR;
    if ( pos<1 || pos>S.curlen || len<0 || len>S.curlen-pos+1 )
        return ERROR;
    for ( count=1,p=S.head; pos>count*CHUNKSIZE; count++,p=p->next );
    i = 0;                  //计数
    j = 0;                  //遍历Sub
    k = (pos-1)%CHUNKSIZE;  //遍历S
    r = Sub.head;
    while ( i<len ) {
        if ( !r ) {
            if ( !(r=(Chunk*)malloc(sizeof(Chunk))) )
                exit(OVERFLOW);
            r->next = NULL;
            if ( !Sub.head )
                Sub.tail=Sub.head=r;
            else {
                Sub.tail->next=r;
                Sub.tail = r;
            }
        }
        while ( i<len ) {
            r->ch[j] = p->ch[k];
            j = (j+1)%CHUNKSIZE;
            k = (k+1)%CHUNKSIZE;
            i++;
            if ( !k ) 
                p = p->next;
            if ( !j ) {
                r = r->next;
                break;
            }
        }
    }
    Sub.curlen = len;
    count = (Sub.curlen-1)%CHUNKSIZE+1;
    while ( count<CHUNKSIZE ) 
        Sub.tail->ch[count++] = '#';
    
    return OK;
}

int Index_L(LString S, LString T, int pos) {
    int i, m, n;
    LString Sub;
    InitString_L(Sub);
    if ( pos>0 ) {
        m = StrLength_L(S);
        n = StrLength_L(T);
        i = pos;
        while( i<m-n+1 ) {
            SubString_L(Sub, S, i, T.curlen);
            if ( StrCompare_L(Sub, T) ) 
                i++;
            else 
                return i;
        }
    }
    return 0;
}

Status Replace_L(LString &S, LString T, LString V) {
    int i;
    i = Index_L(S, T, 1);
    while ( i ) {
        StrDelete_L(S, i, T.curlen);
        StrInsert_L(S, i, V);
        i += V.curlen;
        i = Index_L(S, T, i);
    }
    return OK;
}

Status StrInsert_L(LString &S, int pos, LString T) {
    int i, j, k, count;
    Chunk *r, *p1, *p2, *q;
    LString Tmp;
    InitString_L(Tmp);
    if ( pos<1 || pos>S.curlen+1 )
        return ERROR;
    i = j = k = 0;
    count = 1;
    r = Tmp.head;
    p1 = S.head;
    p2 = NULL;
    q = T.head;
    while ( p1 || q || p2 ) {
        if ( !r ) {
            if ( !(r=(Chunk*)malloc(sizeof(Chunk))) )
                exit(OVERFLOW);
            r->next = NULL;
            if ( !Tmp.head )
                Tmp.head = Tmp.tail = r;
            else {
                Tmp.tail->next = r;
                Tmp.tail = r;
            }
        }
        if ( p1 ) {
            while ( p1&&count<pos ) {
                r->ch[i] = p1->ch[j];
                i = (i+1)%CHUNKSIZE;
                j = (j+1)%CHUNKSIZE;
                count ++;
                if ( !j||p1->ch[j]=='#' )
                    p1 = p1->next;
                if ( !i ) {
                    r = r->next;
                    break;
                }
            }
            if ( count==pos ) {
                p2 = p1;
                p1 = NULL;
            }
        }
        else if ( q ) {
            while ( q ) {
                r->ch[i] = q->ch[k];
                i = (i+1)%CHUNKSIZE;
                k = (k+1)%CHUNKSIZE;
                if ( !k||q->ch[k]=='k' )
                    q = q->next;
                if ( !i ) {
                    r = r->next;
                    break;
                }
            }
        }
        else {
            while ( p2 ) {
                r->ch[i] = p2->ch[j];
                i = (i+1)%CHUNKSIZE;
                j = (j+1)%CHUNKSIZE;
                if ( !j||p2->ch[j]=='#' )
                    p2 = p2->next;
                if ( !i ) {
                    r = r->next;
                    break;
                }
            }
        }
    }
    Tmp.curlen = S.curlen + T.curlen;
    count = (Tmp.curlen-1)%CHUNKSIZE+1;
    while ( count<CHUNKSIZE ) 
        Tmp.tail->ch[count++] = '#';
    ClearString_L(S);
    S.head = Tmp.head;
    S.tail = Tmp.tail;
    S.curlen = Tmp.curlen;

    return OK;
}

Status StrDelete_L(LString &S, int pos, int len) {
    int first, last, m, n, count;
    Chunk *p, *q, *r;
    if ( pos<1 || pos>StrLength_L(S) || len<0 || len>S.curlen-pos+1 )
        return ERROR;
    first   =   pos;
    last    =   pos+len-1;
    for( count=1,p=S.head; pos>count*CHUNKSIZE; count++, p=p->next );
            //p指向first所在块
    for ( q=p; last>count*CHUNKSIZE; count++, q=q->next );
            //q指向last所在块
    
    m = (first-1)%CHUNKSIZE;
    n = (last-1)%CHUNKSIZE;
    n = (n+1)%CHUNKSIZE;
    if ( !n )
        q = q->next;
    while ( q&&q->ch[n]!='#' ) {
        p->ch[m] = q->ch[n];
        m = (m+1)%CHUNKSIZE;
        n = (n+1)%CHUNKSIZE;
        if ( !n )
            q = q->next;
        if ( !m )
            p = p->next;
    }
    S.curlen -= len;
    for ( count=1,S.tail=S.head; S.curlen>count*CHUNKSIZE; count++, S.tail=S.tail->next);
    count = (S.curlen-1)%CHUNKSIZE+1;
    while ( count<CHUNKSIZE )
        S.tail->ch[count++] = '#';
    r = S.tail->next;
    while ( r ) {
        S.tail->next = r->next;
        free(r);
        r = S.tail->next;
    }

    return OK;
}

Status StrTraverse_L(LString S) {
    int i;
    Chunk *p;
    p = S.head;
    while ( p ) {
        for ( i=0; i<CHUNKSIZE; i++ )
            if ( p->ch[i]!='#' )
                printf("%c ", p->ch[i]);
        p = p->next;
    }
    printf("\n");
}

#endif