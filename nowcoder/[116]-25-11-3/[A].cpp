#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a >= c && b <= d) {
        cout << "A";
        return 0;
    }
    cout << "B";
    return 0;
}