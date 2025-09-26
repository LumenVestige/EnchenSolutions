//
// Created by sanenchen on 25-9-26.
//
#include <stdio.h>
#include <cmath>
bool isPrime(const int num) {
    int temp = sqrt(num);
    for (int i = 2; i < temp; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    for (int i = 0; i <= 1000000; ++i) {
        if (isPrime(i)) {}
            // printf("%d ", i);
    }
}