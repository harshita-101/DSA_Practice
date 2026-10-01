#include <iostream>
#include <list>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;

        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ListNode *newNode = new ListNode(digit);
        current->next = newNode;
        current = current->next;

        if (l1 != NULL)
            l1 = l1->next;

        if (l2 != NULL)
            l2 = l2->next;
    }
    return dummy->next;
}

int main()
{
    // Example usage
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *result = addTwoNumbers(l1, l2);

    // Print the result
    while (result != nullptr)
    {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}