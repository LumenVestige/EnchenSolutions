#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(2 * n, -1);
    stack<int> st;
    // 先给复制一遍
    nums.insert(nums.end(), nums.begin(), nums.end());
    // 从左往右扫描
    // for (int i = 0; i < nums.size(); ++i) {
    //     int tmp = nums[i];
    //     while(!st.empty() && tmp > nums[st.top()]) {
    //         ans[st.top()] = tmp;
    //         st.pop();
    //     }
    //     if (i < n) st.push(i);
    // }
    // 从右往左扫描
    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] <= nums[i])
            st.pop();
        if (!st.empty())
            ans[i] = nums[st.top()];
        st.push(i);
    }
    return {ans.begin(), ans.begin() + n};
}

int main() {
    vector<int> nums = {1,2,3,4,3};
    for(auto& i : nextGreaterElements(nums)) 
        cout << i << " ";
    return 0;
}