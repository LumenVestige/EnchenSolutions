#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    stack<char> st;
    for (auto& c : str) {
        if (c == 'a') {
            st.push(c);
        } else {
            if (st.empty()) {
                cout << "Bad";
                return 0;
            }
            st.pop();
        }
    }
    if (!st.empty()) {
        cout << "Bad";
        return 0;
    }
    cout << "Good";
    return 0;
}