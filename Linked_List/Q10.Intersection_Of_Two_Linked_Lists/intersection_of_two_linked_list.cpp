#include <iostream>
#include <list>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *pA = headA;
    ListNode *pB = headB;

    while (pA != pB)
    {
        pA = (pA == NULL) ? headB : pA->next;
        pB = (pB == NULL) ? headA : pB->next;
    }
    return pA;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{
    // Common part of both linked lists
    ListNode *common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    // List A
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    // List B
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);

    ListNode *intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL)
    {
        cout << "Intersection Node: " << intersection->val << endl;
    }
    else
    {
        cout << "No intersection found." << endl;
    }

    return 0;
}