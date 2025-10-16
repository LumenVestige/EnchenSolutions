//
// Created by sanenchen on 25-10-10.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int nums[15];
    for (int i = 0; i < 15; ++i) {
        scanf("%d", &nums[i]);
    }
    int target;
    scanf("%d", &target);
    int left = -1, right = 15;
    while (left + 1 != right) {
        int mid = (left + right) / 2;
        if (nums[mid] >= target) {
            right = mid;
        } else {
            left = mid;
        }
    }
    if (right == 15) {
        printf("NO");
    } else {
        printf("%d", right);
    }
    return 0;
}