#include "SequenceString.cpp"

int main() {
    char *chars = "abcdefg";
    char *t = "@@@@";
    char *v = "#####";
    SString T, S, V;
    int i;
    printf("Test of StrAssign_Sq function.\n");
    StrAssign_Sq(T, chars);
    StrTraverse_Sq(T);

    printf("\nTest of StrEmpty_Sq funcion.\n");
    StrEmpty_Sq(T) ? printf("String is empty.\n") : printf("String is not empty.\n");

    printf("\nTest of StrLenth_Sq function.\n");
    printf("The length is String T is %d.\n", StrLength_Sq(T));

    printf("\nTest of StrCopy_Sq funtcion.\n");
    printf("Copy string s from string t.\n");
    StrCopy_Sq(S, T);
    printf("Print string s: ");
    StrTraverse_Sq(S);
    printf("Replication success.\n");

    printf("\nTest of StrCompare_Sq funcion.\n");
    i = StrCompare_Sq(S, T);
    i==0 ? printf("String S is equal to string T.\n") : printf("String S is not equal to string T.\n");

    printf("\nTest of StrInsert_Sq function.\n");
    StrAssign_Sq(T, t);
    printf("Print string T: ");
    StrTraverse_Sq(T);
    printf("Print string S: ");
    StrTraverse_Sq(S);
    printf("Insert string T before the second character of string s.\n");
    StrInsert_Sq(S, T, 2);
    printf("Print S: ");
    StrTraverse_Sq(S);

    printf("\nTest of StrLength_Sq function.\n");
    printf("The length of string S is %d.\n", StrLength_Sq(S));

    printf("\nTest of Replace_Sq function.\n");
    StrAssign_Sq(V, v);
    printf("Print v: ");
    StrTraverse_Sq(V);
    printf("Print T: ");
    StrTraverse_Sq(T);
    printf("Replace all strings t int string S with string v.\n");
    Replace_Sq(S, T, V);
    printf("Print S: ");
    StrTraverse_Sq(S);


    printf("\nTest of StrDelete_Sq function.\n");
    printf("Delete four characters from the second character in string S.\n");
    StrDelete_Sq(S, 2, 4);
    printf("Print S: ");
    StrTraverse_Sq(S);

    printf("\nTest of Concat_Sq function.\n");
    printf("Print T: ");
    StrTraverse_Sq(T);
    printf("Print V: ");
    StrTraverse_Sq(V);
    printf("Connect string T and V to form string S.\n");
    Concat_Sq(S, T, V);
    printf("Print S: ");
    StrTraverse_Sq(S);

    printf("Clear string S, T and V as empty strings.\n");
    ClearString_Sq(S);
    ClearString_Sq(T);
    ClearString_Sq(V);
    printf("Cleaning is complete.\n");
    system("pause");
    return 0;
}