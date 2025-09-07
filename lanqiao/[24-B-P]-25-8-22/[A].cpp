//
// Created by sanenchen on 25-8-22.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int total = 50, special = 7;
    int allTimes = 0, specialTime = 0;
    for (int i = 0; i < total - special; ++i) {
        for (int j = i + 1; j < total; ++j)
            allTimes++;
    }
    cout << allTimes;
    return 0;
}