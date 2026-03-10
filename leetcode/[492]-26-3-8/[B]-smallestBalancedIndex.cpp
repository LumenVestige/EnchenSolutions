#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int smallestBalancedIndex(vector<int>& nums) {
    vector<long long> prefix_add(nums.size(), 0);
    for (int i = 1; i < nums.size(); ++i) {
        prefix_add[i] = prefix_add[i-1] + nums[i-1];
    }
    // 从右往左来
    long long mul = 1;
    for (int i = nums.size() - 1; i >= 0; ++i) {
        if (mul == prefix_add[i]) {
            return i;
        }
        if (mul > prefix_add[i-1] / nums[i]) {
            break;
        }
        mul *= nums[i];
    }
    return -1;
}

signed main() {
    vector<int> nums = {813,974,946,966,915,924,812,1000,891,875,989,656,991,806,818,999,971,276,923,997,992,943,983,811,909,990,924,991,726,818,969,690,996,784,992,949,915,931,932,821,699,688,712,805,849,489,406,482,777,974,479,237,963,903,957,995,814,864,832,889,936,467,831,970,757,646,962,987,885,924,918,710,763,839,860,888,971,994,339,253,564,759,68,747,797,716,939,987,68,953,1000,298,10,1,1,1,1,1,48,1,77,2};
    cout << smallestBalancedIndex(nums);
    return 0;
}