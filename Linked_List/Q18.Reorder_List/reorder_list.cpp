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

void reorderList(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *first = head;
    ListNode *second = slow->next;
    slow->next = NULL;

    ListNode *prev = NULL;
    ListNode *curr = second;

    while (curr != NULL)
    {
        ListNode *nextNode = curr->next;

        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    second = prev;
    while (second != NULL)
    {

        ListNode *temp1 = first->next;
        ListNode *temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

int main()
{
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    cout << "Enter the elements: ";

    for (int i = 0; i < n; i++)
    {
        int val;
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

    reorderList(head);

    cout << "Reordered Linked List: ";

    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}