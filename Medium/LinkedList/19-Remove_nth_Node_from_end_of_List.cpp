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
    ListNode* removeNthFromEnd(ListNode* head, int n) {//O(n)
        ListNode *temp = head;
        int size = 0;
        while(temp != NULL){
            temp = temp->next;
            size++;
        }
        int idx = size - n;
        if(idx<0){
            return NULL;
        }
        if(idx == 0){
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int count = 0;
        temp = head;
        ListNode* change = NULL;
        while(count < idx-1){
            temp = temp->next;
            count++;
        }
        change = temp->next;
        temp->next = temp->next->next;
        delete change;
        return head;
    }
};