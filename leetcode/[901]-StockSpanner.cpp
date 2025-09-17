#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> st;
    int currentDay = -1;
public:
    StockSpanner() {
        st.emplace(-1, INT_MAX);
    }
    
    int next(int price) {
        while (price >= st.top().second)
            st.pop();
        currentDay++;
        int ans = currentDay - st.top().first;
        st.emplace(currentDay, price);
        return ans;
    }
};

int main() {

}