#include <bits/stdc++.h>
using namespace std;

auto f(vector<int>& v) {
    return &v;
}

int main() {
    vector<int> a;
    cout << &a << endl;
    auto& b = *f(a);
    cout << &(*f(a)) << endl << &b;
    return 0;
}

