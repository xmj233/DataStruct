#include "BlockChainString.cpp"

int main() {
    char *chars="abcdefg";
    char *a = "@@@";
    LString S, T, V, Sub;
    InitString_L(S);
    InitString_L(T);
    InitString_L(V);
    InitString_L(Sub);
    printf("Test of StrAssign_L function.\n");
    StrAssign_L(T, chars);
    StrTraverse_L(T);

    printf("\nTest of StrEmpty_L function.\n");
    StrEmpty_L(S) ? printf("String S is empty.\n") : printf("String S is not empty.\n");
    StrEmpty_L(T) ? printf("String T is empty.\n") : printf("String T is not empty.\n");

    printf("\nTest of StrLength_L function.\n");
    printf("The length of string S is %d.\n", StrLength_L(S));
    printf("The length of string T is %d.\n", StrLength_L(T));

    printf("\nTest of StrCopy_L function.\n");
    printf("Copy string S from string T.\n");
    StrCopy_L(S, T);
    printf("Print string S: ");
    StrTraverse_L(S);

    printf("\nTest of StrCompare_L function.\n");
    !StrCompare_L(S, T) ? printf("String S is equal to string T.\n"): printf("String S is not equal to string T.\n");

    printf("\nTest of Concat_L function.\n");
    printf("Print string S: ");
    StrTraverse_L(S);
    printf("Print string T: ");
    StrTraverse_L(T);
    printf("Connect string S and T to form string V.\n");
    Concat_L(V, S, T);
    printf("Print string V: ");
    StrTraverse_L(V);
    printf("The length of string V is %d.\n", StrLength_L(V));

    printf("\nTest of SubString_L function.\n");
    printf("Using string Sub to return a three-character substring strating at the eighth character of string V.\n");
    SubString_L(Sub, V, 8, 3);
    printf("Print string Sub: ");
    StrTraverse_L(Sub);

    printf("\nTest of StrInsert_L function.\n");
    printf("Print string S: ");
    StrTraverse_L(S);
    printf("The length of string S is %d.\n", StrLength_L(S));
    printf("Insert string Sub before the second character of string S.\n");
    StrInsert_L(S, 2, Sub);
    printf("Print string S: ");
    StrTraverse_L(S);
    printf("The length of string S is %d.\n", StrLength_L(S));

    printf("\nTest of StrDelete_L function.\n");
    printf("Print string S: ");
    StrTraverse_L(S);
    printf("Delete seven characters from the second character in string S.\n");
    StrDelete_L(S, 2, 7);
    printf("Print string S: ");
    StrTraverse_L(S);
    printf("The length of string S is %d.\n", StrLength_L(S));

    printf("\nTest of Replace_L function.\n");
    printf("Print string Sub: ");
    StrTraverse_L(Sub);
    printf("Print string V: ");
    StrTraverse_L(V);
    StrAssign_L(T, a);
    printf("Print string T: ");
    StrTraverse_L(T);
    printf("Replace all substrings in string V that are equal to string Sub with string string T.\n");
    Replace_L(V, Sub, T);
    printf("Print string V: ");
    StrTraverse_L(V);
    return 0;
}