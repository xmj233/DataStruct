#include "Hanoi.cpp"

int main() {
    char x, y, z;
    int n;
    x = 'x';
    y = 'y';
    z = 'z';
    n = 64;

    hanoi(n, x, y, z);
    system("pause");
    return 0;
}