//
// Created by sanenchen on 25-10-26.
//
#include <bits/stdc++.h>
using namespace std;

long long countStableSubarrays(vector<int> &capacity) {
    // 前缀和
    vector<long long> prefix(capacity.size() + 1, 0);
    for (int i = 1; i <= capacity.size(); ++i) {
        prefix[i] = prefix[i - 1] + capacity[i - 1];
    }
    int n = capacity.size();
    long long ans = 0;
    // 使用hashmap优化
    unordered_map<int, unordered_map<long long, int>> cnt;
    for (int i = 0; i < n; ++i) {
        int x = capacity[i];
        long long t = prefix[i] - x;
        if (cnt.count(x) && cnt[x].count(t)) {
            ans += cnt[x][t];
        }

        if (i >= 1) {
            int k = i - 1;
            int c = capacity[k];
            long long p = prefix[k + 1];
            cnt[c][p]++;
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     cnt[capacity[i]].push_back(i);
    // }
    // for (auto& it : cnt) {
    //     auto v = it.second;
    //     for (int i = 0; i < v.size(); ++i) {
    //         for (int j = i + 1; j < v.size(); ++j) {
    //             if (v[j] - v[i] + 1 >= 3) {
    //                 if (it.first == prefix[v[j]] - prefix[v[i] + 1]) {
    //                     ans++;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // }
    return ans;
}
int main() {
    vector<int> capacity = {9, 3, 3, 3, 9};
    cout << countStableSubarrays(capacity);
    return 0;
}