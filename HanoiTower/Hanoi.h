/* 汉诺塔问题
    递归的思想
    2020.1.31 */

#ifndef HANOI_H
#define HANOI_H

#include <stdio.h>
#include <windows.h>

int c = 0;

void hanoi(int n, char x, char y, char z);

void move(char x, int n, char z);

#endif