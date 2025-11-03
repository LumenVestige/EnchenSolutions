#include <bits/stdc++.h>
using namespace std;
vector<int> findMissingElements(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ma = nums[nums.size() - 1];
    int mi = nums[0];
    int point = 0;
    vector<int> ans;
    for (int i = mi; i <= ma && point < nums.size(); ++i) {
        if (nums[point] != i) {
            ans.push_back(i);
        } else point++;
    }
    return ans;
}
int main() {
    vector<int> nums = {1,4,2,5};
    for (auto& i : findMissingElements(nums)) {
        cout << i << " ";
    }
    return 0;
}