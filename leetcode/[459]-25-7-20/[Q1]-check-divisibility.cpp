//
// Created by sanenchen on 25-7-20.
//
#include "../LeetCodes.h"

bool LeetCodes::checkDivisibility(int n) {
    int temp = n;
    int sum = 0, product = 1;
    while (n != 0) {
        sum += n % 10;
        product *= n % 10;
        n = n / 10;
    }
    return temp % (sum + product) == 0;
}
