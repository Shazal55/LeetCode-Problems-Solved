#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
class MyLinkedList {
public:
    Node* head;

    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        if(index<0){
            return -1;
        }
        Node *temp = head;
        for(int i = 0; i<index; i++){
            temp = temp->next;
        }
        if(temp == NULL){
            return -1;
        }
        return temp->data;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        newNode -> next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        Node *newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(head == NULL){
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        for(int i = 0; i<index-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;

    }
    
    void deleteAtIndex(int index) {
        if(head == NULL || index<0){
            return;
        }
        if(index == 0){
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *temp = head;
        for(int i= 0; i<index-1; i++){
            temp = temp->next;
        }
        if(temp->next == NULL){
            return;
        }
        Node *todelete = temp->next;
        temp->next = todelete->next;
        delete todelete;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
