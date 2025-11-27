#include <stdio.h>
  #include <stdlib.h>
  
  int main() {
    int n;
    scanf("%d", &n);
    double ans = 1;
    for (int i = 2; i <= n; ++i) {
      ans -= 1.0 / i;
    }
    printf("%.5lf", ans);
    return 0;
  }