//
// Created by sanenchen on 2025/9/3.
//
#include <bits/stdc++.h>
using namespace std;

int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
    vector<int> benefits(grumpy.size());
    int origin = 0; // 原本就满意的人
    for (int i = 0; i < grumpy.size(); ++i) {
        benefits[i] = grumpy[i] * customers[i];
        if (grumpy[i] == 0) origin += customers[i];
    }
    // 可以额外拯救的人
    int extra = 0, prefix = 0;
    for (int i = 0; i < benefits.size(); ++i) {
        prefix += benefits[i];
        if (i + 1 < minutes) continue;
        extra = max(extra, prefix);
        prefix -= benefits[i - minutes + 1];
    }
    return origin + extra;
}

int main() {
    vector<int> customers = {1,0,1,2,1,1,7,5}, grumpy = {0,1,0,1,0,1,0,1};
    cout << maxSatisfied(customers, grumpy, 3);
    return 0;
}
