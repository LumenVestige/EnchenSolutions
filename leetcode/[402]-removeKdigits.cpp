//
// Created by sanenchen on 25-9-22.
//
#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k) {
    // stack<int> st;
    // vector<int> downPos(num.size(), -1);
    // for (int i = num.size() - 1; i >= 0; --i) {
    //     while (!st.empty() && num[i] <= num[st.top()])
    //         st.pop();
    //     if (!st.empty())
    //         downPos[i] = st.top();
    //     st.push(i);
    // }
    // // 开删！
    // string ans;
    // for (int i = 0; i < downPos.size(); ++i) {
    //     if (downPos[i] == i + 1 && k > 0) {
    //         k--;
    //         continue;
    //     } else {
    //         ans += num[i];
    //     }
    // }
    // while (k > 0) {
    //     ans.erase(ans.end() - 1);
    //     k--;
    // }
    string s = num;
    while (k--) {
        for (int i = 0; i < s.size(); ++i) {
            // 找到下降点
            // 当前的这个数大于后一个数 则删除这个数
            if (i < s.size() - 1 && s[i] > s[i + 1]) {
                s.erase(s.begin() + i);
                break;
            }
            if (i == s.size() - 1) {
                s.erase(s.begin() + i);
            }
        }
    }
    // 去除前导0
    while (1) {
        if (s[0] != '0') break;
        s = s.substr(1, s.size() - 1);
    }
    return s.empty() ? "0" : s;
}
int main() {
    cout << removeKdigits("33526221184202197273", 19);
    return 0;
}