//
// Created by sanenchen on 25-7-25.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    string position;
    cin >> position;
    char temp;
    int temp_ans = 0;
    for (int i = 0; i < position.length(); i ++) {
        if (i == 0) {
            // 最开始
            temp = position[i];
            temp_ans++;
        }
        if (position[i] == temp) {
            temp_ans++;
        } else {
            temp_ans = 1;
            temp = position[i];
        }
        if (temp_ans >= 7) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}