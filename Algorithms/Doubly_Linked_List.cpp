#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class Doubly{
private:
    Node *head;
    Node *tail;
public:
    Doubly();
    // ~Doubly();
    bool isEmpty();
    int getSize();

    bool insertFront(int val);
    bool insertEnd(int val);
    bool insertAt(int pos,int val);

    bool deleteFront();
    bool deleteBack();
    bool deleteAt(int pos);

    bool search(int val);
    void display();
};

Doubly :: Doubly(){
    head = tail = NULL;
}
bool Doubly :: isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}
int Doubly :: getSize(){
    int size = 0;
    if(head == NULL){
        return size;
    }
    Node *current = head;
    while(current != NULL){
        current = current->next;
        size++;
    }
    return size;
}
bool Doubly :: insertFront(int val){
    Node *newNode = new Node(val);
    if(isEmpty()){
        head = tail = newNode;
        return true;
    }
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    head = newNode;
    return true;
}

bool Doubly :: insertEnd(int val){
    Node *newNode = new Node(val);
    if(isEmpty()){
        head = tail = newNode;
        return true;
    }
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = NULL;
    tail = newNode;
    return true;
}

bool Doubly :: insertAt(int pos,int val){
    if(pos <= 0){
        cout<<"Invalid Position Entered"<<endl;
        return false;
    }
    Node *newNode = new Node(val);
    if(pos == 1){
        if(isEmpty()){
            head = tail = newNode;

        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return true;
    }
    Node *current = head;
    int currentPos = 1;
    while(current != NULL && currentPos < pos -1){
        current = current->next;
        currentPos++;
    }
    if(current == NULL){
        cout<<"Invalid Position entered"<<endl;
        return false;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if(current ->next != NULL){
        current->next->prev = newNode;
    }
    else{
        tail = newNode;
    }
    current->next = newNode;
    return true;
}

bool Doubly :: deleteFront(){
    if(isEmpty()){
        cout<<"List is already empty"<<endl;
        return false;
    }
    if(head == tail){
        delete head;
        head = tail = NULL;
        return true;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return true;
}
bool Doubly :: deleteBack(){
    if(isEmpty()){
        cout<<"List is already empty"<<endl;
        return false;
    }
    if(head == tail){
        delete tail;
        head = tail = NULL;
        return true;
    }
    Node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
    return true;
}

bool Doubly :: deleteAt(int pos){
    if(pos <= 0){
        cout<<"Invalid Position Entered"<<endl;
        return false;
    }
    if(isEmpty()){
        cout<<"List is already empty"<<endl;
        return false;
    }
    if(pos == 1){
        if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
        return true;
    }
    Node *current = head;
    int currentPos = 1;
    while(current != NULL && currentPos < pos ){
        current = current->next;
        currentPos++;
    }
    if(current == NULL){
        cout<<"Invalid Position entered"<<endl;
        return false;
    }
    if(current == tail){
        tail = tail->prev;
        tail->next = NULL;
        delete current;
        return true;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    return true;
}

void Doubly :: display(){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" <=> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
bool Doubly :: search(int val){
    if(isEmpty()){
        cout<<"List is Empty"<<endl;
        return false;
    }
    Node *temp = head;
    int pos = 1;
    while(temp != NULL){
        if(temp ->data == val){
            cout<<"Value "<<val<<" found at Position "<<pos<<endl;
            return true;
        }
        temp = temp->next;
        pos++;
    }
    cout<<"Value not found"<<endl;
    return false;
}
int main(){
    Doubly dl;
    dl.insertFront(10);
    dl.insertFront(20);
    dl.insertEnd(5);
    dl.insertEnd(25);
    dl.insertAt(3,11);
    dl.display();
    cout<<"Size of List : "<<dl.getSize()<<endl;
    // dl.deleteFront();
    // dl.deleteBack();
    // dl.deleteAt(3);
    // dl.display();
    dl.search(11);
}