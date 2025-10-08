//
// Created by sanenchen on 25-10-5.
//
#include <bits/stdc++.h>
using namespace std;
string removeSubstring(string s, int k) {
    vector<pair<char, int>> st;
    for (auto& i : s) {
        if (!st.empty()) {
            if (st.back().first == i)
                st.back().second++;
            else st.emplace_back(i, 1);
            // 每次判断
            if (st.size() >= 2 && st.back().first == ')' && st.back().second == k && st[st.size() - 2].second >= k) {
                st.erase(st.end() - 1);
                st[st.size() - 1].second -= k;
                if (st[st.size() - 1].second == 0)
                    st.erase(st.end() - 1);
            }
        } else {
            st.emplace_back(i, 1);
        }
    }
    string ans;
    for (auto& [c, i] : st) {
        for (int j = 0; j < i; ++j)
            ans += c;
    }
    return ans;
}
int main() {
    cout << removeSubstring("((()))()()()", 3);
    return 0;
}