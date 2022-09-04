#include"../defs.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if(fast==nullptr||fast->next==nullptr){
            return nullptr;
        }
        slow = dummyHead;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* result= fast;
        delete dummyHead;
        return result;
    }
};