//
// Created by sanenchen on 25-7-4.
//
#include "Solutions.h"
// T1 两数之和
vector<int> Solutions::twoSum(vector<int> &nums, int target) {
    vector<int> ans = {};
    // 键值对 HashMap
    unordered_map<int, int> map;
    // 丢入hash表 key为值 value为下标
    int counter = 0;
    // 25.7.3 优化，没必要先全部存入哈希，可以尝试边比对边存哈希，节省部分内存开支
    // for (const auto &num: nums) {
    //     map[num] = counter++;
    // }
    counter = 0;
    for (const auto &num: nums) {
        // 从第一个数开始撸
        int target_num = target - num;
        // 在hashmap中查找有没有当前的答案
        auto it = map.find(target_num);
        if (it != map.end()) {
            ans.push_back(it->second);
            ans.push_back(counter);
            return ans;
        }
        map.insert({num, counter});
        counter++;
    }
    return {};
}