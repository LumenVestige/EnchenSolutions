//
// Created by sanenchen on 25-7-23.
//
#include "codeforces.h"
#include "bits/stdc++.h"
using namespace std;
void CodeForces::watermelon() {
    int w;
    bool ans = false;
    cin >> w;
    for (int i = 1; i < w; i++) {
        if (i % 2 == 0 && (w - i) % 2 == 0) {
            ans = true;
        }
    }
    const string res = (ans) ? "YES" : "NO";
    cout << res;
}
