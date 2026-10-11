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

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr != NULL)
    {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    ListNode *curr1 = reverseList(l1);
    ListNode *curr2 = reverseList(l2);
    int carry = 0;
    int sum = 0;
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    while (curr1 != NULL || curr2 != NULL || carry != 0)
    {
        int val1 = (curr1 != NULL) ? curr1->val : 0;
        int val2 = (curr2 != NULL) ? curr2->val : 0;
        sum = val1 + val2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ListNode *newNode = new ListNode(digit);
        current->next = newNode;
        current = current->next;
        if (curr1 != NULL)
        {
            curr1 = curr1->next;
        }
        if (curr2 != NULL)
        {
            curr2 = curr2->next;
        }
    }

    ListNode *list = reverseList(dummy->next);

    return list;
}


int main() {
    int n, m, digit;

    cout << "Enter number of digits in first number: ";
    cin >> n;

    ListNode* l1 = new ListNode(0);
    ListNode* tail1 = l1;

    cout << "Enter digits of first number in forward order: ";
    for (int i = 0; i < n; i++) {
        cin >> digit;
        tail1->next = new ListNode(digit);
        tail1 = tail1->next;
    }

    cout << "Enter number of digits in second number: ";
    cin >> m;

    ListNode* l2 = new ListNode(0);
    ListNode* tail2 = l2;

    cout << "Enter digits of second number in forward order: ";
    for (int i = 0; i < m; i++) {
        cin >> digit;
        tail2->next = new ListNode(digit);
        tail2 = tail2->next;
    }

    ListNode* result = addTwoNumbers(l1->next, l2->next);

    cout << "Sum: ";
    while (result != nullptr) {
        cout << result->val;
        if (result->next != nullptr) {
            cout << " -> ";
        }
        result = result->next;
    }

    cout << endl;
    return 0;
}
