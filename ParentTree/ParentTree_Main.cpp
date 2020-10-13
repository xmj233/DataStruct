#include "ParentTree.cpp"

int main() {
    FILE *fp;
    PTree T;
    InitTree_P(T);
    printf("Test of CreateTree_P function.\n");
    fp = fopen("ParentTree_1.txt", "r");
    CreateTree_P(fp, T);
    fclose(fp);
    LevelOrderTraverse_P(T);

    printf("\n Test of TreeDepth_P function.\n");
    printf("The depth of the tree T is %d.\n", TreeDepth_P(T));

    printf("\nTest of Root_P function.\n");
    printf("The value of the root node is %c.\n", Root_P(T));

    printf("\nTest of Value_P function.\n");
    printf("The value of the fifth node in tree T is %c.\n", Value_P(T, 5));

    printf("\nTest of Assign_P function.\n");
    Assign_P(T, 'E', 'M');
    LevelOrderTraverse_P(T);

    printf("\nTest of Parent_P function.\n");
    printf("%c\n", Parent_P(T, 'M'));

    printf("\n Test of LeftChild_P function.\n");
    printf("%c\n", LeftChild_P(T, 'F'));

    printf("\nTest of RightChild_P function.\n");
    printf("%c\n", RightChild_P(T, 'F'));

    printf("\nTest of LeftSibling_p function.\n");
    printf("%c\n", LeftSibling_P(T, 'H'));

    printf("\nTest of RightSibling_P function.\n");
    printf("%c\n", RightSibling_P(T, 'H'));

    return 0;
}