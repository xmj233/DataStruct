#include "ThreadBinaryTree.cpp"

void Print(TElemType_Thr e) {
    printf("%c ", e);
}

int main() {
    FILE *fp;
    BiThrTree Thrt1, Thrt2, Thrt3, T1, T2, T3;
    //fp = fopen("ThreadBinaryTree.txt", "w");
    //fputs("ABDG^^^EH^^I^^CF^J^^^", fp);
    //fclose(fp);
    fp = fopen("ThreadBinaryTree.txt", "r");
    CreateBiTree_Thr(fp, T1);
    fseek(fp, 0, SEEK_SET);
    CreateBiTree_Thr(fp, T2);
    fseek(fp, 0, SEEK_SET);
    CreateBiTree_Thr(fp, T3);
    fclose(fp);
    printf("Test of InOrder... function.\n");
    InOrderThreading_Thr(Thrt1, T1);
    InOrderTraverse_Thr(Thrt1, Print);
    printf("\n\nTest of PreOrder... function.\n");
    PreOrderThreading_Thr(Thrt2, T2);
    PreOrderTraverse_Thr(Thrt2, Print);
    
    printf("\n\nTest of PostOrder... function.\n");
    PostOrderThreading_Thr(Thrt3, T3);
    PostOrderTraverse_Thr(Thrt3, Print);

    return 0;
}