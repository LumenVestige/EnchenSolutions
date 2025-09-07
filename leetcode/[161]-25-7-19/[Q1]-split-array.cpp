//
// Created by sanenchen on 25-7-19.
//
#include "../LeetCodes.h"

bool isPrime(const int num) {
    int tmp = sqrt(num);
    for(int i = 2;i <= tmp;i++)
        if(num%i == 0)
            return false;
    return true;
}

long long LeetCodes::splitArray(vector<int>& nums) {
    long long a=0, b=0;
    for (int i = 0; i < nums.size(); i++) {
        if (i <= 1) {
            b += nums[i];
        } else {
            if (isPrime(i))
                a += nums[i];
            else b+= nums[i];
        }
    }
    return abs(a-b);
}
