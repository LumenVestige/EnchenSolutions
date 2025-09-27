#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    string s;
    cin >> s;
    // 找到. 分割为两部分
    int posDot = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '.') {
            posDot = i;
            break;
        }
    }
    // [0, p), (p, size - 1]
    string main = s.substr(0, posDot);
    string small = s.substr(posDot + 1, s.size() - 1);
    // 递归查找
    function<int(string, int)> solve = [&](string tmp, int pos)-> int {
        // 终点
        if (pos == tmp.size()) {
            return 0;
        }
        int current = tmp[pos] - '0';
        int next = solve(tmp, pos+1);
        if (next >= 5) {
            current++;
        }
        if (current == 10) return 9;
        return current;
    };
    int lastSmall = small[0] - '0';
    if (lastSmall >= 5) {
        if (main[main.size() - 1] != '9') {
            main[main.size() - 1] = main[main.size() - 1] + 1;
        } else {
            // 从后往前加 如果遇到9 则变为0 前面加一个flag
            bool flag = false; // 进位flag
            for (int i = main.size() - 1; i >= 0; --i) {
                if (flag) {
                    if (main[i] == '9') {
                        main[i] = '0';
                        flag = true;
                    } else {
                        main[i] = main[i] + 1;
                        flag = false;
                        break;
                    }
                } else if (main[i] == '9') {
                    main[i] = '0';
                    flag = true;
                }
            }
            if (flag) {
                main.insert(main.begin(), '1');
            }
        }
    }
    cout << main;
    return 0;
}