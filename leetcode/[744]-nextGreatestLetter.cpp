//
// Created by sanenchen on 25-8-15.
//
#include <bits/stdc++.h>
using namespace std;
char nextGreatestLetter(vector<char>& letters, char target) {
    int left = -1, right = letters.size();
    while (left + 1 != right) {
        int mid = left + (right - left) / 2;
        if (letters[mid] > target)
            right = mid;
        else left = mid;
    }
    if (right == letters.size()) return letters[0];
    return letters[right];
}
int main() {
    vector<char> letters = {'c','f','j'};
    cout << nextGreatestLetter(letters, 'c');
}