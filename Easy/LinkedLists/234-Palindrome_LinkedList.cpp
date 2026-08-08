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
    ListNode* reverse(ListNode *head){
        ListNode *current = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    ListNode *copyList(ListNode* head){
        if(head == NULL){
            return NULL;
        }
        ListNode *newHead = new ListNode(head->val);
        ListNode *original = head->next;
        ListNode *copy = newHead;
        while(original != NULL){
            copy->next = new ListNode(original->val);
            copy = copy->next;
            original = original->next;
        }
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *copy = copyList(head);
        ListNode *reversed = reverse(copy);
        ListNode *Original = head;
        while(Original!= NULL && reversed != NULL){
            if(Original->val != reversed->val){
                return false;
            }
            Original = Original->next;
            reversed = reversed->next;
        }
        return true;
    }
};