//
// Created by sanenchen on 25-7-13.
//
#include "LeetCodes.h"
int LeetCodes::matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    // 先给他们排个序
    ranges::sort(players);
    ranges::sort(trainers);
    // 两根指针，一根是player 一根是trainer
    int player = 0, trainer = 0;
    // 目前已经排序好了 目的是：运动员对应着能力恰好不浪费训练力的教练
    // 用player 来对应教练
    int pairs = 0;
    // 继续的条件：学生指针小于学生总数，教师指针小于教师总数才可以执行判断，否则代表已经空掉了
    while (player < players.size() && trainer < trainers.size()) {
        // 如果当前的学生能力低于当前的教师：
        if (players[player] <= trainers[trainer]) {
            // 这个教练用过了 教练指针移动 ++
            // 学生找到配对了 学生指针移动 ++
            trainer++;
            player++;
            pairs++;
        }
        // 如果当前学生能力高于老师：
        else {
            // 教练指针移动，找到更好的教练
            trainer++;
        }
    }
    return pairs;
}