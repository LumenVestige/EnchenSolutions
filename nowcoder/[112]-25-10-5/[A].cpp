//
// Created by sanenchen on 25-10-6.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int gold = ceil(n * 0.1);
    int silver = 2 * gold, bronze = 3 * gold;
    if (k <= gold)
        cout << "Gold Medal";
    else if (k <= gold + silver)
        cout << "Silver Medal";
    else if (k <= gold + silver + bronze)
        cout << "Bronze Medal";
    else cout << "Da Tie";
    return 0;
}