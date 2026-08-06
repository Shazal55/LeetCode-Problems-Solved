#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
class Queue{
private:
    Node *front;
    Node* rear;
    int numItems;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    bool Enqueue(int x);
    bool Dequeue();
    void makeNull();
    void display();
};
Queue :: Queue(){
    front = rear = NULL;
    numItems = 0;
}
Queue :: ~Queue(){
    makeNull();
}
bool Queue :: isEmpty(){
    return numItems == 0;
}
bool Queue :: Enqueue(int x){
    Node *newNode = new Node(x);
    if(isEmpty()){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    numItems++;
    return true;
}
bool Queue :: Dequeue(){
    if(isEmpty()){
        cout<<"Queue is already empty"<<endl;
        return false;
    }
    Node *temp = front;
    front = front->next;
    delete temp;
    numItems--;
    return true;
}
void Queue :: makeNull(){
    while(!isEmpty()){
        Dequeue();
    }
}
void Queue :: display(){
    if (isEmpty()){
        cout<<"Queue is already empty"<<endl;
        return;
    }
    Node *temp = front;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Queue q;
    q.Enqueue(10);
    q.Enqueue(12);
    q.Enqueue(14);
    q.display();
    q.Dequeue();
    q.display();
}