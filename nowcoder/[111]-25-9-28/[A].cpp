#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    vector<int> nums(3);
    for (int i = 0; i < 3; ++i) {
        cin >> nums[i];
    }
    for (int i = 1; i < 3; ++i) {
        if (nums[i] - 1 != nums[i - 1]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}