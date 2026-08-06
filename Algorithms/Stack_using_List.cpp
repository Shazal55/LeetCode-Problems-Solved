#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class Stack{
private:
    Node *top;
public:
    Stack();
    ~Stack();
    bool push(int val);
    bool pop();
    bool isEmpty();
    void makeNull();
    void display();
};
Stack :: Stack(){
    top = NULL;
}
Stack :: ~Stack(){
    makeNull();
}
bool Stack :: isEmpty(){
    return top == NULL;
}
bool Stack :: push(int val){
    Node *newNode = new Node(val);
    newNode->next = top;
    top = newNode;
    return true;
}
bool Stack :: pop(){
    if(isEmpty()){
        cout<<"Stack is already empty"<<endl;
        return false;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
    return true;
}
void Stack :: makeNull(){
    while(top != NULL){
        Node *curr = top;
        top = top->next;
        delete curr;
    }
}
void Stack :: display(){
    Node *temp = top;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Stack sk;
    sk.push(10);
    sk.push(20);
    sk.push(30);
    sk.push(45);
    sk.display();
    sk.pop();
    sk.display();
    sk.makeNull();
    sk.display();
}
