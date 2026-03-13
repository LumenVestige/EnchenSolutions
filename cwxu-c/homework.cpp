#include <stdio.h>

int main() {
    int max(int x, int y, int z);
    int a, b, c, d;
    scanf("%d%d%d", &a, &b, &c);
    d = max(a, b, c);
    printf("%d\n", d);
    return 0;
}

int max(int x, int y, int c) {
    int f;
    f = (a > b) ? a : b;
    f = (f > c) ? f : c;
    return f;
}