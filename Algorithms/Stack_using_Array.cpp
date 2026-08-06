#include <iostream>
using namespace std;
class Stack{
private:
    int *StackArray;
    int Stacksize;
    int top;
public:
    Stack(int x);
    ~Stack();
    bool isEmpty();
    bool isFull();
    bool push(int val);
    bool pop(int &val); 
    void display();
    void top_element(int &);
};
Stack :: Stack(int x){
    Stacksize = x;
    StackArray = new int[Stacksize];
    top = -1;
}
Stack :: ~Stack(){
    delete [] StackArray;
    StackArray = NULL;
}
bool Stack :: isEmpty(){
    return top == -1;
}
bool Stack :: isFull(){
    return top == Stacksize - 1;
}
bool Stack :: push(int val){
    if(isFull()){
        cout<<"Stack is already full"<<endl;
        return false;
    }
    top++;
    StackArray[top] = val;
    return true;
}
bool Stack :: pop(int &val){
    if(isEmpty()){
        cout<<"Stack is already empty"<<endl;
        return false;
    }
    val = StackArray[top];
    top--;
    return true;
}
void Stack :: display(){
    if(isEmpty()){
        cout<<"Stack is already empty"<<endl;
        return;
    }
    for(int i = top; i>= 0; i--){
        cout<<StackArray[i]<<" ";
    }
}
void Stack :: top_element(int &val){
    if(isEmpty()){
        cout<<"Stack is already empty"<<endl;
        return;
    }
    val = StackArray[top];
}
int main(){
    Stack sk(10);
    int x;
    sk.push(10);
    sk.push(20);
    sk.push(30);
    sk.display();
    cout<<endl;
    sk.pop(x);
    cout<<x<<endl;
    sk.top_element(x);
    cout<<x<<endl;
}