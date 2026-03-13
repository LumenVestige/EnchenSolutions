#include <bits/stdc++.h>
using namespace std;

int scoreDifference(vector<int>& nums) {
    bool chaed = false;
    int p1 = 0, p2 = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] & 1) {
            chaed = !chaed;
        }
        if ((i + 1) % 6 == 0) {
            chaed = !chaed;
        }
        if (!chaed) {
            p1 += nums[i];
        } else {
            p2 += nums[i];
        }
    }
    return p1 - p2;
}

int main() {
    vector<int> nums = {1,2,3};
    cout << scoreDifference(nums);
    return 0;
}