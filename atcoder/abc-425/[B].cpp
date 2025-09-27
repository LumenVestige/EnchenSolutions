#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    // sort(tmp.begin(), tmp.end());
    vector<int> needAdd(11, 1);
    for(int i = 0; i < n; ++i) {
        if (nums[i] > n) {
            cout << "No";
            return 0;
        }
        if (nums[i] != -1) {
            needAdd[nums[i]]--;
        }
    }
    stack<int> st;
    for (int i = 1; i <= n; ++i) {
        if (needAdd[i] < 0) {
            cout << "No";
            return 0;
        }
        if (needAdd[i] != 0)
            st.push(i);
    }
    vector<int> ans(nums);
    for (int i = 0; i < n; ++i) {
        if (nums[i] == -1) {
            ans[i] = st.top();
            st.pop();
        }
    }
    if (!st.empty()) {
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    for (auto& i : ans) {
        cout << i << " ";
    }

    return 0;
}