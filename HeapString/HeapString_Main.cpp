#include "HeapString.cpp"

int main() {
    char *chars = "abcdefg";
    char *t     = "@@@@";
    char *v     = "#####";  
    HString S, T, V, Sub;
    InitString(S);
    InitString(T);
    InitString(V);
    InitString(Sub);
    printf("Test of StrAssign_H function.\n");
    StrAssign_H(S, chars);
    printf("Print string S: ");
    StrTraverse_H(S);

    printf("\nTest of StrEmpty_H function.\n");
    StrEmpty_H(S) ? printf("String s is empty.\n") : printf("String s if not empty.\n");
    StrEmpty_H(T) ? printf("String t is empty.\n") : printf("String t if not empty.\n");

    printf("\nTest of StrLenth_H function.\n");
    printf("The length of string S is %d.\n", StrLength_H(S));
    printf("The length of string T is %d.\n", StrLength_H(T));

    printf("\nTest of StrCopy_H function.\n");
    StrCopy_H(T, S);
    printf("Print string T: ");
    StrTraverse_H(T);

    printf("\nTest of StrInsert_H function.\n");
    printf("Print S: ");
    StrTraverse_H(S);
    printf("Insert string T Before the last character of string S.\n");
    StrInsert_H(S, S.length+1, T);
    printf("Print S: ");
    StrTraverse_H(S);

    printf("\nTest of StrDelete_H function.\n");
    printf("Print string T: ");
    StrTraverse_H(T);
    printf("Delete four characters from the fourth character in string T.\n");
    StrDelete_H(T, 4, 4);
    printf("Print string T: ");
    StrTraverse_H(T);

    printf("\nTest of SubString_H function.\n");
    printf("Using the string Sub to return a seven-character substring staring at the eighth character of the string s.\n");
    SubString_H(Sub, S, 8, 7);
    printf("Print string Sub: ");
    StrTraverse_H(Sub);

    printf("\nTest of Replace_H function.\n");
    StrAssign_H(V, v);
    printf("Print string T: ");
    StrTraverse_H(T);
    printf("Print string V: ");
    StrTraverse_H(V);
    printf("Print string S: ");
    StrTraverse_H(S);
    printf("Replace all substrings in string S that are equal to string T with string V.\n");
    Replace_H(S, T, V);
    printf("Print string S: ");
    StrTraverse_H(S);

    printf("\nTest of Concat_H function.\n");
    StrAssign_H(T, t);
    printf("Print string T: ");
    StrTraverse_H(T);
    printf("Print string V: ");
    StrTraverse_H(V);
    printf("Connect string T and V to form string S.\n");
    Concat_H(S, T, V);
    printf("Print string S: ");
    StrTraverse_H(S);

    printf("\nClear String S, T, V.\n");
    ClearString_H(S);
    ClearString_H(T);
    ClearString_H(V);
    printf("Clearing is complete.\n");
    
    return 0;

}