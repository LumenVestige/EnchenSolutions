#include <bits/stdc++.h>
using namespace std;

int main() {
    // 尝试用前缀和？
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); ++i) 
        cin >> nums[i];
    int ans = 0;
    for (auto& i : nums)
        ans += i == 1 ? 0 : 1;
    return 0;
}