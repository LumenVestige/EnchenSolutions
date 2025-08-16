//
// Created by sanenchen on 25-8-16.
//
#include <bits/stdc++.h>
using namespace std;
int maximum69Number (int num) {
    string num_str = to_string(num);
    for (auto& it : num_str) {
        if (it == '6') {
            it = '9';
            break;
        }
    }
    return stoi(num_str);
}
int main() {
    cout << maximum69Number(9666);
    return 0;
}