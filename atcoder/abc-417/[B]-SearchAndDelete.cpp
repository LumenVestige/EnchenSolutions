//
// Created by sanenchen on 25-8-2.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> v1(n1);
    unordered_map<int, int> g_map;
    for (int i = 0; i < n1; ++i) {
        cin >> v1[i];
    }
    for (int i = 0; i < n2; ++i) {
        int t;
        cin >> t;
        if (g_map.find(t) == g_map.end()) {
            g_map[t] = 1;
        } else {
            g_map[t]++;
        }
    }
    for (auto& i : v1) {
        if (g_map[i] != 0) {
            g_map[i]--;
        } else {
            cout << i << " ";
        }
    }

    return 0;
}