//
// Created by sanenchen on 2025/9/3.
//
#include <bits/stdc++.h>
using namespace std;

long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
    // 计算原始数组
    vector<int> originPrefix(prices.size() + 1, 0);
    for (int i = 1; i <= prices.size(); ++i) {
        originPrefix[i] = originPrefix[i - 1] + prices[i - 1] * strategy[i - 1];
    }
    // 计算改为卖出的prefix
    vector<int> payoutPrefix(prices.size() + 1, 0);
    for (int i = 1; i <= prices.size(); ++i) {
        payoutPrefix[i] = payoutPrefix[i - 1] + prices[i - 1];
    }
    // 遍历每一个
    int ans = originPrefix[prices.size()];
    for (int i = k; i <= prices.size(); ++i) {
        // 向前退k个
        int tmp = originPrefix[i - k] + originPrefix[prices.size()] - originPrefix[i] + payoutPrefix[i] - payoutPrefix[i - k / 2];
        ans = max(ans, tmp);
    }
    return ans;
}

int main() {
    vector<int> prices = {4,7,13}, strategy = {-1,-1,0};
    cout << maxProfit(prices, strategy, 2);
    return 0;
}
