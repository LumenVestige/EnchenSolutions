#include <stdio.h>
#include <stdlib.h>
#include <string>

void sort(int* nums) {
    // 冒泡排序
    for (int i = 0; i < 10; ++i) {
        for (int j = i; j < 10; ++j) {
            if (nums[i] > nums[j]) {
                nums[i] = nums[i] ^ nums[j];
                nums[j] = nums[i] ^ nums[j];
                nums[i] = nums[i] ^ nums[j];
            }
        }
    }
}
int main() {
    int arr[24];
    for (int i = 0; i < 7; i++) {
        scanf("%d", &arr[i]); // 1 2 3 5 6 7 8
    }
    int n;
    scanf("%d", &n); // 4
    int pos = 7;
    for (int i = 0; i < 7; ++i) {
        // arr[i] > n
        if (arr[i] > n) {
            pos = i;
            break;
        }
    }
    printf("%d \n", pos);
    for (int i = 0; i < pos; ++i) {
        printf("%d ", arr[i]);
    }
    printf("%d ", n);
    for (int i = pos; i < 7; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}

