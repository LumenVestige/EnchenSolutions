//
// Created by sanenchen on 25-8-30.
//
#include <bits/stdc++.h>
using namespace std;

int getLeastFrequentDigit(int n) {
    unordered_map<int, int> g_map;
    pair<int, int> tmp(INT_MAX, INT_MAX);
    while (n != 0) {
        g_map[n % 10]++;
        n /= 10;
    }
    for (const auto &i: g_map) {
        if (tmp.second > i.second) {
            tmp = i;
        } else if (tmp.second == i.second) {
            if (i.first < tmp.first) tmp.first = i.first;
        }
    }
    return tmp.first;
}


int main() {
    cout << getLeastFrequentDigit(723344511);
    return 0;
}
