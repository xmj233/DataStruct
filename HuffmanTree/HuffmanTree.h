/* 赫夫曼编码
    20200216    */
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../Status.h"

typedef struct {
    unsigned int weight;
    unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;

typedef char * *HuffmanCode;

Status InitHuffmanTree(HuffmanTree &HT);

//w存放n个字符的权值，构造赫夫曼树HT
Status CreateHuffmanTree(HuffmanTree &HT, int *w, int n);

Status Select(HuffmanTree T, int end, int &s1, int &s2);

//逆序计算赫夫曼编码
Status HuffmanCoding_1(HuffmanTree HT, HuffmanCode &HC);

//顺序计算赫夫曼编码
Status HuffmanCoding_2(HuffmanTree HT, HuffmanCode &HC);

void ShowHuffmanTree(HuffmanTree HT);

void ShowHuffmanCode(HuffmanCode HC, HuffmanTree HT);


#endif