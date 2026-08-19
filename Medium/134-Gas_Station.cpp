#include <iostream>
#include <vector>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int g = gas.size();
    int totalGas = 0, totalCost = 0;
    int currentGas = 0;
    int start = 0;
    for(int i = 0; i<g; i++){
        currentGas = currentGas + gas[i] - cost[i];
        totalGas += gas[i];
        totalCost += cost[i];
        if(currentGas < 0){
            start = i+1;
            currentGas = 0;
        }
    }
    return totalGas < totalCost ? -1 : start;
}
int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout<<"Starting index : "<<canCompleteCircuit(gas,cost)<<endl;
    return 0;
}
//Output : Starting index : 3