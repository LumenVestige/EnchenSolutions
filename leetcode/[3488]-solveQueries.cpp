//
// Created by sanenchen on 25-8-16.
//
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int target) {
    int left = -1, right = nums.size();
    while (left + 1 != right) {
        int mid = (left + right) >> 1;
        if (nums[mid] >= target)
            right = mid;
        else left = mid;
    }
    return right;
}

int distance(int nums_size, int tmp, int target) {
    int direct = abs(tmp - target);
    int undirect = abs(nums_size - max(target, tmp) + min(target, tmp));
    return min(direct, undirect);
}

vector<int> solveQueries(vector<int> &nums, vector<int> &queries) {
    unordered_map<int, vector<int>> hashmap;
    for (int i = 0; i < nums.size(); ++i) {
        hashmap[nums[i]].push_back(i);
    }
    vector<int> ans;
    for (auto& query : queries) {
        int target = nums[query];
        auto it = hashmap.find(target);
        // 有且只有自己一个元素
        if (it == hashmap.end()) {
            ans.push_back(-1);
            continue;
        }
        if (it->second.size() == 1) {
            ans.push_back(-1);
            continue;
        }
        // int targetPosition = lowerBound(it->second, query);
        int targetPosition = *lower_bound(it->second.begin(), it->second.end(), query);
        int leftDistance = INT_MAX, rightDistance = INT_MAX;

        if (targetPosition - 1 >= 0)
            leftDistance = distance(nums.size(), it->second[targetPosition - 1], it->second[targetPosition]);
        else leftDistance = distance(nums.size(), it->second[it->second.size() - 1], it->second[targetPosition]);
        if (targetPosition + 1 < it->second.size())
            rightDistance = distance(nums.size(), it->second[targetPosition + 1], it->second[targetPosition]);
        else rightDistance = distance(nums.size(), it->second[0], it->second[targetPosition]);

        ans.push_back(min(leftDistance, rightDistance));

    }
    return ans;
}

int main() {
    vector<int> nums = {5,20,12,14,12,17,13,7,7,5,20,5,5,5,12,19,6};
    vector<int> queries = {0};
    for (auto &it: solveQueries(nums, queries))
        cout << it << " ";
    return 0;
}
