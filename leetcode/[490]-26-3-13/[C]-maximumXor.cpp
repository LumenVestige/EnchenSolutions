#include <bits/stdc++.h>
using namespace std;
string maximumXor(string s, string t) {
    // 贪心法: 优先把高位赋值为1
    vector<int> nums(2);
    for (auto& i : t) {
        nums[i-'0']++;
    }
    string ans = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            if (nums[1]) {
                ans += '1';
                nums[1]--;
            } else {
                ans += '0';
            }
        } else {
            if (nums[0]) {
                ans += '1';
                nums[0]--;
            } else {
                ans += '0';
            }
        }
    }
    return ans;
}
int main() {
    cout << maximumXor("101", "011");
}