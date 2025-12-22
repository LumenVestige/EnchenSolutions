#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a, b;
int add() {
    return a + b;
}
int sub() {
    return a - b;
}
int mul() {
    return a * b;
}
void process() {
    printf("%d\n", add());
    printf("%d\n", sub());
    printf("%d\n", mul());
}
int main() {
    scanf("%d%d", &a, &b);
    process();
    return 0;
}
