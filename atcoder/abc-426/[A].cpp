//
// Created by sanenchen on 25-10-4.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> ver;
    ver["Ocelot"] = 0;
    ver["Serval"] = 1;
    ver["Lynx"] = 2;
    string a, b;
    cin >> a >> b;
    if (ver[a] >= ver[b]) cout << "Yes";
    else cout << "No";
    return 0;
}