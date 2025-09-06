//
// Created by sanenchen on 25-7-26.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int temp = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '#' && i - 1 >= 0 && s[i - 1] != '#')
            s[i - 1] = 'o';
        if (s[i] == '#')
            temp = i;
    }
    if (temp != s.length() - 1) {
        s[s.length() - 1] = 'o';
    }
    if (s == ".") {
        cout << "o";
        return 0;
    }
    cout << s;

    return 0;
}