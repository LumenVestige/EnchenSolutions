#include <bits/stdc++.h>
using namespace std;

vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> diff(length, 0);
    for (auto& item : updates) {
        diff[item[0]] += item[2];
        if (item[1] + 1 < diff.size())
            diff[item[1] + 1] -= item[2];
    }
    vector<int> ans(length);
    ans[0] = diff[0];
    for (int i = 1; i < length; ++i) {
        ans[i] = diff[i] + ans[i - 1];
    }
    return ans;
}

int main() {
    vector<vector<int>> updates = {{1, 3, 2}, {2, 4, 3}, {0, 2, -2}};
    for (auto& i : getModifiedArray(5, updates)) {
        cout << i << " ";
    }
    return 0;
}