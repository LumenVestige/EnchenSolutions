#include <bits/stdc++.h>
using namespace std;

vector<int> getSneakyNumbers(vector<int>& nums) {
    unordered_map<int, int> cnt;
    vector<int> ans;
    for (auto& i : nums) {
        if (cnt.count(i)) {
            ans.push_back(i);
        }
        cnt[i]++;
    }
    return ans;
}

int main() {
    vector<int> nums = {0,1,1,0};
    for (auto& i : getSneakyNumbers(nums)) {
        cout << i << " ";
    }
    return 0;
}