//
// Created by sanenchen on 25-9-1.
//
#include <bits/stdc++.h>

using namespace std;

vector<int> countBits(int n) {
    auto binaryCountOne = [&](int t) -> int {
        int counter = 0;
        while (t != 0) {
            if (t % 2 == 1) counter++;
            t /= 2;
        }
        return counter;
    };
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; ++i) {
        ans[i] = binaryCountOne(i);
    }
    return ans;
}

int main() {
    for (auto& i : countBits(5))
        cout << i << " ";
    return 0;
}