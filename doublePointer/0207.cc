#include "../defs.h"

// Definition for singly-linked list.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int Asize = 0;
        int Bsize = 0;
        ListNode *temp = headA;
        while (temp != nullptr)
        {
            temp = temp->next;
            Asize++;
        }
        temp = headB;
        while (temp != nullptr)
        {
            temp = temp->next;
            Bsize++;
        }
        if (Asize > Bsize)
        {
            ListNode *fast = headA;
            int loop = Asize - Bsize;
            while (loop--)
            {
                fast = fast->next;
            }
            ListNode *slow = headB;
            while (fast != nullptr && slow != nullptr)
            {
                if (fast == slow)
                {
                    return fast;
                }
                fast = fast->next;
                slow = slow->next;
            }
        }
        else
        {
            ListNode *fast = headB;
            int loop = Bsize - Asize;
            while (loop--)
            {
                fast = fast->next;
            }
            ListNode *slow = headA;
            while (fast != nullptr && slow != nullptr)
            {
                if (fast == slow)
                {
                    return fast;
                }
                fast = fast->next;
                slow = slow->next;
            }
        }
        return nullptr;
    }
};