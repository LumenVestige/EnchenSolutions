//
// Created by sanenchen on 2025/9/3.
//
#include <bits/stdc++.h>
using namespace std;

int minimumRecolors(string blocks, int k) {
    // 找到最少的B即可
    int sum_b = 0, min_ans = INT_MAX;
    for (int i = 0; i < blocks.size(); ++i) {
        sum_b += (blocks[i] == 'W') ? 1 : 0;
        if (i + 1 < k) continue;
        min_ans = min(min_ans, sum_b);
        sum_b -= (blocks[i - k + 1] == 'W') ? 1 : 0;
    }
    return min_ans;
}

int main() {
    cout << minimumRecolors("WBBWWBBWBW", 7);
    return 0;
}