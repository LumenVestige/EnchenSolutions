#include <bits/stdc++.h>
using namespace std;

int randomInRange(int lo, int hi) {
    // 处理 lo > hi 的情况
    if (lo > hi) {
        int temp = lo;
        lo = hi;
        hi = temp;
    }
    // 初始化随机种子（仅需在程序中执行一次）
    static bool isSeeded = false;
    if (!isSeeded) {
        srand(time(0));
        isSeeded = true;
    }
    // 计算范围长度，rand() % 范围长度 得到 [0, 长度-1]，再加 lo
    int range = hi - lo + 1;
    return rand() % range + lo;
}
void qsort(vector<int>& nums, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int n = randomInRange(lo, hi);
    swap(nums[lo], nums[n]); 
    int p = nums[lo];
    int left = lo, right = hi;
    while (left != right) {
        while (nums[right] >= p && left < right) {
            right--;
        }
        while (nums[left] <= p && left < right) {
            left++;
        }
        if (left < right) {
            int t = nums[left];
            nums[left] = nums[right];
            nums[right] = t;
        }
    }
    int t = nums[lo];
    nums[lo] = nums[right];
    nums[right] = t;
    qsort(nums, lo, right - 1);
    qsort(nums, right + 1, hi);
}

vector<int> sortArray(vector<int>& nums) {
    qsort(nums, 0, nums.size() - 1);
    return nums;
}
