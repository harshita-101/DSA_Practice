#include <iostream>
#include <list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL || list2 == NULL)
    {
        return list1 == NULL ? list2 : list1;
    }

    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main()
{
    // Example usage
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    ListNode *merged = mergeTwoLists(list1, list2);

    // Print the merged list
    while (merged != nullptr)
    {
        std::cout << merged->val << " ";
        merged = merged->next;
    }

    return 0;
}