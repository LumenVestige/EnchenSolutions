#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N, L;
    cin >> N >> L;
    vector<int> nums(N);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    for (auto& i : nums) {
        if (L >= i) {
            L++;
        } else {
            break;
        }
    }
    cout << L;
    return 0;
}