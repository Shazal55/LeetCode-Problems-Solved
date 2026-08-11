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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        int count = 0;
        //Check if k nodes exists
        while(count<k){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
            count++;
        }
        //Recursion call
        ListNode *prevNode = reverseKGroup(temp,k);
        //Reverse current group
        temp = head;
        count = 0;
        while(count<k){
            ListNode *next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            count++;
        }
        return prevNode;
    }
};