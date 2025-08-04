//
// Created by sanenchen on 25-8-3.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;
    bool check = n[n.length() - 1] == '0';
    if (check)
        cout << "NO";
    else cout << "YES";
    return 0;
}