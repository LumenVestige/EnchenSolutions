#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    // 先给复制一遍
    nums.insert(nums.end(), nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        int tmp = nums[i];
        while(!st.empty() && tmp > nums[st.top()]) {
            ans[st.top()] = tmp;
            st.pop();
        }
        if (i < n) st.push(i);
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,1};
    for(auto& i : nextGreaterElements(nums)) 
        cout << i << " ";
    return 0;
}