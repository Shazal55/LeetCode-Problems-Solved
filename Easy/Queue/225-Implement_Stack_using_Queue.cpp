#include <iostream>
#include <queue>
using namespace std;
class MyStack {
public:

    queue<int> que1;
    queue<int> que2;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!que1.empty()){
            que2.push(que1.front());
            que1.pop();
        }
        que1.push(x);
        while(!que2.empty()){
            que1.push(que2.front());
            que2.pop();
        }
    }
    
    int pop() {
        int ans = que1.front();
        que1.pop();
        return ans;
    }
    
    int top() {
        return que1.front();
    }
    
    bool empty() {
        return que1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */