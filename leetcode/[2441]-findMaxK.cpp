#include <bits/stdc++.h>
using namespace std;

int findMaxK(vector<int>& nums) {
    int ans = -1;
    unordered_set<int> cnt;
    for (auto& i : nums) {
        if (cnt.count(-i)) ans = max(abs(i), ans);
        cnt.insert(i);
    }
    return ans;
}

int main() {
    vector<int> nums = {-1,10,6,7,-7,1};
    cout << findMaxK(nums);
    return 0;
}