#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int target) {
    int left = -1, right = nums.size();
    while (left + 1 != right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) 
            right = mid;
        else left = mid;
    }
    return right;
}

vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    // 对items排序 价格从低到高 价值从高到低
    sort(items.begin(), items.end(), [](const auto& a, const auto& b){
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    });
    unordered_map<int, int> hash_map;
    unordered_map<>;
    vector<int> price, ans;
    int currentMax = 0;
    // 构建前缀最大值
    for (int i = 0; i < items.size(); ++i) {
        currentMax = max(currentMax,items[i][1]);
        hash_map[items[i][0]] = currentMax;
        price.push_back(items[i][0]);
    }
    // for (auto& q : items) {
    //     cout << q[0] << " ";
    // }
    // cout << endl;

    // sort(price.begin(), price.end());
    for (auto& q : queries) {
        int location = lowerBound(price, q + 1) - 1;
        if (location >= 0)
            ans.push_back(hash_map[items[location][0]]);
        else ans.push_back(0);
    }
    return ans;
}

int main() {
    vector<vector<int>> items = {
        {10, 1000}
    };
    vector<int> queries = {5};
    for (auto& i : maximumBeauty(items, queries)) {
        cout << i << " ";
    }
    return 0;
}