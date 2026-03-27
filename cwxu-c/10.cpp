#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node {
    string name;
    int nums;
    bool operator<(const node& others) const {
        return nums < others.nums;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<node> pq;
    vector<node> noneFull; // 第一个是所属学校，第二个是剩余席位
    int n, c;
    cin >> n >> c;
    while (n--) {
        string name;
        int nums;
        cin >> name >> nums;
        pq.push({name, nums});
        cout << name << " " << ceil(1.0 * nums/c) << endl;
    }
    int tot = 0;
    while (!pq.empty()) {
        // 处理当前学校
        auto [name, nums] = pq.top();
        pq.pop();
        int rooms = nums / c;
        int d = nums % c; // 落单的小朋友要到后面排队队哦
        if (d != 0 && rooms != 0)
            pq.push({name, d});
        if (rooms == 0) {
            // 尝试给这个落单的小朋友找到合适的家
            bool find = false;
            for (auto& [n_name, n_nums] : noneFull) {
                if (n_nums - d >= 0) {
                    // 找到啦
                    n_nums -= d;
                    find = true;
                    break;
                }
            }
            if (!find) {
                // 很抱歉，这些小朋友容不下了 新开一个吧
                noneFull.push_back({name, c - d});
                rooms++;
            }
        }
        tot += rooms;
    }
    cout << tot;

    return 0;
}