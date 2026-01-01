#include <stdio.h>
#include <stdlib.h>
int main() {
    int i, *p;
    scanf("%d", &i);
    p = &i;
    *p = 5;
    printf("%d\n", i);
    printf("%d\n", *p);
    printf("%d\n", p);
    printf("%d", &i);
    return 0;
}
