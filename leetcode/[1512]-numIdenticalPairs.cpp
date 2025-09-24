#include <bits/stdc++.h>
using namespace std;
int numIdenticalPairs(vector<int>& nums) {
    int pairs = 0;
    unordered_map<int, int> cnt;
    for (int i = 0 ; i < nums.size(); ++i) {
        pairs += cnt[nums[i]];
        cnt[nums[i]]++;
    }
    return pairs;
}
int main() {
    vector<int> nums = {1,1,1,1};
    cout << numIdenticalPairs(nums);
    return 0;
}