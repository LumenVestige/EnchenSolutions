#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int> &arr) {
    stack<int> st;
    for (auto& num : arr) {
        if (st.empty() || num >= st.top()) {
            st.emplace(num);
        } else {
            int mx = st.top(); // 取一个最大的
            st.pop();
            while (!st.empty() && st.top() > num)
                st.pop();
            st.emplace(mx);
        }
    }
    return st.size();
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};
    cout << maxChunksToSorted(arr);
    return 0;
}
