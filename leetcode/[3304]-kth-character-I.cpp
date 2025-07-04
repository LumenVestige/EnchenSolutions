#include "LeetCodes.h"
//
// Created by sanenchen on 25-7-4.
//



char LeetCodes::kthCharacterI(int k) {
    string word = "a";

    // 计算应该循环的次数
    /**
     *  一个字符，操作一次翻倍为2
     *  2翻倍为4
     *  假设k=5，则需要2^3 > 5才可以
     *  则需要操作3次
     */
    int times = 0;
    for (int i = 1; i <= k; i++) {
        if (pow(2, i) > k) {
            times = i;
            break;
        }
    }
    for (int i = 0; i < times; i++) {
        // 遍历 word 字符串
        string newWord = word;
        for (auto c: word) {
            // cout << c << endl;
            if (c == 'z') // 判断是否是字符 'z'
                newWord += 'a';
            else newWord += ++c;
        }
        word = newWord;
    }
    cout << word << endl;
    return word[k - 1];
}