#include <iostream>
using namespace std;
class Queue{
private:
    int *queuearray;
    int size;
    int rear;
    int front;
public:
    Queue(int x);
    ~Queue();
    bool Enqueue(int x);
    bool Dequeue();
    bool isEmpty();
    bool isFull();
    void MakeNull();
    void Display();
};
Queue :: Queue(int x){
    size = x;
    queuearray = new int[size];
    rear = front = -1;
}
Queue :: ~Queue(){
    delete [] queuearray;
}
bool Queue :: isEmpty(){
    return front == -1;
}
bool Queue :: isFull(){
    if ((rear + 1) % size == front){
        return true;
    }
    else{
        return false;
    }
}
bool Queue :: Enqueue(int x){
    if(isFull()){
        cout<<"Queue is already full "<<endl;
        return false;
    }
    if(isEmpty()){
        rear++;
        front++;
    }
    else{
        rear = (rear + 1)%size;
    }
    queuearray[rear] = x;
    return true;
}
bool Queue :: Dequeue(){
    if(isEmpty()){
        cout<<"Queue is already empty"<<endl;
        return false;
    }
    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1)%size;
    }
    return true;
}
void Queue :: Display(){
    for(int i = front; i<=rear; i++){
        cout<<queuearray[i]<<" "<<endl;
    }
}
void Queue :: MakeNull(){
    front = rear = -1;
}
int main(){
    Queue q(5);
    q.Enqueue(5);
    q.Enqueue(10);
    q.Enqueue(15);
    q.Display();
}