#ifndef DIFFERENCE_CPP
#define DIFFERENCE_CPP

#include "./Difference.h"

void Difference(SLinkList &space) {
    InitList(space);
    int head = MAXSIZE-1;
    int tail = head;
    int len_a, len_b, i, j, a, b, p, k;
    scanf("%d %d", &len_a, &len_b);
    for ( i=1; i<=len_a; i++ ) {
        scanf("%d", &a);
        j = Malloc(space);
        space[j].data = a;
        space[j].cur = space[tail].cur;
        space[tail].cur = j; 
        tail = j;
    }
    for ( i=1; i<=len_b; i++ ) {
        scanf("%d", &b);
        p = head;
        k = space[head].cur;
        while ( k&&space[k].data!=b ) {
            p = k;
            k = space[k].cur;
        }
        if ( k==0 ) {
            j = Malloc(space);
            space[j].data = b;
            space[j].cur = space[tail].cur;
            space[tail].cur = j;
            //tail = j;
        }
        else {
            space[p].cur = space[k].cur;
            Free(space, k);
            if ( tail==k ) 
                tail = p;
        }
    }
}

#endif