//
// Created by sanenchen on 25-10-2.
//
#include <bits/stdc++.h>
using namespace std;
int maxBottlesDrunk(int numBottles, int numExchange) {
    int alreadyDrink = 0, emptyBottles = 0;
    while (true) {
        if (numBottles != 0) {
            alreadyDrink++;
            emptyBottles++;
            numBottles--;
        } else {
            if (emptyBottles / numExchange > 0) {
                numBottles++;
                emptyBottles -= numExchange;
                numExchange++;
            } else {
                return alreadyDrink;
            }
        }
    }
}
int main() {
    cout << maxBottlesDrunk(10, 3);
    return 0;
}