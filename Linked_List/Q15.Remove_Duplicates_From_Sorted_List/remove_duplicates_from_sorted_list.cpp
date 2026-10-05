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

ListNode *deleteDuplicate(ListNode *head)
{
    ListNode *current = head;

    while (current != NULL && current->next != NULL)
    {
        if (current->val == current->next->val)
        {
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }
    return head;
}

int main()
{
    int n;
    cout << "Enter the value of nodes in List: ";
    cin >> n;

    if (n < 0)
    {
        cout << "List is empty.";
        return 0;
    }

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
    head = deleteDuplicate(head);

    cout << "Linked List after removing duplicates.";

    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}