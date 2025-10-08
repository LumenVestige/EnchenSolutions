#include <bits/stdc++.h>

using namespace std;

string makeGood(string s) {
    stack<char> st;
    st.push(' ');
    for (auto& i : s) {
        if (st.top() - 32 != i && st.top() + 32 != i)
            st.push(i);
        else st.pop();
    }
    string ans;
    while (st.top() != ' ') {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    cout << makeGood("leEeetcode");
    return 0;
}