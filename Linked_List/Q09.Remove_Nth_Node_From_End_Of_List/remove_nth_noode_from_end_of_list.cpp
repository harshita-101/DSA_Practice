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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *slow = dummy;
    ListNode *fast = dummy;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return dummy->next;
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

    int removePosition;

    cout << "Enter n (node to remove from end): ";
    cin >> removePosition;

    head = removeNthFromEnd(head, removePosition);

    cout << "Linked list after removing the node: ";

    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}