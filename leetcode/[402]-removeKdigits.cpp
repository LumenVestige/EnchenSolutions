//
// Created by sanenchen on 25-9-22.
//
#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k) {
    stack<char> st;
    for (char i : num) {
        // 如果当前的数 大于了栈 则退栈
        while (!st.empty() && i < st.top() && k > 0) {
            st.pop();
            k--;
        }
        st.push(i);
    }
    // 栈转字符串
    string ans;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    // 删除最后一位 如果k大于0
    while (k > 0) {
        ans.erase(ans.end() - 1);
        k--;
    }
    while (!ans.empty() && ans[0] == '0')
        ans.erase(ans.begin()); // 删除前导0
    if (ans.empty()) return "0";
    return ans;
}
int main() {
    cout << removeKdigits("1432219", 3);
    return 0;
}