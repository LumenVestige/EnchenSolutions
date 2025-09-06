#include <bits/stdc++.h>
using namespace std;
// 在此总结一下不定长的滑动窗口
// 不定长 先固定左指针 left = 0 枚举右指针 right 
// 如果不符合条件了 就收缩左指针 直到符合条件为止，但要及时判断
int maximumLengthSubstring(string s) {
    int left = 0, ans = 0;
    unordered_map<char, int> cnt;
    for (int right = 0; right < s.size(); ++right) { // 枚举右端点
        // 入 
        cnt[s[right]]++;
        // 判断是否当前cnt大于了2
        while (cnt[s[right]] > 2) {
            cnt[s[left]]--;
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}
int main() {
    cout << maximumLengthSubstring("bcbbbcba");
    cout << endl;
    return 0;
}