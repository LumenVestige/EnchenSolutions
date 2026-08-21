    // // 层序
    // queue<int> que;
    // que.push(1);
    // vector<int> ans;
    // while (!que.empty()) {
    //     int r = que.front();
    //     que.pop();
    //     // 扫描子节点情况
    //     int cnt = 0;
    //     for (auto& z : g[r]) {
    //         if (star[z]) {
    //             cnt++;
    //             ans.push_back(z);
    //         }
    //         que.push(z);
    //     }
    //     if (!star[r]) {
    //         ans.pop_back();
    //     }
    // }
    // cout << ans.size() << " ";
    // for (auto& i : ans) {
    //     cout << i << " ";
    // }
    // cout << endl;