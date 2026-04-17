#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string nums;
    string s1, s2;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        nums += tmp + '0';
    }
    stack<int> st;
    queue<int> que;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int tmp;
            cin >> tmp;
            st.push(tmp);
            que.push(tmp);
        } else {
            int top = st.top();
            st.pop();
            s1 += top + '0';
            top = que.front();
            que.pop();
            s2 += top + '0';
        }
    }
    if (s1 == s2 && s1 == nums) {
        cout << "both";
    } else if (s1 == nums && s2 != nums) {
        cout << "stack";
    } else if (s2 == nums && s1 != nums) {
        cout << "queue";
    } else {
        cout << -1;
    }
    return 0;
}
