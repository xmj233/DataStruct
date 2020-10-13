#include "SeqBinaryTree.cpp"

Status Print(TElemType e) {
    printf("%c ", e);
    return OK;
}

int main() {
    FILE *fp, *fpp;
    SqBiTree T;
    Position p;
    InitBiTree_Sq(T);
    fp = fopen("SeqBinaryTree_Le.txt", "w");
    fputs("ABCDEF^G^HI^J\n", fp);
    fclose(fp);
    printf("Test of CreateBiTree_Le_Sq function.\n");
    fp = fopen("SeqBinaryTree_Le.txt", "r");
    CreateBiTree_Le_Sq(fp, T);
    fclose(fp);
    LevelOrderTraverse_Sq(T, Print);
    printf("\n");
    InOrderTraverse_Sq(T, Print, 0);
    printf("\n");
    PostOrderTraverse_Sq(T, Print, 0);

    printf("\n\nTest of CreateBiTree_Pre_Sq function.\n");
    fpp = fopen("SeqBinaryTree_Pre.txt", "w");
    fputs("ABDG^^^EH^^I^^CF^J^^^", fpp);
    fclose(fpp);
    fpp = fopen("SeqBinaryTree_Pre.txt", "r");
    CreateBiTree_Pre_Sq(fpp, T, 0);
    fclose(fpp);
    PreOrderTraverse_Sq(T, Print, 0);

    printf("\n\nTest of BiTreeDepth_Sq function.\n");
    printf("The depth of Tree T is %d.\n", BiTreeDepth_Sq(T));

    printf("\nTest of Root_Sq function.\n");
    printf("Return the value of Root: %c.\n", Root_Sq(T));

    printf("\nTest of Value_Sq function.\n");
    p.level = 3;
    p.order = 2;
    printf("%c.\n", Value_Sq(T, p));

    printf("\nTest of Assign_Sq funciton.\n");
    Assign_Sq(T, p, 'M');
    printf("%c.\n", Value_Sq(T, p));
    LevelOrderTraverse_Sq(T, Print);

    printf("\n\nTest of Parent_Sq function.\n");
    printf("%c.\n", Parent_Sq(T, p));

    printf("\n Test of RightChild_Sq function.\n");
    printf("%c.\n", RightChild_Sq(T, p));

    printf("\nTest of LeftSibling_Sq function.\n");
    p.level = 3;
    p.order = 1;
    printf("%c.\n", LeftSibling_Sq(T, p));

    printf("\nTest of RightSibling_Sq function.\n");
    p.level = 2;
    p.order = 2;
    printf("%c.\n", RightSibling_Sq(T, p));

}