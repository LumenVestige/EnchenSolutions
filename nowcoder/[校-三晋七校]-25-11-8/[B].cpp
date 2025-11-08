#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    int pos = 0;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        // 步行
        int normal = (nums[i] - pos) * A;
        ans += min(B, normal);
        pos = nums[i];
    }
    cout << ans;
    return 0;
}