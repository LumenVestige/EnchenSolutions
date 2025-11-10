//
// Created by sanenchen on 25-7-23.
//
#include "codeforces.h"
#include "bits/stdc++.h"

using namespace std;

int CodeForces::nextRound() {
    int n, k;
    cin >> n >> k;
    vector<int> scores;
    scores.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
    }
    int advance = 0;
    sort(scores.begin(), scores.end());
    reverse(scores.begin(), scores.end());
    int target = scores[k - 1];
    for (auto it : scores) {
        if (it >= target && it > 0)
            advance++;
    }
    cout << advance;
    return 0;
}
