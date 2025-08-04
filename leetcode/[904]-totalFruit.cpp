//
// Created by sanenchen on 25-8-4.
//
#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    // 左指针 右指针 构建一个滑动窗口
    // 如果目前的情况符合条件（有且仅有两种不同的树）向右扩展 自动维护的
    // 如果目前的情况已经不符合条件了 则左指针收缩 直到符合条件
    int left = 0;
    int ans = 0;
    unordered_map<int, int> g_map;

    function<bool()> check = [&]() -> bool {
        return g_map.size() <= 2;
    };

    for (int right = 0; right < fruits.size(); ++right) {
        g_map[fruits[right]]++;
        // 避免构建tmp数组
        while (!check()) {
            g_map[fruits[left]]--;
            if (g_map[fruits[left]] == 0) {
                g_map.erase(fruits[left]);
            }
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;

}
int main() {
    vector<int> trees = {3,3,3,1,2,1,1,2,3,3,4};
    auto ans = totalFruit(trees);
    cout << ans;
    return 0;
}