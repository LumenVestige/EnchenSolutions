//
// Created by sanenchen on 25-7-4.
//
#include "LeetCodes.h"

char LeetCodes::kthCharacterII(long long k, vector<int>& operations) {
    vector<char> word = {'a'};
    // 遍历operations
    for (auto& operation : operations) {
        if (operation == 0) {
            word.insert(word.end(),word.begin(),word.end());
        } else {
            // 遍历word
            vector<char> newWord = word;
            for (auto c : word) {
                if (c == 'z')
                    newWord.push_back('a');
                newWord.push_back(++c);
            }
            word = newWord;
        }
    }
    return word[k - 1];
}