#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    string str;
    cin >> n;
    cin >> str;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            string tmp;
            cin >> tmp;
            int pos = str.find(tmp);
            if (pos != string::npos) {
                cout << pos << endl;
            } else {
                cout << -1 << endl;
            }
        } else if (op == 2) {
            string s1, s2;
            cin >> s1 >> s2;
            int pos = str.find(s1);
            if (pos != string::npos) {
                str = str.replace(pos, s1.size(), s2);
            }
            cout << str << endl;
        } else {
            string s1, s2, s3;
            cin >> s1 >> s2 >> s3;
            string finder = s1+s2;
            int size = s3.size();
            // 查找所有的位置
            vector<int> poses;
            int bg = 0;
            while (true) {
                int pos = str.find(finder, bg);
                if (pos == string::npos) {
                    break;
                }
                poses.push_back(pos);
                bg = pos + 1;
            }
            for (int i = 0; i < poses.size(); ++i) {
                str = str.insert(size*i+poses[i]+1, s3);
            }
            cout << str << endl;
        }
    }
    return 0;
}