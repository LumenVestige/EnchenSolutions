//
// Created by sanenchen on 25-9-16.
//
#include <bits/stdc++.h>
using namespace std;
// 从左往右扫描
vector<int> finalPricesLeftToRight(vector<int>& prices) {
    stack<int> st;
    vector<int> ans(prices);
    for (int i = 0; i < prices.size(); ++i) {
        int tmp = prices[i];
        while (!st.empty() && tmp <= prices[st.top()]) {
            ans[st.top()] -= prices[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

// 从右往左扫描
vector<int> finalPrices(vector<int>& prices) {
    stack<int> st; // st则记录比较小的值
    vector<int> ans(prices);
    for (int i = prices.size() - 1; i >= 0; --i) {
        int tmp = prices[i];
        while (!st.empty() && tmp < prices[st.top()]) {
            st.pop();
        }
        if (!st.empty())
            ans[i] -= prices[st.top()];
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> ans = {8,4,6,2,3};
    for (auto& i : finalPrices(ans)) 
        cout << i << " ";
    return 0;
}