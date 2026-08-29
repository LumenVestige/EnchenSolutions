#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct StudentList {
    int id;
    StudentList* prev, *next;
    StudentList(int idx) : id(idx), prev(nullptr), next(nullptr) {}
};
StudentList* arr[100005];
void solve() {
    int n;
    cin >> n;
    StudentList* root = new StudentList(-1);
    root->next = new StudentList(1);
    root->next->prev = root;
    arr[1] = root->next;
    for (int i = 2; i <= n; ++i) {
        int k, p;
        cin >> k >> p;
        // 找到id为k的同学
        auto* cur = root;
        cur = arr[k];
        if (cur->id == k) {
            auto* newStu = new StudentList(i);
            arr[i] = newStu;
            if (p == 0) {
                // 加载left
                cur = cur->prev;
            }
            newStu->prev = cur;
            newStu->next = cur->next;
            if (cur->next != nullptr) {
                cur->next->prev = newStu;
            }
            cur->next = newStu;
        }
        cur = cur->next;
    }
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        int tmp; cin >> tmp;
        auto* cur = arr[tmp];
        if (cur != nullptr && cur->id == tmp) {
            if (cur->prev != nullptr)
                cur->prev->next = cur->next;
            if (cur->next != nullptr)
                cur->next->prev = cur->prev;
            arr[tmp] = nullptr;
        }
    }
    root = root->next;
    while (root != nullptr) {
        cout << root->id << " ";
        root = root->next;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}