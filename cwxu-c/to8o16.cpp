//
// Created by sanenchen on 25-10-10.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void to8(int n) {
    char a[32];
    int i = 0;
    bool isNeg = false;
    if (n < 0) {
        isNeg = true;
        n = -n;
    }
    while (n > 0) {
        int t = n % 8;
        n /= 8;
        a[i] = '0' + t;
        i++;
    }
    if (isNeg)
        printf("-");
    for (int j = i - 1; j >= 0; --j)
        printf("%c", a[j]);
    printf(" ");
}

void to16(int n) {
    char a[32];
    int i = 0;
    bool isNeg = false;
    if (n < 0) {
        isNeg = true;
        n = -n;
    }
    while (n > 0) {
        int t = n % 16;
        n /= 16;
        if (t < 10)
            a[i] = '0' + t;
        else a[i] = 'a' + t - 10;
        i++;
    }
    if (isNeg)
        printf("-");
    for (int j = i - 1; j >= 0; --j)
        printf("%c", a[j]);
    printf("\n");
}

int main() {
    for (int i = 0; i < 8; ++i) {
        int t;
        scanf("%d", &t);
        to8(t);
        to16(t);
    }
    return 0;
}