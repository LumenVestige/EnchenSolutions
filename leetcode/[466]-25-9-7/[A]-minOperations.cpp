#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums) {
    int tmp = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != tmp) 
            return 1;
    }
    return 0;
}

int main() {
    vector<int> nums = {1,2};
    cout << minOperations(nums) << endl;
    return 0;
}