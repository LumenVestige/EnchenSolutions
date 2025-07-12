//
// Created by sanenchen on 25-7-11.
//
#include "LeetCodes.h"

int LeetCodes::countDays(int days, vector<vector<int> > &meetings) {
    // sort(meetings.begin(), meetings.end());
    // for (auto it : meetings) {
    //     cout << "[";
    //     for (auto i : it) {
    //         cout << i << ", ";
    //     }
    //     cout << "]";
    // }
    //


    
    // 构建一个数组 大小=days,遍历meetings 如果遇到开会，就把那一天标记为1，最后梳理没有被标记为1的个数
    vector<int> need_meeting(days + 1,0);
    for (auto item: meetings) {
        int start_day = item[0];
        int last_day = item[1];
        for (int i = start_day; i <= last_day; i++) {
            need_meeting[i] = 1;
        }
    }
    // 计数没有被标记为1的
    int counter = 0;
    for (auto it: need_meeting) {
        if (it == 0) {
            counter++;
        }
    }
    return  1;
}
