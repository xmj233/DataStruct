#include "TridentBinaryTree.cpp"

void Print(TriElemType e) {
    printf("%c ", e);
}

int main() {
    FILE *fp;
    TriBiTree T, c;
    TriBiTNode *e;
    printf("Test of CreateBiTree_Tri function.\n");
    //fp = fopen("TridentBinaryTree_1.txt", "w");
    //fputs("ABDG^^^EH^^I^^CF^J^^^", fp);
    //fclose(fp);
    fp = fopen("TridentBinaryTree_1.txt", "r");
    CreateBiTree_Tri(fp, T);
    fclose(fp);
    LevelOrderTraverse_Tri(T, Print);
    PreOrderTraverse_Tri(T, Print);
    InOrderTraverse_Tri(T, Print);
    PostOrderTraverse_Tri(T, Print);

    printf("\nTest of BiTreeDepth_Tir function.\n");
    printf("The depth of the tree T is %d.\n", BiTreeDepth_Tri(T));

    printf("\nTest of Root_Tri function.\n");
    printf("The value of the root node is %c.\n", Root_Tri(T)->data);

    printf("\nTest of LeftSibling_Tri function.\n");
    e = T->lchild->rchild;
    printf("The value of left_child node of E node is %c.\n", LeftSibling_Tri(T, e)->data);

    printf("\nTest of InsertChild_Tri function.\n");
    //fp = fopen("TridentBinaryTree_2.txt", "w");
    //fputs("MNF^^^^", fp);
    //fclose(fp);
    fp = fopen("TridentBinaryTree_2.txt", "r");
    CreateBiTree_Tri(fp, c);
    fclose(fp);
    e = T->lchild->lchild;
    InsertChild_Tri(T, e, 1, c);
    LevelOrderTraverse_Tri(T, Print);

    printf("\nTest of DeleteChild_Tri funcion.\n");
    DeleteChild_Tri(T, e, 1);
    LevelOrderTraverse_Tri(T, Print);

    return 0;
}
