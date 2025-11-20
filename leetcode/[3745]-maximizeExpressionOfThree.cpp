#include <bits/stdc++.h>
using namespace std;

int maximizeExpressionOfThree(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size() - 1;
    return nums[n] + nums[n - 1] - nums[0];
}

int main() {
    vector<int> nums = {1,4,2,5};
    cout << maximizeExpressionOfThree(nums);
    return 0;
}