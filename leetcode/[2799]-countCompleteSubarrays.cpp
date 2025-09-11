//
// Created by sanenchen on 25-9-10.
//
#include <bits/stdc++.h>
using namespace std;

int countCompleteSubarrays(vector<int>& nums) {
    // 先获取不同元素的数量
    unordered_map<int, int> hash_map;
    for (auto& i : nums) {
        hash_map[i]++;
    }
    const int diff = hash_map.size();
    int left = 0, ans = 0;
    hash_map.clear();
    for (int right = 0; right < nums.size(); ++right) {
        // 入
        hash_map[nums[right]]++;
        while (hash_map.size() == diff) {
            // 直到不符合
            hash_map[nums[left]]--;
            if (hash_map[nums[left]] == 0) hash_map.erase(hash_map.find(nums[left]));
            left ++;
        }
        ans += left;
    }
    return ans;
}

int main() {
    vector<int> nums = {1,3,1,2,2};
    cout << countCompleteSubarrays(nums);
    return 0;
}