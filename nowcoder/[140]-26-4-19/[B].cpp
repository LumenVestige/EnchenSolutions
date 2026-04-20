#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0;
    string str;
    cin >> n >> str;
    string st;
    for (auto& i : str) {
        if (i == 'o') { // mo 判断
            if (st.size() >= 1 && st[st.size()-1] == 'm') {
                st.pop_back();
                continue;
            }
        } else if (i == 'u') { // niu 判断
            if (st.size() >= 2 && st[st.size()-1] == 'i' && st[st.size()-2] == 'n') {
                st.pop_back();
                st.pop_back();
                continue;
            }
        }
        st.push_back(i);
    }
    if (st.empty()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}