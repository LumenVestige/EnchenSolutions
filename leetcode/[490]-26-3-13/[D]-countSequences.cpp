#include <bits/stdc++.h>
using namespace std;
#define ll long long
int countSequences(vector<int>& nums, long long k) {
    map<tuple<int, ll, ll>, int> mem;
    auto dfs = [&](auto&& dfs, int i, ll p, ll q)->int {
        if (i < 0) {
            return p % q == 0 && (p / q) == k;
        }
        auto it = mem.find({i, p, q});
        if (it != mem.end()) {
            return it->second;
        }
        int res = 0;
        res += dfs(dfs, i-1, p*nums[i], q); // *
        res += dfs(dfs, i-1, p, q*nums[i]); // /
        res += dfs(dfs, i-1, p, q); // none
        mem[{i, p, q}] = res;
        return res;
    };
    return dfs(dfs, nums.size()-1, 1, 1);
}
int main() {
    vector<int> nums = {2,3,2};
    cout << countSequences(nums, 6);
}