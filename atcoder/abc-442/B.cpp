#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int q;
    cin >> q;
    int vo = 0;
    bool state = false;
    for (int i = 0; i < q; ++i) {
        int tmp;
        cin >> tmp;
        switch (tmp) {
            case 1: 
                vo++;
                break;
            case 2:
                vo -= vo > 0 ? 1 : 0;
                break;
            case 3:
                state = !state;
                break;
        }
        if (state && vo >= 3) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}