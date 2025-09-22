//
// Created by sanenchen on 25-9-22.
//
#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &heights) {
    stack<int> st;
    vector<int> left(heights.size(), -1), right(heights.size() , heights.size());
    for (int i = 0; i < heights.size(); ++i) { // 找到左侧第一个小于当前数的数
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        if (!st.empty())
            left[i] = st.top();
        st.push(i);
    }
    st = stack<int>();
    for (int i = heights.size() - 1; i >= 0; --i) {
        while (!st.empty() && heights[st.top()] > heights[i])
            st.pop();
        if (!st.empty())
            right[i] = st.top();
        st.push(i);
    }
    int maxArea = 0;
    for (int i = 0; i < left.size(); ++i) {
        int width = right[i] - left[i] - 1;
        int height = heights[i];
        int area = width * height;
        maxArea = max(area, maxArea);
    }
    return maxArea;
}
int main() {
    vector<int> heights{1, 4};
    cout << largestRectangleArea(heights);
    return 0;
}