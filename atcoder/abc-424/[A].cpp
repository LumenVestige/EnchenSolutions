//
// Created by sanenchen on 25-9-20.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b || b == c || c == a)
        cout << "Yes";
    else cout << "No";
    return 0;
}