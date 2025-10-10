//
// Created by sanenchen on 25-10-10.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    char a[81], b[81], d[81];
    fgets(a, 80, stdin);
    fgets(b, 80, stdin);
    fgets(d, 80, stdin);
    int i = 0;
    int upper = 0, lower = 0, num = 0, space = 0, other = 0;
    while (a[i] != '\n') {
        char c = a[i];
        if (c >= 'A' && c <= 'Z') {
            upper++;
        } else if (c >= 'a' && c <= 'z') {
            lower++;
        } else if (c >= '0' && c <= '9') {
            num++;
        } else if (c == ' ') {
            space++;
        } else {
            other++;
        }
        i++;
    }
    i = 0;
    while (b[i] != '\n') {
        char c = b[i];
        if (c >= 'A' && c <= 'Z') {
            upper++;
        } else if (c >= 'a' && c <= 'z') {
            lower++;
        } else if (c >= '0' && c <= '9') {
            num++;
        } else if (c == ' ') {
            space++;
        } else {
            other++;
        }
        i++;
    }
    i = 0;
    while (d[i] != '\n') {
        char c = d[i];
        if (c >= 'A' && c <= 'Z') {
            upper++;
        } else if (c >= 'a' && c <= 'z') {
            lower++;
        } else if (c >= '0' && c <= '9') {
            num++;
        } else if (c == ' ') {
            space++;
        } else {
            other++;
        }
        i++;
    }
    printf("%d %d %d %d %d", upper, lower, num, space, other);
    return 0;
}