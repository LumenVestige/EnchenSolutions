//
// Created by sanenchen on 25-9-21.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n / 2 == 0) {
        cout << "NO";
        return 0;
    }
    if (n == 7) cout << "YES";
    else if ((n % 3) % 2 == 0) cout << "YES";
    else if (n % 2 == 0) cout << "YES";
    else if (n % 3 == 0) cout << "YES";
    else if ((n % 2) % 3 == 0) cout << "YES";
    else cout << "NO";
    return 0;
}