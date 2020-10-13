#include "SequenceStack.cpp"

void Print(SElemType e) {
    printf("%d ", e);
}

int main() {
    SqStack S;
    int i;
    SElemType e;
    InitStack(S);
    if ( StackEmpty(S) )
        printf("栈为空.\n");
    else 
        printf("栈不空.\n");
    printf("Test of Push function.\n");
    printf("创建一个栈.\n");
    for ( i=1; i<=5; i++ ) 
        Push(S, i*2);
    StackTraverse(S, Print);
    printf("将100入栈.\n");
    Push(S, 100);
    StackTraverse(S, Print);
    printf("栈长度为%d\n", StackLength(S));

    printf("\nTest of Pop function.\n");
    printf("出栈.\n");
    Pop(S, e);
    printf("出栈元素为%d\n", e);
    StackTraverse(S, Print);
    printf("栈长度为%d\n", StackLength(S));

    printf("\nTest of GetTop function.\n");
    GetTop(S, e);
    printf("栈顶元素为%d.\n", e);
    if ( StackEmpty(S) )
        printf("栈为空.\n");
    else 
        printf("栈不空.\n");
    DestoryStack(S);

    return 0;
}