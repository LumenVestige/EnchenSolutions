//
// Created by sanenchen on 25-7-4.
//
#include "LeetCodes.h"
// 未解决 超时 不知道咋办

string operation(string word, queue<int> &operate) {
    if (operate.empty()) {
        // cout << word << endl;
        return word;
    }
    if (operate.front() == 0) {
        // copy的
        // cout << word << endl;
        operate.pop();
        stringstream newWord;
        newWord << word << word;
        return operation(newWord.str(), operate);
    } else {
        // 遍历word
        stringstream newWord;
        newWord << word;
        // cout << word << endl;
        for (auto c: word) {
            if (c == 'z')
                newWord.put('a');
            newWord.put(++c);
        }
        operate.pop();
        return operation(newWord.str(), operate);
    }
}

char LeetCodes::kthCharacterII(long long k, vector<int> &operations) {
    string word = "a";
    // 遍历operations
    // for (auto& operation : operations) {
    //     if (operation == 0) {
    //         word.insert(word.end(),word.begin(),word.end());
    //     } else {
    //         // 遍历word
    //         vector<char> newWord = word;
    //         for (auto c : word) {
    //             if (c == 'z')
    //                 newWord.push_back('a');
    //             newWord.push_back(++c);
    //         }
    //         word = newWord;
    //     }
    // }
    // 用递归扯一扯？？ 可能可以减掉数据复制的问题

    // 将operations扔进一个栈中
    queue<int> operation_queue;
    for (auto &op: operations) {
        operation_queue.push(op);
    }


    return operation(word, operation_queue)[k - 1];
}
