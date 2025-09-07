//
// Created by sanenchen on 25-8-15.
//
#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, long long target) {
    int left = -1, right = nums.size();
    while (left + 1 != right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target)
            right = mid;
        else left = mid;
    }
    return right;
}

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
    // 先给potions排个序
    sort(potions.begin(), potions.end());
    vector<int> ans;
    // 遍历 找到每一个的答案
    for (auto& it : spells) {
        long long target = (long long)ceil((long double)success / it); // 向上取整
        int lowerBound = search(potions, target);
        ans.push_back(potions.size() - lowerBound);
    }

    return ans;
}

int main() {
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    for (auto& it : successfulPairs(spells, potions, 7)) {
        cout << it << " ";
    }
    return 0;
}
