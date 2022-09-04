#include "../defs.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        size_t Asize = 0;
        size_t Bsize = 0;
        ListNode* fast = headA;
        while (fast!=nullptr)
        {
            Asize++;
            fast = fast->next;
        }
        fast = headB;
        while (fast!=nullptr){
            Bsize++;
            fast = fast->next;
        }
        if(Asize>Bsize){
            ListNode* slow = headB;
            fast = headA;
            size_t diff = Asize-Bsize;
            while(diff--){
                fast = fast->next;
            }
            while(fast!=nullptr){
                if(fast == slow){
                    return fast;
                }
                fast = fast->next;
                slow = slow->next;
            }
        }else{
            ListNode* slow = headA;
            fast = headB;
            size_t diff = Bsize-Asize;
            while(diff--){
                fast = fast->next;
            }
            while(fast!=nullptr){
                if(fast == slow){
                    return fast;
                }
                fast = fast->next;
                slow = slow->next;
            }
        }
        return nullptr;
    }
};