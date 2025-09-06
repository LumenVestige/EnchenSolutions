#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

vector<ull> find_x(ull n) {
    vector<ull> result;
    
    // 尝试不同的m值，m表示添加的0的个数
    for (int m = 1; m <= 18; m++) {
        ull divisor = 1;
        bool overflow = false;
        
        // 计算divisor = 1 + 10^m
        for (int i = 0; i < m; i++) {
            if (divisor > n / 10) {  // 防止乘法溢出
                overflow = true;
                break;
            }
            divisor *= 10;
        }
        
        if (overflow) {
            break;  // 10^m已足够大，无需继续尝试更大的m
        }
        
        divisor += 1;  // 得到1 + 10^m
        
        if (divisor > n) {
            break;  // 除数大于n，不可能有解
        }
        
        // 检查是否能整除
        if (n % divisor == 0) {
            ull x = n / divisor;
            
            // 检查x是否不以0结尾
            if (x % 10 != 0) {
                result.push_back(x);
            }
        }
    }
    
    sort(result.begin(), result.end());
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        ull n;
        cin >> n;
        
        vector<ull> x_values = find_x(n);
        
        if (x_values.empty()) {
            cout << "0\n";
        } else {
            cout << x_values.size() << "\n";
            for (size_t i = 0; i < x_values.size(); i++) {
                if (i > 0) {
                    cout << " ";
                }
                cout << x_values[i];
            }
            cout << "\n";
        }
    }
    
    return 0;
}
