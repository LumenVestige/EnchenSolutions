//
// Created by sanenchen on 25-8-13.
//
#include <bits/stdc++.h>

using namespace std;

vector<int> avoidFlood(vector<int> &rains) {
    vector<int> ans(rains.size(), 1);
    set<int> st;
    unordered_map<int, int> rained;
    for (int i = 0; i < rains.size(); ++i) {
        // 如果不下雨 加入堆中
        if (rains[i] == 0)
            st.insert(i);
        else {
            ans[i] = -1;
            // 下雨 判断是否是第一次下雨
            if (rained.find(rains[i]) != rained.end()) {
                // 再次下雨 找到一个晴天 清空掉
                int last_rain = rained[rains[i]];
                auto it = st.lower_bound(last_rain);
                if (it == st.end())
                    return {}; // 没找到晴天了

                ans[*it] = rains[i];
                st.erase(it);
            }
            rained[rains[i]] = i;
            // 即使你用晴天抽干了之前的水，当前这次下雨又会让该湖泊再次积水，因此需要更新记录为当前位置，而不是删除它。
            // 重点！！！！！！ 只是找了一天晴天抽干了水 但是马上又下回来了 所以更新索引
        }
    }
    return ans;
}

int main() {
    vector<int> rains = {1, 2, 0, 0, 2, 1};
    for (auto &i: avoidFlood(rains)) {
        cout << i << " ";
    }
    return 0;
}
