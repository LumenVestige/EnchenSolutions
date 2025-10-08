//
// Created by sanenchen on 25-10-3.
//
#include <bits/stdc++.h>
using namespace std;
vector<string> summaryRanges(vector<int>& nums) {
    if (nums.empty())
        return {};
    int beg = nums[0], tmp = nums[0];
    int end = nums[0];
    nums.push_back(nums[nums.size() - 1]);
    vector<string> ans;
    for (int i = 1; i < nums.size(); ++i) {
        if (tmp + 1 == nums[i]) {
            tmp = nums[i];
        } else {
            if (beg == end) {
                ans.push_back(to_string(beg));
            } else {
                ans.push_back(to_string(beg) + "->" + to_string(end));
            }
            beg = nums[i];
            tmp = nums[i];
        }
        end = nums[i];
    }
    return ans;
}
int main() {
    vector<int> nums = {0,1,2,4,5,7};
    for (auto& i : summaryRanges(nums)) {
        cout << i << endl;
    }
    return 0;
}