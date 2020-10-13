#include "CircularQueue.cpp"

void Print(QElemType e) {
    printf("%d ", e);
}

int main() {
    SqQueue Q;
    int i;
    QElemType e;
    InitQueue(Q);
    QueueEmpty(Q) ? printf("The queue is empty.\n") : printf("The queue is not empty.\n");
    printf("Test of EnQueue function.\n");
    printf("Create a circular queue.\n");
    for ( i=1; i<=5; i++ ) 
        EnQueue(Q, i*2);
    QueueEmpty(Q) ? printf("The queue is empty.\n") : printf("The queue is not empty.\n");
    QueueTraverse(Q, Print);
    printf("The length of the queue is %d.\n", QueueLength(Q));
    printf("Enqueue 666.\n");
    EnQueue(Q, 666);
    QueueTraverse(Q, Print);
    printf("The length of the queue is %d.\n", QueueLength(Q));

    printf("\nTest of DeQueue function.\n");
    printf("Out of Queue.\n");
    DeQueue(Q, e);
    QueueTraverse(Q, Print);
    EnQueue(Q, 333);
    EnQueue(Q, 333);
    QueueTraverse(Q, Print);

    ClearQueue(Q);
    DestoryQueue(Q);

    return 0;
}