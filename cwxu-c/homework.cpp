//
// Created by sanenchen on 25-10-10.
//
#include <cstdio>
#include <stdlib.h>
#include <cmath>
int main() {
    double a, b;
    scanf("%lf%lf", &a, &b);
    double min = ((a > b) ? b : a);
    double max = ((a > b) ? a : b);
    printf("%.2lf %.2lf", min, max);
    return 0;
}