#include <bits/stdc++.h>
using namespace std;

// int upperBound(vector<long long>& nums, int target) {
//     int left = -1, right = nums.size();
//     while (left + 1 != right) {
//         int mid = (left + right) / 2;
//         if (nums[mid] <= target) {
//             left = mid;
//         } else {
//             right = mid;
//         }
//     }
//     return left;
// }

// int largestPrime(int n) {
//     // 预处理
//     int MX = 500000;
//     bool is_prime[MX + 1];
//     vector<int> primes;
//     is_prime[0] = is_prime[1] = false; // 0 和 1 不是质数
//     memset(is_prime, 1, sizeof(is_prime));
//     for (int i = 2; i <= MX; i++) {
//         if (is_prime[i]) {
//             primes.push_back(i);
//             for (long long j = 1LL * i * i; j <= MX; j += i) {
//                 is_prime[j] = false; // j 是质数 i 的倍数
//             }
//         }
//     }
//     vector<long long> mag = {0};
//     long long sum = 0;
//     for (auto& i : primes) {
//         sum += i;
//         if (sum > MX) break;
//         if (is_prime[sum]) mag.push_back(sum);
//     }

//     return mag[upperBound(mag, n)];
// }

// int upperBound(vector<long long>& nums, int target) {
//     int left = -1, right = nums.size();
//     while (left + 1 != right) {
//         int mid = (left + right) / 2;
//         if (nums[mid] <= target) {
//             left = mid;
//         } else {
//             right = mid;
//         }
//     }
//     return left;
// }
// vector<long long> mag = {0};
// auto init = [] {
//     unordered_set<long long> numCheck;
//     for (int i = 0; i < 1000000000; ++i);  
//     // 预处理
//     auto isSu = [&](long long x) {
//         for (long long i = 2; i <= sqrt(x); ++i) {
//             if (x % i == 0) {
//                 return false;
//             }
//         }
//         numCheck.insert(x);
//         return true;
//     };

//     long long sum = 0;
//     for (int i = 2; i <= 5 * 1e5; ++i) {
//         isSu(i);
//     }
//     for (int i = 2; i <= 5 * 1e5; ++i) {
//         if (numCheck.count(i)) {
//             sum += i;
//             if (numCheck.count(sum)) mag.push_back(sum);
//         }
//     }
//     return 0;
// }();
int largestPrime(int n) {
    return mag[upperBound(mag, n)];
}

int main() {
    cout << largestPrime(15);
    return 0;
}