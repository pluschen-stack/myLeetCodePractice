#include "../defs.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode* dummyHead = new ListNode(-1,head);
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        while(fast->next!=nullptr){
            if(n!=0){
                fast = fast->next;
                n--;
                continue;
            }
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* tobeDelete = slow->next;
        slow->next=tobeDelete->next;
        delete tobeDelete;
        //这一行不可以删掉，因为tobeDelete可能会是head
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};