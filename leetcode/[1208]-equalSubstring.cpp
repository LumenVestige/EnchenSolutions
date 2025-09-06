#include <bits/stdc++.h>
using namespace std;

int equalSubstring(string s, string t, int maxCost) {
    // 如果 开销没有超 那么就记录比较 右指针继续右移动
    // 如果 开销超过了 那么左边就退出 直到开销退出去
    int currentCost = 0, currentChange = 0, ans = 0, left = 0;
    for (int right = 0; right < s.size(); ++right) {
        // 记录当前开销
        currentCost += abs(s[right] - t[right]);
        currentChange++;
        // 判断是否超出开销
        while (currentCost > maxCost) {
            // 左边开销减去 左边指针++ 判断是否需要改变 对应的currentChange--
            currentCost -= abs(s[left] - t[left]);
            currentChange--;
            left++;
        }
        ans = max(ans, currentChange);
    }
    return ans;
}

int main() {
    cout << equalSubstring("abcd", "bcdf", 3);
    return 0;
}