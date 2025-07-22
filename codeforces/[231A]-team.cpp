//
// Created by sanenchen on 25-7-23.
//
#include "codeforces.h"
#include "stdc++.h"
using namespace std;

int CodeForces::team() {
    int n;
    cin >> n;
    vector<vector<int> > contest;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        contest.push_back(temp);
    }
    int will_write = 0;
    for (auto t : contest) {
        // t 是每一题
        int temp = 0;
        for (auto p : t) {
            // p 是每个人对这题的把握
            temp += p;
            if (p == 2)
                break;
        }
        will_write = (temp >= 2) ? (will_write + 1) : will_write;
    }
    cout << will_write;
    return 0;
}
