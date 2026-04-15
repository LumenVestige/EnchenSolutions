#include <bits/stdc++.h>
using namespace std;
#define int long long

int count(int y) {
    unordered_set<int> us;
    int size = 0;
    while (y != 0) {
        us.insert(y%10);
        y /= 10;
        size++;
    }
    if (size < 4) {
        us.insert(0);
    }
    return us.size();
}

void printYear(int y) {
    int size = 0;
    int z = y;
    while (y != 0) {
        size++;
        y /= 10;
    }
    size = 4-size;
    while(size--) {
        cout << 0;
    }
    cout << z;
}

signed main() {
    int y, n;
    cin >> y >> n;
    int age = 0;
    for (int i = y; i <= 10000; ++i) {
        if (count(i) == n) {
            cout << age << " ";
            printYear(i);
            return 0;
        }
        age++;
    }
    return 0;
}