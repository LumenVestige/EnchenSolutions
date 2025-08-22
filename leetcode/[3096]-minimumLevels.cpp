//
// Created by sanenchen on 25-8-20.
//
#include <bits/stdc++.h>
using namespace std;

int minimumLevels(vector<int> &possible) {
    vector<int> prefix(possible.size());
    prefix[0] = possible[0] == 0 ? -1 : 1;
    for (int i = 1; i < possible.size(); ++i)
        prefix[i] = (possible[i] == 0 ? -1 : 1) + prefix[i - 1];
    int ans = INT_MAX;
    for (int i = 0; i < possible.size() - 1; ++i) {
        // Alice[0, i]题 Bob [i + 1, n]
        if (prefix[i] > prefix[possible.size() - 1] - prefix[i])
            ans = min(ans, i + 1);
    }
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    vector<int> ans = {0, 0, 0};
    cout << minimumLevels(ans);
    return 0;
}
