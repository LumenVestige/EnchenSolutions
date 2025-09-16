//
// Created by sanenchen on 25-9-16.
//
#include <bits/stdc++.h>
using namespace std;
// 从右到左
vector<int> dailyTemperaturesRightToLeft(vector<int>& temperatures) {
    stack<int> st;
    vector<int> ans(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; --i) {
        int t = temperatures[i]; // 当前的这个温度
        while (!st.empty() && temperatures[st.top()] <= t) {
            st.pop();
        }
        if (!st.empty()) { // 如果还没有全被弹出的话 说明是存在大于当前数的
            ans[i] = st.top() - i;
        }
        st.push(i);
    }
    return ans;
}
vector<int> dailyTemperatures(vector<int>& temperatures) {
    // 这一个单调栈是一个todolist
    stack<int> st;
    vector<int> ans(temperatures.size());
    for (int i = 0; i < temperatures.size(); ++i) {
        // 先解决掉 当前这个数是否比栈内数要大一些
        int t = temperatures[i];
        while (!st.empty() && t > temperatures[st.top()]) {
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    for (auto& i : dailyTemperatures(temperatures))
        cout << i << " ";
    return 0;
}