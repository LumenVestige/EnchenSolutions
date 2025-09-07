//
// Created by sanenchen on 25-9-1.
//
#include <bits/stdc++.h>
using namespace std;
// 优先队列
struct Ratio {
    int pass, total;

    bool operator <(const Ratio &oth) const {
        return static_cast<long long>(oth.total + 1) * oth.total * (total - pass) <
               static_cast<long long>(total + 1) * total * (oth.total - oth.pass);
    }
};


double maxAverageRatio(vector<vector<int> > &classes, int extraStudents) {
    priority_queue<Ratio> pq;
    for (auto &c: classes) {
        pq.push({c[0], c[1]});
    }
    for (int i = 0; i < extraStudents; ++i) {
        auto [pass, total] = pq.top();
        pq.pop();
        pq.push({pass + 1, total + 1});
    }
    // 计算所有班级的及格率
    double tmp = 0;
    for (int i = 0; i < classes.size(); ++i) {
        auto [pass, total] = pq.top();
        pq.pop();
        tmp += 1.0 * pass / total;
    }
    return 1.0 * tmp / classes.size();
}

int main() {
    vector<vector<int> > classes = {{1, 2}, {3, 5}, {2, 2}};
    cout << maxAverageRatio(classes, 2);
    return 0;
}
