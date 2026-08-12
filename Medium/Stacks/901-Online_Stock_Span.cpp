#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class StockSpanner {
public:
    stack<int> s;
    vector<int> prices;
    StockSpanner() {
    }
    int next(int price) {
        int i = prices.size();
        while (!s.empty() && prices[s.top()] <= price) {
            s.pop();
        }
        int ans;
        if (s.empty()) {
            ans = i + 1;
        }
        else {
            ans = i - s.top();
        }
        prices.push_back(price);
        s.push(i);
        return ans;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
