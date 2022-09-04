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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(-1,head);
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        size_t i = 0;
        while(fast->next!=nullptr){
            if(i++ < n){
                fast = fast->next;
                continue;
            }
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        ListNode* result = dummyHead->next;
        delete temp;
        delete dummyHead;
        return result;
    }
};