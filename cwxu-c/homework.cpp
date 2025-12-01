#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            printf("Not");
            return 0;
        }
    }
    gcd
    printf("YES");
    return 0;
}