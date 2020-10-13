#include "HuffmanTree.cpp"

int main() {
    HuffmanTree HT;
    HuffmanCode HC;
    int w[8] = {5, 29, 7, 8, 14, 23, 3, 11};
    int n = 8;
    InitHuffmanTree(HT);
    printf("Test of CreateHuffmanTree function.\n");
    CreateHuffmanTree(HT, w, n);
    ShowHuffmanTree(HT);

    printf("\nTest of HuffmanCoding_1 function.\n");
    HuffmanCoding_1(HT, HC);
    ShowHuffmanCode(HC, HT);
    

    printf("\nTest of HuffmanCoding_2 function.\n");
    HuffmanCoding_2(HT, HC);
    ShowHuffmanCode(HC, HT);

    system("pause");

    return 0;
}