#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val){
            ListNode *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
        ListNode *current = head;
        while(current != NULL && current->next != NULL){
            if(current->next->val == val){
                ListNode *temp = current->next;
                current->next = current->next->next;
                temp->next = NULL;
                delete temp;
            }
            else{
                current = current->next;
            }
        }
        return head;
    }
};