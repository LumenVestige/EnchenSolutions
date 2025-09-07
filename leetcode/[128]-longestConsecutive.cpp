//
// Created by sanenchen on 25-8-14.
//
#include <bits/stdc++.h>

using namespace std;

class UnionFind {
public:
    unordered_map<int, int> parents, rank;
    explicit UnionFind(vector<int>& nums) {
        for (int num : nums)
            parents[num] = num;
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    void union_n(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        // 合并到数小那一个 默认前面一个数小
        parents[root_y] = root_x;
        // // 按秩合并
        // if (rank[root_x] > rank[root_y])
        //     parents[root_y] = root_x;
        // else if (rank[root_x] < rank[root_y])
        //     parents[root_x] = root_y;
        // else {
        //     parents[root_y] = root_x;
        //     rank[root_x] += 1;
        // }
    }

    bool checkExist(int x) {
        return parents.find(x) != parents.end();
    }
};

int longestConsecutive(vector<int> &nums) {
    // 构建并查集
    UnionFind union_find(nums);
    // 遍历 询问
    for (auto& it : nums) {
        if (union_find.checkExist(it - 1)) { // 存在 合并二者
            union_find.union_n(it - 1, it);
        }
    }
    for (auto& it : nums) {
        union_find.find(it);
    }
    int ans = 0;
    for (auto it : union_find.parents) {
        cout << it.first << " " << it.second << endl;
        ans = max(ans, it.first - it.second + 1);
    }

    return ans;
}

int main() {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << longestConsecutive(nums);
    return 0;
}
