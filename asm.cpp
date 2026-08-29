#include <stdio.h>
extern "C" long fast_add(long a, long b);
__asm__(
    ".global _fast_add\n\t"
    "_fast_add:\n\t"
    "    "
    "    ret"
);
int main() {
    printf("%ld", fast_add(1, 2));
}