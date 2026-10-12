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

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || k == 1)
    {
        return head;
    }

    ListNode *temp = head;
    int count = 0;

    while (count < k && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (count < k)
    {
        return head;
    }
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *groupStart = head;
    int i = 0;
    while (i < k)
    {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        i++;
    }

    groupStart->next = reverseKGroup(curr, k);

    return prev;
}

int main()
{
    int n, k, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Linked list is empty." << endl;
        return 0;
    }

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    cout << "Enter linked list elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        ListNode *newNode = new ListNode(val);

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

    cout << "Enter k: ";
    cin >> k;

    if (k <= 0) {
        cout << "k must be positive." << endl;
        return 0;
    }

    head = reverseKGroup(head, k);

    cout << "Reversed list: ";

    ListNode *temp = head;
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