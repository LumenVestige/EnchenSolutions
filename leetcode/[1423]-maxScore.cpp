//
// Created by sanenchen on 2025/9/3.
//
#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &cardPoints, int k) {
    // 并不是一个贪心！
    // // 先构建一个前缀和数组
    // vector<int> prefix(cardPoints.size() + 1, 0);
    // for (int i = 1; i <= cardPoints.size(); ++i) {
    //     prefix[i] = prefix[i - 1] + cardPoints[i - 1];
    // }
    // int left = -1, right = cardPoints.size();
    // while (k--) {
    //     // 比较 left + 1 和 right - 1 哪一个大
    //     if (cardPoints[left + 1] > cardPoints[right - 1])
    //         left++;
    //     else right--;
    // }
    // // 计算结果
    // int ans = 0;
    // // 左半部分
    // if (left >= 0) {
    //     ans += prefix[left + 1];
    // }
    // if (right < cardPoints.size()) {
    //     ans += prefix[cardPoints.size()] - prefix[right];
    // }
    // return ans;


    // 逆向思维 两边最大 那么就是中间最小
    // 求总和
    int total = 0;
    for (auto& it : cardPoints)
        total += it;
    // 覆写 k
    k = cardPoints.size() - k;
    int ans = INT_MAX, prefix = 0;
    for (int i = 0; i < cardPoints.size(); ++i) {
        prefix += cardPoints[i];
        if (i + 1 < k) continue;
        ans = min(ans, prefix);
        prefix -= cardPoints[i - k + 1];
    }
    if (k == cardPoints.size()) return total;
    return total - ans;
}

int main() {
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    cout << maxScore(cardPoints, 3);
    return 0;
}
