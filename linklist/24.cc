#include"../defs.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1,head);
        ListNode* cur = dummyHead;
        while(cur->next!=nullptr&&cur->next->next!=nullptr){
            ListNode* rest = cur->next->next->next;
            ListNode* temp = cur->next;

            cur->next = cur->next->next;
            cur->next->next = temp;
            temp->next = rest;
            cur = temp;
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};