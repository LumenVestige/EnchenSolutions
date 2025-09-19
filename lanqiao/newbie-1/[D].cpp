#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 10;
    vector<int> foods(10);
    for (int i = 0; i < 10; ++i)
        cin >> foods[i];
    int ans = 0, lesser = 0, mucher = 0;
    // 严格小于等于100
    for (auto &i : foods) {
        if (ans <= 100) {
            lesser = ans;
            ans += i;
            mucher = ans;
        } else
            break;
    }
    // cout << lesser << " " << mucher << endl;
    if (abs(100 - lesser) == abs(100 - mucher))
        cout << mucher;
    else
        cout << ((abs(100 - lesser) < abs(100 - mucher)) ? lesser : mucher);
    return 0;
}