#include "../defs.h"

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

class MyLinkedList
{
public:
    MyLinkedList()
    {
        dummyHead = new ListNode(0);
        size = 0;
    }

    int get(int index)
    {
        if (index + 1> size  || index < 0)
        {
            return -1;
        }
        ListNode *cur = dummyHead;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->next->val;
    }

    void addAtHead(int val)
    {
        ListNode *newHead = new ListNode(val);
        newHead->next = dummyHead->next;
        dummyHead->next = newHead;
        size++;
    }

    void addAtTail(int val)
    {
        ListNode *newTail = new ListNode(val);
        ListNode *cur = dummyHead;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newTail;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
        {
            return;
        }
        else if (index < 0)
        {
            addAtHead(val);
            return;
        }
        ListNode *cur = dummyHead;
        while (index--)
        {
            cur = cur->next;
        }
        ListNode *newNode = new ListNode(val, cur->next);
        cur->next = newNode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index + 1 > size || index < 0)
        {
            return;
        }
        ListNode *cur = dummyHead;
        while (index--)
        {
            cur = cur->next;
        }
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        size--;
    }

private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    size_t size;
    ListNode *dummyHead;
};

int main()
{
    MyLinkedList *linkedList = new MyLinkedList();
    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1, 2); //链表变为1-> 2-> 3
    linkedList->get(1);           //返回2
    linkedList->deleteAtIndex(1); //现在链表是1-> 3
    linkedList->get(1);           //返回3
    linkedList->get(3);           //返回-1
    linkedList->deleteAtIndex(3); 
    linkedList->deleteAtIndex(0); //现在链表是3
    linkedList->get(0);           //返回3
    linkedList->deleteAtIndex(0); //现在链表是
    linkedList->get(0);           //返回
}
