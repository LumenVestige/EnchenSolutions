//
// Created by sanenchen on 25-9-19.
//
#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    vector<unordered_map<char, int>> chars;
public:
    Spreadsheet(int rows) {
        unordered_map<char, int> zero;
        for (char a = 'A'; a <= 'Z'; ++a) {
            zero[a] = 0;
        }
        chars.resize(rows + 1);
        for (int i = 1; i <= rows; ++i)
            chars[i] = zero;
    }

    void setCell(string cell, int value) {
        const char cln = cell[0];
        const int row = stoi(cell.substr(1, cell.size() - 1));
        chars[row][cln] = value;
    }

    void resetCell(string cell) {
        // 解析cell字符
        // 第一个代表是列A B C 第二个代表行
        // // char 转 int
        const char cln = cell[0];
        const int row = stoi(cell.substr(1, cell.size() - 1));
        chars[row][cln] = 0;
    }

    int getValue(string formula) {
        // 挨个遍历
        string x = "", y = "";
        bool flag = false;
        for (int i = 1; i < formula.size(); ++i) {
            if (formula[i] != '+') {
                if (!flag) x += formula[i];
                else y += formula[i];
            } else flag = true;
        }
        int a, b;
        // 判断第一个数
        if (x[0] > '9') {
            const char cln = x[0];
            const int row = stoi(x.substr(1, x.size() - 1));
            //cout << x.substr(1, x.size() - 1);
            a = chars[row][cln];
        } else a = stoi(x);
        // 判断第二个数
        if (y[0] > '9') {
            const char cln = y[0];
            const int row = stoi(y.substr(1, y.size() - 1));
            //cout << y.substr(1, y.size() - 1);
            b = chars[row][cln];
        } else b = stoi(y);
        return a + b;
    }
};

int main() {
    Spreadsheet(2);
    return 0;
}
