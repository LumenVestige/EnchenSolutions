#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> threeSum(vector<int>& nums) {
    unordered_map<int, int> cnt;
    for (int i = 0; i < nums.size(); ++i) {
        cnt[nums[i]]++;
    }
    
}
int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    for (auto& i : threeSum(nums)) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}