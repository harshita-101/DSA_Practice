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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }

        current = current->next;
    }

    if (list1 != NULL)
    {
        current->next = list1;
    }
    else
    {
        current->next = list2;
    }

    return dummy->next;
}

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Find the middle of the linked list
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the linked list into two halves
    ListNode *second = slow->next;
    slow->next = NULL;

    // Sort both halves
    ListNode *left = sortList(head);
    ListNode *right = sortList(second);

    // Merge the sorted halves
    return mergeTwoLists(left, right);
}

int main()
{
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Linked list is empty." << endl;
        return 0;
    }

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    cout << "Enter the elements: ";

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        ListNode *newNode = new ListNode(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = sortList(head);

    cout << "Sorted linked list: ";

    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}