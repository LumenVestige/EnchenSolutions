//
// Created by sanenchen on 25-7-5.
//
#include "../LeetCodes.h"
string to_base(int n, int base) {
    string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";

    if (n == 0) return "0";  // Special case for zero

    while (n > 0) {
        result += chars[n % base];
        n /= base;
    }

    reverse(result.begin(), result.end());  // Reverse the result string
    return result;
}
string LeetCodes::concatHex36(int n) {
    int n_2 = pow(n,2);
    int n_3 = pow(n ,3);

    // 16进制转化
    string out = "";
    stringstream ss;
    ss << hex << n_2;
    ss >> out;
    ranges::transform(out, out.begin(), ::toupper);
    cout << out << endl;

    // 36进制转化
    string out_2 = to_base(n_3, 36);  // Using the to_base function for base 36 conversion
    cout << "Base 36: " << out << endl;
    return out + out_2;
}