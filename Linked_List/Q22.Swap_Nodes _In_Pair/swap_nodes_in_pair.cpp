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

ListNode *swapPairs(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *first = head;
    ListNode *newhead = head->next;
    ListNode *prevPair = NULL;

    while (first != NULL && first->next != NULL)
    {
        ListNode *second = first->next;
        ListNode *nextPair = first->next->next;

        if (prevPair != NULL)
        {
            prevPair->next = second;
        }

        second->next = first;
        first->next = nextPair;
        prevPair = first;
        first = nextPair;
    }
    return newhead;
}


int main()
{
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Linked list is empty." << endl;
        return 0;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "Enter linked list elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        ListNode* newNode = new ListNode(val);

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

    head = swapPairs(head);

    cout << "List after swapping pairs: ";

    ListNode* temp = head;
    while (temp != nullptr)
    {
        cout << temp->val;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }

    cout << endl;
    return 0;
}
