#include <iostream>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        unordered_map<Node*,Node*> m;
        Node *newHead = new Node(head->val);
        m[head] = newHead;
        Node *oldtemp = head->next;
        Node *newtemp = newHead;

        while(oldtemp != NULL){
            Node *copyNode = new Node(oldtemp->val);
            m[oldtemp] = copyNode;
            newtemp->next = copyNode;
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        oldtemp = head;
        newtemp = newHead;
        while(oldtemp != NULL){
            newtemp->random = m[oldtemp->random];
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
        return newHead;
    }
};