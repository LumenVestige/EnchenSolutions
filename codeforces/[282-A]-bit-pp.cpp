//
// Created by sanenchen on 25-7-23.
//
#include "codeforces.h"
#include "stdc++.h"

using namespace std;

int CodeForces::bitPP() {
    int n;
    cin >> n;
    vector<string> operations;
    operations.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> operations[i];
    }
    int x = 0;
    for (auto it: operations) {
        if (it.find('+') != -1)
            x++;
        else
            x--;
    }
    cout << x;
    return 0;
}
