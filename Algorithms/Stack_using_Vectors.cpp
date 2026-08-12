#include <iostream>
#include <vector>
using namespace std;
class Stack{
private:
    vector<int> vec;
public:
    void push(int x);
    void pop();
    int top();
    bool empty();
};
void Stack :: push(int x){
    vec.push_back(x);
}
void Stack :: pop(){
    vec.pop_back();
}
int Stack :: top(){
    return vec[vec.size()-1];
}
bool Stack :: empty(){
    return vec.size() == 0;
}
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}