#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    // 来一套hash表
    unordered_map<int, int> indexMap; // 第一个是值 第二个是对应的位置
    for (int i = 0; i < nums1.size(); ++i) 
        indexMap[nums1[i]] = i;
    vector<int> ans(nums1.size(), -1);
    stack<int> st;
    for (int i = 0; i < nums2.size(); ++i) {
        int tmp = nums2[i];
        while (!st.empty() && tmp > nums2[st.top()]) {
            ans[indexMap[nums2[st.top()]]] = tmp;
            st.pop();
        }
        if (indexMap.find(nums2[i]) != indexMap.end())
            st.push(i);
    }
    return ans;
}

int main() {
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    for (auto& i : nextGreaterElement(nums1, nums2))
        cout << i << " ";
    return 0;
}