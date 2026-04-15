#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    stack<int> nums;
    stack<char> ops;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        nums.push(tmp);
    }
    for (int i = 0; i < n - 1; ++i) {
        char op;
        cin >> op;
        ops.push(op);   
    }
    while (!ops.empty()) {
        int n1 = nums.top();
        nums.pop();
        int n2 = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        switch (op) {
        case '+':
            nums.push(n1+n2);
            break;
        case '-':
            nums.push(n2-n1);
            break;
        case '*':
            nums.push(n1*n2);
            break;
        case '/':
            if (n1 == 0) {
                cout << "ERROR: " << n2 << "/0";
                return 0;
            }
            nums.push(n2/n1);
            break;
        }
    }
    cout << nums.top() << endl;
    return 0;
}