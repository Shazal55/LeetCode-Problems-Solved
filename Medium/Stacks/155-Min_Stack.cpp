#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class MinStack {
public:
    stack<pair<int,int>> s;
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()){
            s.push({value,value});
        }
        else{
            int minvalue = min(value,s.top().second);
            s.push({value,minvalue});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
//Optimize 
class MinStack1 {
public:
    stack<long long int> s;
    long long int minvalue;
    MinStack1() {
        
    }
    
    void push(int value) {
        if(s.empty()){
            s.push(value);
            minvalue = value;
        }
        else{
            if(value < minvalue){
                s.push((long long) 2 * value - minvalue);
                minvalue = value;
            }
            else{
                s.push(value);
            }
        }
    }
    
    void pop() {
        if(s.top() < minvalue){
            minvalue = 2 * minvalue - s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top() < minvalue){
            return minvalue;
        }
        return s.top();
    }
    
    int getMin() {
        return minvalue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */