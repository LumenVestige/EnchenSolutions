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
        if (c == '(' || c == '[') {
            st.push(c);
        } else if (c == ']' || c == ')') {
            if (st.empty()) {
                cout << "false";
                return 0;
            }
            if (c == ']') {
                if (st.top() != '[') {
                    cout << "false";
                    return 0;
                }
                st.pop();
            } else if (c == ')') {
                if (st.top() != '(') {
                    cout << "false";
                    return 0;
                }
                st.pop(); 
            }
        }
    }
    cout << "true";
    return 0;
}