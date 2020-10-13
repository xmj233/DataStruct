#include "LinkQueue.cpp"

void Print(QElemType e) {
    printf("%d ", e);
}

int main() {
    LinkQueue Q;
    int i;
    QElemType e;
    InitQueue(Q);
    printf("队列是否为空：%d.\n", QueueEmpty(Q));
    printf("Test of EnQueue function.\n");
    printf("创建一个队列.\n");
    for ( i=1; i<=5; i++ ) {
        EnQueue(Q, i*2);
    }
    QueueTraverse(Q, Print);
    printf("队列的长度为%d.\n", QueueLength(Q));
    printf("入队列222.\n");
    EnQueue(Q, 222);
    QueueTraverse(Q, Print);
    printf("队列的长度为%d.\n", QueueLength(Q));
    printf("队列是否为空：%d\n", QueueEmpty(Q));

    printf("\n Test of DeQueue function.\n");
    printf("出队列.\n");
    DeQueue(Q, e);
    DeQueue(Q, e);
    QueueTraverse(Q, Print);

    printf("\n Test of GetHead function.\n");
    GetHead(Q, e);
    printf("队列的头部元素为%d.\n", e);

    printf("\n Test of ClearQueue function.\n");
    Q.front!=NULL&&Q.rear!=NULL ? printf("Q存在\n") : printf("Q不存在\n");
    printf("队列是否为空：%d\n", QueueEmpty(Q));
    printf("清空队列\n");
    ClearQueue(Q);
    printf("队列是否为空：%d\n", QueueEmpty(Q));

    printf("\n Test of Destory function.\n");
    printf("销毁Q前：");
    Q.front!=NULL&&Q.rear!=NULL ? printf("Q存在\n") : printf("Q不存在\n");
    printf("销毁Q后：");
    DestoryQueue(Q);
    Q.front!=NULL&&Q.rear!=NULL ? printf("Q存在\n") : printf("Q不存在\n");

    system("pause");

    return 0;
}