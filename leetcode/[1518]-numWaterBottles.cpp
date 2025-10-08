//
// Created by sanenchen on 25-10-1.
//
#include <bits/stdc++.h>
using namespace std;
int numWaterBottles(int numBottles, int numExchange) {
    int alreadyDrink = numBottles, emptyBottles = numBottles;
    while (emptyBottles / numExchange > 0) {
        // 可换的水
        int tmp = emptyBottles / numExchange;
        alreadyDrink += tmp;
        emptyBottles -= tmp * numExchange;
        emptyBottles += tmp;
    }
    return alreadyDrink;
}
int main() {
    cout << numWaterBottles(9, 3);
    return 0;
}