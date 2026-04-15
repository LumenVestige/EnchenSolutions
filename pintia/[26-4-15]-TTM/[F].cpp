#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    vector<int> nums(9);
    for (int i = 0; i < 9; ++i) {
        cin >> nums[i];
    }
    for (int i = 0; i < 8; ++i) {
        if (i % 2 == 0) {
            nums[i+1] += nums[i] / 2;
            nums[i] = nums[i] % 2;
        } else {
            nums[i+1] += nums[i] / 3;
            nums[i] = nums[i] % 3;
        }
        
    }
    for (int i = 0; i < 8; ++i) {
        cout << nums[i] << " ";
    }
    cout << nums[8];
    return 0;
}