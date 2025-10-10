//
// Created by sanenchen on 25-10-10.
//
#include <cstdio>
#include <stdlib.h>
#include <cmath>
int main() {
    float x, y;
    int a;
    scanf("%f%d%f", &x, &a, &y);
    float c = x+a%3*(int)(x+y)%2/4;
    printf("%.6f", c);
    return 0;
}