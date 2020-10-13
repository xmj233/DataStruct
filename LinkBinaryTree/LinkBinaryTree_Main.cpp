#include "LinkBinaryTree.cpp"

void Print(TElemType e) {
    printf("%c ", e);
}

int main() {
    FILE *fp, *fpp;
    BiTree T, c;
    BiTNode *e;
    InitBiTree(T);
    InitBiTree(c);
    printf("Test of CreateBiTree function.\n");
    fp = fopen("LinkBinaryTree.txt", "w");
    fputs("ABDG^^^EH^^I^^CF^J^^^", fp);
    fclose(fp);
    fp = fopen("LinkBinaryTree.txt", "r");
    CreateBiTree(fp, T);
    fclose(fp);
    LevelOrderTraverse(T, Print);
    printf("\n");
    PreOrderTraverse_1(T, Print);
    printf("\n");
    PreOrderTraverse_2(T, Print);
    printf("\n");
    InOrderTraverse_1(T, Print);
    printf("\n");
    InOrderTraverse_2(T, Print);
    printf("\n");
    PostOrderTraverse_1(T, Print);
    printf("\n");
    PostOrderTraverse_2(T, Print);
    printf("\n");

    printf("\nTest of BiTreeDepth funtcion.");
    printf("The depth of the tree T is %d.\n", BiTreeDepth(T));

    printf("\nTest of Parent function.\n");
    e = T->lchild->rchild;
    printf("The value of the parent node of E node is %c.\n", Parent(T, e)->data);

    printf("\nTest of LeftChild function.\n");
    printf("The value of the left child node of the node E is %c.\n", LeftChild(T, e)->data);

    printf("\n Test of RightChild function.\n");
    printf("The value of the right child node of the node E is %c.\n", RightChild(T, e)->data);

    printf("\nTest of LeftSibling function.\n");
    printf("The value of the right brother of the node E is %c.\n", LeftSibling(T, e)->data);

    printf("\nTest of RightSibling function.\n");
    e = T->lchild->lchild;
    printf("The value of the right brother of the node D is %c.\n", RightSibling(T, e)->data);

    printf("\nTest of InsertChild function.\n");
    fpp=fopen("LinkBinaryTree_2.txt", "w");
    fputs("MNF^^^^", fpp);
    fclose(fpp);
    fpp=fopen("LinkBinaryTree_2.txt", "r");
    CreateBiTree(fpp, c);
    fclose(fpp);
    PreOrderTraverse_1(c, Print);
    printf("\n");
    InsertChild(T, e, 1, c);
    PreOrderTraverse_1(T, Print);

    printf("\n\nTest of DeleteChild function.\n");
    DeleteChild(T, e, 1);
    PreOrderTraverse_1(T, Print);

    return 0;
}