//
// Created by sanenchen on 25-10-10.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if (a < b && b < c)
        printf("%.2lf %.2lf %.2lf", a, b, c);
    else if (b < a && a < c) 
        printf("%.2lf %.2lf %.2lf", b, a, c);
    else if (c < a && a < b) 
        printf("%.2lf %.2lf %.2lf", c, a, b);
    else if (c < b && b < a) 
        printf("%.2lf %.2lf %.2lf", c, b, a);
    else if (b < c && c < a)
        printf("%.2lf %.2lf %.2lf", b, c, a);
    else if (a < c && c < b)
        printf("%.2lf %.2lf %.2lf", a, c, b);
    return 0;
}