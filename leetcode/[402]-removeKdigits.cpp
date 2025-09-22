//
// Created by sanenchen on 25-9-22.
//
#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k) {
    stack<int> st;
    vector<int> downPos(num.size(), -1);
    for (int i = num.size() - 1; i >= 0; --i) {
        while (!st.empty() && num[i] <= num[st.top()])
            st.pop();
        if (!st.empty())
            downPos[i] = st.top();
        st.push(i);
    }
    // 开删！
    string ans;
    for (int i = 0; i < downPos.size(); ++i) {
        if (downPos[i] != i + 1 && k >) {
            ans += num[i];
        }
    }
    cout << ans << endl;
    return "";
}
int main() {
    cout << removeKdigits("1432219", 3);
    return 0;
}