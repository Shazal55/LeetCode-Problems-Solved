#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class LinkedList{
public:
    Node *head;
    LinkedList();
    bool insert_at_beginning(int val);
    bool insert_at_end(int val);
    bool insert_at_pos(int pos,int val);

    bool delete_from_beginning();
    bool delete_from_end();
    bool delete_from_pos(int pos);

    bool search(int val);
    void display();
    bool isEmpty();
    int countNodes();

    int recursionlength(Node *x);
    bool updateNode(int old,int update);
    bool reverseList();
    bool sortList();
    void recursivePrint(Node *head);
    void recursiveReverse(Node *current, Node* prev);
    ~LinkedList();
};

LinkedList :: LinkedList(){
    head = NULL;
}
bool LinkedList :: isEmpty(){
    return head == NULL;
}
bool LinkedList :: insert_at_beginning(int val){
    Node *newNode = new Node(val);
    if(head == NULL){
        head = newNode;
    }
    else{
    newNode->next = head;
    head = newNode;
    }
    return true;
}

bool LinkedList :: insert_at_end(int val){
    Node *newNode = new Node(val);
    if(head == NULL){
        head = newNode;
    }
    else{
        Node *current = head;
        while(current -> next != NULL){
            current = current->next;
        }
        current ->next = newNode;
    }
    return true;
}

bool LinkedList :: insert_at_pos(int pos,int val){
    if(pos <= 0){
        cout<<"Invalid Position entered"<<endl;
        return false;
    }
    if(pos == 1){
       return insert_at_beginning(val);
    }
    Node *newNode = new Node(val);
    int currentpos = 1;
    Node *current = head;
    while(current && currentpos < pos - 1){
        current = current->next;
        currentpos++;
    }
    if(current == NULL){
        cout<<"Position not found"<<endl;
        return false;
    }
    newNode->next = current->next;
    current->next = newNode;
    return true;
}

void LinkedList :: display(){
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

bool LinkedList :: delete_from_beginning(){
    if(head == NULL){
        cout<<"LinkedList is already empty"<<endl;
        return false;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    return true;
}

bool LinkedList :: delete_from_end(){
    if(head == NULL){
        cout<<"List is already empty"<<endl;
        return false;
    }
    Node *temp = head;
    if(temp->next == NULL){
        delete temp;
        head = NULL;
        return true;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return true;
}

bool LinkedList :: delete_from_pos(int pos){
    if(pos <= 0){
        cout<<"Invalid Position entered"<<endl;
        return false;
    }
    if(head == NULL){
        cout<<"List is already empty"<<endl;
        return false;
    }
    if(pos == 1){
        return delete_from_beginning();
    }
    Node *temp = head;
    Node *prev = NULL;
    int currentpos = 1;
    while(temp && currentpos < pos){
        prev =  temp;
        temp = temp->next;
        currentpos++;
    }
    if(temp == NULL){
        cout<<"Position not found"<<endl;
        return false;
    }
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
    return true;
}

int LinkedList :: countNodes(){
    Node *temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

bool LinkedList :: search(int val){
    int pos = 1;
    Node *temp = head;
    while(temp){
        if(temp->data == val){
            cout<<"Value found at position "<<pos<<endl;
            return true;
        }
        temp = temp->next;
        pos++;
    }
    cout<<"Value not found in the LinkedList"<<endl;
    return false;
}

bool LinkedList :: updateNode(int old, int update){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == old){
            temp->data = update;
            cout<<"Value "<<old<<" updated with "<<update<<" Successfully"<<endl;
            return true;
        }
        temp = temp->next;
    }
    cout<<"Value not found "<<endl;
    return false;
}

bool LinkedList :: reverseList(){
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while(current != NULL){
        next = current ->next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return true;
}

bool LinkedList :: sortList(){
    if(head == NULL || head->next == NULL){
        return true;
    }
    Node *current;
    Node *index;
    int temp;
    for(current = head; current != NULL; current = current->next){
        for(index = current->next; index != NULL; index = index->next){
            if(current->data > index->data){
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

int LinkedList :: recursionlength(Node *head){
    if(head == NULL){
        return 0;
    }
    return 1 + recursionlength(head -> next);
}

void LinkedList :: recursivePrint(Node *head){
    if(head == NULL){
        cout<<"NULL"<<endl;
        return;
    }
    cout<<head->data<<" -> ";
    recursivePrint(head->next);
}
void LinkedList :: recursiveReverse(Node *current, Node *prev = NULL){
    if(current == NULL){
        head = prev;
        recursivePrint(head);
        return;
    }
    Node *next =  current->next;
    current->next = prev;
    recursiveReverse(next,current);
}
LinkedList :: ~LinkedList(){
    Node *temp = head;
    while(temp){
        Node *current = temp;
        temp = temp->next;
        delete current;
    }
    head = NULL;
}
int main(){
    LinkedList ll;
    ll.insert_at_beginning(5);
    ll.insert_at_beginning(10);
    ll.insert_at_beginning(15);
    ll.insert_at_end(20);
    ll.insert_at_end(25);
    ll.insert_at_pos(4,100);
    ll.display();
    ll.delete_from_beginning();
    ll.delete_from_end();
    ll.display();
    ll.delete_from_pos(3);
    ll.display();
    cout<<"Total Nodes : "<<ll.countNodes()<<endl;
    ll.search(5);
    ll.updateNode(5,15);
    ll.display();
    ll.insert_at_beginning(2);
    ll.insert_at_beginning(0);
    ll.display();
    ll.reverseList();
    ll.display();

    ll.sortList();
    ll.display();
    cout<<"Length of List : "<<ll.recursionlength(ll.head)<<endl;
    ll.recursivePrint(ll.head);
    cout<<"Recursive reverse"<<endl;
    ll.recursiveReverse(ll.head);
    return 0;
}
