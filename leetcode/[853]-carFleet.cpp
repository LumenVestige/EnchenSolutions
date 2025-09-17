#include <bits/stdc++.h>
using namespace std;
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> cars;
    for (int i = 0; i < position.size(); ++i) {
        cars.emplace_back(position[i], speed[i]);
    }
    sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    stack<double> st; // todolist
    for (int i = 0; i < position.size(); ++i) {
        double t = 1.0 * (target - cars[i].first) / cars[i].second;
        while (!st.empty() && st.top() <= t)
            st.pop();
        st.push(t);
    }
    return st.size();
}
int main() {
    vector<int> position = {10,8,0,5,3}, speed={2,4,1,1,3};
    cout << carFleet(12, position, speed);
    return 0;
}