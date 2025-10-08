//
// Created by sanenchen on 25-10-5.
//
#include <bits/stdc++.h>
using namespace std;
string resultingString(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        if (st.empty())
            st.push(s[i]);
        else {
            auto c = st.top();
            if (c + 1 == s[i] || c - 1 == s[i] || (c == 'z' && s[i] == 'a') || (c == 'a' && s[i] == 'z'))
                st.pop();
            else st.push(s[i]);
        }
    }
    string ans;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    cout << resultingString("abc");
    return 0;
}