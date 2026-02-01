#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void pushCheck(char c, stack<char>& st) {
    if (!st.empty() && c == st.top()) {
        if (c == 'o') {
            st.pop();
            pushCheck('O', st);
        } else {
            st.pop();
        }
    } else {
        st.push(c);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        stack<char> st;
        for (int i = 0; i < str.size(); ++i) {
            pushCheck(str[i], st);
        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }

    return 0;
}