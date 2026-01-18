#include <stdio.h>
#include <stdlib.h>

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
    int nums[10] = {2,4,2,5,6,1,33,44,22,989};
    sort(nums);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", nums[i]);
    }
    return 0;
}
