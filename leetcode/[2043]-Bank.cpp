//
// Created by sanenchen on 25-10-26.
//
#include <bits/stdc++.h>
using namespace std;

class Bank {
private:
    unordered_map<long long, long long> ac;
public:
    Bank(vector<long long>& balance) {
        for (int i = 0; i < balance.size(); ++i) {
            ac[i + 1] = balance[i];
        }
    }

    bool transfer(int account1, int account2, long long money) {
        if (ac.count(account1) && ac.count(account2) && money < ac[account1]) {
            ac[account1] -= money;
            ac[account2] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money) {
        if (ac.count(account)) {
            ac[account] += money;
            return true;
        }
        return false;
    }

    bool withdraw(int account, long long money) {
        if (ac.count(account) && money < ac[account]) {
            ac[account] -= money;
            return true;
        }
        return false;
    }
};
