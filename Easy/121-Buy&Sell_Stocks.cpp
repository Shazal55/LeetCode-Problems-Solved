#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int> &prices){
    int max = 0;
    for(int i = 0; i < prices.size();i++){ //Brute force O(n^2)
        for(int j = i+1; j < prices.size();j++){
            if(prices[j] - prices[i] > max){
                max = prices[j]-prices[i];
            }
        }
    }
    return max;
}
int maxProfit1(vector<int> &prices){ //Optimized approach O(n)
    int maxProfit = 0;
    int bestbuy = prices[0];
    for(int i = 0; i < prices.size(); i++){
        if( prices[i] > bestbuy){
            maxProfit = max(maxProfit,prices[i] - bestbuy);
        }
        bestbuy = min(bestbuy,prices[i]);
    }
    return maxProfit;
}
int main(){
    vector<int> vec = {7,1,5,3,7,4};
    cout<<maxProfit1(vec);
}