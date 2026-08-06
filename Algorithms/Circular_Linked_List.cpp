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
class Circular{
private:
    Node *head;
public:
    Circular();
    ~Circular();
    bool insert_Start_Node(int x);
    bool insert_end_Node(int x);
    bool delete_Start_Node(int &x);
    bool delete_end_Node(int &x);
    bool isEmpty();
    void display();
};
Circular :: Circular(){
    head = NULL;
}
Circular :: ~Circular(){
    if(head == NULL){
        return;
    }
    Node *current = head->next;
    while(current != head){
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
}
bool Circular :: isEmpty(){ 
    return head == NULL;
}
bool Circular :: insert_end_Node(int val){
    Node *newNode = new Node(val);
    if(isEmpty()){
        head = newNode;
        newNode->next = head;
        return true;
    }
    Node *current = head;
    while(current->next != head){
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return true;
}

bool Circular :: insert_Start_Node(int val){
    Node *newNode = new Node(val);
    if(isEmpty()){
        head = newNode;
        newNode->next = head;
        return true;
    }
    Node *current = head;
    while(current->next != head){
        current = current->next;
    }
    newNode->next = head;
    current->next = newNode;
    head = newNode;
    return true;
}

bool Circular :: delete_Start_Node(int &val){
    if(isEmpty()){
        return false;
    }
    if(head->next == head){
        val = head ->data;
        delete head;
        head = NULL;
        return true;
    }
    Node *current = head;
    while(current->next != head){
        current = current->next;
    }
    Node *temp = head;
    val = temp->data;
    head = head->next;
    current->next = head;
    delete temp;
    return true;
}
bool Circular :: delete_end_Node(int &val){
    if(isEmpty()){
        return false;
    }
    if(head->next == head){
        val = head->data;
        delete head;
        head = NULL;
        return true;
    }
    Node *current = head;
    while(current->next->next != head){
        current = current->next;
    }
    Node *temp = current->next;
    val = temp->data;
    current->next = head;
    temp->next = NULL;
    delete temp;
    return true;
}

void Circular :: display(){
    if(isEmpty()){
        cout << "List is empty\n";
        return;
    }
    Node *temp = head;
    do{
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    while(temp != head);
    cout<<temp->data<<endl;
}
int main(){
    Circular cl;
    int val;
    cl.insert_Start_Node(5);
    cl.insert_Start_Node(0);
    cl.insert_end_Node(10);
    cl.insert_end_Node(15);
    cl.insert_end_Node(20);
    cl.insert_end_Node(30);
    cl.display();
    cl.delete_end_Node(val);
    cl.delete_Start_Node(val);
    cl.display();
}